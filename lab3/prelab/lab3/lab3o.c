/**************************************************************************
 * FILE NAME:  lab3o.c
 *
 * EECS461 at the University of Michigan
 * Lab 3o solution
 *
 * Created 2004 ericjw
 * Revision History:
 *	7-25-06 lovelljc
 *	1-24-07 ericjw
 *
 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *	2008-08-07		Marianne Schmid
 *  2011-02-09	    Thomas Schneider
 **************************************************************************/

#include <mpc5553.h>
#include <serial.h>
#include <qadc.h>
#include <ecs.h>
#include <isr.h>

#define CALIBRATE               0
#define TRIGGER                 1
#define CAPTURE                 2
#define SEND                    3

#define NUM_POINTS              512
#define AVG_PERIOD_LEN          200

#define SINGLE_SCAN_CHANNEL     3

#define INTERRUPT_FREQUENCY     50000//50kHz sampling frequency


vuint32_t num_used = 0;
uint16_t buffer[NUM_POINTS];
void ocIsr(void);



int main(void) {
  uint16_t tmp2;
  uint16_t wait, cycles, cnt, mode;
  uint32_t results[4];
  uint32_t avg = 0;
  static uint32_t delay = 1;
  int8_t ch;
  uint8_t i;

  init_ECS(3);
  init_COM(1, 115200);     /* to communicate with display */
  qadcInit_single(SINGLE_SCAN_CHANNEL);

  init_interrupts(ocIsr, INTERRUPT_FREQUENCY);
  disable_interrupts();


  for(i=28; i<33; i++)
  {
 	SIU.PCR[i].B.PA = 0; /* GPIO */
 	SIU.PCR[i].B.OBE = 1; /* Output */
 	SIU.PCR[i].B.WPE = 0;
  }


  mode = CALIBRATE;
  while (1) {

    switch (mode) {

      case CALIBRATE: /* averaging code */
        for (i = 0; i < NUM_POINTS/3; i++) {
          results[0] = qadcReadQ1();
          avg += results[0];
          avg -= avg/(AVG_PERIOD_LEN);
        }
        mode = TRIGGER;
        break;

      case TRIGGER: /* triggering code */
        /* initialize previous results to large values */
        results[3] = 0xFFFF;
        results[2] = 0xFFFF;
        results[1] = 0xFFFF;
        cycles = 0;
        while (  cycles <= 5000  /* if we can't get a lock on an edge, continue anyways */ )
        {
          ++cycles;

          results[0] = qadcReadQ1();
          avg += (*results) & 0x0000FFFF;
          avg -= avg/(AVG_PERIOD_LEN);

          /* trigger when signal is at average power, and when
             signal is rising. */

          /* average power check */
          if (*results < avg/(AVG_PERIOD_LEN+3) ||
            *results > avg/(AVG_PERIOD_LEN-3))
              {
              results[3] = results[2];
              results[2] = results[1];
              results[1] = results[0];
              continue;
              }

          /* rising signal check */
          if (results[3] > results[0])
              {
              results[3] = results[2];
              results[2] = results[1];
              results[1] = results[0];
              continue;
              }

          /* we passed all conditions, so go on */
          break;
        }

        mode = CAPTURE;
        break;

      case CAPTURE:

        num_used=0;
        enable_interrupts();
          while (num_used < NUM_POINTS){}
        disable_interrupts();

        // before entering send, flush any 'S' character received from the PC
        while ( serial_readyToReceive(1) )
        {
          serial_getchar(1);
        }
        mode = SEND;
        break;

      case SEND:
        // use the simple transport encoding:
        // | BLOCK_START | DATA |  // two fields, start and data
        #define BLOCK_START   0x80 // BLOCK_START is a reserved control character
        // the DATA field includes 512 samples with 14 bit resolution each. A sample
        // is encoded in two characters. The allowed characters exclude the block start character
        // Character    | 1                    | 0                    |
        // Bit          | 7 | 6 .. 0           | 7 | 6 .. 0           | Bit 7 is the most significant bit
        // Value        | 0 | ( sample / 128 ) | 0 | ( sample % 128 ) |
        // so the first byte includes the 7 most significant bits, the second the 7 least significant bits of the data sample

        // MPC                        MATLAB
        //  |                           |                               < - - - - - - - - - -+
        //  | ----+                     |                                        LOOP        :
        //  |     | capture             |                                                    :
        //  | < - +                     |                                                    :
        //  |                           |                                                    :
        //  | <----------'S'----------- |                                                    :
        //  |                           |                                                    :
        //  |                           | -----+                                             :
        //  # --------BLOCK_START-----> |      | wait blockstart                             :
        //  #                           | <----+                                             :
        //  # send                      |                                                    :
        //  #                           | -----+                                             :
        //  # ------ DATA (1024 Bytes)  |      |                                             :
        //  #       ------              |      | fread with timeout set to 3 seconds         :
        //  #             ------        |      |                                             :
        //  #                   ------> |      |                                             :
        //  | ----+                     | <----+                                             :
        //  |     | trigger             |                                                    :
        //  | <---+                     | -----+                                             :
        //  |                           |      | display                                     :
        //  |                           | <----+                                             :
        //  |                           |                               < - - - - - - - - - -+

        // Wait till the oscilloscope display is ready to receive the data
        ch = serial_getchar(1);

        if ( ch == 'S' )
        {
          SIU.GPDO[29].B.PDO = 1;

          // this character is reserved as control character
          // send ehe block start
          serial_putchar(  1, BLOCK_START );

          // send the data bytes
          for (cnt = 0; cnt < NUM_POINTS; cnt++)
          {
            uint16_t tmp2 = buffer[cnt];

            // in any case, clip to 14 bits to keep the BLOCK_START out of the data stream
            if (tmp2 > 0x7FFFU)
            {
              tmp2 = 0x7FFFU;
            }

            // for each sample send two bytes, with 7 bit data each.
            serial_putchar( 1, (uint8_t)( (tmp2 / 128U ) & 0x7FU ) ); // the most significant 7 bits first
            serial_putchar( 1, (uint8_t)( (tmp2 % 128U ) & 0x7FU ) ); // the least significant 7 bits second
          }

          SIU.GPDO[29].B.PDO = 0;
        }


        mode = CALIBRATE;
        break;

      default:
        mode = CALIBRATE;
        break;
    }
  }

  return 0;
}




void ocIsr (void){
	SIU.GPDO[28].B.PDO = 1;
	if (num_used < NUM_POINTS) {
		buffer[num_used] = qadcReadQ1();
		num_used++;
	}
	else {
		disable_interrupts();
    }
    SIU.GPDO[28].B.PDO = 0;
}


/* EOF */

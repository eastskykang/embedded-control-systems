/**************************************************************************
 * FILE NAME:  flexcan.c
 *
 * EECS461 at the University of Michigan
 * 5553 CAN Driver File
 *
 * Adapted from the MPC555 TouCAN driver written by Paul Griffiths
 *  and freescale RAppID FlexCAN initialization code
 *              Created 8/29/2005, Ron Hagiz
 *
 * Revision History:
 *   10-19-06  lovelljc    for 5553 micro
 *
  * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 *
 * Revision History:
 *	2010-03-26		Gregor Ochsner		changed PROPSEG, PSEG1, PSEG2 to get 500 kBit/s
/**************************************************************************/

#include <mpc5553.h>
#include <flexcan.h>

/* Define a null pointer */
#ifndef NULL
#define NULL    ((void*)0)
#endif


/* A macro that either takes the given value or a default
 * value based on the mask. The appropriate mask bit must
 * be set for the expression to evaluate to val, else it
 * evaluates to dflt.*/
#define MASK(p,m,val,dflt)      ( (p->param_mask & m) ? val : dflt )


/* Define a user rx ISR to call */
static void (*can_usr_rxisr)();

/* interrupt count */
int can_int_cnt = 0;


#include "IntcInterrupts.h"     /* Implement functions from this file */ //eric


/***********************************************************************
 * INTERRUPT ROUTINE FOR FLEXCAN
 ***********************************************************************/
#pragma push /* Save the current state */
#pragma section code_type ".__exception_handlers"
/* Symbol EXCEPTION_HANDLERS is defined in the application linker command file (.lcf)
   It is defined to the start of the code memory area used for the .__exception_handlers section.
 */
/*lint -esym(752, EXCEPTION_HANDLERS) */
__declspec(section ".__exception_handlers") extern long EXCEPTION_HANDLERS;
#pragma force_active on
#pragma interrupt on
#pragma function_align 16   			/* We use 16 bytes alignment for Exception handlers */
void can_isr (void)
{
  // INTCInterruptFn *handlerFn = (INTCInterruptFn*)(*(unsigned int*)&INTC.IACKR.R);
  int32_t interrupt_source = INTC.IACKR.R;
										// Read IACKR after each interrupt

  interrupt_source = (interrupt_source >> 2) & 0x01FF;
										// look at INTVEC field only

  // INTC vector 155 = CANA_MB0, 170 = MB15, 171 = MB16-31, 172 = MB32-63
  if(interrupt_source >= 155 && interrupt_source <= 172)
										// Make sure the interrupt came from a CAN message buffer
  {
    (*can_usr_rxisr)();
    can_int_cnt++;            			// Increment global interrupt counter.
  }
  else
  {// Handle other external interrupts if present
  }

  INTC.EOIR.R = 0;          			// Signal end of servicing interrupt
}
#pragma interrupt off
#pragma force_active off
#pragma pop



/*****************************************************************
 * can_init - Initialize one of the CAN modules
 *
 * Call this function before using the CAN module.
 * The function returns 0 upon success and -1 upon failure.
 ****************************************************************/

int can_init(struct FLEXCAN2_tag *can)
{
  int i, x;
  static int init_status;
  register int32_t temp;

  if (can == NULL)
    return -1;

  /* initialize the usr ISR to NULL */
  can_usr_rxisr = NULL;

  /* Setup external interrupts to call the CAN ISR */
  asm("wrteei 0");      				// Disable external interrupts
  // Interrupt controller handles interrupts from peripherals (CAN)
  INTC.MCR.B.VTES = 0;  				// 4 byte vector table entry size
  INTC.MCR.B.HVEN = 0;  				// Interrupt controller in software vector mode
  asm("lis  temp, can_isr@h");
  asm("ori  temp, temp, can_isr@l");
  asm("mtivor4  temp");   				// IVOR4 is the external interrupt vector
  INTC.CPR.B.PRI = 0; 					// Do not ignore interrupts by priority
  // INTERRUPTS STILL MUST BE ENABLED USING   asm (" wrteei 1");
  // ASSUME THIS IS BEING DONE LATER, OUTSIDE OF CAN_INIT

  // Set SIU pins for CAN_A
  SIU.PCR[83].B.PA = 1; // Pin 83 is CNTXA
  SIU.PCR[84].B.PA = 1; // Pin 84 is CNRXA

  /* Reset FlexCAN Module */
  can->MCR.B.SOFTRST = 1;               // set reset bit
  while( can->MCR.B.SOFTRST == 1){}

  /*disable the FlexCAN module*/
  can->MCR.B.MDIS = 1;

  /* Set CAN clock source 1: system clock , 0: oscillator */
  can->CR.B.CLKSRC = 0;					// Oscillator runs at 8MHz


  /*enable the FlexCAN module*/
  can->MCR.B.MDIS = 0;

/* Enter freeze mode for initialization */
  can->MCR.B.HALT = 1;

/* CAN MODULE CONTROL REGISTER */
/* Set propagation segment and phase segments */
/* time quantas must be equal to 16 to get 500 kBit/s   --> time quantas = 1 + (PROPSEG+1) + (PSEG1 +1) + (PSEG2+1) = 16*/
  can->CR.B.PROPSEG = 2;    			// Propagation segment time
  can->CR.B.PSEG1 = 5;      			// Phase buffer segment 1 length (time)
  can->CR.B.PSEG2 = 5;      			// Phase segment 2 time
/* Set resync jump width */
  can->CR.B.RJW = 3;        			// Max time (2-bit value) the bit time can be changed by re-sync; 0 = 1 quanta
/* Set prescalar for serial clock */
  can->CR.B.PRESDIV = 0x0;  			// Ratio between CLKSRC and CAN serial clock; 0 = div by 1
										//(16 time quantas per bit time) --> 500 kBit/s
/* Set arbitration scheme */
  can->CR.B.LBUF = 0;       			// 0 = Buffer with lowest ID is transmitted first
/* Disable error/bus off interrupts */
  can->CR.B.BOFFMSK = 0;    			// Disable bus off interrupt
  can->CR.B.ERRMSK = 0;     			// Disable error interrupt
/* Disable loopback mode -- enable this for self testing */
  can->CR.B.LPB = 0;
/* Disable listen-only mode (does not acknowledge) */
  can->CR.B.LOM = 0;
/* Set sampling mode to use just one sample */
  can->CR.B.SMP = 0;
/* Turn off timer synchronization */
  can->CR.B.TSYN = 0;

/* Set the FlexCAN Maximum Buffer Size */
  can->MCR.B.MAXMB = 0x0F;  			// Allow 16 (of 64) message buffers to operate

/* clear message buffer memory */
  for(x=0; x < 64; x++)
  {
    can->BUF[x].CS.R = 0;
    can->BUF[x].ID.R = 0;
    for(i=0; i < 8; i++) can->BUF[x].DATA.B[i] = 0;
  }

/* Initialize all receiver masks */
  can->RXGMASK.R = 0x1FFFFFFF;  		// Channels except 14 and 15 check every ID bit
  can->RX14MASK.R = 0x0;    			// Channels 14 and 15 receive any message ID (for monitor)
  can->RX15MASK.R = 0x0;
  // In RX masks, 1 = check ID bit for match, 0 = dontcare
  // ie: 0xFF00 = match only ID bits 15 through 8

/* Clear all interrupt flags and mask off all interrupts */
  can->IMRH.R = 0;  					// No interrupts on any message buffer initially
  can->IMRL.R = 0;

/* Negate the HALT and the FREEZE bit to let the module synchronize. */
  can->MCR.B.HALT = 0;                 	// Leave freeze mode
  can->MCR.B.FRZ = 0;                  	// Disable freeze mode

  /* await synchronization */
  for(i=1; i < 255; i++){}             	// delay

  if(can->MCR.B.NOTRDY == 1)
    init_status = 1;
  else
    init_status = 0;


  return init_status;
}




/* Initialize a buffer for receiving.
 * The function returns 0 upon success and -1, -3 & -4 upon failure. */
int can_rxbuff_init(struct FLEXCAN2_tag *can, int buff_num, int id, int doIRQ)
{
  if(can==NULL)
    return -1;

  /* check for valid buff_num */
  if( buff_num > 15)    				// Only enabled 15 buffers for now
    return(-3);

  if( can_usr_rxisr == NULL && doIRQ )
    return(-4);

  /* Set the buffer to inactive */
  can->BUF[buff_num].CS.B.CODE = 0;

  /* set ID to standard mode */
  can->BUF[buff_num].CS.B.IDE = 0;

  /* Set the frame ID (for matching) */
  can->BUF[buff_num].ID.R = id;

  /* Set the interrupt mask to trigger an IRQ upon receiving a message */
  if( doIRQ )
  {
    INTC.PSR[155+buff_num].B.PRI = 10;  // Set interrupt controller priority for the
                                        //  receive buffer we're initializing
    if(buff_num < 32)
      can->IMRL.R |= 1<<buff_num; // OR mask with existing masks
    else
      can->IMRH.R |= 1<<(buff_num-32);
  }

  /* set as active receive buffer */
  can->BUF[buff_num].CS.B.CODE = 4;

  return 0;
}





/* Take a function pointer that should be called in response to
 * an interrupt for the CAN modules */
int can_set_rxisr(void (*fctn_ptr)())
{
  if( fctn_ptr == NULL )
    return -1;

  /* store the user's isr in a global fctn pointer */
  can_usr_rxisr = fctn_ptr;

  return 0;
}




/* Receive CAN message:
 * Poll one of the CAN receive buffers for a message.
 * Set renew to 0 to deactivate the receive buffer, or set to renew to 1
 * to continue receiving messages with the specified buffer. renew does
 * nothing if no message is received - the buffer remains active.
 * The function returns 0 upon success, -1 upon failure and 1 if no message was received. */
int can_rxmsg(struct FLEXCAN2_tag *can, CAN_RXBUFF *buff, uint8_t renew)
{
  char High_Buffnum; // Boolean flag
  int timer;

  if(can==NULL || buff==NULL)
    return -1;

  /* Check for a message in the receive buffer
   * by reading the IFLAG register. Each bit in the IFLAG
   * register is a flag for the message buffer with the same number.
   * See MPC555 UM 16-13 for the receive process. */
  High_Buffnum = buff->buff_num >= 32;

  if( !High_Buffnum && (can->IFRL.R & (0x01 << (buff->buff_num))) ||
      High_Buffnum && (can->IFRH.R & (0x01 << (buff->buff_num - 32))))
  {
    unsigned short i;

    /* Lock the message buffer by checking the BUSY bit.
    * If the BUSY bit is set, loop until it is cleared.
    * This condition is guaranteed to be cleared in <=20
    * clock cycles. (on 555)
    */
    while( can->BUF[buff->buff_num].CS.B.CODE & 0x01 ); // 0x01 = MB is busy

	/* Indicate that a message is returned in buff */
    buff->isFilled = 1;

    /* Get the timestamp */
    buff->timestamp = (unsigned char)( can->BUF[buff->buff_num].CS.B.TIMESTAMP );

    /* Get the data length */
    buff->length = (unsigned char)( can->BUF[buff->buff_num].CS.B.LENGTH );

    /* limit the length - just in case */
    buff->length = (buff->length > 8 ? 8 : buff->length);

    /* Get the message ID registers */  // Currently for Standard ID's only
    // buff->id = BUILD32BIT(can->BUF[buff->buff_num].ID_HIGH.R, can->MBUFF[buff->buff_num].ID_LOW.R);
    buff->id = can->BUF[buff->buff_num].ID.B.STD_ID;

    /* Get the data */
    for(i=0; i < buff->length ; i++)
      buff->data[i] = can->BUF[buff->buff_num].DATA.B[i]; // Read data byte by byte

    /* Read the free running timer, which unlocks the buffer */
    buff->frt = can->TIMER.R;

    /* If the buffer shouldn't continue receiving, then
     * we should deactivate it. */
    if( !renew )
    {
      /* deactivate */
      can->BUF[buff->buff_num].CS.B.CODE = 0x0;

      /* Clear the IMASK flag for this buffer so it cannot cause an interrupt. */
      if(High_Buffnum)
        can->IMRH.R &= ~(1 << (buff->buff_num - 32));
      else
        can->IMRL.R &= ~(1 << buff->buff_num);
    }

    /* Clear IFLAG */
    if(High_Buffnum)
      can->IFRH.R &= ~(0x01<<(buff->buff_num - 32));
    else
      can->IFRL.R = (0x01<<(buff->buff_num));//eric
//      can->IFRL.R &= ~(0x01<<(buff->buff_num));

    timer = can->TIMER.R;  // Read timer to unlock MB
  }
  else
  {
    /* Indicate that a message is NOT in buff */
    buff->isFilled = 0;
    return 1;
  }

  return 0;               /* success */
}




/* Transmit a CAN message on the specified CAN module and buffer. The
 * message is sent "once, unconditionally."
 * The function returns 0 upon success and -1, -2, or -3 upon failure.
 */
int can_txmsg(struct FLEXCAN2_tag *can, CAN_TXBUFF *buff)
{
  char High_Buffnum; // Boolean flag
  int i;

  High_Buffnum = buff->buff_num >= 32;

	/* Set the code to tx inactive */
	can->BUF[buff->buff_num].CS.B.CODE = 0x08;

    /* (required for Tx) */
	can->BUF[buff->buff_num].CS.B.SRR = 1;

	/* Set the ID registers*/
	can->BUF[buff->buff_num].ID.R = buff->id;

	/* Copy the data to the data registers */
    for (i = (buff->length)-1; i >= 0; i--)
      can->BUF[buff->buff_num].DATA.B[i] = buff->data[i];

	/* Set the data length */
	can->BUF[buff->buff_num].CS.B.LENGTH = buff->length;

	/* Clear the IMASK flag for this buffer so that completed
	 * transmission does not cause an IRQ */
    if(High_Buffnum)
      can->IMRH.R &= ~(1 << (buff->buff_num - 32));
    else
      can->IMRL.R &= ~(1 << buff->buff_num);

	/* clear the IFLAG bit for this buffer */
    if(High_Buffnum)
      can->IFRH.R = (1 << (buff->buff_num - 32));
    else
      can->IFRL.R = (1 << buff->buff_num); // Write a 1 to clear the flag - eric

	/* Release the buffer for transmission by setting the CODE
	 * to "transmit once unconditionally." */
	can->BUF[buff->buff_num].CS.B.CODE = 0x0C;

	return 0;		/* success */
}




/* Deactivate a CAN buffer
 * This function is provided as a replacement for stop_transmission(). It
 * sets the buffer code to inactive and clears its corresponding bit in IFLAG.
 * This call could interrupt the transmission or reception of a message.
 * The function returns 0 upon success and -1 or -3 upon failure.
 */
int can_deactivate_buffer(struct FLEXCAN2_tag *can, int buff)
{
  /* Check the buffer number */
  if(buff < 0 || buff > 63)
    return -3;

  /* Set the buffer's code to inactive. */
  can->BUF[buff].CS.B.CODE = 4;

  /* Clear the appropriate IMASK bit. */
  if(buff < 32)
    can->IMRL.R &= ~(1<<buff);
  else
    can->IMRH.R &= ~(1<<(buff-32));

  /* Clear the appropriate IFLAG bit.
  - faster than can_clear_buff_flag() since  we have checked arguments already */
  if(buff < 32)
    can->IFRL.R = 1<<buff;
  else
    can->IFRH.R = 1<<(buff-32);

  return 0;
}




/* Get and clear one bit of the IFLAG register
 * These functions access the bit of the IFLAG
 * register that corresponds to the buffer specified by buff.
 * The functions return -1 or -3 upon failure.
 */
int can_get_buff_flag(struct FLEXCAN2_tag *can, int buff)
{
  /* Check the buffer number */
  if(buff < 0 || buff > 63)
    return -3;

  return ((buff < 32) ? ((can->IFRL.R)>>buff) & 0x01 : ((can->IFRH.R)>>(buff-32)) & 0x01);
}



int can_clear_buff_flag(struct FLEXCAN2_tag *can, int buff)
{
  /* Check the buffer number */
  if(buff < 0 || buff > 63)
    return -3;

  /* Clear the appropriate IFLAG bit. */
  if(buff < 32)
    can->IFRL.R = 1<<buff;
  else
    can->IFRH.R = 1<<(buff-32);

  return 0;
}



/* Build the value for a standard ID (in the 32 bit ID register, use bits 3 - 13 */
uint32_t can_build_std_ID( uint16_t id /*11-bit (0-2047)*/)
{
  uint32_t reg = 0;

	reg |= (id << 18);

	return reg;
}



// EOF

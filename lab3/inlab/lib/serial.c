/**************************************************************************
 * FILE NAME:  serial.c     
 *
 * University of Michigan                                                 
 * EECS 461, Embedded Control Systems, Fall 2003                          
 * 
 * Created: 10/19/1999 by Noah J. Cowan                                   
 * Updated: 9/12/2003  by Ganesh S. Dasika                                
 * Updated: 11/24/2003 by David Thorsley                                
 * Updated: 6/23/2005  by Eric Williams                                 
 * Updated: 7/10/2006  lovelljc                                         
 * Updated: 8/28/2006  ericjw    
 *
 * Revised and adapted to use at IMRT ETH Zurich 
 * 151-0593-00 Embedded Conrol Systems (ECS) 
 *
 * See Chapter 21 in MPC5553/5554 Reference Manual
 * 
 * Revision History:
 *	2008-06-11		Marianne Schmid
 **************************************************************************/

#include <serial.h>
#include <mpc5553.h>
#include <ecs.h>

void init_COM(int port, int baudrate)
{
    uint32_t SYSTEM_FREQUENCY;

    SYSTEM_FREQUENCY = get_sys_freq();

    switch (port)
    {
    case 2:
        /* set up sci_b output pin mapping 
		*  System Integration Unit (SIU),
		*  Pad Configuration Register (PCR)
		*  Pin Assignment (PA) */
        SIU.PCR[91].B.PA = 0b01;
        SIU.PCR[92].B.PA = 0b01;

        /* set up sci_b module 
		*  Enhanced Serial Communication Interface (eSCI)*/
        ESCI_B.CR2.B.MDIS = 0; /*Module disable 0 --> enabled */
        ESCI_B.CR1.B.SBR = SYSTEM_FREQUENCY/16/baudrate; /*SCI baud rate*/
        ESCI_B.CR1.B.TE = 1; /*Transmitter enable*/
        ESCI_B.CR1.B.RE = 1; /*Receiver enabled*/
        break;

    default:
        /* set up sci_a output pin mapping 
		*  System Integration Unit (SIU),
		*  Pad Configuration Register (PCR)
		*  Pin Assignment (PA) */
        SIU.PCR[89].B.PA = 0b01;
        SIU.PCR[90].B.PA = 0b01;

        /* set up sci_a module 
		*  Enhanced Serial Communication Interface (eSCI)*/
        ESCI_A.CR2.B.MDIS = 0; /*Module disable 0 --> enabled */
        ESCI_A.CR1.B.SBR = SYSTEM_FREQUENCY/16/baudrate; /*SCI baud rate*/
        ESCI_A.CR1.B.TE = 1; /*Transmitter enable*/
        ESCI_A.CR1.B.RE = 1; /*Receiver enabled*/
		break;
    }
}


/* returns 1 if transmit register ready for another byte */
char serial_readyToSend(int port)
{
    uint8_t status;
	do
    {   /* wait for transmit byte sent to the shift register, ready for another byte.
		*  Status register (SR), Transmit data register empty flag (TDRE)*/
        if (port == 1)
            status = ESCI_A.SR.B.TDRE; 
        else if (port == 2)
            status = ESCI_B.SR.B.TDRE;
    } while(!status);

    return 1;
}

char serial_putchar(int port, uint8_t sbyte)
{
    while(!serial_readyToSend(port))
      ;  /* wait for ready to send */

    if (port == 1)
        {
		/* Clear TDRE by writing 1 to it*/
        ESCI_A.SR.R = 0x80000000;
        ESCI_A.DR.B.D = sbyte;
        }
    else if (port == 2)
        {
		/* Clear TDRE by writing 1 to it*/
        ESCI_B.SR.R = 0x80000000;
        ESCI_B.DR.B.D = sbyte;
        }

    return 0;
}

void serial_puts(int port, char *sptr)
{
    while(*sptr)
    {
        serial_putchar(port, *sptr);
        ++sptr;
    }
}

/* returns 1 if data is waiting to be received */
char serial_readyToReceive(int port)
{
    if (port == 1)
		/*Receive data register full flag*/
        return (char)ESCI_A.SR.B.RDRF; 
    else
		/*Receive data register full flag*/
        return (char)ESCI_B.SR.B.RDRF;
}


/* wait for a byte to be received from the serial port */
char serial_getchar(int port)
{
    while(serial_readyToReceive(port) == 0)
      ; /* wait for new incoming data */

    if (port == 1)
        {
		/* Clear RDRF by writing 1 to it */
        ESCI_A.SR.R = 0x20000000;   
		/* read the port */
        return (unsigned char)(ESCI_A.DR.B.D & 0x00ff); 
        }
    else
        {
		/* Clear RDRF by writing 1 to it */
        ESCI_B.SR.R = 0x20000000;  
		/* read the port */
        return (unsigned char)(ESCI_B.DR.B.D & 0x00ff); 
        }
}

/* EOF */
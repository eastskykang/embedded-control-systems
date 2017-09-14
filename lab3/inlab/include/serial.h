/**************************************************************************
* FILE NAME:  serial.h              
                                                
 * University of Michigan                                                 
 * EECS 461, Embedded Control Systems, Fall 2003                      
 * See Chapter 14 in MPC555 User's Manual                                 
 * Created: 10/19/1999 by Noah J. Cowan    
 *
 * Revision History: 
 * Updated: 9/12/2003 by Ganesh S. Dasika
 * Updated: 11/24/2003 by David Thorsley             

 * Revised and adapted to use at IMRT ETH Zurich 
 * 151-0593-00 Embedded Conrol Systems (ECS) 
 *
 * Revision History:
 *	2008-06-11		Marianne Schmid
 **************************************************************************/

#ifndef __SERIAL_H__
#define __SERIAL_H__

#ifdef __cplusplus
  extern "C" {
#endif

// Function Prototypes
char serial_readyToSend(int port);
char serial_readyToReceive(int port);
char serial_putchar(int port, unsigned char sbyte);
void serial_puts(int port, char *sptr);
char serial_getchar(int port);
void init_COM(int port,int baudrate);

#ifdef __cplusplus
  }
#endif

#endif /*__SERIAL_H__*/

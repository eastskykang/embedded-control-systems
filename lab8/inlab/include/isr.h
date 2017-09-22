/**************************************************************************
 * FILE NAME: isr.h                                                       *
 * AUTHOR: Noah J. Cowan, 10/17/00                                        *
 * Revised: Eric G. Castle, 8/14/02                                       *
 * Revised: David Thorsley, 11/24/03                                      *
 * Revised: Paul Griffiths, 10/4/04                                       *
 * Updated for MPC5553: Jeff Lovell, 8/7/06                               *
 *Revised: Yefei Wang  4/29/10											  *
  *  2011-02-09		Thomas Schneider - Adapted to new version			  *		
 **************************************************************************/


#ifndef __ISR_H__
#define __ISR_H__

#ifndef NULL
#define NULL    ((void*) 0)
#endif // NULL


void init_interrupts(void (*fctn_ptr)(), int freq);
void enable_interrupts(void);
void disable_interrupts(void);


#endif // __ISR__

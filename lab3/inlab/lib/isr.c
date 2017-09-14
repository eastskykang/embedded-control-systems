/**************************************************************************
 * FILE NAME: isr.c                                                       *
 * INCLUDE FILES: mpc555.h (OUTDATED), irq.h                              *
 * ADD. DEPENDENCIES: exceptions.s                                        *
 * AUTHOR: Noah J. Cowan, 10/17/00                                        *
 *         (adapted from code by Steve Mihalik, Motorola)                 *
 *         for MPC555 microprocessor                                      *
 * Revised:                                                               *
 *      Eric G. Castle, 8/14/02                                           *
 *      Ganesh Dasika   2/5/04                                            *
 *      Paul Griffiths  10/4/04                                           *
 *      Eric Williams   6/23/05 (for MPC55xx micro)                       *
 *      Jeff Lovell     10/2/06                                           *
 *      Eric Williams   10/4/06                                           *
 *      Yefei Wang      10/29/4											  *
 *																		  *
 * Revised and adapted to use at IDSC ETH Zurich 						  *
 * 151-0593-00 Embedded Control Systems (ECS) 							  *
 * 																		  *
 * Revision History:													  *
  *	2008-08-26		Marianne Schmid - Adapted to CodeWarrior IDE version 2.2 *
  * 2011-02-09		Thomas Schneider - Adapted to CW version 2.7 and Oscilloscope of lab 3 *
 **************************************************************************/

#include <mpc5553.h>
#include <isr.h>
#include <ecs.h>

int int_cnt;         /* Interrupt counter */

void (*user_isr)();


/***********************************************************************
 * INTERRUPT ROUTINES - FOR DECREMENTER
 * Summary:
 ***********************************************************************/
#pragma push /* Save the current state */
#pragma section code_type ".__exception_handlers"
__declspec(section ".__exception_handlers") extern long EXCEPTION_HANDLERS;
#pragma force_active on
#pragma interrupt on
#pragma function_align 16   /* We use 16 bytes alignment for Exception handlers */

void dec_isr (void)
{
  register short temp;

  (*user_isr)();

  int_cnt++;                    /* Increment global interrupt counter */

  asm("mfspr    temp, 336");    /* Debugging- see where the interrupt came from */
  asm("lis      temp, 0x0800"); /* Write "1" clear Dec Interrupt Status (DIS) flag */
  asm("mtspr    336, temp");    /* 336 is TSR timer status register */
}

#pragma interrupt off
#pragma force_active off
#pragma pop


/* from example by S.Mihalik */
asm void init_DEC(long count) {
#pragma unused (count)
/* count is r3 */

  wrteei 0                      /* Stop interrupts if enabled */

  mtdec         r3
  mtdecar       r3              /* Load same initial value to DECAR */

  lis           r0, 0x0440      /* Enable DEC interrupt and auto-reload */
                                /* 0000 0100 0100 0000
                                 *   DIE = 1  decrementer interrupt enable
                                 *   ARE = 1  auto-reload enable */
  mttcr         r0

  li            r0, 0x4000      /* Enable Time Base and Decrementer (set TBEN) */
  mthid0        r0

  lis           r4, dec_isr@h
  ori           r4, r4, dec_isr@l
  mtivor10      r4              /* IVOR10 contains interrupt vector for DEC */

}

/***************************************************************************
 * init_interrupts()
 * INTERRUPT INITIALIZATION ROUTINE - FOR DECREMENTER INTERRUPTS
 *Note that in this version the enabling of interrupts is not automatic for the conve-
 *nience of enabling and disabling them freely in the program
 ***************************************************************************/
void init_interrupts(void (*fctn_ptr)(), int freq)
{
  int count;

  user_isr = fctn_ptr;

  if (user_isr == NULL)
    return;

  if (!freq)
    return;

  count = get_sys_freq() / freq;
  init_DEC(count);

  //enable_interrupts();		/* NOTE:  the Interrupts must be activated later on. */
}



void enable_interrupts(void)
{
  asm (" wrteei 1");            /* Enable External interrupts (MSR.EE=1) */
}

void disable_interrupts(void)
{
  asm (" wrteei 0");            /* Disable External interrupts (MSR.EE=0) */
}
/* EOF */

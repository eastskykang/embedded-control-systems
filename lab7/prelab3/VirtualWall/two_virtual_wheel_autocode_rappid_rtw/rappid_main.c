/*
 * File: rappid_main.c
 *
 * Code generated for Simulink model 'two_virtual_wheel_autocode'.
 *
 * Model version                  : 1.93
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Thu Sep 21 16:08:25 2017
 *
 * Target selection: rappid.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/* Model's headers */
#include "two_virtual_wheel_autocode.h"
#include "RAppID_Blockset.h"

extern const vuint32_t IntcIsrVectorTable[];
extern IVOR4Handler();                 /* INTC */
extern IVOR11Handler();                /* FIT */
void SYSTEM_INIT_TASK(void)
{
  /* Initialize model */
  two_virtual_wheel_autocode_initialize(1);
}

void SYSTEM_TASK(void)
{
  boolean_T eventFlags[2];             /* Model has 2 rates */

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  two_virtual_wheel_autocode_SetEventsForThisBaseStep(eventFlags);

  /* Set model inputs associated with base rate here */
  two_virtual_wheel_autocode_step(0);

  /* Get model outputs here */
  if (eventFlags[1]) {
    /* Set model inputs associated with subrates here */
    two_virtual_wheel_autocode_step(1);

    /* Get model outputs here */
  }
}

void initIrqVectorsFIT(void)
{
  asm(" lis  r3, IVOR11Handler@h ");   /* IVPR = upper half of L2SRAM start address */
  asm(" mtivpr	r3 ");
  asm(" li   r3, IVOR11Handler@l ");   /* IVOR11 = lower half of handler address */
  asm(" mtivor11   r3 ");
}

void initFIT(void)
{
  asm(" li	r3, 0 ");                   /* Initialize time base to 0  */
  asm(" mttbu	r3 ");
  asm(" mttbl	r3 ");
  asm(" lis	r3, 0x281 ");              /* Enable FIT interrupt and set	*/
  asm(" ori	r3, r3, 0x6000 ");         /* timeout Base Tick  0.002 */
  asm(" mftcr   r12 ");                /* Get Current TCR Register Value */
  asm(" or      r3,r3,r12 ");          /* Preserve current values and add FIT enable sets */
  asm(" mttcr	r3 ");                   /* Set TCR register   for FIT and Previous MSR values */
  asm(" li r3, 0x4000 ");              /* Enable Time Base and Decrementer (set TBEN) */
  asm(" mthid0	r3 ");
}

void ClrFitFlag(void)
{
  asm(" lis  r3, 0x0400 ");
  asm(" mttsr r3 ");                   /* Write "1" clear FIT Interrupt Status flag */
}

void FitISR(void)
{
  ClrFitFlag();                        /* Clear FIT's flag */
  SYSTEM_TASK();
}

void initIrqVectors(void)
{
  asm(" lis r3, IVOR4Handler@h ");     /* IVPR = upper half of L2SRAM start address */
  asm("	mtivpr	r3 ");
  asm(" li r3, IVOR4Handler@l ");      /* IVOR4 = lower half of handler address */
  asm(" mtivor4   r3 ");
}

void initINTC(void)
{
  INTC.MCR.B.HVEN = 0;                 /* Initialize INTC for software vector mode */
  INTC.MCR.B.VTES = 0;                 /* Use default vector table entry offsets of 4 B */
  INTC.IACKR.R = (uint32_t) &IntcIsrVectorTable[0];/* Set INTC ISR vector table base addr */
}

void enableIrq(void)
{
  asm(" wrteei 1");                    /* Enable external interrupts */
}

void main(void)
{
  SYSTEM_INIT_TASK();                  /*  Initialize the processor. */
  initIrqVectorsFIT();                 /* Initialize interrupt vectors registers*/
  initFIT();                           /* Initialize FIT routine */
  initIrqVectors();                    /* Initialize exceptions: only need to load IVPR */
  initINTC();                          /* Initialize INTC for software vector mode */
  INTC.CPR.B.PRI = 0;                  /* Ensure INTC's current priority is 0 */
  enableIrq();                         /* Enable IRQ */

  /* Attach SYSTEM_TASK to a timer or interrupt service routine with
   * period 0.002 seconds (the model's base sample time) here.  The
   * call syntax for SYSTEM_TASK is
   * SYSTEM_TASK();
   */
  for (;;) {
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

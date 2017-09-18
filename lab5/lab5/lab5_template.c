/**************************************************************************
 * FILE NAME:  lab5.c
 *
 * EECS461 at the University of Michigan
 * Lab 5 - Template
 *
 * Created July 2005 Eric Williams
 *
 * Revision History:
 *   8-9-06  lovelljc
 *  10-4-06  ericjw
 *
 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *	2008-09-04		Marianne Schmid
 *	2009-09-13		Marianne Schmid (different name for MiosChannel)
 *	2011-02-14		Thomas Schneider
 **************************************************************************/

#include <mpc5553.h>
#include <math.h>
#include <ecs.h>
#include <mios.h>
#include <qadc.h>
#include <isr.h>

#define SCF_MIOS_CHANNEL	12		/* The haptic interface uses eMIOS[12]  for the sc-Filter*/
#define SINUS_MIOS_CHANNEL   1       /* The haptic interface uses eMIOS[0]. Use eMIOS[1] for this lab */
#define PWM_PERIOD_ns       50000   /* 50000 Initialize PWM at 20 kHz */
#define MIOS_CLOCK_SCALER   0b0000  /* Divide by (SCALER + 1) = 1 */

#define SINGLE_SCAN_CHANNEL     0   /* Use AN0 for external input, AN1 for ECS interface board potentiometer */
#define NUM_CONTINUOUS_CHANNELS 0   /* Can scan up to 8 input channels continuously */

#define INTERRUPT_FREQUENCY_A 20000   /* Fixed-Interval Interrupts frequency (Hz) for IsrA*/
#define INTERRUPT_FREQUENCY_B  /* fill in here */   /* Fixed-Interval Interrupts frequency (Hz) for IsrB*/
#define INTERRUPT_FREQUENCY_C  /* fill in here */   /* Fixed-Interval Interrupts frequency (Hz) for IsrC*/

/* Use the appropriate interrupt frequency when calling an ISR */

void IsrA(void)
{
    /* fill in here */
}

void IsrB(void)
{
    /* fill in here */
}

void IsrC(void)
{
    /* fill in here */
}

int main() {

	/* initialize processor */
	init_ECS(5);
	init_MIOS_clock(MIOS_CLOCK_SCALER);
	init_PWM(SINUS_MIOS_CHANNEL,PWM_PERIOD_ns);
	init_PWM(SCF_MIOS_CHANNEL,1000); /* 1 MHz */
	qadcInit_single(SINGLE_SCAN_CHANNEL);

	/* initialize GPIO */
	/* fill in here */

	/* init interrupts */
	init_interrupts(IsrA, INTERRUPT_FREQUENCY_A);
	/* enable interrupts */
	/* fill in here */

	while(1)
	{
		/* Loop forever */
	}
	return(0);
}

/* EOF */

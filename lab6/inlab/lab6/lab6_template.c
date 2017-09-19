/**************************************************************************
 * FILE NAME:  lab6.c
 *
 * EECS461 at the University of Michigan
 * Lab 6 - Template
 *
 * Revision History:
 * 	8-16-06	lovelljc
 *
 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *	2008-09-04		Marianne Schmid
 *	2011-03-29		Thomas Schneider
 *  2012-08-15		Patrick Müller
 *  2015-02-18      Fabian Byland
 **************************************************************************/

#include <mpc5553.h>
#include <ecs.h>
#include <mios.h>
#include <fqd.h>
#include <motor.h>
#include <serial.h>
#include <isr.h>
#include <worlds.h>

#define SCF_MIOS_CHANNEL	12		/* The haptic interface uses eMIOS[12]  for the SC-Filter*/
#define HAPTIC_MIOS_CHANNEL	0		/* The haptic interface uses eMIOS[0]  for the PWM Signal*/
#define PWM_PERIOD_ns       (25000) /* 25000 Initialize PWM at 40 kHz */
#define MIOS_CLOCK_SCALER	0b000	/* Divide by (SCALER + 1) */

#define INTERRUPT_FREQUENCY	1000	/* Fixed-Interval Interrupts frequency (Hz) */
/* TIMESTEP defined in worlds.h - should be 1 / INTERRUPT_FREQUENCY */


void sdIsr(void) {
	/* ISR for the spring-damper system */
	/* Calculate the wheel's velocity */
	/* Calculate and apply the correct torque to haptic wheel */
	/* Fill in here */
}

void wdIsr(void) {
	/* ISR for the wall-damper system */
	/* Calculate the wheel's velocity */
	/* Calculate and apply the correct torque to haptic wheel */
    /* Fill in here */
  }

void smIsr(void) {
	/* ISR for the spring-mass system */
    /* Fill in here */
}

void smdIsr(void) {
	/* ISR for the spring-mass-damper system */
    /* Fill in here */
}

#define ENTER_CRITICAL()  asm (" wrteei 0");
#define LEAVE_CRITICAL()  asm (" wrteei 1");

/*shared variables between main and interrupt service routine*/
static float K, J;
void smdIsrEx(void) {
	/* ISR for the spring-mass-damper system with adaptable K and J */
    /* Fill in here */
}

void knobIsr(void) {
	/* ISR for the virtual knob system */
    /* Fill in here */
}

int main()
{
	float *inc_var = &K;
	init_ECS(6);
	init_MIOS_clock(MIOS_CLOCK_SCALER);
	init_PWM(HAPTIC_MIOS_CHANNEL,PWM_PERIOD_ns);
	set_PWMDutyCycleLimits(HAPTIC_MIOS_CHANNEL, 0.24, 0.76);
	init_PWM(SCF_MIOS_CHANNEL,1000);  /* 1 MHz */

	init_FQD();
	init_COM(1,115200);

	/* used for smdIsrEx(void)
	  *serial_puts(1,"\r\nK selected, Enter k,j,+,-\r\n");
	/*

	/* Initialize GPIO */
	/* Fill in here */

	/* init interrupts */
	init_interrupts(/* isr name */, INTERRUPT_FREQUENCY);
	/* Enable interrupts */
    /* Fill in here */

	while(1){
	}
	return(0);
}

//EOF

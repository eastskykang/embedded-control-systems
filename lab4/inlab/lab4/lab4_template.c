/**************************************************************************
 * FILE NAME:  lab4.c
 *
 * EECS461 at the University of Michigan
 * Lab 4 Template
 *
 * Created July 2005
 *
 * Revision History:
 *   8-3-06  lovelljc
 *
 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *  2008-09-04      Marianne Schmid
 **************************************************************************/
#include <ecs.h>
#include <mios.h>
#include <fqd.h>
#include <worlds.h>
#include <motor.h>
#include <qadc.h>
#include <mpc5553.h>

#define SCF_MIOS_CHANNEL        12                      /* The haptic interface uses eMIOS[12]  for the sc-Filter*/
#define HAPTIC_MIOS_CHANNEL     0                       /* The ECS interface board sends eMIOS[0] to the haptic interface motor */
#define PWM_PERIOD_ns           (25000)                 /* 25000 Initialize PWM at 40 kHz */
#define MIOS_CLOCK_SCALER       /*Fill in here*/        /* Select a clock prescalar that allows the eMIOS to run at the maximum possible frequency */
#define SINGLE_SCAN_CHANNEL     3                       /* Use AN3 for input of the potentiometer */
#define NUM_CONTINUOUS_CHANNELS 0                       /* Can scan up to 8 input channels continuously */+

#define LAB 4

int main()
{
    /* Variable declarations here */

    /* Initializations */
    init_ECS(LAB);                                      /* Set the system clock to 40 MHz, enable the motor */
    init_MIOS_clock(MIOS_CLOCK_SCALER);                 /* Set the clock prescaler */
    init_PWM(HAPTIC_MIOS_CHANNEL, /*Fill in here*/);
    init_PWM(SCF_MIOS_CHANNEL,1000);                    /* The sc-filter is run with 1 MHz*/
    set_PWMDutyCycleLimits(HAPTIC_MIOS_CHANNEL, 0.24, 0.76);
    init_FQD();

    /* Fill in lab4.c code here */

    return(0);

}

/* EOF */

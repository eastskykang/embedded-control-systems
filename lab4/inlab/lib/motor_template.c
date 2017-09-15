/**************************************************************************
 * FILE NAME: motor.c
 *
 * EECS461 at the University of Michigan
 * Motor control library - Template
 *
 * Created July 2005 by Ron Hagiz
 *
 * Revision History:
 *  7-27-06 lovelljc
 *  8-28-06 ericjw  formatting
 *
 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *  2008-09-04      Marianne Schmid
 *  2011-02-10      Thomas Schneider
 *  2014-09-11      Stijn van Dooren - added Torquemax & Torquemin definitions
 **************************************************************************/

#include <motor.h>
#include <mios.h>

#ifndef HAPTIC_MIOS_CHANNEL
#define HAPTIC_MIOS_CHANNEL 0
#endif

/*Limit of motor in stationary use corresponds to 700 Nmm that no harm to the motor is caused.  In dynamic use, higher loads are possible*/
#define Torquemax   835     /*mNm*/
#define Torquemin  -835     /*mNm*/

/* Performs the conversion between a virtual torque value and a PWM duty cycle */
float outputTorque(float torque) {
    /* Fill in here */
}

/* EOF */

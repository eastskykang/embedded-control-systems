/**************************************************************************
 * FILE NAME: motor.h

 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *	2008-06-11		Marianne Schmid
 **************************************************************************/

#ifndef __MOTOR_H__
#define __MOTOR_H__

#ifdef __cplusplus
  extern "C" {
#endif

float outputTorque(float torque);

#ifdef __cplusplus
  }
#endif

#endif /*__MOTOR_H__*/

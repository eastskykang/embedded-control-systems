/**************************************************************************
 * FILE NAME: mios.h

 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *	2008-06-11		Marianne Schmid
 *  2012-06-28		Pascal Lutz
 **************************************************************************/

#ifndef __MIOS_H__
#define __MIOS_H__

#include <ecs.h>

#ifdef __cplusplus
  extern "C" {
#endif

void init_MIOS_clock(uint8_t prescaler);

void init_PWM(int miosChannel, uint32_t newPeriod_ns);

void set_PWMPeriod_ns(int miosChannel, uint32_t newPeriod_ns);

int8_t set_PWMDutyCycleLimits(int miosChannel, float minimum, float maximum);

void set_PWMDutyCycle(int miosChannel, float dutyCycle);

#ifdef __cplusplus
  }
#endif

#endif /*__MIOS_H__*/

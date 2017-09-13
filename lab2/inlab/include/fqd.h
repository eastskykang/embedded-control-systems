/**************************************************************************
 * FILE NAME: fqd.h                                                  
 
 * Revised and adapted to use at IMRT ETH Zurich 
 * 151-0593-00 Embedded Conrol Systems (ECS) 
 *
 * Revision History:
 *	2008-08-20		Marianne Schmid
 **************************************************************************/

#ifndef __FQD_H__
#define __FQD_H__

#include <ecs.h>

#ifdef __cplusplus
  extern "C" {
#endif

#define ETPU_CHAN_NOT_USED        (-1)

/* ----------------------------------------------------------------------
 * Quadrature Decoding initialization function
 * Refer to the AN2842 application note for information about the
 * initialization procedure
------------------------------------------------------------------------- */
void init_FQD();

/* ----------------------------------------------------------------------
 * Returns the value of the QD position counter
 * The PC is a 24-bit register but we will only use the least significant
 * 16 bits
------------------------------------------------------------------------- */
uint16_t ReadFQD_pc();

/* ----------------------------------------------------------------------
 * updateCounter() maintains a signed 32-bit count value based on the ticks
 * of the QD. It requires two static variables, the signed 32-bit counter and
 * an unsigned 16-bit variable to hold last read count value. The 32-bit counter
 * is updated by the difference between the current QD count (ReadFQD_pc()) and
 * the last read QD count. The calculation must account for wrap-around
 * of the 16-bit QD counter. The value returned is the 32-bit counter.
 *
 *   - implementaion - by comparing the value of the current and previous values
 *              returned from ReadFQD_pc(), a signed difference value can
 *				be found. This difference is added to the 32-bit counter.
 *
 *   - return - Function should return a long containing the updated 32-bit count
 *				value
 *
------------------------------------------------------------------------- */
int32_t updateCounter();

/* ----------------------------------------------------------------------
 *  Starting from an initial angle, updateAngle returns the angle of the haptic
 *  wheel in degrees. The return value of updateCounter may be used.
 *
 *  Important conversion information:
 *	-We use 1000-pulse encoders on 2 channels. It is necessary to first
 *	 compute the number of time the position counter incremenents for every
 *	 rotation of the encoder wheel.
------------------------------------------------------------------------- */
float updateAngle();

#ifdef __cplusplus
  }
#endif

#endif /*__FQD_H__*/

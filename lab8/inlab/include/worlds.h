/**************************************************************************
 * FILE NAME: worlds.h

 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *	2008-08-01		Marianne Schmid
 *	2011-02-10		Thomas Schneider
 **************************************************************************/

#ifndef __WORLDS_H__
#define __WORLDS_H__

#ifdef __cplusplus
  extern "C" {
#endif

#define TIMESTEP 0.001    /* Lab6: 1 / INTERRUPT_FREQUENCY (0.001)*/
#define WALL_POSITION 90  /* Lab4 & 6: Angle the virtual wall is located at */

/*Lab4*/
float virtualWall(float angle);
float virtualSpring(float angle);

/*Lab6*/
float virtualSpringDamper(float angle, float velocity);
float virtualWallDamper(float angle, float velocity);
float virtualSpringMass(float angle);
float virtualSpringMassDamper(float angle, float velocity);
float virtualSpringMassDamperEx(float angle, float velocity, float K, float M);
float virtualKnob(float angle, float velocity);

#ifdef __cplusplus
  }
#endif

#endif /*__WORLDS_H__*/

/**************************************************************************
 * FILE NAME: ecs.h                                                  
 
 * Revised and adapted to use at IMRT ETH Zurich 
 * 151-0593-00 Embedded Conrol Systems (ECS) 
 *
 * Revision History:
 *	2008-08-20		Marianne Schmid
 **************************************************************************/

#ifndef __ECS_H__
#define __ECS_H__

#include <typedefs.h>

#ifdef __cplusplus
  extern "C" {
#endif

void init_ECS(int labno);

uint32_t get_sys_freq(void);

void init_speed(long mhz);

void init_fp(void);

#ifdef __cplusplus
  }
#endif

#endif /* __ECS_H__ */

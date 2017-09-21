/********************************************************************************/
/* FILE NAME: etpu_EngineSystem.h                   COPYRIGHT (c) MOTOROLA 2003 */
/* VERSION:  0.0                                    All Rights Reserved         */
/*                                                                              */
/* DESCRIPTION: This file contains all the function prototype, data type        */
/*              declaration, constants definition etc. for etpu_main.c.         */
/*                                                                              */
/*==============================================================================*/
/* UPDATE HISTORY                                                               */
/* REV      AUTHOR        DATE	    DESCRIPTION OF CHANGE                       */
/* ---      -------      --------    ---------------------                      */
/* 0.0      Ming Li      12/02/03    Initial creation                           */
/********************************************************************************/

/*--------------------------------------------------------------------+
   |                           Include Header Files                      |
   +--------------------------------------------------------------------*/
#include "mpc5554.h"                   //mpc5554 register definitions.
#include "etpu_util.h"                 //useful utility routines.
#include "etpu_image.h"

/*--------------------------------------------------------------------+
   |                           Macro Definition                          |
   +--------------------------------------------------------------------*/

/*--------------------------------------------------------------------+
   |                           Constatns Definition                      |
   +--------------------------------------------------------------------*/
/* define functions to channels */
#define PWM0                           0
#define PWM0_CHAN_PRIORITY             3
#define PWM1                           1
#define ETPU_MISC                      0
#define ETPU_ENTRY_TABLE               0x0
#define PWM2                           2

struct etpu_config_t etpu_config_A = {
  ETPU_MISC_ENABLE,                    //MCR register
  ETPU_MISC_VAL,                       //MISC value from eTPU compiler link file

  //Configure eTPU engine A
  ETPU_FILTER_CLOCK_DIV8 +
  ETPU_CHAN_FILTER_3SAMPLE +
  ETPU_ENTRY_TABLE,

  //Configure eTPU engine A timebases
  ETPU_TCR2CTL_DIV8 +
  ( 7 << 16) +                         //TCR2 prescaler of 8 (7+1)
  ETPU_TCR1CTL_DIV2 +
  3,                                   //TCR1 prescaler of 4 (3+1)
  0,

  //Configure eTPU engine b
  ETPU_FILTER_CLOCK_DIV4 +
  ETPU_CHAN_FILTER_3SAMPLE +
  ETPU_ENTRY_TABLE,

  //Configure eTPU engine B timebases
  ETPU_TCR2CTL_DIV8 +
  ( 7 << 16) +                         //TCR2 prescaler of 8 (7+1)
  ETPU_TCR1CTL_DIV2 +
  3,
  0
};

/*********************************************************************
 *
 * Copyright:
 *	MOTOROLA, INC. All Rights Reserved.
 *  You are hereby granted a copyright license to use, modify, and
 *  distribute the SOFTWARE so long as this entire notice is
 *  retained without alteration in any modified and/or redistributed
 *  versions, and that such modified versions are clearly identified
 *  as such. No licenses are granted by implication, estoppel or
 *  otherwise under any patents or trademarks of Motorola, Inc. This
 *  software is provided on an "AS IS" basis and without warranty.
 *
 *  To the maximum extent permitted by applicable law, MOTOROLA
 *  DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED, INCLUDING
 *  IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR
 *  PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH REGARD TO THE
 *  SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF) AND ANY
 *  ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL MOTOROLA BE LIABLE FOR ANY DAMAGES WHATSOEVER (INCLUDING
 *  WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS
 *  INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY
 *  LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  Motorola assumes no responsibility for the maintenance and support
 *  of this software
 ********************************************************************/

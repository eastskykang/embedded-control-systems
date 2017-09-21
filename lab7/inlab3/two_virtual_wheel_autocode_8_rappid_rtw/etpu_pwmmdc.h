/*******************************************************************************
 * FILE NAME: etpu_pwmmdc.h         COPYRIGHT (c) Freescale Semiconductor 2005
 *                                              All Rights Reserved
 *
 * DESCRIPTION:
 * This file contains the prototypes and defines for the eTPU function PWM
 * Master For DC Motors (PWMMDC), PWM Full Range (PWMF) and PWM Commutated (PWMC)
 * API.
   ================================================================================
 * REV      AUTHOR      DATE        DESCRIPTION OF CHANGE
 * ---   -----------  ----------    ---------------------
 * 2.0   M. Brejl     02/Mar/05     Initial version derived from PWMM func.
 *       M. Princ
 * 2.1   M. Brejl     22/Mar/05     New PWMMDC API state flow:
 *       M. Princ                   init -> enable <-> disable.
 *******************************************************************************/

#ifndef _FS_ETPU_PWMMDC_H_
#define _FS_ETPU_PWMMDC_H_
#include "etpu_pwmmdc_auto.h"          /* Auto generated header file for eTPU PWMMDC */
#include "etpu_pwmc_auto.h"            /* Auto generated header file for eTPU PWMC */
#include "etpu_pwmf_auto.h"            /* Auto generated header file for eTPU PWMF */

/*******************************************************************************
 *                            Definitions
 *******************************************************************************/
#define FS_ETPU_PWMMDC_NOT_USED        (uint8_t)(-1)

/* modulation options */
#define FS_ETPU_PWMMDC_MOD_NO          FS_ETPU_PWMMDC_MODULATION_NO /* no modulation: update duty-cycles */
#define FS_ETPU_PWMMDC_MOD_VOLTAGE_UNSIGNED FS_ETPU_PWMMDC_MODULATION_UNSIGNED /* voltage unsigned */
#define FS_ETPU_PWMMDC_MOD_VOLTAGE_SIGNED FS_ETPU_PWMMDC_MODULATION_SIGNED /* voltage signed */

/* update options */
#define FS_ETPU_PWMMDC_NORMAL          FS_ETPU_PWMMDC_INIT_NORMAL /* normal update */
#define FS_ETPU_PWMMDC_HALF_CYCLE      FS_ETPU_PWMMDC_INIT_HALF_CYCLE /* half-cycle update */

/* alignment options */
#define FS_ETPU_PWMMDC_EDGE_ALIGNED    FS_ETPU_PWMMDC_FM_EDGE_ALIGNED /* edge-aligned */
#define FS_ETPU_PWMMDC_CENTER_ALIGNED  FS_ETPU_PWMMDC_FM_CENTER_ALIGNED /* center-aligned */

/* phases_type options */
#define FS_ETPU_PWMMDC_FULL_RANGE_SINGLE_CHANNELS 0              /* full range - single channels */
#define FS_ETPU_PWMMDC_FULL_RANGE_COMPL_PAIRS 1                  /* full range - complementary pairs */
#define FS_ETPU_PWMMDC_COMMUTATED_SINGLE_CHANNELS 2              /* commutated - single channels */
#define FS_ETPU_PWMMDC_COMMUTATED_COMPL_PAIRS 3                  /* commutated - complementary pairs */

/* phaseA_negate_duty phaseB_negate_duty phaseC_negate_duty options */
#define FS_ETPU_PWMMDC_DUTY_POS        0                         /* do not negate duty-cycle */
#define FS_ETPU_PWMMDC_DUTY_NEG        FS_ETPU_PWMMDC_OPTION_DUTY_NEG /* negate duty-cycle */

/* swap options */
#define FS_ETPU_PWMMDC_NO_SWAP         0                         /* do not swap dead-time insertion */
#define FS_ETPU_PWMMDC_SWAP            FS_ETPU_PWMMDC_OPTION_SWAP /* swap dead-time insertion */

/* base_ch_polarity and compl_ch_polarity options */
#define FS_ETPU_PWMMDC_ACTIVE_HIGH     0                         /* active high */
#define FS_ETPU_PWMMDC_ACTIVE_LOW      2                         /* active low */

/* base_ch_disable_pin_state and compl_ch_disable_pin_state options */
#define FS_ETPU_PWMMDC_PIN_LOW         FS_ETPU_PWMF_STOP_LOW     /* pin low */
#define FS_ETPU_PWMMDC_PIN_HIGH        FS_ETPU_PWMF_STOP_HIGH    /* pin high */

/* commutation byte options */
#define FS_ETPU_PWMMDC_OFF_LOW         1                         /* OFF - pin low */
#define FS_ETPU_PWMMDC_OFF_HIGH        2                         /* OFF - pin high */
#define FS_ETPU_PWMMDC_ON_ACTIVE_HIGH  3                         /* ON - polarity active high */
#define FS_ETPU_PWMMDC_ON_ACTIVE_LOW   4                         /* ON - polarity active low */
#define FS_ETPU_PWMMDC_COMPL_NOT_USED  0                         /* complementary channel not used */

/* num_phases options */
#define FS_ETPU_PWMMDC_1_PHASE         1                         /* 1 phase  (A) */
#define FS_ETPU_PWMMDC_2_PHASES        2                         /* 2 phases (A,B) */
#define FS_ETPU_PWMMDC_3_PHASES        3                         /* 3 phases (A,B,C) */

/*******************************************************************************
 *                       Function Prototypes
 *******************************************************************************/

/* Initialization of PWMMDC channel and 3 phases. */
int32_t fs_etpu_pwmmdc_init_3ph( uint8_t channel,
  uint8_t priority,
  uint8_t phaseA_channel,
  uint8_t phaseA_negate_duty,
  uint8_t phaseB_channel,
  uint8_t phaseB_negate_duty,
  uint8_t phaseC_channel,
  uint8_t phaseC_negate_duty,
  uint8_t modulation,
  uint8_t update,
  uint8_t alignment,
  uint8_t phases_type,
  uint8_t swap,
  uint8_t base_ch_disable_pin_state,
  uint8_t compl_ch_disable_pin_state,
  uint24_t start_offset,
  uint24_t period,
  uint24_t update_time,
  uint24_t dead_time,
  uint24_t min_pw);

/* Initialization of PWMMDC channel and 2 phases. */
int32_t fs_etpu_pwmmdc_init_2ph( uint8_t channel,
  uint8_t priority,
  uint8_t phaseA_channel,
  uint8_t phaseA_negate_duty,
  uint8_t phaseB_channel,
  uint8_t phaseB_negate_duty,
  uint8_t modulation,
  uint8_t update,
  uint8_t alignment,
  uint8_t phases_type,
  uint8_t swap,
  uint8_t base_ch_disable_pin_state,
  uint8_t compl_ch_disable_pin_state,
  uint24_t start_offset,
  uint24_t period,
  uint24_t update_time,
  uint24_t dead_time,
  uint24_t min_pw);

/* Initialization of PWMMDC channel and 1 phase. */
int32_t fs_etpu_pwmmdc_init_1ph( uint8_t channel,
  uint8_t priority,
  uint8_t phaseA_channel,
  uint8_t phaseA_negate_duty,
  uint8_t modulation,
  uint8_t update,
  uint8_t alignment,
  uint8_t phases_type,
  uint8_t swap,
  uint8_t base_ch_disable_pin_state,
  uint8_t compl_ch_disable_pin_state,
  uint24_t start_offset,
  uint24_t period,
  uint24_t update_time,
  uint24_t dead_time,
  uint24_t min_pw);

/* Enable PWM generation - 3 phases. */
int32_t fs_etpu_pwmmdc_enable_3ph( uint8_t channel,
  uint8_t base_ch_polarity,
  uint8_t compl_ch_polarity);

/* Enable PWM generation - 2 phases. */
int32_t fs_etpu_pwmmdc_enable_2ph( uint8_t channel,
  uint8_t base_ch_polarity,
  uint8_t compl_ch_polarity);

/* Enable PWM generation - 1 phase. */
int32_t fs_etpu_pwmmdc_enable_1ph( uint8_t channel,
  uint8_t base_ch_polarity,
  uint8_t compl_ch_polarity);

/* Disable PWM generation - 3 phases. */
int32_t fs_etpu_pwmmdc_disable_3ph( uint8_t channel,
  uint8_t base_ch_disable_pin_state,
  uint8_t compl_ch_disable_pin_state);

/* Disable PWM generation - 2 phases. */
int32_t fs_etpu_pwmmdc_disable_2ph( uint8_t channel,
  uint8_t base_ch_disable_pin_state,
  uint8_t compl_ch_disable_pin_state);

/* Disable PWM generation - 1 phase. */
int32_t fs_etpu_pwmmdc_disable_1ph( uint8_t channel,
  uint8_t base_ch_disable_pin_state,
  uint8_t compl_ch_disable_pin_state);

/* Set PWM period */
int32_t fs_etpu_pwmmdc_set_period( uint8_t channel,
  uint24_t period);

/* Update of input voltage in case of unsigned modulation */
int32_t fs_etpu_pwmmdc_update_voltage_unsigned( uint8_t channel,
  uint24_t voltage);

/* Update of input voltage in case of signed modulation */
int32_t fs_etpu_pwmmdc_update_voltage_signed( uint8_t channel,
  int24_t voltage);

/* Update of phase duty-cycles in case of no modulation */
int32_t fs_etpu_pwmmdc_update_duty_cycles( uint8_t channel,
  int24_t dutyA,
  int24_t dutyB,
  int24_t dutyC);

/* Apply commutation command */
int32_t fs_etpu_pwmmdc_commutate( uint8_t phase_channel,
  uint32_t commut_cmd);

/* Create commutation command */
uint32_t fs_etpu_pwmmdc_commut_cmd( uint8_t phase_channel,
  uint8_t base_ch_cmd,
  uint8_t compl_ch_cmd,
  uint8_t negate_duty,
  uint8_t swap);

/*******************************************************************************
 *        Information for eTPU Graphical Configuration Tool
 *******************************************************************************/
/* channel assignment when (fs_etpu_pwmmdc_init_3ph: phases_type=FS_ETPU_PWMMDC_FULL_RANGE_SINGLE_CHANNELS)
   master = channel
   phaseA = phaseA_channel
   phaseB = phaseB_channel
   phaseC = phaseC_channel
 */
/* channel assignment when (fs_etpu_pwmmdc_init_3ph: phases_type=FS_ETPU_PWMMDC_COMMUTATED_SINGLE_CHANNELS)
   master = channel
   phaseA = phaseA_channel
   phaseB = phaseB_channel
   phaseC = phaseC_channel
 */
/* channel assignment when (fs_etpu_pwmmdc_init_2ph: phases_type=FS_ETPU_PWMMDC_FULL_RANGE_SINGLE_CHANNELS)
   master = channel
   phaseA = phaseA_channel
   phaseB = phaseB_channel
 */
/* channel assignment when (fs_etpu_pwmmdc_init_2ph: phases_type=FS_ETPU_PWMMDC_COMMUTATED_SINGLE_CHANNELS)
   master = channel
   phaseA = phaseA_channel
   phaseB = phaseB_channel
 */
/* channel assignment when (fs_etpu_pwmmdc_init_1ph: phases_type=FS_ETPU_PWMMDC_FULL_RANGE_SINGLE_CHANNELS)
   master = channel
   phaseA = phaseA_channel
 */
/* channel assignment when (fs_etpu_pwmmdc_init_1ph: phases_type=FS_ETPU_PWMMDC_COMMUTATED_SINGLE_CHANNELS)
   master = channel
   phaseA = phaseA_channel
 */
/* channel assignment when (fs_etpu_pwmmdc_init_3ph: phases_type=FS_ETPU_PWMMDC_FULL_RANGE_COMPL_PAIRS)
   master = channel
   phaseA_base_channel = phaseA_channel
   phaseA_compl_channel = phaseA_channel + 1
   phaseB_base_channel = phaseB_channel
   phaseB_compl_channel = phaseB_channel + 1
   phaseC_base_channel = phaseC_channel
   phaseC_compl_channel = phaseC_channel + 1
 */
/* channel assignment when (fs_etpu_pwmmdc_init_3ph: phases_type=FS_ETPU_PWMMDC_COMMUTATED_COMPL_PAIRS)
   master = channel
   phaseA_base_channel = phaseA_channel
   phaseA_compl_channel = phaseA_channel + 1
   phaseB_base_channel = phaseB_channel
   phaseB_compl_channel = phaseB_channel + 1
   phaseC_base_channel = phaseC_channel
   phaseC_compl_channel = phaseC_channel + 1
 */
/* channel assignment when (fs_etpu_pwmmdc_init_2ph: phases_type=FS_ETPU_PWMMDC_FULL_RANGE_COMPL_PAIRS)
   master = channel
   phaseA_base_channel = phaseA_channel
   phaseA_compl_channel = phaseA_channel + 1
   phaseB_base_channel = phaseB_channel
   phaseB_compl_channel = phaseB_channel + 1
 */
/* channel assignment when (fs_etpu_pwmmdc_init_2ph: phases_type=FS_ETPU_PWMMDC_COMMUTATED_COMPL_PAIRS)
   master = channel
   phaseA_base_channel = phaseA_channel
   phaseA_compl_channel = phaseA_channel + 1
   phaseB_base_channel = phaseB_channel
   phaseB_compl_channel = phaseB_channel + 1
 */
/* channel assignment when (fs_etpu_pwmmdc_init_1ph: phases_type=FS_ETPU_PWMMDC_FULL_RANGE_COMPL_PAIRS)
   master = channel
   phaseA_base_channel = phaseA_channel
   phaseA_compl_channel = phaseA_channel + 1
 */
/* channel assignment when (fs_etpu_pwmmdc_init_1ph: phases_type=FS_ETPU_PWMMDC_COMMUTATED_COMPL_PAIRS)
   master = channel
   phaseA_base_channel = phaseA_channel
   phaseA_compl_channel = phaseA_channel + 1
 */
#endif

/*********************************************************************
 *
 * Copyright:
 *	Freescale Semiconductor, INC. All Rights Reserved.
 *  You are hereby granted a copyright license to use, modify, and
 *  distribute the SOFTWARE so long as this entire notice is
 *  retained without alteration in any modified and/or redistributed
 *  versions, and that such modified versions are clearly identified
 *  as such. No licenses are granted by implication, estoppel or
 *  otherwise under any patents or trademarks of Freescale
 *  Semiconductor, Inc. This software is provided on an "AS IS"
 *  basis and without warranty.
 *
 *  To the maximum extent permitted by applicable law, Freescale
 *  Semiconductor DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED,
 *  INCLUDING IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A
 *  PARTICULAR PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH
 *  REGARD TO THE SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF)
 *  AND ANY ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL Freescale Semiconductor BE LIABLE FOR ANY DAMAGES WHATSOEVER
 *  (INCLUDING WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS,
 *  BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER
 *  PECUNIARY LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  Freescale Semiconductor assumes no responsibility for the
 *  maintenance and support of this software
 ********************************************************************/

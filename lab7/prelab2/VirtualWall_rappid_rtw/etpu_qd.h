/*******************************************************************************
 * FILE NAME: etpu_qd.h              COPYRIGHT (c) Freescale Semiconductor 2005
 *                                              All Rights Reserved
 * DESCRIPTION:
 * This file contains the prototypes and definitions for the eTPU Quadrature
 * Decoder (QD) API.
 *===============================================================================
 * REV      AUTHOR      DATE        DESCRIPTION OF CHANGE
 * ---   -----------  ----------    ---------------------
 * 0.1   A. Butok     23/Feb/04     Initial version.
 * 0.2   M. Princ     16/Nov/04     Automatic switch between 3 modes:
 *                                  slow-normal-fast. Commutations removed.
 * 2.0   M. Brejl     22/Mar/05     New QD API state flow:
 *       M. Princ                   init -> (disable -> align -> enable).
 *******************************************************************************/

#ifndef _ETPU_QD_H_
#define _ETPU_QD_H_
#include "etpu_qd_auto.h"              /* Auto generated header file for eTPU QD. */

/*******************************************************************************
 *                            Definitions
 *******************************************************************************/
/* signals options */
#define FS_ETPU_QD_PRIM_SEC            (0)                       /* Primary and secondary only. */
#define FS_ETPU_QD_PRIM_SEC_INDEX      (1)                       /* Index, primary and secondary. */
#define FS_ETPU_QD_PRIM_SEC_HOME       (2)                       /* Home, primary and secondary. */
#define FS_ETPU_QD_PRIM_SEC_INDEX_HOME (3)                       /* Index, Home, primary and secondary. */

/* configuration options */
#define FS_ETPU_QD_CONFIGURATION_0     (0)                       /* Both QD pins are 0 when the INDEX is reached. */
#define FS_ETPU_QD_CONFIGURATION_1     (1)                       /* Both QD pins are 1 when the INDEX is reached. */

/* direction options */
#define FS_ETPU_QD_DIRECTION_INC       (0)                       /* Positive Direction. */
#define FS_ETPU_QD_DIRECTION_DEC       (1)                       /* Negative Direction. */

/* home_transition options */
#define FS_ETPU_QD_HOME_TRANS_LOW_HIGH FS_ETPU_QD_HOME_FM_DETECT_LOW_HIGH /* Detection of low-high transition. */
#define FS_ETPU_QD_HOME_TRANS_HIGH_LOW FS_ETPU_QD_HOME_FM_DETECT_HIGH_LOW /* Detection of high-low transition. */
#define FS_ETPU_QD_HOME_TRANS_ANY      FS_ETPU_QD_HOME_FM_DETECT_ANY /* Detection of any transition. */

/* index_pulse options */
#define FS_ETPU_QD_INDEX_PULSE_POSITIVE FS_ETPU_QD_INDEX_FM_PULSE_POSITIVE /* Index pulse of positive polarity. */
#define FS_ETPU_QD_INDEX_PULSE_NEGATIVE FS_ETPU_QD_INDEX_FM_PULSE_NEGATIVE /* Index pulse of negative polarity. */

/* index_pc_reset options */
#define FS_ETPU_QD_INDEX_PC_NO_RESET   FS_ETPU_QD_INDEX_FM_PC_NO_RESET /* Position Counter is NOT reset on Index transition. */
#define FS_ETPU_QD_INDEX_PC_RESET      FS_ETPU_QD_INDEX_FM_PC_RESET /* Position Counter is reset on Index transition. */

/* etpu_tcr_freq options */
#define FS_ETPU_QD_ETPU_A_TCR1_FREQ    etpu_a_tcr1_freq          /* frequency of eTPU engine A - TCR1 */
#define FS_ETPU_QD_ETPU_A_TCR2_FREQ    etpu_a_tcr2_freq          /* frequency of eTPU engine A - TCR2 */
#define FS_ETPU_QD_ETPU_B_TCR1_FREQ    etpu_b_tcr1_freq          /* frequency of eTPU engine B - TCR1 */
#define FS_ETPU_QD_ETPU_B_TCR2_FREQ    etpu_b_tcr2_freq          /* frequency of eTPU engine B - TCR2 */

/* mode */
#define FS_ETPU_QD_MODE_SLOW           (1)                       /* Slow mode */
#define FS_ETPU_QD_MODE_NORMAL         (2)                       /* Normal mode */
#define FS_ETPU_QD_MODE_FAST           (4)                       /* Fast mode */

/*******************************************************************************
 *                       Function Prototypes
 *******************************************************************************/

/* QD Phase A, Phase B, Home and Index channel initialization. */
int32_t fs_etpu_qd_init( uint8_t channel_primary,
  int8_t channel_home,
  int8_t channel_index,
  uint8_t signals,
  uint8_t priority,
  uint8_t configuration,
  uint8_t timer,
  uint24_t pc_max,
  uint24_t slow_normal_threshold,
  uint24_t normal_slow_threshold,
  uint24_t normal_fast_threshold,
  uint24_t fast_normal_threshold,
  fract24_t window_ratio1,
  fract24_t window_ratio2,
  uint8_t home_transition,
  uint8_t index_pulse,
  uint8_t index_pc_reset,
  uint32_t etpu_tcr_freq,
  uint24_t pc_per_rev);

/* Disable QD channels. */
int32_t fs_etpu_qd_disable( uint8_t channel_primary,
  int8_t channel_home,
  int8_t channel_index,
  uint8_t signals);

/* Enable QD channels. */
int32_t fs_etpu_qd_enable( uint8_t channel_primary,
  int8_t channel_home,
  int8_t channel_index,
  uint8_t signals,
  uint8_t priority);

/* Align QD. */
int32_t fs_etpu_qd_align(uint8_t channel_primary,
  int24_t pc);

/* Set QD pc_interrupt values. */
int32_t fs_etpu_qd_set_pc_interrupts(uint8_t channel_primary,
  int24_t pc_interrupt1,
  int24_t pc_interrupt2);

/* Enable QD pc_interrupt processing. */
int32_t fs_etpu_qd_enable_pc_interrupts(uint8_t channel_primary);

/* Disable QD pc_interrupt processing. */
int32_t fs_etpu_qd_disable_pc_interrupts(uint8_t channel_primary);

/* Change QD Position Counter. */
int32_t fs_etpu_qd_set_pc(uint8_t channel_primary,
  int24_t pc);

/* Change QD Revolution Counter. */
int32_t fs_etpu_qd_set_rc(uint8_t channel_primary,
  int24_t rc);

/* Set QD mode to slow. */
int32_t fs_etpu_qd_set_slow_mode(uint8_t channel_primary);

/* Get Position Counter value on last transition. */
int24_t fs_etpu_qd_get_pc(uint8_t channel_primary);

/* Get Position Counter for SC value on last transition. */
int24_t fs_etpu_qd_get_pc_sc(uint8_t channel_primary);

/* Get Revolution Counter value. */
int24_t fs_etpu_qd_get_rc(uint8_t channel_primary);

/* Get direction. */
int8_t fs_etpu_qd_get_direction(uint8_t channel_primary);

/* Get current mode of the QD function. */
uint8_t fs_etpu_qd_get_mode(uint8_t channel_primary);

/* Get TCR time of last transition. */
uint24_t fs_etpu_qd_get_tcr(uint8_t channel_primary);

/* Get period. */
uint24_t fs_etpu_qd_get_period(uint8_t channel_primary);

/* Get the state of Phase A input channel on last transition. */
uint8_t fs_etpu_qd_get_pinA(uint8_t channel_primary);

/* Get the state of Phase B input channel on last transition. */
uint8_t fs_etpu_qd_get_pinB(uint8_t channel_primary);

/*******************************************************************************
 *======================== for TPU3 API Compatibility ===========================
 *******************************************************************************/

/* FQD Phase A, Phase B channel initialization. */
void tpu_fqd_init(uint8_t channel,
                  uint8_t priority,
                  int16_t init_position);

/* Get current operating mode of the FQD function. */
uint8_t tpu_fqd_current_mode(uint8_t channel);

/* Get current position count for the quadrature input signal. */
int16_t tpu_fqd_position(uint8_t channel);

/* Get data parameters associated with the FQD channel. */
void tpu_fqd_data(uint8_t channel,
                  int16_t *tcr1,
                  int16_t *edge,
                  int16_t *primary_pin,
                  int16_t *secondary_pin);

/*******************************************************************************
 *        Information for eTPU Graphical Configuration Tool
 *******************************************************************************/
/* full function name: QD - Quadrature Decoder */
/* channel assignment when (signals=FS_ETPU_QD_PRIM_SEC)
   Primary = channel_primary
   Secondary = channel_primary + 1
 */
/* channel assignment when (signals=FS_ETPU_QD_PRIM_SEC_INDEX)
   Primary = channel_primary
   Secondary = channel_primary + 1
   Index = channel_index
 */
/* channel assignment when (signals=FS_ETPU_QD_PRIM_SEC_HOME)
   Primary = channel_primary
   Secondary = channel_primary + 1
   Home = channel_home
 */
/* channel assignment when (signals=FS_ETPU_QD_PRIM_SEC_INDEX_HOME)
   Primary = channel_primary
   Secondary = channel_primary + 1
   Home = channel_home
   Index = channel_index
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

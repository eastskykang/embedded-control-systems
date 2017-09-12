/*******************************************************************************
* FILE NAME: etpu_qd.c              COPYRIGHT (c) Freescale Semiconductor 2005
*                                              All Rights Reserved
* DESCRIPTION:
* This file contains the eTPU Quadrature Decoder (QD) API.
*===============================================================================
* REV      AUTHOR      DATE        DESCRIPTION OF CHANGE
* ---   -----------  ----------    ---------------------
* 0.1   A. Butok     23/Feb/04     Initial version.
* 0.2   M. Princ     16/Nov/04     Automatic switch between 3 modes:
*                                  slow-normal-fast. Commutations removed.
* 2.0   M. Brejl     22/Mar/05     New QD API state flow:
*       M. Princ                   init -> (disable -> align -> enable).
*******************************************************************************/
#include "etpu_util.h"          /* Utility routines for working with the eTPU */
#include "etpu_qd.h"            /* eTPU QD API */

extern uint32_t fs_etpu_data_ram_start;
extern uint32_t fs_etpu_data_ram_ext;

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_init
*PURPOSE      : To initialize an eTPU channels to implement QD.
*INPUTS NOTES : This function has 19 parameters:
*  channel_primary       - This is the Primary channel number (Phase A).
*                          The Secondary channel (Phase B) is alwayes a channel
*                          one higner.
*                          0-31 for ETPU_A and 64-95 for ETPU_B.
*  channel_home          - If a Home signal is processed, this is the Home
*                          channel number.
*                          0-31 for ETPU_A and 64-95 for ETPU_B.
*  channel_index         - If an Index signal is processed, this is the Index
*                          channel number.
*                          0-31 for ETPU_A and 64-95 for ETPU_B.
*  signals               - This parameter determines which QD signals are used.
*                          This parameter should be assigned a value of:
*                          FS_ETPU_QD_PRIM_SEC
*                          FS_ETPU_QD_PRIM_SEC_INDEX
*                          FS_ETPU_QD_PRIM_SEC_HOME
*                          FS_ETPU_QD_PRIM_SEC_INDEX_HOME.
*  priority              - This is the priority to assign to the QD function.
*                          This parameter should be assigned a value of:
*                          FS_ETPU_PRIORITY_HIGH or
*                          FS_ETPU_PRIORITY_MIDDLE or
*                          FS_ETPU_PRIORITY_LOW or
*                          FS_ETPU_PRIORITY_DISABLED.
*  configuration         - This is the configuration of channels.
*                          This parameter should be assigned a value of:
*                          FS_ETPU_QD_CONFIGURATION_0 or
*                          FS_ETPU_QD_CONFIGURATION_1.
*  timer                 - This is the timer to use as a reference for the QD
*                          signals.
*                          This parameter should be assigned to a value of:
*                          FS_ETPU_TCR1 or
*                          FS_ETPU_TCR2.
*  pc_max                - Maximum value of Position Counter.
*                          This parameter is optional and can be set to zero;
*                          then the automatic Position Counter reset is not
*                          performed.
*  slow_normal_threshold - This is the threshold for automatic switching from
*                          slow mode to normal mode, in [rpm].
*  normal_slow_threshold - This is the threshold for automatic switching from
*                          normal mode to slow mode, in [rpm].
*  normal_fast_threshold - This is the threshold for automatic switching from
*                          normal mode to fast mode, in [rpm].
*  fast_normal_threshold - This is the threshold for automatic switching from
*                          fast mode to normal mode, in [rpm].
*                          (When all thresholds are set to zero QD function
*                          runs in slow mode only.)
*  window_ratio1         - This is the ratio which applies when scheduling
*                          the window beginning (in normal and fast mode).
*                          This parameter determines how much time prior the
*                          expected next QD edge the window opens.
*                          This is a fractional value in format (9.15)
*                          (0x00800000 corresponds to 1.0)
*                          and should be assigned a value between
*                          0.5 (0x00400000) and 0.9 (0x00733333).
*  window_ratio2         - This is the ratio which applies when scheduling
*                          the window ending (in normal and fast mode).
*                          This parameter determines how much time after the
*                          expected next QD edge the window opens.
*                          This is a fractional value in format (9.15)
*                          (0x00800000 corresponds to 1.0)
*                          and should be assigned a value between
*                          1.1 (0x008CCCCC) and 1.5 (0x00C00000).
*  home_transition       - This parameter selects a type of Home signal
*                          transition to detect.
*                          This parameter should be assigned a value of:
*                          FS_ETPU_QD_HOME_TRANS_LOW_HIGH,
*                          FS_ETPU_QD_HOME_TRANS_HIGH_LOW or
*                          FS_ETPU_QD_HOME_TRANS_ANY.
*                          This parameter is ignored if Home channel is not 
*                          used.
*  index_pulse           - This parameter selects a type of Index signal pulse
*                          to detect.
*                          This parameter should be assigned to a value of:
*                          FS_ETPU_QD_INDEX_PULSE_POSITIVE or
*                          FS_ETPU_QD_INDEX_PULSE_NEGATIVE.
*                          This parameter is ignored if Index channel is not
*                          used.
*  index_pc_reset        - This parameter selects an action to perform on Index
*                          signal detection.
*                          This parameter should be assigned to a value of:
*                          FS_ETPU_QD_INDEX_PC_NO_RESET or
*                          FS_ETPU_QD_INDEX_PC_RESET.
*                          This parameter is ignored if Index channel is not
*                          used.
*  etpu_tcr_freq         - This is the frequency of TCR module used by QD
*                          channels, in [Hz].
*  qd_pc_per_rev         - This is the number of QD Position Counter increments
*                          per revolution.
*
* RETURNS NOTES: Error codes which can be returned are: FS_ETPU_ERROR_VALUE,
*                FS_ETPU_ERROR_MALLOC
******************************************************************************/
int32_t fs_etpu_qd_init( uint8_t   channel_primary,
                         uint8_t   channel_home,
                         uint8_t   channel_index,
                         uint8_t   signals,
                         uint8_t   priority,
                         uint8_t   configuration,
                         uint8_t   timer,
                         uint24_t  pc_max,
                         uint24_t  slow_normal_threshold,
                         uint24_t  normal_slow_threshold,
                         uint24_t  normal_fast_threshold,
                         uint24_t  fast_normal_threshold,
                         fract24_t window_ratio1,
                         fract24_t window_ratio2,
                         uint8_t   home_transition,
                         uint8_t   index_pulse,
                         uint8_t   index_pc_reset,
                         uint32_t  etpu_tcr_freq,
                         uint24_t  pc_per_rev)
{
   uint32_t * pba;

   uint8_t options = 0;

   /****************************************
    * Parameters bounds check.
    ***************************************/
   #ifdef FS_ETPU_MC_PARAM_CHECK
   if(((channel_primary>31)&&(channel_primary<64))||(channel_primary>95)||
      (configuration>FS_ETPU_QD_CONFIGURATION_1)||
      (timer>FS_ETPU_TCR2)||
      ((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
       (signals==FS_ETPU_QD_PRIM_SEC_HOME))&&
      (((channel_home>31)&&(channel_home<64))||
       (channel_home>95)||(home_transition>FS_ETPU_QD_HOME_TRANS_ANY))||
      ((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
       (signals==FS_ETPU_QD_PRIM_SEC_INDEX))&&
      (((channel_index>31)&&(channel_index<64))||
       (channel_index>95)||(index_pulse>FS_ETPU_QD_INDEX_PULSE_NEGATIVE)||
       (index_pc_reset>FS_ETPU_QD_INDEX_PC_RESET)))
   {
      return(FS_ETPU_ERROR_VALUE);
   }
   #endif

   /****************************************
    * PRAM allocation.
    ***************************************/
   if ((pba=fs_etpu_malloc(FS_ETPU_QD_NUM_PARMS))== 0)
   {
      return(FS_ETPU_ERROR_MALLOC);
   }

   /****************************************
    * Write channel configuration registers
    * and FM (function mode) bits.
    ***************************************/
   /* PRIMARY CHANNEL */
   eTPU->CHAN[channel_primary].CR.R = (FS_ETPU_QD_TABLE_SELECT << 24) +
                                      (FS_ETPU_QD_FUNCTION_NUMBER << 16) +
                                (((uint32_t)pba - fs_etpu_data_ram_start) >> 3);
   eTPU->CHAN[channel_primary].SCR.R = (uint32_t)((timer << 1) + 
                                       FS_ETPU_QD_FM_CHANNEL_PRIMARY);

   /* SECONDARY CHANNEL */
   eTPU->CHAN[channel_primary+1].CR.R = eTPU->CHAN[channel_primary].CR.R;
   eTPU->CHAN[channel_primary+1].SCR.R = (uint32_t)((timer << 1) +
                                         FS_ETPU_QD_FM_CHANNEL_SECONDARY);

   /* HOME CHANNEL */
   if((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
      (signals==FS_ETPU_QD_PRIM_SEC_HOME))
   {
      eTPU->CHAN[channel_home].CR.R = (FS_ETPU_QD_HOME_TABLE_SELECT << 24) +
                                      (FS_ETPU_QD_HOME_FUNCTION_NUMBER << 16) +
                                (((uint32_t)pba - fs_etpu_data_ram_start) >> 3);

      eTPU->CHAN[channel_home].SCR.R = home_transition;
   }

   /* INDEX CHANNEL */
   if((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
      (signals==FS_ETPU_QD_PRIM_SEC_INDEX))
   {
      eTPU->CHAN[channel_index].CR.R = (FS_ETPU_QD_INDEX_TABLE_SELECT << 24) +
                                       (FS_ETPU_QD_INDEX_FUNCTION_NUMBER << 16)+
                                (((uint32_t)pba - fs_etpu_data_ram_start) >> 3);

      eTPU->CHAN[channel_index].SCR.R = (uint32_t)index_pc_reset + index_pulse;
   }

   /****************************************
    * Write parameters.
    ***************************************/
   if (pc_max>0)
      options = FS_ETPU_QD_PC_MAX_ENABLED;

   if (pc_per_rev > 0)
   {
       if (slow_normal_threshold > 0)
           slow_normal_threshold = (uint24_t)(((30*etpu_tcr_freq)/
                                        (pc_per_rev*slow_normal_threshold))<<2);
       if (normal_slow_threshold > 0)
           normal_slow_threshold = (uint24_t)(((30*etpu_tcr_freq)/
                                        (pc_per_rev*normal_slow_threshold))<<2);
       if (normal_fast_threshold > 0)
           normal_fast_threshold = (uint24_t)(((30*etpu_tcr_freq)/
                                        (pc_per_rev*normal_fast_threshold))<<2);
       if (fast_normal_threshold > 0)
           fast_normal_threshold = (uint24_t)(((30*etpu_tcr_freq)/
                                        (pc_per_rev*fast_normal_threshold))<<2);
   }

   *(pba + ((FS_ETPU_QD_PC_OFFSET - 1)>>2)) = 0;
   *(pba + ((FS_ETPU_QD_RC_OFFSET - 1)>>2)) = 0;
   *(pba + ((FS_ETPU_QD_PERIOD_OFFSET - 1)>>2)) = 0;
   *(pba + ((FS_ETPU_QD_PCMAX_OFFSET - 1)>>2)) = pc_max;
   *(pba + ((FS_ETPU_QD_PCINTERRUPT1_OFFSET - 1)>>2)) = 0;
   *(pba + ((FS_ETPU_QD_PCINTERRUPT2_OFFSET - 1)>>2)) = 0;
   *(pba + ((FS_ETPU_QD_SLOW_NORMAL_THR_OFFSET - 1)>>2))= slow_normal_threshold;
   *(pba + ((FS_ETPU_QD_NORMAL_SLOW_THR_OFFSET - 1)>>2))= normal_slow_threshold;
   *(pba + ((FS_ETPU_QD_NORMAL_FAST_THR_OFFSET - 1)>>2))= normal_fast_threshold;
   *(pba + ((FS_ETPU_QD_FAST_NORMAL_THR_OFFSET - 1)>>2))= fast_normal_threshold;
   *(pba + ((FS_ETPU_QD_LAST_LEADING_EDGE_OFFSET - 1)>>2)) = 0;
   *(pba + ((FS_ETPU_QD_LAST_EDGE_OFFSET - 1)>>2)) = 0;
   *(pba + ((FS_ETPU_QD_PC_SC_OFFSET - 1)>>2)) = 0;
   *((uint8_t*)pba + FS_ETPU_QD_DIRECTION_OFFSET) = 0;
   *((uint8_t*)pba + FS_ETPU_QD_PINS_OFFSET) = (uint8_t)(configuration << 2);
   *((uint8_t*)pba + FS_ETPU_QD_OPTIONS_OFFSET) = options;
   *(pba + ((FS_ETPU_QD_RATIO1_OFFSET - 1)>>2)) = (uint32_t)window_ratio1;
   *(pba + ((FS_ETPU_QD_RATIO2_OFFSET - 1)>>2)) = (uint32_t)window_ratio2 -
                                                  0x00800000;

   /****************************************
    * Write HSR.
    ***************************************/
   eTPU->CHAN[channel_primary].HSRR.R = FS_ETPU_QD_INIT;
   eTPU->CHAN[channel_primary+1].HSRR.R = FS_ETPU_QD_INIT;
   if((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
      (signals==FS_ETPU_QD_PRIM_SEC_HOME))
      eTPU->CHAN[channel_home].HSRR.R = FS_ETPU_QD_HOME_INIT;
   if((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
      (signals==FS_ETPU_QD_PRIM_SEC_INDEX))
      eTPU->CHAN[channel_index].HSRR.R = FS_ETPU_QD_INDEX_INIT;

   /****************************************
    * Set channel priorities and enable.
    ***************************************/
   fs_etpu_enable(channel_primary, priority);
   fs_etpu_enable((uint8_t)(channel_primary+1), priority);
   if((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
      (signals==FS_ETPU_QD_PRIM_SEC_HOME))
      fs_etpu_enable(channel_home, priority);
   if((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
      (signals==FS_ETPU_QD_PRIM_SEC_INDEX))
      fs_etpu_enable(channel_index, priority);

   return(0);
}

/*******************************************************************************
* FUNCTION     : fs_etpu_qd_disable
* PURPOSE      : To disable an eTPU Quadrature Decoder channels.
* INPUTS NOTES : This function has 4 parameters:
*
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*  channel_home    - If a Home signal is processed, this is the Home channel
*                    number.
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*  channel_index   - If an Index signal is processed, this is the Index channel
*                    number.
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*  signals         - This parameter determines which QD signals are used.
*                    This parameter should be assigned a value of:
*                    FS_ETPU_QD_PRIM_SEC
*                    FS_ETPU_QD_PRIM_SEC_INDEX
*                    FS_ETPU_QD_PRIM_SEC_HOME
*                    FS_ETPU_QD_PRIM_SEC_INDEX_HOME.
* RETURNS NOTES: Error code which can be returned is: FS_ETPU_ERROR_VALUE
*******************************************************************************/
int32_t fs_etpu_qd_disable( uint8_t channel_primary,
                            uint8_t channel_home,
                            uint8_t channel_index,
                            uint8_t signals)
{
   /****************************************
    * Parameters bounds check.
    ***************************************/
   #ifdef FS_ETPU_MC_PARAM_CHECK
   if(((channel_primary>31)&&(channel_primary<64))||(channel_primary>95)||
      ((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
       (signals==FS_ETPU_QD_PRIM_SEC_HOME))&&
      (((channel_home>31)&&(channel_home<64))||(channel_home>95))||
      ((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
       (signals==FS_ETPU_QD_PRIM_SEC_INDEX))&&
      (((channel_index>31)&&(channel_index<64))||(channel_index>95)))
   {
      return(FS_ETPU_ERROR_VALUE);
   }
   #endif

   /****************************************
    * Disable channel.
    ***************************************/
   fs_etpu_disable(channel_primary);
   fs_etpu_disable((uint8_t)(channel_primary+1));
   if((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
      (signals==FS_ETPU_QD_PRIM_SEC_HOME))
      fs_etpu_disable(channel_home);
   if((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
      (signals==FS_ETPU_QD_PRIM_SEC_INDEX))
      fs_etpu_disable(channel_index);

   return(0);
}

/*******************************************************************************
* FUNCTION     : fs_etpu_qd_enable
* PURPOSE      : To enable an eTPU Quadrature Decoder channels.
* INPUTS NOTES : This function has 5 parameters:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*  channel_home    - If a Home signal is processed, this is the Home channel
*                    number.
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*  channel_index   - If an Index signal is processed, this is the Index channel
*                    number.
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*  signals         - This parameter determines which QD signals are used.
*                    This parameter should be assigned a value of:
*                    FS_ETPU_QD_PRIM_SEC
*                    FS_ETPU_QD_PRIM_SEC_INDEX
*                    FS_ETPU_QD_PRIM_SEC_HOME
*                    FS_ETPU_QD_PRIM_SEC_INDEX_HOME.
*  priority        - This is the priority to assign to the QD channels.
*                    This parameter should be assigned a value of:
*                    FS_ETPU_PRIORITY_HIGH, FS_ETPU_PRIORITY_MIDDLE or
*                    FS_ETPU_PRIORITY_LOW.
*
* RETURNS NOTES: Error code which can be returned is: FS_ETPU_ERROR_VALUE
*******************************************************************************/
int32_t fs_etpu_qd_enable( uint8_t channel_primary,
                           uint8_t channel_home,
                           uint8_t channel_index,
                           uint8_t signals,
                           uint8_t priority)
{
   /****************************************
    * Parameters bounds check.
    ***************************************/
   #ifdef FS_ETPU_MC_PARAM_CHECK
   if(((channel_primary>31)&&(channel_primary<64))||(channel_primary>95)||
      ((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
       (signals==FS_ETPU_QD_PRIM_SEC_HOME))&&
      (((channel_home>31)&&(channel_home<64))||(channel_home>95))||
      ((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
       (signals==FS_ETPU_QD_PRIM_SEC_INDEX))&&
      (((channel_index>31)&&(channel_index<64))||(channel_index>95))||
      (priority>FS_ETPU_PRIORITY_HIGH))
   {
      return(FS_ETPU_ERROR_VALUE);
   }
   #endif

   /****************************************
    * Enable channel.
    ***************************************/
   fs_etpu_enable(channel_primary, priority);
   fs_etpu_enable((uint8_t)(channel_primary+1), priority);
   if((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
      (signals==FS_ETPU_QD_PRIM_SEC_HOME))
      fs_etpu_enable(channel_home, priority);
   if((signals==FS_ETPU_QD_PRIM_SEC_INDEX_HOME)||
      (signals==FS_ETPU_QD_PRIM_SEC_INDEX))
      fs_etpu_enable(channel_index, priority);

   return(0);
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_align
*PURPOSE      : This function changes the Position Counter value to ensure
*               its divisibility by 4 when leading edge occurs. This depends
*               on QD Configuration, and of the QD Primary and
*               Secondary pin states.
*               Position Counter dedicated for SC is reset to 0.
*INPUTS NOTES : This function has 2 parameters:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*  pc              - This is the Position Counter value to be set.
*                    The actual value set is in range from pc-1 to pc+2,
*                    to ensure PC divisibility by 4 on the leading edge.
*
*RETURNS NOTES: Error code that can be returned is: FS_ETPU_ERROR_VALUE.
*******************************************************************************/
int32_t fs_etpu_qd_align(uint8_t channel_primary,
                         int24_t pc)
{
   uint8_t pins;

   /* Parameters bounds check */
   #ifdef FS_ETPU_MC_PARAM_CHECK
   if(((channel_primary>31)&&(channel_primary<64))||(channel_primary>95))
   {
      return(FS_ETPU_ERROR_VALUE);
   }
   #endif

   eTPU->CHAN[channel_primary].HSRR.R = FS_ETPU_QD_INIT;
   eTPU->CHAN[channel_primary+1].HSRR.R = FS_ETPU_QD_INIT;

   /* Wait till initialization is finished */
   while (eTPU->CHAN[channel_primary+1].HSRR.R != 0) {}

   /* Read actual pins state */
   pins = (uint8_t)(fs_etpu_get_chan_local_8(channel_primary,
                    FS_ETPU_QD_PINS_OFFSET) & 0x07);

   /* Adjust pc so that the leading edge counts a multiple of 4 */
   if ((pins == 0x01) || (pins == 0x06))
       pc += 1;
   else if ((pins == 0x02) || (pins == 0x05))
       pc -= 1;
   else if ((pins == 0x03) || (pins == 0x04))
       pc += 2;

   /* Write pc and reset pc_sc */
   fs_etpu_set_chan_local_24(channel_primary,FS_ETPU_QD_PC_OFFSET,(uint24_t)pc);
   fs_etpu_set_chan_local_24(channel_primary,FS_ETPU_QD_PC_SC_OFFSET, 0);

   return(0);
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_set_pc_interrupts
*PURPOSE      : This function changes the pc_interrupt values.
*INPUTS NOTES : This function has 3 parameters:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*  pc_interrupt1   - This is the pc_interrupt1 value to be set.
*  pc_interrupt2   - This is the pc_interrupt2 value to be set.
*
*RETURNS NOTES: Error code that can be returned is: FS_ETPU_ERROR_VALUE.
*******************************************************************************/
int32_t fs_etpu_qd_set_pc_interrupts(uint8_t channel_primary,
                                     int24_t pc_interrupt1,
                                     int24_t pc_interrupt2)
{
   /* Parameters bounds check */
   #ifdef FS_ETPU_MC_PARAM_CHECK
   if(((channel_primary>31)&&(channel_primary<64))||(channel_primary>95))
   {
      return(FS_ETPU_ERROR_VALUE);
   }
   #endif

   fs_etpu_set_chan_local_24(channel_primary, FS_ETPU_QD_PCINTERRUPT1_OFFSET,
                             (uint24_t)pc_interrupt1);
   fs_etpu_set_chan_local_24(channel_primary, FS_ETPU_QD_PCINTERRUPT2_OFFSET,
                             (uint24_t)pc_interrupt2);

   return(0);
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_enable_pc_interrupts
*PURPOSE      : This function enables the pc_interrupt processing.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: Error code that can be returned is: FS_ETPU_ERROR_VALUE.
*******************************************************************************/
int32_t fs_etpu_qd_enable_pc_interrupts(uint8_t channel_primary)
{
   uint8_t options;

   /* Parameters bounds check */
   #ifdef FS_ETPU_MC_PARAM_CHECK
   if(((channel_primary>31)&&(channel_primary<64))||(channel_primary>95))
   {
      return(FS_ETPU_ERROR_VALUE);
   }
   #endif

   options = fs_etpu_get_chan_local_8(channel_primary,
                                      FS_ETPU_QD_OPTIONS_OFFSET);
   options |= FS_ETPU_QD_PC_INTERRUPT_ENABLED;
   fs_etpu_set_chan_local_8(channel_primary,FS_ETPU_QD_OPTIONS_OFFSET, options);

   return(0);
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_disable_pc_interrupts
*PURPOSE      : This function disables the pc_interrupt processing.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: Error code that can be returned is: FS_ETPU_ERROR_VALUE.
*******************************************************************************/
int32_t fs_etpu_qd_disable_pc_interrupts(uint8_t channel_primary)
{
   uint8_t options;

   /* Parameters bounds check */
   #ifdef FS_ETPU_MC_PARAM_CHECK
   if(((channel_primary>31)&&(channel_primary<64))||(channel_primary>95))
   {
      return(FS_ETPU_ERROR_VALUE);
   }
   #endif

   options = fs_etpu_get_chan_local_8(channel_primary, 
                                      FS_ETPU_QD_OPTIONS_OFFSET);
   options &= (uint8_t)(~FS_ETPU_QD_PC_INTERRUPT_ENABLED);
   fs_etpu_set_chan_local_8(channel_primary,FS_ETPU_QD_OPTIONS_OFFSET, options);

   return(0);
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_set_pc
*PURPOSE      : This function changes the Position Counter value.
*INPUTS NOTES : This function has 2 parameters:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*  pc              - This is the Position Counter value to be set.
*
*RETURNS NOTES: Error code that can be returned is: FS_ETPU_ERROR_VALUE.
*******************************************************************************/
int32_t fs_etpu_qd_set_pc(uint8_t channel_primary,
                          int24_t pc)
{
   /* Parameters bounds check */
   #ifdef FS_ETPU_MC_PARAM_CHECK
   if(((channel_primary>31)&&(channel_primary<64))||(channel_primary>95))
   {
      return(FS_ETPU_ERROR_VALUE);
   }
   #endif

   fs_etpu_set_chan_local_24(channel_primary,FS_ETPU_QD_PC_OFFSET,(uint24_t)pc);

   return(0);
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_set_rc
*PURPOSE      : This function changes the Revolution Counter value.
*INPUTS NOTES : This function has 2 parameters:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*  rc              - This is the Revolution Counter value to be set.
*
*RETURNS NOTES: Error code that can be returned is: FS_ETPU_ERROR_VALUE.
*******************************************************************************/
int32_t fs_etpu_qd_set_rc(uint8_t channel_primary,
                          int24_t rc)
{
   /* Parameters bounds check */
   #ifdef FS_ETPU_MC_PARAM_CHECK
   if(((channel_primary>31)&&(channel_primary<64))||(channel_primary>95))
   {
      return(FS_ETPU_ERROR_VALUE);
   }
   #endif

   fs_etpu_set_chan_local_24(channel_primary,FS_ETPU_QD_RC_OFFSET,(uint24_t)rc);

   return(0);
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_set_slow_mode
*PURPOSE      : This function changes the QD mode to slow.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: Error code that can be returned is: FS_ETPU_ERROR_VALUE.
*******************************************************************************/
int32_t fs_etpu_qd_set_slow_mode(uint8_t channel_primary)
{
   /* Parameters bounds check */
   #ifdef FS_ETPU_MC_PARAM_CHECK
   if(((channel_primary>31)&&(channel_primary<64))||(channel_primary>95))
   {
      return(FS_ETPU_ERROR_VALUE);
   }
   #endif

   fs_etpu_set_chan_local_8(channel_primary, FS_ETPU_QD_MODE_CURRENT_OFFSET,
                            FS_ETPU_QD_MODE_SLOW);

   return(0);
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_get_pc
*PURPOSE      : This function returns the Position Counter value.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: Position Counter value.
*******************************************************************************/
int24_t fs_etpu_qd_get_pc( uint8_t channel_primary)
{
   return(fs_etpu_get_chan_local_24s(channel_primary, FS_ETPU_QD_PC_OFFSET));
}

/******************************************************************************
*FUNCTION     : fs_etpu_qd_get_pc_sc
*PURPOSE      : This function returns the Position Counter for SC value.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: Position Counter for SC value.
*******************************************************************************/
int24_t fs_etpu_qd_get_pc_sc( uint8_t channel_primary)
{
   return(fs_etpu_get_chan_local_24s(channel_primary, FS_ETPU_QD_PC_SC_OFFSET));
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_get_rc
*PURPOSE      : This function returns the Revolution Counter value.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: Revolution Counter value.
*******************************************************************************/
int24_t fs_etpu_qd_get_rc( uint8_t channel_primary)
{
   return(fs_etpu_get_chan_local_24s(channel_primary, FS_ETPU_QD_RC_OFFSET));
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_get_direction
*PURPOSE      : This function returns the motion system direction.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: The returned value can be one of:
*               0 - FS_ETPU_QD_DIRECTION_INC
*               1 - FS_ETPU_QD_DIRECTION_DEC
*******************************************************************************/
int8_t fs_etpu_qd_get_direction(uint8_t channel_primary)
{
   if ((int8_t)(fs_etpu_get_chan_local_8(channel_primary,
       FS_ETPU_QD_DIRECTION_OFFSET)) > 0)
      return(FS_ETPU_QD_DIRECTION_INC);
   else
      return(FS_ETPU_QD_DIRECTION_DEC);
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_get_mode
*PURPOSE      : This function returns the current mode of QD operation.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: The returned value can be one of:
*               1 - FS_ETPU_QD_MODE_SLOW
*               2 - FS_ETPU_QD_MODE_NORMAL
*               4 - FS_ETPU_QD_MODE_FAST
*******************************************************************************/
uint8_t fs_etpu_qd_get_mode(uint8_t channel_primary)
{
   return((uint8_t)(fs_etpu_get_chan_local_8(channel_primary,
                                        FS_ETPU_QD_MODE_CURRENT_OFFSET) & 0x7));
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_get_tcr
*PURPOSE      : This function returns the TCR time of the last detected
*               transition.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: TCR time of the last transition.
*******************************************************************************/
uint24_t fs_etpu_qd_get_tcr( uint8_t channel_primary)
{
   return(fs_etpu_get_chan_local_24(channel_primary, FS_ETPU_QD_LAST_EDGE_OFFSET));
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_get_period
*PURPOSE      : This function returns the QD period.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: QD period.
*******************************************************************************/
uint24_t fs_etpu_qd_get_period( uint8_t channel_primary)
{
   return(fs_etpu_get_chan_local_24(channel_primary, FS_ETPU_QD_PERIOD_OFFSET));
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_get_pinA
*PURPOSE      : This function returns the current state of Primary (Phase A)
*               input signal.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: State of Phase A input channel.
*******************************************************************************/
uint8_t fs_etpu_qd_get_pinA( uint8_t channel_primary)
{
   return((uint8_t)(fs_etpu_get_chan_local_8(channel_primary,
                   FS_ETPU_QD_PINS_OFFSET) & 0x1));
}

/*******************************************************************************
*FUNCTION     : fs_etpu_qd_get_pinB
*PURPOSE      : This function returns the current state of Secondary (Phase B)
*               input signal.
*INPUTS NOTES : This function has 1 parameter:
*  channel_primary - This is the Primary channel number (Phase A).
*                    0-31 for ETPU_A and 64-95 for ETPU_B.
*
*RETURNS NOTES: State of Phase B input channel.
*******************************************************************************/
uint8_t fs_etpu_qd_get_pinB( uint8_t channel_primary)
{
   return((uint8_t)((fs_etpu_get_chan_local_8(channel_primary,
                    FS_ETPU_QD_PINS_OFFSET) &  0x2) >> 1));
}


/*******************************************************************************
*=============== TPU3 API Compatibility Functions ==============================
*******************************************************************************/
#if 0
/*******************************************************************************
*FUNCTION      : tpu_fqd_init
*PURPOSE       : This routine is used to initialize a pair of eTPU channels
*                to run the QD function.
*INPUTS NOTES  : This function has 4 parameters:
*               *tpu     - This is a pointer to the TPU3 module. Not used.
*               channel  - This is the channel number of the primary QD channel.
*                          The next channel is used as the secondary.
*                          0-30 for ETPU_A and 64-94 for ETPU_B.
*               priority - This is the priority to assign to the QD function.
*                          This parameter should be assigned a value of:
*                          FS_ETPU_PRIORITY_HIGH, FS_ETPU_PRIORITY_MIDDLE,
*                          FS_ETPU_PRIORITY_LOW or FS_ETPU_PRIORITY_DISABLE.
*               init_position - This is the starting position of the counter.
*RETURNS NOTES : none
*******************************************************************************/
void tpu_fqd_init(struct TPU3_tag *tpu,
                  UINT8 channel,
                  UINT8 priority,
                  INT16 init_position)
{
   fs_etpu_qd_init( channel,
                    0,
                    0,
                    FS_ETPU_QD_PRIM_SEC,
                    priority,
                    0,
                    FS_ETPU_TCR1,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

     fs_etpu_qd_set_pc( channel,
                        init_position);
}

/*******************************************************************************
*FUNCTION      : tpu_fqd_current_mode
*PURPOSE       : This function returns the current mode of the QD channels.
*INPUTS NOTES  : This function has 2 parameters:
*                 *tpu    - This is a pointer to the TPU3 module. Not used.
*                 channel - This is the Primary or Secondary channel number.
*                           0-31 for ETPU_A and 64-95 for ETPU_B.
*RETURNS NOTES : The current mode which will be FS_ETPU_QD_MODE_NORMAL or
*                FS_ETPU_QD_MODE_FAST.
*******************************************************************************/
UINT8 tpu_fqd_current_mode(struct TPU3_tag *tpu,
                           UINT8 channel)
{
   return ((UINT8)fs_etpu_qd_get_mode(channel));
}

/*******************************************************************************
*FUNCTION      : tpu_fqd_position
*PURPOSE       : This function returns the current Position Counter value
*                of QD channels.
*INPUTS NOTES  : This function has 2 parameters:
*                 *tpu    - This is a pointer to the TPU3 module. Not used.
*                 channel - This is the Primary or Secondary channel number.
*                           0-31 for ETPU_A and 64-95 for ETPU_B.
*RETURNS NOTES : The current Position Counter value.
*******************************************************************************/
INT16 tpu_fqd_position(struct TPU3_tag *tpu,
                       UINT8 channel)
{
   return((INT16)fs_etpu_qd_get_pc(channel));
}

/*******************************************************************************
*FUNCTION      : tpu_fqd_data
*PURPOSE       : This function returns the data parameters associated with
*                the QD channels.
*INPUTS NOTES  : This function has 6 parameters:
*            *tpu           - This is a pointer to the TPU3 module. Not used.
*            channel        - This is the Primary or Secondary channel number.
*                             0-31 for ETPU_A and 64-95 for ETPU_B.
*            *tcr1          - The current Value of the TCR1 timebase.
*            *edge          - The last edge time.
*            *primary_pin   - The current state of the Primary channel, this
*                             will be TPU_FQD_PIN_HIGH or TPU_FQD_PIN_LOW.
*            *secondary_pin - The current state of the Secondary channel, this
*                             will be TPU_FQD_PIN_HIGH or TPU_FQD_PIN_LOW.
*RETURNS NOTES : none
*******************************************************************************/
void tpu_fqd_data(struct TPU3_tag *tpu,
                  UINT8 channel,
                  INT16 *tcr1,
                  INT16 *edge,
                  INT16 *primary_pin,
                  INT16 *secondary_pin)
{
   *tcr1=(INT16)(eTPU->TB1R_A.R);
   *edge=(INT16)(fs_etpu_qd_get_tcr(channel));
   *primary_pin  =(INT16)(fs_etpu_qd_get_pinA(channel));
   *secondary_pin=(INT16)(fs_etpu_qd_get_pinB(channel));
}
#endif
/*********************************************************************
 *
 * Copyright:
 *  Freescale Semiconductor, INC. All Rights Reserved.
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

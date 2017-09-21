/**************************************************************************
 *
 * Title: Functions to generate EMIOS functions
 *
 * Filename: EMIOS_library.c
 *
 *
 * First used on: MPC5554
 *
 * Compiler:
 *
 * Creation date:		03/15/06
 * $Author: r20020 $
 *
 * Copyright Freescale Semiconductor Inc
 * 2006 All Rights Reserved
 *
 * Notes :
 * <RELEVANT information only - leave blank if none>
 *
 *
 * Revision History :
 *  $Date: 2006/10/10 20:47:03 $
 *
 *
 *************************************************************************/

#include "EMIOS_library.h"

/*********************************************************************************
   Function Name :emios_init_opwfm_fnc()

   Description:To Set the initial value sof A and B registers with duty cycle and period

   Inputs: emios Channel Number, Duty cycle, Period

   Outputs: None

 **********************************************************************************/
/* set Init values for OPWFM */
void emios_init_opwfm_fnc(uint16_t emios_chan, uint32_t dutyCycle, uint32_t
  period)
{
  /* EMIOS Unified Channel Setup Mode : Pulse Width and Frequency Modulation Mode:
     In this mode, register A1 contains the duty cycle and register B1 contains the
     period of the output signal. */
  EMIOS.CH[emios_chan].CADR.R = dutyCycle;/* Channel A Data Register - CADR0   */
  EMIOS.CH[emios_chan].CBDR.R = period;/* Channel B Data Register - CBDR0   */
}

/*********************************************************************************
   Function Name :emios_gen_opwfm_fnc()

   Description:To generate Output PWM with duty cycle and period

   Inputs: emios Channel Number, Duty cycle, Period, emios Clock

   Outputs: None

 **********************************************************************************/
void emios_gen_opwfm_fnc(uint16_t emios_chan, uint32_t dutyCycle, uint32_t
  frequency, uint32_t sysClock, uint16_t prescaler)
{
  uint32_t A1;
  uint32_t B1;
  uint32_t currCounter;
  uint32_t buff = 30;                  /*Time in UC clock cycles required to complete FORCMA */
  if (dutyCycle > 99 ) {               /* Write out to A & B registers for case of 100 % dutycycle */
    EMIOS.CH[emios_chan].CADR.R = 0;   /* Write the Duty Cycle Value for the Channel */
    EMIOS.CH[emios_chan].CBDR.R = 0;   /* Write the Frequency Value for the Channel */
    EMIOS.CH[emios_chan].CCR.B.FORCMB = 1;
  } else if (dutyCycle < 1 ) {         /* Write out to A & B registers for case of 0 % dutycycle */
    EMIOS.CH[emios_chan].CADR.R = 100; /* Write the Duty Cycle Value for the Channel */
    EMIOS.CH[emios_chan].CBDR.R = 100; /* Write the Frequency Value for the Channel */
    EMIOS.CH[emios_chan].CCR.B.FORCMA = 1;
  } else {                             /* Write out to A & B registers for a dutycycle or frequency change */
    B1 = (sysClock*1000000)/(prescaler*frequency) ;
    A1 = ((dutyCycle*B1)/100) ;
    currCounter = EMIOS.CH[emios_chan].CCNTR.R ;
    if (A1 > 1)
      A1 = A1-1;                       /*Account for A reg value off by 1*/
    EMIOS.CH[emios_chan].CADR.R = A1;
    if (A1 < currCounter )             /*To prevent counter wrap condition*/
    {
      if (currCounter + buff > EMIOS.CH[emios_chan].CBDR.R ) {
      } else {
        EMIOS.CH[emios_chan].CCR.B.FORCMA = 1;
      }
    }

    if (B1 > 1)
      B1 = B1-1;                       /*Account for B reg value off by 1*/
    EMIOS.CH[emios_chan].CBDR.R = B1;
  }
}

/*********************************************************************************
   Function Name :emios_clear_interrupt_flag_fnc()

   Description:To Clear the interrupt flag

   Inputs: eMIOS Channel Number

   Outputs: None

 **********************************************************************************/
void emios_clear_interrupt_flag_fnc(uint16_t emios_chan)
{
  EMIOS.CH[emios_chan].CSR.B.FLAG = 1;
}

/*********************************************************************************
   Function Name :emios_enable_interrupt_flag_fnc()

   Description:To Enable the interrupt flag

   Inputs: eMIOS Channel Number

   Outputs: None

 **********************************************************************************/
void emios_enable_interrupt_flag_fnc(uint16_t emios_chan)
{
  EMIOS.CH[emios_chan].CCR.B.FEN = 1;
}

/*********************************************************************************
   Function Name :emios_clear_interrupt_flag_fnc()

   Description:To clear the interrupt flag

   Inputs: eMIOS Channel Number

   Outputs: None

 **********************************************************************************/
void emios_clear_interrupt_enable_fnc(uint16_t emios_chan)
{
  EMIOS.CH[emios_chan].CCR.B.FEN = 0;
}

/*********************************************************************************
   Function Name :emios_get_pulse_count_fnc()

   Description:Count the number of input pulses or edges

   Inputs: eMIOS Channel Number

   Outputs: Pulse Count

 **********************************************************************************/
uint32_t emios_get_pulse_count_fnc(uint16_t emios_chan)
{
  uint32_t count;
  count = EMIOS.CH[emios_chan].CCNTR.R;
  return(count);
}

/*********************************************************************************
   Function Name: emios_get_pulse_time_fnc()

   Description: Get the time required for a desired number of events

   Inputs: eMIOS Channel Number, max_counter, Max Counter value, System Clock, Channel Prescaler

   Outputs: Pulse Accumulated Time

 **********************************************************************************/
uint32_t emios_get_pulse_time_fnc(uint16_t emios_chan,uint32_t counter_max,
  uint32_t sysClock, uint16_t prescaler)
{
  int32_t counterDiff;
  uint32_t AReg;
  uint32_t BReg;
  uint32_t pulse_time;
  AReg = EMIOS.CH[emios_chan].CADR.R;
  BReg = EMIOS.CH[emios_chan].CBDR.R;
  counterDiff = (int32_t)(AReg - BReg);
  if (counterDiff < 0) {
    counterDiff = (int32_t)( counterDiff + counter_max);
  }

  /* calculate the Pulse Accumulation time in us */
  pulse_time = (uint32_t)((counterDiff*prescaler)/sysClock);
  return(pulse_time);
}

/*********************************************************************************
   Function Name: emios_set_counter_fnc()

   Description: To Set the Counter Bus with the Maximum value

   Inputs: emios Channel Number, Counter maximum value

   Outputs: None

 **********************************************************************************/
void emios_set_counter_fnc(uint16_t emios_chan, uint32_t counter_max)
{
  EMIOS.CH[emios_chan].CADR.R = counter_max;/* Channel A Data Register - CADR0   */
  EMIOS.CH[emios_chan].CBDR.R = 0x00000000;/* Channel  B Data Register - CBDR0   */
  EMIOS.CH[emios_chan].CCR.R = 0x0C000610;/* Channel  Control Register - CCR0 */
}

/*********************************************************************************
   Function Name :emios_get_ipwm_fnc()

   Description:To measure the width of the Input Pulse

   Inputs: emios Channel Number,Max Counter value, System Clock, Channel Prescaler

   Outputs: Return Period of the width Pulse wave in us

 **********************************************************************************/
uint32_t emios_get_ipwm_fnc(uint16_t emios_chan,uint32_t counter_max, uint32_t
  sysClock, uint16_t prescaler)
{
  int32_t counterDiff;
  uint32_t AReg;
  uint32_t BReg;
  uint32_t pWidth;
  AReg = EMIOS.CH[emios_chan].CADR.R;
  BReg = EMIOS.CH[emios_chan].CBDR.R;
  counterDiff = (int32_t)(AReg - BReg);
  if (counterDiff < 0)                 /* Errata condition rollover occured,correct pulse width */
  {
    /*Add Counter Maximum for the channelto the value before rollover */
    counterDiff = (int32_t)(counterDiff + counter_max);
  }

  /*calculate the Pulse width in us */
  pWidth = (uint32_t)((counterDiff*prescaler)/sysClock);
  return(pWidth);
}

/*********************************************************************************
   Function Name :emios_get_ipm_fnc()

   Description:To measure periodthe Input Pulse

   Inputs: emios Channel Number,Max Counter value, System Clock, Channel Prescaler

   Outputs: Return Period of the Input Pulse wave in us

 **********************************************************************************/
uint32_t emios_get_ipm_fnc(uint16_t emios_chan,uint32_t counter_max,uint32_t
  sysClock,uint16_t prescaler)
{
  int32_t counterDiff;
  uint32_t AReg;
  uint32_t BReg;
  uint32_t period;
  AReg = EMIOS.CH[emios_chan].CADR.R;
  BReg = EMIOS.CH[emios_chan].CBDR.R;
  counterDiff = (int32_t)(AReg - BReg);
  if (counterDiff < 0)                 /* Errata condition rollover occured,correct pulse width */
  {
    /*Add Counter Maximum for the channel to the value before rollover */
    counterDiff = (int32_t)(counterDiff + counter_max);
  }

  /*calculate the period in us */
  period = (uint32_t)((counterDiff*prescaler)/sysClock);
  return(period);
}

/*********************************************************************************
   Function Name :emios_ch_trigger()

   Description:To set the A and B registers after initialisation

   Inputs: emios Channel Number,A register value, B register value

   Outputs: None

 **********************************************************************************/
void emios_ch_trigger(unsigned int emios_chan, unsigned int regA, unsigned int
                      regB)
{
  EMIOS.CH[emios_chan].CADR.R = regA;  /* Channel 2 A Data Register */
  EMIOS.CH[emios_chan].CBDR.R = regB;  /* Channel 2 B Data Register */
}

/**************************************************************************
 *
 * Title: Declarations for EMIOS_library.c file and EMIOS Registers
 *
 * Filename: EMIOS_library.h
 *
 *
 * First used on: MPC5554
 *
 * Compiler:
 *
 * Creation date:		03/15/06
 * Date last modified:	$Author: r20020 $
 *
 *
 *
 * Notes :
 * <RELEVANT information only - leave blank if none>
 *
 *
 * Revision History :
 *
 *
 *
 *************************************************************************/

#ifndef _EMIOS_LIBRARY_H
#define _EMIOS_LIBRARY_H
#include "RAppID_Blockset.h"

/* set Init values for OPWFM */
void emios_init_opwfm_fnc(uint16_t emios_chan, uint32_t dutyCycle, uint32_t
  period);

/* Generate Output PWM  */
void emios_gen_opwfm_fnc(uint16_t emios_chan, uint32_t dutyCycle, uint32_t
  frequency, uint32_t sysClock, uint16_t prescaler);

/* Generate Output PWM with immediate update  */
void immediateupdate_emios_gen_opwfm_fnc(uint16_t emios_chan, uint32_t dutyCycle,
  uint32_t
  frequency, uint32_t sysClock, uint16_t prescaler);

/* Measure the Input Pulse Width  */
uint32_t emios_get_ipwm_fnc(uint16_t emios_chan,uint32_t counter_max,uint32_t
  sysClock, uint16_t
  prescaler);

/* Measure the Input Pulse Period  */
uint32_t emios_get_ipm_fnc(uint16_t emios_chan,uint32_t counter_max, uint32_t
  sysClock,uint16_t prescaler);

/* Set the Counter Bus with the Maximum value  */
void emios_set_counter_fnc(uint16_t emios_chan, uint32_t counter_max);

/* Clear the interrupt flag  */
void emios_clear_interrupt_flag_fnc(uint16_t emios_chan);

/* Count the number of input pulses or edges  */
uint32_t emios_get_pulse_count_fnc(uint16_t emios_chan);

/* Measure the Input Pulse Accumulated Time  */
uint32_t emios_get_pulse_time_fnc(uint16_t emios_chan,uint32_t counter_max,
  uint32_t sysClock, uint16_t prescaler);

/* Enable the the interrupt on Flag set Event */
void emios_enable_interrupt_flag_fnc(uint16_t emios_chan);

/* Clear the the interrupt on Flag set Event */
void emios_clear_interrupt_enable_fnc(uint16_t emios_chan);

/* Trigger the channel with A and B register values */
void emios_ch_trigger(unsigned int emios_chan, unsigned int regA, unsigned int
                      regB);

#endif

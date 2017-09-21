/*
 * File: two_virtual_wheel_autocode_data.c
 *
 * Code generated for Simulink model 'two_virtual_wheel_autocode'.
 *
 * Model version                  : 1.93
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Thu Sep 21 16:08:25 2017
 *
 * Target selection: rappid.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "two_virtual_wheel_autocode.h"
#include "two_virtual_wheel_autocode_private.h"

/* Block parameters (auto storage) */
Parameters_two_virtual_wheel_au two_virtual_wheel_autocode_P = {
  -45.0,                               /* Expression: -45
                                        * Referenced by: '<Root>/Constant5'
                                        */
  45.0,                                /* Expression: 45
                                        * Referenced by: '<Root>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S6>/Constant'
                                        */
  0.76,                                /* Expression: 0.76
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.24,                                /* Expression: 0.24
                                        * Referenced by: '<Root>/Saturation'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/Gain'
                                        */
  40000.0,                             /* Expression: 40000
                                        * Referenced by: '<Root>/Constant2'
                                        */
  0.002F,                              /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                        * Referenced by: '<S2>/Discrete-Time Integrator2'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<S2>/Discrete-Time Integrator2'
                                        */
  7.5F,                                /* Computed Parameter: springconstant2_Gain
                                        * Referenced by: '<S2>/spring  constant2'
                                        */
  0.002F,                              /* Computed Parameter: DiscreteTimeIntegrator3_gainval
                                        * Referenced by: '<S2>/Discrete-Time Integrator3'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator3_IC
                                        * Referenced by: '<S2>/Discrete-Time Integrator3'
                                        */
  0.015F,                              /* Computed Parameter: damping4_Gain
                                        * Referenced by: '<S2>/damping4'
                                        */
  533.333313F,                         /* Computed Parameter: virtualinertia2_Gain
                                        * Referenced by: '<S2>/1//virtual inertia2'
                                        */
  0.02F,                               /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S5>/Discrete-Time Integrator1'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                        * Referenced by: '<S5>/Discrete-Time Integrator1'
                                        */
  7.5F,                                /* Computed Parameter: springconstant1_Gain
                                        * Referenced by: '<S5>/spring  constant1'
                                        */
  0.02F,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  0.0F,                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  0.15F,                               /* Computed Parameter: damping1_Gain
                                        * Referenced by: '<S5>/damping1'
                                        */
  5.33333349F,                         /* Computed Parameter: virtualinertia1_Gain
                                        * Referenced by: '<S5>/1//virtual inertia1'
                                        */
  0.0F,                                /* Computed Parameter: RateTransition1_X0
                                        * Referenced by: '<Root>/Rate Transition1'
                                        */
  0.09F,                               /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S1>/Gain'
                                        */
  0.0F,                                /* Computed Parameter: UnitDelay1_X0
                                        * Referenced by: '<S1>/Unit Delay1'
                                        */
  -0.000311F,                          /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S6>/Gain'
                                        */
  45,                                  /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<Root>/Switch'
                                        */
  -45,                                 /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<Root>/Switch1'
                                        */
  50U,                                 /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  1000000U,                            /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<Root>/Constant'
                                        */
  50U,                                 /* Expression: uint32(A_init)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  1000000U,                            /* Expression: uint32(B_init)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  128U,                                /* Expression: uint32(clock)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  1000U,                               /* Expression: uint32(speed_max_rpm)
                                        * Referenced by: '<S7>/eTPU Quadrature Decoder'
                                        */
  4000U,                               /* Expression: uint32(pcincrements_per_rev)
                                        * Referenced by: '<S7>/eTPU Quadrature Decoder'
                                        */
  50U,                                 /* Expression: uint32(A_init)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  40000U,                              /* Expression: uint32(B_init)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  128U,                                /* Expression: uint32(clock)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  13U,                                 /* Expression: uint16(channelNo)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  12U,                                 /* Expression: uint16(emios_chan)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  1U,                                  /* Expression: uint16(prescaler)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  0U,                                  /* Computed Parameter: UnitDelay_X0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  1U,                                  /* Expression: uint16(channelNo)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  0U,                                  /* Expression: uint16(emios_chan)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  1U,                                  /* Expression: uint16(prescaler)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  109U,                                /* Computed Parameter: GeneralPurposeOutput_P1
                                        * Referenced by: '<S3>/General Purpose Output'
                                        */
  205U,                                /* Expression: uint16(pinNum)
                                        * Referenced by: '<S3>/General Purpose Output'
                                        */
  1U,                                  /* Expression: uint8(etpu)
                                        * Referenced by: '<S7>/eTPU Quadrature Decoder'
                                        */
  4U,                                  /* Expression: uint8(chan)
                                        * Referenced by: '<S7>/eTPU Quadrature Decoder'
                                        */
  4U,                                  /* Expression: uint8(pcscaling)
                                        * Referenced by: '<S7>/eTPU Quadrature Decoder'
                                        */
  0                                    /* Computed Parameter: Constant_Value_hq
                                        * Referenced by: '<S3>/Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

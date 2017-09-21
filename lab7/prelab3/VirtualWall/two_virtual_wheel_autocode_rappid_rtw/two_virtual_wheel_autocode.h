/*
 * File: two_virtual_wheel_autocode.h
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

#ifndef RTW_HEADER_two_virtual_wheel_autocode_h_
#define RTW_HEADER_two_virtual_wheel_autocode_h_
#ifndef two_virtual_wheel_autocode_COMMON_INCLUDES_
# define two_virtual_wheel_autocode_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* two_virtual_wheel_autocode_COMMON_INCLUDES_ */

#include "two_virtual_wheel_autocode_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T RateTransition1;            /* '<Root>/Rate Transition1' */
  real32_T RateTransition;             /* '<Root>/Rate Transition' */
  int32_T eTPUQuadratureDecoder_o1;    /* '<S7>/eTPU Quadrature Decoder' */
  int32_T eTPUQuadratureDecoder_o2;    /* '<S7>/eTPU Quadrature Decoder' */
  uint32_T DataTypeConversion3;        /* '<Root>/Data Type Conversion3' */
  uint32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  int8_T eTPUQuadratureDecoder_o3;     /* '<S7>/eTPU Quadrature Decoder' */
} BlockIO_two_virtual_wheel_autoc;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay1_DSTATE;          /* '<S1>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S5>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S5>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S2>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3_DSTATE;/* '<S2>/Discrete-Time Integrator3' */
  real32_T RateTransition1_Buffer0;    /* '<Root>/Rate Transition1' */
  uint32_T FastDynamics_ELAPS_T;       /* '<Root>/FastDynamics' */
  uint32_T FastDynamics_PREV_T;        /* '<Root>/FastDynamics' */
  uint32_T SlowDynamics_ELAPS_T;       /* '<Root>/SlowDynamics' */
  uint32_T SlowDynamics_PREV_T;        /* '<Root>/SlowDynamics' */
  uint16_T UnitDelay_DSTATE;           /* '<S1>/Unit Delay' */
} D_Work_two_virtual_wheel_autoco;

/* Parameters (auto storage) */
struct Parameters_two_virtual_wheel_au_ {
  real_T Constant5_Value;              /* Expression: -45
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant3_Value;              /* Expression: 45
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant_Value;               /* Expression: 0.5
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.76
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0.24
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant2_Value;              /* Expression: 40000
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real32_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                            * Referenced by: '<S2>/Discrete-Time Integrator2'
                                            */
  real32_T DiscreteTimeIntegrator2_IC; /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                        * Referenced by: '<S2>/Discrete-Time Integrator2'
                                        */
  real32_T springconstant2_Gain;       /* Computed Parameter: springconstant2_Gain
                                        * Referenced by: '<S2>/spring  constant2'
                                        */
  real32_T DiscreteTimeIntegrator3_gainval;/* Computed Parameter: DiscreteTimeIntegrator3_gainval
                                            * Referenced by: '<S2>/Discrete-Time Integrator3'
                                            */
  real32_T DiscreteTimeIntegrator3_IC; /* Computed Parameter: DiscreteTimeIntegrator3_IC
                                        * Referenced by: '<S2>/Discrete-Time Integrator3'
                                        */
  real32_T damping4_Gain;              /* Computed Parameter: damping4_Gain
                                        * Referenced by: '<S2>/damping4'
                                        */
  real32_T virtualinertia2_Gain;       /* Computed Parameter: virtualinertia2_Gain
                                        * Referenced by: '<S2>/1//virtual inertia2'
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                            * Referenced by: '<S5>/Discrete-Time Integrator1'
                                            */
  real32_T DiscreteTimeIntegrator1_IC; /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                        * Referenced by: '<S5>/Discrete-Time Integrator1'
                                        */
  real32_T springconstant1_Gain;       /* Computed Parameter: springconstant1_Gain
                                        * Referenced by: '<S5>/spring  constant1'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                           * Referenced by: '<S5>/Discrete-Time Integrator'
                                           */
  real32_T DiscreteTimeIntegrator_IC;  /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  real32_T damping1_Gain;              /* Computed Parameter: damping1_Gain
                                        * Referenced by: '<S5>/damping1'
                                        */
  real32_T virtualinertia1_Gain;       /* Computed Parameter: virtualinertia1_Gain
                                        * Referenced by: '<S5>/1//virtual inertia1'
                                        */
  real32_T RateTransition1_X0;         /* Computed Parameter: RateTransition1_X0
                                        * Referenced by: '<Root>/Rate Transition1'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S1>/Gain'
                                        */
  real32_T UnitDelay1_X0;              /* Computed Parameter: UnitDelay1_X0
                                        * Referenced by: '<S1>/Unit Delay1'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S6>/Gain'
                                        */
  int32_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<Root>/Switch'
                                        */
  int32_T Switch1_Threshold;           /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<Root>/Switch1'
                                        */
  uint32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  uint32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint32_T EMIOSOutputPWM_P3;          /* Expression: uint32(A_init)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  uint32_T EMIOSOutputPWM_P4;          /* Expression: uint32(B_init)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  uint32_T EMIOSOutputPWM_P5;          /* Expression: uint32(clock)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  uint32_T eTPUQuadratureDecoder_P3;   /* Expression: uint32(speed_max_rpm)
                                        * Referenced by: '<S7>/eTPU Quadrature Decoder'
                                        */
  uint32_T eTPUQuadratureDecoder_P4;   /* Expression: uint32(pcincrements_per_rev)
                                        * Referenced by: '<S7>/eTPU Quadrature Decoder'
                                        */
  uint32_T EMIOSOutputPWM1_P3;         /* Expression: uint32(A_init)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  uint32_T EMIOSOutputPWM1_P4;         /* Expression: uint32(B_init)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  uint32_T EMIOSOutputPWM1_P5;         /* Expression: uint32(clock)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  uint16_T EMIOSOutputPWM_P1;          /* Expression: uint16(channelNo)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  uint16_T EMIOSOutputPWM_P2;          /* Expression: uint16(emios_chan)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  uint16_T EMIOSOutputPWM_P6;          /* Expression: uint16(prescaler)
                                        * Referenced by: '<Root>/EMIOS Output PWM'
                                        */
  uint16_T UnitDelay_X0;               /* Computed Parameter: UnitDelay_X0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  uint16_T EMIOSOutputPWM1_P1;         /* Expression: uint16(channelNo)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  uint16_T EMIOSOutputPWM1_P2;         /* Expression: uint16(emios_chan)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  uint16_T EMIOSOutputPWM1_P6;         /* Expression: uint16(prescaler)
                                        * Referenced by: '<Root>/EMIOS Output PWM1'
                                        */
  uint16_T GeneralPurposeOutput_P1;    /* Computed Parameter: GeneralPurposeOutput_P1
                                        * Referenced by: '<S3>/General Purpose Output'
                                        */
  uint16_T GeneralPurposeOutput_P2;    /* Expression: uint16(pinNum)
                                        * Referenced by: '<S3>/General Purpose Output'
                                        */
  uint8_T eTPUQuadratureDecoder_P1;    /* Expression: uint8(etpu)
                                        * Referenced by: '<S7>/eTPU Quadrature Decoder'
                                        */
  uint8_T eTPUQuadratureDecoder_P2;    /* Expression: uint8(chan)
                                        * Referenced by: '<S7>/eTPU Quadrature Decoder'
                                        */
  uint8_T eTPUQuadratureDecoder_P5;    /* Expression: uint8(pcscaling)
                                        * Referenced by: '<S7>/eTPU Quadrature Decoder'
                                        */
  boolean_T Constant_Value_hq;         /* Computed Parameter: Constant_Value_hq
                                        * Referenced by: '<S3>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_two_virtual_wheel_auto {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_two_virtual_wheel_au two_virtual_wheel_autocode_P;

/* Block signals (auto storage) */
extern BlockIO_two_virtual_wheel_autoc two_virtual_wheel_autocode_B;

/* Block states (auto storage) */
extern D_Work_two_virtual_wheel_autoco two_virtual_wheel_autocod_DWork;

/* External function called from main */
extern void two_virtual_wheel_autocode_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void two_virtual_wheel_autocode_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void two_virtual_wheel_autocode_initialize(boolean_T firstTime);
extern void two_virtual_wheel_autocode_step(int_T tid);
extern void two_virtual_wheel_autocode_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_two_virtual_wheel_auto *const
  two_virtual_wheel_autocode_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'two_virtual_wheel_autocode'
 * '<S1>'   : 'two_virtual_wheel_autocode/ConversionSystem'
 * '<S2>'   : 'two_virtual_wheel_autocode/FastDynamics'
 * '<S3>'   : 'two_virtual_wheel_autocode/GPIO Blocks'
 * '<S4>'   : 'two_virtual_wheel_autocode/RAppID-EC'
 * '<S5>'   : 'two_virtual_wheel_autocode/SlowDynamics'
 * '<S6>'   : 'two_virtual_wheel_autocode/Subsystem'
 * '<S7>'   : 'two_virtual_wheel_autocode/eTPU Blocks'
 */
#endif                                 /* RTW_HEADER_two_virtual_wheel_autocode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

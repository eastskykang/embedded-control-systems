/*
 * File: two_virtual_wheel_autocode.c
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

/* Block signals (auto storage) */
BlockIO_two_virtual_wheel_autoc two_virtual_wheel_autocode_B;

/* Block states (auto storage) */
D_Work_two_virtual_wheel_autoco two_virtual_wheel_autocod_DWork;

/* Real-time model */
RT_MODEL_two_virtual_wheel_auto two_virtual_wheel_autocode_M_;
RT_MODEL_two_virtual_wheel_auto *const two_virtual_wheel_autocode_M =
  &two_virtual_wheel_autocode_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void two_virtual_wheel_autocode_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(two_virtual_wheel_autocode_M, 1));
}

/* rate_monotonic_scheduler */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  two_virtual_wheel_autocode_M->Timing.RateInteraction.TID0_1 =
    (two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1])++;
  if ((two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.02s, 0.0s] */
    two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void two_virtual_wheel_autocode_step0(void) /* Sample time: [0.002s, 0.0s] */
{
  uint16_T rtb_DataTypeConversion;
  real32_T rtb_Sum1;
  real32_T Sum;
  real_T tmp;
  real_T u;

  {                                    /* Sample time: [0.002s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (SFunc_EMIOS_opwfm): '<Root>/EMIOS Output PWM' */

  /*Generate the Output PWM*/
  emios_gen_opwfm_fnc(12, two_virtual_wheel_autocode_P.Constant1_Value,
                      two_virtual_wheel_autocode_P.Constant_Value_h, 128,1);

  /* RateTransition: '<Root>/Rate Transition1' */
  if (two_virtual_wheel_autocode_M->Timing.RateInteraction.TID0_1) {
    two_virtual_wheel_autocode_B.RateTransition1 =
      two_virtual_wheel_autocod_DWork.RateTransition1_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* S-Function (SFunc_eTPU_quadraturedecoder): '<S7>/eTPU Quadrature Decoder' */
  {
    two_virtual_wheel_autocode_B.eTPUQuadratureDecoder_o1 = (int32_t)
      ((fs_etpu_qd_get_pc(3)*4)/4);
    if (fs_etpu_qd_get_period(3)==0) {
      two_virtual_wheel_autocode_B.eTPUQuadratureDecoder_o2 = 0;
    } else {
      two_virtual_wheel_autocode_B.eTPUQuadratureDecoder_o2 = (int32_t) ((60 *
        3.2E+7)/(fs_etpu_qd_get_period(3) * (4000/4)));/* lines on motor = pcincrements_per_rev/4 */
    }

    two_virtual_wheel_autocode_B.eTPUQuadratureDecoder_o3 = (int8_t)
      fs_etpu_qd_get_direction(3);
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   */
  if (two_virtual_wheel_autocode_B.eTPUQuadratureDecoder_o1 >=
      two_virtual_wheel_autocode_P.Switch_Threshold) {
    u = two_virtual_wheel_autocode_P.Constant3_Value;
  } else {
    u = two_virtual_wheel_autocode_P.Constant4_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */
  if (two_virtual_wheel_autocode_B.eTPUQuadratureDecoder_o1 >=
      two_virtual_wheel_autocode_P.Switch1_Threshold) {
    tmp = two_virtual_wheel_autocode_P.Constant4_Value;
  } else {
    tmp = two_virtual_wheel_autocode_P.Constant5_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Sum: '<Root>/Sum'
   */
  u = floor(u + tmp);
  if (rtIsNaN(u) || rtIsInf(u)) {
    u = 0.0;
  } else {
    u = fmod(u, 65536.0);
  }

  rtb_DataTypeConversion = (uint16_T)(u < 0.0 ? (uint16_T)(int32_T)(int16_T)
    -(int16_T)(uint16_T)-u : (uint16_T)u);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* Sum: '<S1>/Sum1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  Gain: '<S1>/Gain'
   *  Sum: '<S1>/Sum'
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  rtb_Sum1 = (real32_T)(int16_T)(uint16_T)(rtb_DataTypeConversion -
    two_virtual_wheel_autocod_DWork.UnitDelay_DSTATE) *
    two_virtual_wheel_autocode_P.Gain_Gain_m +
    two_virtual_wheel_autocod_DWork.UnitDelay1_DSTATE;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/FastDynamics'
   */
  two_virtual_wheel_autocod_DWork.FastDynamics_ELAPS_T =
    two_virtual_wheel_autocode_M->Timing.clockTick0 -
    two_virtual_wheel_autocod_DWork.FastDynamics_PREV_T;
  two_virtual_wheel_autocod_DWork.FastDynamics_PREV_T =
    two_virtual_wheel_autocode_M->Timing.clockTick0;

  /* Sum: '<S2>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator2'
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator3'
   *  Gain: '<S2>/damping4'
   *  Gain: '<S2>/spring  constant2'
   *  Sum: '<S2>/Sum1'
   */
  Sum = (rtb_Sum1 -
         two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator2_DSTATE) *
    two_virtual_wheel_autocode_P.springconstant2_Gain -
    two_virtual_wheel_autocode_P.damping4_Gain *
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator3'
   */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator2_DSTATE = (real32_T)
    ((real_T)two_virtual_wheel_autocode_P.DiscreteTimeIntegrator2_gainval *
     (real_T)two_virtual_wheel_autocod_DWork.FastDynamics_ELAPS_T)
    * two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator3_DSTATE +
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator2_DSTATE;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator3' incorporates:
   *  Gain: '<S2>/1//virtual inertia2'
   */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator3_DSTATE = (real32_T)
    ((real_T)two_virtual_wheel_autocode_P.DiscreteTimeIntegrator3_gainval *
     (real_T)two_virtual_wheel_autocod_DWork.FastDynamics_ELAPS_T)
    * (two_virtual_wheel_autocode_P.virtualinertia2_Gain * Sum) +
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S6>/Gain'
   *  Sum: '<Root>/Sum4'
   */
  u = (real_T)(((0.0F - two_virtual_wheel_autocode_B.RateTransition1) - Sum) *
               two_virtual_wheel_autocode_P.Gain_Gain_a) +
    two_virtual_wheel_autocode_P.Constant_Value;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Gain: '<Root>/Gain'
   *  Saturate: '<Root>/Saturation'
   */
  u = floor((u >= two_virtual_wheel_autocode_P.Saturation_UpperSat ?
             two_virtual_wheel_autocode_P.Saturation_UpperSat : u <=
             two_virtual_wheel_autocode_P.Saturation_LowerSat ?
             two_virtual_wheel_autocode_P.Saturation_LowerSat : u) *
            two_virtual_wheel_autocode_P.Gain_Gain);
  if (rtIsNaN(u) || rtIsInf(u)) {
    u = 0.0;
  } else {
    u = fmod(u, 4.294967296E+9);
  }

  two_virtual_wheel_autocode_B.DataTypeConversion3 = u < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-u : (uint32_T)u;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  u = floor(two_virtual_wheel_autocode_P.Constant2_Value);
  if (rtIsNaN(u) || rtIsInf(u)) {
    u = 0.0;
  } else {
    u = fmod(u, 4.294967296E+9);
  }

  two_virtual_wheel_autocode_B.DataTypeConversion2 = u < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-u : (uint32_T)u;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */

  /* S-Function (SFunc_EMIOS_opwfm): '<Root>/EMIOS Output PWM1' */

  /*Generate the Output PWM*/
  emios_gen_opwfm_fnc(0, two_virtual_wheel_autocode_B.DataTypeConversion3,
                      two_virtual_wheel_autocode_B.DataTypeConversion2, 128,1);

  /* RateTransition: '<Root>/Rate Transition' */
  if (two_virtual_wheel_autocode_M->Timing.RateInteraction.TID0_1) {
    two_virtual_wheel_autocode_B.RateTransition = rtb_Sum1;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* S-Function (SFunc_GPIO_output): '<S3>/General Purpose Output' */

  /* Pin Data Output Signal */
  gpo_writedata_fnc(205, two_virtual_wheel_autocode_P.Constant_Value_hq);/* GPIO Pin Data Output Registers */

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  two_virtual_wheel_autocod_DWork.UnitDelay_DSTATE = rtb_DataTypeConversion;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  two_virtual_wheel_autocod_DWork.UnitDelay1_DSTATE = rtb_Sum1;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.002, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  two_virtual_wheel_autocode_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void two_virtual_wheel_autocode_step1(void) /* Sample time: [0.02s, 0.0s] */
{
  real32_T Sum;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  SubSystem: '<Root>/SlowDynamics'
   */
  two_virtual_wheel_autocod_DWork.SlowDynamics_ELAPS_T =
    two_virtual_wheel_autocode_M->Timing.clockTick1 -
    two_virtual_wheel_autocod_DWork.SlowDynamics_PREV_T;
  two_virtual_wheel_autocod_DWork.SlowDynamics_PREV_T =
    two_virtual_wheel_autocode_M->Timing.clockTick1;

  /* Sum: '<S5>/Sum2' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
   *  Gain: '<S5>/damping1'
   *  Gain: '<S5>/spring  constant1'
   *  Sum: '<S5>/Sum'
   */
  Sum = (two_virtual_wheel_autocode_B.RateTransition -
         two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator1_DSTATE) *
    two_virtual_wheel_autocode_P.springconstant1_Gain -
    two_virtual_wheel_autocode_P.damping1_Gain *
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator1_DSTATE = (real32_T)
    ((real_T)two_virtual_wheel_autocode_P.DiscreteTimeIntegrator1_gainval *
     (real_T)two_virtual_wheel_autocod_DWork.SlowDynamics_ELAPS_T)
    * two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator_DSTATE +
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S5>/1//virtual inertia1'
   */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator_DSTATE = (real32_T)
    ((real_T)two_virtual_wheel_autocode_P.DiscreteTimeIntegrator_gainval *
     (real_T)two_virtual_wheel_autocod_DWork.SlowDynamics_ELAPS_T)
    * (two_virtual_wheel_autocode_P.virtualinertia1_Gain * Sum) +
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Update for RateTransition: '<Root>/Rate Transition1' */
  two_virtual_wheel_autocod_DWork.RateTransition1_Buffer0 = Sum;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  two_virtual_wheel_autocode_M->Timing.clockTick1++;
}

void two_virtual_wheel_autocode_step(int_T tid)
{
  switch (tid) {
   case 0 :
    two_virtual_wheel_autocode_step0();
    break;

   case 1 :
    two_virtual_wheel_autocode_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void two_virtual_wheel_autocode_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)two_virtual_wheel_autocode_M, 0,
                sizeof(RT_MODEL_two_virtual_wheel_auto));

  /* block I/O */
  (void) memset(((void *) &two_virtual_wheel_autocode_B), 0,
                sizeof(BlockIO_two_virtual_wheel_autoc));

  {
    two_virtual_wheel_autocode_B.RateTransition1 = 0.0F;
    two_virtual_wheel_autocode_B.RateTransition = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&two_virtual_wheel_autocod_DWork, 0,
                sizeof(D_Work_two_virtual_wheel_autoco));
  two_virtual_wheel_autocod_DWork.UnitDelay1_DSTATE = 0.0F;
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator_DSTATE = 0.0F;
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator2_DSTATE = 0.0F;
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator3_DSTATE = 0.0F;
  two_virtual_wheel_autocod_DWork.RateTransition1_Buffer0 = 0.0F;

  /* Start for S-Function (rappid_ec): '<S4>/S-Function' */
  sys_init_rp();

  /* Start for S-Function (SFunc_EMIOS_opwfm): '<Root>/EMIOS Output PWM' */
  emios_init_opwfm_fnc(12, 50, 1000000);/* Set the initial Duty cycle and Frequency */

  /* Start for RateTransition: '<Root>/Rate Transition1' */
  two_virtual_wheel_autocode_B.RateTransition1 =
    two_virtual_wheel_autocode_P.RateTransition1_X0;

  /* Start for S-Function (SFunc_EMIOS_opwfm): '<Root>/EMIOS Output PWM1' */
  emios_init_opwfm_fnc(0, 50, 40000);  /* Set the initial Duty cycle and Frequency */

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition1' */
  two_virtual_wheel_autocod_DWork.RateTransition1_Buffer0 =
    two_virtual_wheel_autocode_P.RateTransition1_X0;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  two_virtual_wheel_autocod_DWork.UnitDelay_DSTATE =
    two_virtual_wheel_autocode_P.UnitDelay_X0;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay1' */
  two_virtual_wheel_autocod_DWork.UnitDelay1_DSTATE =
    two_virtual_wheel_autocode_P.UnitDelay1_X0;

  /* InitializeConditions for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/FastDynamics'
   */
  two_virtual_wheel_autocod_DWork.FastDynamics_PREV_T =
    two_virtual_wheel_autocode_M->Timing.clockTick0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator2' */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator2_DSTATE =
    two_virtual_wheel_autocode_P.DiscreteTimeIntegrator2_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator3' */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator3_DSTATE =
    two_virtual_wheel_autocode_P.DiscreteTimeIntegrator3_IC;

  /* InitializeConditions for S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/SlowDynamics'
   */
  two_virtual_wheel_autocod_DWork.SlowDynamics_PREV_T =
    two_virtual_wheel_autocode_M->Timing.clockTick1;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator1_DSTATE =
    two_virtual_wheel_autocode_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator_DSTATE =
    two_virtual_wheel_autocode_P.DiscreteTimeIntegrator_IC;
}

/* Model terminate function */
void two_virtual_wheel_autocode_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

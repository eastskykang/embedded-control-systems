/*
 * File: VirtualWall.c
 *
 * Code generated for Simulink model 'VirtualWall'.
 *
 * Model version                  : 1.49
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Thu Sep 21 14:29:55 2017
 *
 * Target selection: rappid.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VirtualWall.h"
#include "VirtualWall_private.h"

/* Named constants for Chart: '<S5>/VirtualWall_Chart' */
#define VirtualWall_IN_Inside_Wall     (1U)
#define VirtualWall_IN_Outside_Wall    (2U)

/* Block signals (auto storage) */
BlockIO_VirtualWall VirtualWall_B;

/* Block states (auto storage) */
D_Work_VirtualWall VirtualWall_DWork;

/* Real-time model */
RT_MODEL_VirtualWall VirtualWall_M_;
RT_MODEL_VirtualWall *const VirtualWall_M = &VirtualWall_M_;

/* Model step function */
void VirtualWall_step(void)
{
  uint16_T rtb_DataTypeConversion;
  real32_T rtb_Sum1;
  real_T u;

  /* S-Function (SFunc_EMIOS_opwfm): '<Root>/EMIOS Output PWM' */

  /*Generate the Output PWM*/
  emios_gen_opwfm_fnc(12, 50U, 1000000U, 128,1);

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/VirtualWallTask'
   */

  /* S-Function (SFunc_eTPU_quadraturedecoder): '<S7>/eTPU Quadrature Decoder' */
  {
    VirtualWall_B.eTPUQuadratureDecoder_o1 = (int32_t) ((fs_etpu_qd_get_pc(3)*4)/
      4);
    if (fs_etpu_qd_get_period(3)==0) {
      VirtualWall_B.eTPUQuadratureDecoder_o2 = 0;
    } else {
      VirtualWall_B.eTPUQuadratureDecoder_o2 = (int32_t) ((60 * 3.2E+7)/
        (fs_etpu_qd_get_period(3) * (4000/4)));/* lines on motor = pcincrements_per_rev/4 */
    }

    VirtualWall_B.eTPUQuadratureDecoder_o3 = (int8_t) fs_etpu_qd_get_direction(3);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  rtb_DataTypeConversion = (uint16_T)VirtualWall_B.eTPUQuadratureDecoder_o1;

  /* Sum: '<S4>/Sum1' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion1'
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   *  Gain: '<S4>/Gain'
   *  Sum: '<S4>/Sum'
   *  UnitDelay: '<S4>/Unit Delay'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  rtb_Sum1 = (real32_T)(int16_T)(uint16_T)(rtb_DataTypeConversion -
    VirtualWall_DWork.UnitDelay_DSTATE) * 0.09F +
    VirtualWall_DWork.UnitDelay1_DSTATE;

  /* Chart: '<S5>/VirtualWall_Chart' */
  /* Gateway: VirtualWallTask/Simulate Virtual Wall/VirtualWall_Chart */
  /* During: VirtualWallTask/Simulate Virtual Wall/VirtualWall_Chart */
  if (VirtualWall_DWork.is_active_c2_VirtualWall == 0U) {
    /* Entry: VirtualWallTask/Simulate Virtual Wall/VirtualWall_Chart */
    VirtualWall_DWork.is_active_c2_VirtualWall = 1U;

    /* Transition: '<S8>:9' */
    VirtualWall_DWork.is_c2_VirtualWall = VirtualWall_IN_Outside_Wall;
  } else {
    switch (VirtualWall_DWork.is_c2_VirtualWall) {
     case VirtualWall_IN_Inside_Wall:
      /* During 'Inside_Wall': '<S8>:2' */
      if (rtb_Sum1 < 0.0F) {
        /* Transition: '<S8>:4' */
        VirtualWall_DWork.is_c2_VirtualWall = VirtualWall_IN_Outside_Wall;
      } else {
        VirtualWall_B.torque = -VirtualWall_DWork.k * (real_T)rtb_Sum1;
      }
      break;

     case VirtualWall_IN_Outside_Wall:
      /* During 'Outside_Wall': '<S8>:1' */
      if (rtb_Sum1 > 0.0F) {
        /* Transition: '<S8>:6' */
        VirtualWall_DWork.is_c2_VirtualWall = VirtualWall_IN_Inside_Wall;
      } else {
        VirtualWall_B.torque = 0.0;
      }
      break;

     default:
      /* Transition: '<S8>:9' */
      VirtualWall_DWork.is_c2_VirtualWall = VirtualWall_IN_Outside_Wall;
      break;
    }
  }

  /* End of Chart: '<S5>/VirtualWall_Chart' */

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S6>/Gain'
   *  Saturate: '<S5>/Saturation1'
   */
  u = (VirtualWall_B.torque >= 835.0 ? 835.0 : VirtualWall_B.torque <= -835.0 ?
       -835.0 : VirtualWall_B.torque) * 0.000311 + 0.5;

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  Gain: '<S3>/Gain'
   *  Saturate: '<S3>/Saturation'
   */
  u = floor((u >= 0.76 ? 0.76 : u <= 0.24 ? 0.24 : u) * 100.0);
  if (rtIsNaN(u) || rtIsInf(u)) {
    u = 0.0;
  } else {
    u = fmod(u, 4.294967296E+9);
  }

  VirtualWall_B.DataTypeConversion1 = (uint32_T)u;

  /* End of DataTypeConversion: '<S3>/Data Type Conversion1' */

  /* S-Function (SFunc_EMIOS_opwfm): '<S3>/EMIOS Output PWM' */

  /*Generate the Output PWM*/
  emios_gen_opwfm_fnc(0, VirtualWall_B.DataTypeConversion1,
                      VirtualWall_ConstB.DataTypeConversion, 128,1);

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  VirtualWall_DWork.UnitDelay_DSTATE = rtb_DataTypeConversion;

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  VirtualWall_DWork.UnitDelay1_DSTATE = rtb_Sum1;

  /* S-Function (SFunc_GPIO_output): '<S1>/General Purpose Output' */

  /* Pin Data Output Signal */
  gpo_writedata_fnc(205, FALSE);       /* GPIO Pin Data Output Registers */
}

/* Model initialize function */
void VirtualWall_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(VirtualWall_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &VirtualWall_B), 0,
                sizeof(BlockIO_VirtualWall));

  /* states (dwork) */
  (void) memset((void *)&VirtualWall_DWork, 0,
                sizeof(D_Work_VirtualWall));

  /* Start for S-Function (rappid_ec): '<S2>/S-Function' */
  sys_init_rp();

  /* Start for S-Function (SFunc_EMIOS_opwfm): '<Root>/EMIOS Output PWM' */
  emios_init_opwfm_fnc(12, 50, 1000000);/* Set the initial Duty cycle and Frequency */

  /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<Root>/VirtualWallTask'
   */
  /* Start for S-Function (SFunc_EMIOS_opwfm): '<S3>/EMIOS Output PWM' */
  emios_init_opwfm_fnc(0, 50, 40000);  /* Set the initial Duty cycle and Frequency */

  /* InitializeConditions for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/VirtualWallTask'
   */
  /* InitializeConditions for Chart: '<S5>/VirtualWall_Chart' */
  VirtualWall_DWork.is_active_c2_VirtualWall = 0U;
  VirtualWall_DWork.is_c2_VirtualWall = 0U;
  VirtualWall_DWork.k = -100.0;
  VirtualWall_B.torque = 0.0;
}

/* Model terminate function */
void VirtualWall_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: foureightbits_thirtytwobit.c
 *
 * Code generated for Simulink model 'foureightbits_thirtytwobit'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Wed Sep 20 11:47:25 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objective: Traceability
 * Validation result: Not run
 */

#include "foureightbits_thirtytwobit.h"
#include "foureightbits_thirtytwobit_private.h"

/* External inputs (root inport signals with auto storage) */
ExternalInputs_foureightbits_th foureightbits_thirtytwobit_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_foureightbits_t foureightbits_thirtytwobit_Y;

/* Real-time model */
RT_MODEL_foureightbits_thirtytw foureightbits_thirtytwobit_M_;
RT_MODEL_foureightbits_thirtytw *const foureightbits_thirtytwobit_M =
  &foureightbits_thirtytwobit_M_;

/* Model step function */
void foureightbits_thirtytwobit_step(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  ArithShift: '<S1>/Shift Left 16 bits'
   *  ArithShift: '<S1>/Shift Left 24 bits'
   *  ArithShift: '<S1>/Shift Left 8 bits'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   *  Inport: '<Root>/In1'
   *  Sum: '<S1>/Sum of Elements'
   */
  foureightbits_thirtytwobit_Y.Out1 = ((((uint32_T)
    foureightbits_thirtytwobit_U.In1[1] << 8) + (uint32_T)
    foureightbits_thirtytwobit_U.In1[0]) + ((uint32_T)
    foureightbits_thirtytwobit_U.In1[2] << 16)) + ((uint32_T)
    foureightbits_thirtytwobit_U.In1[3] << 24);
}

/* Model initialize function */
void foureightbits_thirtytwobit_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(foureightbits_thirtytwobit_M, (NULL));

  /* external inputs */
  (void) memset(foureightbits_thirtytwobit_U.In1, 0,
                4U*sizeof(uint8_T));

  /* external outputs */
  foureightbits_thirtytwobit_Y.Out1 = 0U;
}

/* Model terminate function */
void foureightbits_thirtytwobit_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

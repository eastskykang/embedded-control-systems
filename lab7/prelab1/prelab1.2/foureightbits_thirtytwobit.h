/*
 * File: foureightbits_thirtytwobit.h
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

#ifndef RTW_HEADER_foureightbits_thirtytwobit_h_
#define RTW_HEADER_foureightbits_thirtytwobit_h_
#ifndef foureightbits_thirtytwobit_COMMON_INCLUDES_
# define foureightbits_thirtytwobit_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* foureightbits_thirtytwobit_COMMON_INCLUDES_ */

#include "foureightbits_thirtytwobit_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  uint8_T In1[4];                      /* '<Root>/In1' */
} ExternalInputs_foureightbits_th;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint32_T Out1;                       /* '<Root>/Out1' */
} ExternalOutputs_foureightbits_t;

/* Real-time Model Data Structure */
struct RT_MODEL_foureightbits_thirtytw {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_foureightbits_th foureightbits_thirtytwobit_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_foureightbits_t foureightbits_thirtytwobit_Y;

/* Model entry point functions */
extern void foureightbits_thirtytwobit_initialize(void);
extern void foureightbits_thirtytwobit_step(void);
extern void foureightbits_thirtytwobit_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_foureightbits_thirtytw *const
  foureightbits_thirtytwobit_M;

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
 * '<Root>' : 'foureightbits_thirtytwobit'
 * '<S1>'   : 'foureightbits_thirtytwobit/Subsystem B'
 */
#endif                                 /* RTW_HEADER_foureightbits_thirtytwobit_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: VirtualWall.h
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

#ifndef RTW_HEADER_VirtualWall_h_
#define RTW_HEADER_VirtualWall_h_
#ifndef VirtualWall_COMMON_INCLUDES_
# define VirtualWall_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* VirtualWall_COMMON_INCLUDES_ */

#include "VirtualWall_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T torque;                       /* '<S5>/VirtualWall_Chart' */
  int32_T eTPUQuadratureDecoder_o1;    /* '<S7>/eTPU Quadrature Decoder' */
  int32_T eTPUQuadratureDecoder_o2;    /* '<S7>/eTPU Quadrature Decoder' */
  uint32_T DataTypeConversion1;        /* '<S3>/Data Type Conversion1' */
  int8_T eTPUQuadratureDecoder_o3;     /* '<S7>/eTPU Quadrature Decoder' */
} BlockIO_VirtualWall;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T k;                            /* '<S5>/VirtualWall_Chart' */
  real32_T UnitDelay1_DSTATE;          /* '<S4>/Unit Delay1' */
  uint16_T UnitDelay_DSTATE;           /* '<S4>/Unit Delay' */
  uint8_T is_active_c2_VirtualWall;    /* '<S5>/VirtualWall_Chart' */
  uint8_T is_c2_VirtualWall;           /* '<S5>/VirtualWall_Chart' */
} D_Work_VirtualWall;

/* Invariant block signals (auto storage) */
typedef struct {
  const uint32_T DataTypeConversion;   /* '<S3>/Data Type Conversion' */
} ConstBlockIO_VirtualWall;

/* Real-time Model Data Structure */
struct RT_MODEL_VirtualWall {
  const char_T *errorStatus;
};

/* Block signals (auto storage) */
extern BlockIO_VirtualWall VirtualWall_B;

/* Block states (auto storage) */
extern D_Work_VirtualWall VirtualWall_DWork;
extern const ConstBlockIO_VirtualWall VirtualWall_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void VirtualWall_initialize(boolean_T firstTime);
extern void VirtualWall_step(void);
extern void VirtualWall_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_VirtualWall *const VirtualWall_M;

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
 * '<Root>' : 'VirtualWall'
 * '<S1>'   : 'VirtualWall/GPIO Blocks'
 * '<S2>'   : 'VirtualWall/RAppID-EC'
 * '<S3>'   : 'VirtualWall/VirtualWallTask'
 * '<S4>'   : 'VirtualWall/VirtualWallTask/ConversionSystem'
 * '<S5>'   : 'VirtualWall/VirtualWallTask/Simulate Virtual Wall'
 * '<S6>'   : 'VirtualWall/VirtualWallTask/Subsystem'
 * '<S7>'   : 'VirtualWall/VirtualWallTask/eTPU Blocks'
 * '<S8>'   : 'VirtualWall/VirtualWallTask/Simulate Virtual Wall/VirtualWall_Chart'
 */
#endif                                 /* RTW_HEADER_VirtualWall_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

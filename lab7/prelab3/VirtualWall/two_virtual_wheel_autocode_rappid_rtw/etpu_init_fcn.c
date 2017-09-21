/* ######################################################################
 *
 *                           RAppID
 *     Rapid Application Initialization and Documentation Tool
 *                     freescale Virtual Garage
 *                   MPC5554 Configuration Tool
 *          Automatically Generated Initialization Code
 *
 *
 * #######################################################################
 *
 *  Project Name: base
 *
 *  Project File: base.mat
 *
 *  Revision Number: 1.82
 *
 *  Tool Version: 1.1.1
 *
 *  Target Compiler: metrowerks
 *
 *  Target Part: 5554
 *
 *  Part Errata Fixes: Errata 12
 *
 *  Project Last Save Date: 21-Sep-2017 13:34:28
 *
 *  FunctionName::etpu_init::FunctionName
 *
 *  Date : 21-Sep-2017  Time : 16:8:26.695
 *
 * ####################################################################### */

// ******************  Dependent Include files Here **********************
#include "eTPU_vars.h"
#include "mpc5554.h"
#include "etpu_init_fcn.h"
#include "etpu_set3.h"                 // eTPU binary image files, contains eTPU engine code
#include "etpu_qd.h"
#include "etpu_qd_auto.h"

// ################### User Custom Code Section #########################
//  User Custom Code Section ::etpu_init::includes_start::

//  ::includes_end::      User Custom Code Section ::etpu_init::
// ################### User Custom Code Section #########################

// ************************** Pragma Section **************************

// ################### User Custom Code Section #########################
//  User Custom Code Section ::etpu_init::custom_start::

//  ::custom_end::        User Custom Code Section ::etpu_init::
// ################### User Custom Code Section #########################
uint32_t *fs_free_param;

#define ETPU_CODE_RAM_SIZE             sizeof(etpu_code)
#define ETPU_GLOBALS_SIZE              sizeof(etpu_globals)

// ************* eTPU Engine Initialization Data ************************
static struct etpu_config_t etpu_config_A = {
  // Set up the eTPU Module Configuration Register (ETPU_MCR) Register
  FS_ETPU_MISC_DISABLE                 // MISC operation disabled.
  + FS_ETPU_VIS_OFF                    // SCM is not visible to the IP bus.
  + FS_ETPU_GLOBAL_TIMEBASE_DISABLE,   // Time bases in both engines are disabled to run.

  // Set up the eTPU MISC Compare Register (ETPU_MISCCMPR) Register
  0x00000000,                          // Expected MISC register value = 0x00000000

  // Set up the eTPU A Engine Configuration Register (ETPU_ECR_A) Register
  FS_ETPU_FEND_DISABLE                 // FEND Force end. Normal operation.
  + FS_ETPU_FILTER_CLOCK_DIV2          // FPSCK Filter prescaler clock control. Divide by 2
  + FS_ETPU_CHAN_FILTER_2SAMPLE        // CDFC Channel digital filter control. Mode = 2 Sample Filer Mode
  + FS_ETPU_ENGINE_ENABLE              // STOP ETPU Engine is enabled.
  + 0x0000,                            // ETB Entry table base.

  // Set up the eTPU A Engine Time Bases in Register (ETPU_TBCR_A) Register
  FS_ETPU_TCR2CTL_GATEDDIV8            // TCR2CTL Gated DIV8 clock (system clock / 8)
  + FS_ETPU_TCRCLK_MODE_2SAMPLE        // TCRCF Filter Input : system clock divided by 2 ,Filter Mode : two sample
  + FS_ETPU_ANGLE_MODE_DISABLE         // AM EAC operation is disabled.
  + ( 0x0001 << 16)                    // TCR2P Timer count register 2 prescaler control.
  + FS_ETPU_TCR1CTL_DIV2               // TCR1CTL System Clock divided by 2 as clock source for the TCR1 prescaler
  + 0x0001,                            // TCR1P Timer count register 1 prescaler control.

  // Set up the eTPU A STAC Bus Configuration Register (ETPU_REDCR_A)
  FS_ETPU_TCR1_STAC_DISABLE            // REN1 Server/client operation for resource 1 is disabled.
  + FS_ETPU_TCR1_STAC_SERVER           // RSC1 Resource server operation.
  + ( 0 << 16)                         // SRV1 TCR1 client server. = 0
  + FS_ETPU_TCR2_STAC_DISABLE          // REN2 Server/client operation for resource 1 is disabled.
  + FS_ETPU_TCR2_STAC_SERVER           // RSC2 Resource server operation.
  + ( 0 ),                             // SRV2 TCR2 client server. = 0

  // Set up the eTPU B Engine Configuration Register (ETPU_ECR_B) Register
  FS_ETPU_FEND_DISABLE                 // FEND Force end. Normal operation.
  + FS_ETPU_FILTER_CLOCK_DIV2          // FPSCK Filter prescaler clock control. Divide by 2
  + FS_ETPU_CHAN_FILTER_2SAMPLE        // CDFC Channel digital filter control. Mode = 2 Sample Filer Mode
  + FS_ETPU_ENGINE_ENABLE              // STOP ETPU Engine is enabled.
  + 0x0000,                            // ETB Entry table base.

  // Set up the eTPU B Engine Time Bases in Register (ETPU_TBCR_B) Register
  FS_ETPU_TCR2CTL_GATEDDIV8            // TCR2CTL Gated DIV8 clock (system clock / 8)
  + FS_ETPU_TCRCLK_MODE_2SAMPLE        // TCRCF Filter Input : system clock divided by 2 ,Filter Mode : two sample
  + FS_ETPU_ANGLE_MODE_DISABLE         // AM EAC operation is disabled.
  + ( 0x0001 << 16)                    // TCR2P Timer count register 2 prescaler control.
  + FS_ETPU_TCR1CTL_TCRCLK             // TCR1CTL TCRCLK as clock source for the TCR1 prescaler
  + 0x0001,                            // TCR1P Timer count register 1 prescaler control.

  // Set up the eTPU B STAC Bus Configuration Register (ETPU_REDCR_B)
  FS_ETPU_TCR1_STAC_DISABLE            // REN1 Server/client operation for resource 1 is disabled.
  + FS_ETPU_TCR1_STAC_SERVER           // RSC1 Resource server operation.
  + ( 0 << 16)                         // SRV1 TCR1 client server. = 0
  + FS_ETPU_TCR2_STAC_DISABLE          // REN2 Server/client operation for resource 1 is disabled.
  + FS_ETPU_TCR2_STAC_SERVER           // RSC2 Resource server operation.
  + ( 0 )                              // SRV2 TCR2 client server. = 0
};

static uint8_t load_microcode = 1;     /* etpu_set3.h Microcode loaded */

// ********************* Initialization Function *********************
int16_t etpu_init(void)
{
  // ETPU Initialization Code
  int16_t error_code = 0;
  uint32_t chanConfigParam = 0;

  // Initialize eTPU host side
  error_code = fs_etpu_init(etpu_config_A, (uint32_t *)etpu_code,(uint32_t)
    ETPU_CODE_RAM_SIZE, (uint32_t *)etpu_globals, (uint32_t) ETPU_GLOBALS_SIZE,
    (uint8_t)load_microcode);

  // ********************************************************************
  // ***       Add eTPU Function Initialization calls here            ***
  // ********************************************************************
  fs_etpu_qd_init(3,
                  FS_ETPU_CHAN_NOT_USED,
                  FS_ETPU_CHAN_NOT_USED,
                  FS_ETPU_QD_PRIM_SEC,
                  FS_ETPU_PRIORITY_DISABLE,
                  FS_ETPU_QD_CONFIGURATION_0,
                  FS_ETPU_TCR1,
                  0,                   /* pc_max 0 - automatic position counter reset not performed */
                  0.40 * 1000,         /* slow_normal_threshold */
                  0.35 *1000,          /* normal_slow_threshold */
                  0.80 *1000,          /* normal_fast_threshold */
                  0.75 *1000,          /* fast_normal_threshold */
                  0x733333,            /* window_ratio1: 0.9*2^23 */
                  0x8CCCCC,            /* window_ratio2: 1.1*2^23 */
                  FS_ETPU_QD_HOME_TRANS_LOW_HIGH, /* detection of home_transition low to high */
                  FS_ETPU_QD_INDEX_PULSE_POSITIVE, /* index_pulse of positive polarity */
                  FS_ETPU_QD_INDEX_PC_NO_RESET, /* PC is NOT reset to pc_init on Index transition */
                  32000000,
                  4000);

  // ETPU A Channel 3 initialization, set to ETPU Function Quadrature Decoding
  chanConfigParam = (FS_ETPU_INTERRUPT_DISABLE | FS_ETPU_DMA_DISABLE |
                     FS_ETPU_OUTPUT_DISABLE_OFF | (0x0000 << 24 ) | (0x0002 <<
    28) );
  fs_etpu_chan_init( QD1, FS_ETPU_QD_FUNCTION_NUMBER, 0, FS_ETPU_QD_NUM_PARMS,
                    chanConfigParam, 0);
  fs_etpu_qd_set_pc_interrupts(3,0,0);
  fs_etpu_qd_enable_pc_interrupts(3);
  fs_etpu_qd_enable(3,FS_ETPU_CHAN_NOT_USED,FS_ETPU_CHAN_NOT_USED,
                    FS_ETPU_QD_PRIM_SEC,FS_ETPU_PRIORITY_HIGH);
  return(error_code);
}

/* **********************************************************************
 *
 *                           End of File
 *
 * ********************************************************************* */

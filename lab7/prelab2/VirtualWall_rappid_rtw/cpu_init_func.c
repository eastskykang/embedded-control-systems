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
 *  Part Errata Fixes: None
 *
 *  Project Last Save Date: 21-Sep-2017 13:34:28
 *
 *  FunctionName::cpu_init::FunctionName
 *
 *  Date : 21-Sep-2017  Time : 13:48:20.204
 *
 * ####################################################################### */

// ******************  Dependent Include files Here **********************
#include "typedefs.h"
#include "mpc5554.h"
#include "cpu_init_func.h"

// ################### User Custom Code Section #########################
//  User Custom Code Section ::cpu_init::includes_start::

//  ::includes_end::      User Custom Code Section ::eqadc_init::
// ################### User Custom Code Section #########################

// ************************** Pragma Section **************************

// ################### User Custom Code Section #########################
//  User Custom Code Section ::cpu_init::custom_start::

//  ::custom_end::        User Custom Code Section ::eqadc_init::
// ################### User Custom Code Section #########################
// ********************* Initialization Function *********************
void cpu_init_fcn(void)
{
  /* PLLMRFM System Clock Setup */
  FMPLL.SYNCR.B.LOLRE = 0x0;           /* Ensure loss of lock reset is disabled  */
  FMPLL.SYNCR.B.LOCRE = 0x0;           /* Ensure loss of clock reset is disabled */
  FMPLL.SYNCR.B.LOLIRQ = 0x0;          /* Ensure Loss of lock IRQ is disabled   */

  /* The Pre-Divider has not changed from its reset value. */

  /* The PLL will be ramped using a single stage. A change in MFD causes loss of lock */
  FMPLL.SYNCR.B.RFD = 0x00;
  FMPLL.SYNCR.B.MFD = 0x0C;

  /* Wait for lock */
  while (FMPLL.SYNSR.B.LOCK == 0) {
  }

  FMPLL.SYNSR.B.LOLF = 0x1;            /* Clear loss of lock flag */

  /* Final Frequency is :128Mhz */

  /* Remaining SYNCR bits */
  FMPLL.SYNCR.R = FMPLL.SYNCR.R | 0x00000000;
}

/* **********************************************************************
 *
 *                           End of File
 *
 * ********************************************************************* */

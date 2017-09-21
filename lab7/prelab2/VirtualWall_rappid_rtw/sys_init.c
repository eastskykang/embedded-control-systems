/* ######################################################################
 *
 *                           RAppID
 *     Rapid Application Initialization and Documentation Tool
 *                     freescale Virtual Garage
 *                   MPC5554 Configuration Tool
 *          Automatically Generated Initilization Code
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
 *  Date : 21-Sep-2017  Time : 13:48:24.041
 *
 * ####################################################################### */

// ******************  Dependent Include files Here **********************
#include "mpc5554.h"

// ################### User Custom Code Section #########################
//  User Custom Code Section ::sys_init::includes_start::

//  ::includes_end::      User Custom Code Section ::sys_init::
// ################### User Custom Code Section #########################
#include "intc_init.h"
#include "cpu_init_func.h"
#include "msr_init.h"
#include "etpu_init_fcn.h"
#include "emios_init.h"
#include "siu_init.h"

// **********************  Function Prototypes **************************
// ********************* System Initilization Functions *********************
void sys_init_rp(void)
{
  //  Reset Determination Goes Here
  intc_init_fcn();                     // Initialize the Interrupt Controller
  cpu_init_fcn();                      // Initialize the System Clock
  msr_init_fcn();                      // MSR Initialization.

  // WatchDog TCR Register Initialization Goes Here

  //  FLASH BIU Initialization Goes Here

  // External Bus Initialization Goes Here

  // External Peripheral Initialization Goes Here

  //  Internal Peripheral Bridge Initialization Goes Here

  //  Crossbar Switch Initialization Goes Here
  etpu_init();                         // Initialize the eTPU Host Interface and eTPU Channels.
  emios_init_fcn();                    // Initialize the EMIOS .
  siu_init_fcn();                      // Initialize the SIU (I/O initailization of the device).
}

/* **********************************************************************
 *
 *                           End of File
 *
 * ********************************************************************* */

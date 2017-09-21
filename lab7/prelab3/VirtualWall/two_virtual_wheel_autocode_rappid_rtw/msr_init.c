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
 *  Part Errata Fixes: Errata 33
 *
 *  Project Last Save Date: 21-Sep-2017 13:34:28
 *
 *  FunctionName::msr_init::FunctionName
 *
 *  Date : 21-Sep-2017  Time : 16:8:26.663
 *
 * ####################################################################### */

// ******************  Dependent Include files Here **********************
#include "msr_init.h"

// ################### User Custom Code Section #########################
//  User Custom Code Section ::msr_init::includes_start::

//  ::includes_end::      User Custom Code Section ::msr_init::
// ################### User Custom Code Section #########################

// ************************** Pragma Section **************************

// ################### User Custom Code Section #########################
//  User Custom Code Section ::msr_init::custom_start::

//  ::custom_end::        User Custom Code Section ::msr_init::
// ################### User Custom Code Section #########################
// ********************* Initialization Function *********************
asm void msr_init_fcn(void)
{
  lis r12, 0x0004                      /* # Load upper 16 bits of register value                 */
    ori r12,r12,0x8000                 /* # Load lower 16 bits of register value                 */
    mtmsr r12                          /* # Move data to MSR register                            */
    lis r12, 0x0000                    /* # Load upper 16 bits of register value                 */
    ori r12,r12,0x4000                 /* # Load lower 16 bits of register value                 */
    mtspr 1008,r12                     /* # Move data to HID0 register                           */
}                                      /* **********************************************************************
                                        *
                                        *                           End of File
                                        *
                                        * ********************************************************************* */

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
 *  Part Errata Fixes: Errata 60, Errata 78
 *
 *  Project Last Save Date: 21-Sep-2017 13:34:28
 *
 *  FunctionName::emios_init::FunctionName
 *
 *  Date : 21-Sep-2017  Time : 14:29:57.366
 *
 * ####################################################################### */

// ************************** Pragma Section **************************

// ################### User Custom Code Section #########################
//  User Custom Code Section ::emios_init::custom_start::

//  ::custom_end::        User Custom Code Section ::emios_init::
// ################### User Custom Code Section #########################
// ******************  Dependent Include files Here **********************
#include "emios_init.h"

// ################### User Custom Code Section #########################
//  User Custom Code Section ::emios_init::includes_start::

//  ::includes_end::      User Custom Code Section ::emios_init::
// ################### User Custom Code Section #########################
// ********************* EMIOS Initialization Function *********************
void emios_init_fcn(void)
{
  /* EMIO General Setup */
  EMIOS.MCR.R = 0x14000000;            /* Module Control Register - MCR */
  EMIOS.OUDR.R = 0x00000000;           /* Output Update Disable Register - OUDR */

  /* Unified Channel 0 Setup */
  EMIOS.CH[0].CADR.R = 0x00000640;     /* Channel 0 A Data Register - CADR0 */
  EMIOS.CH[0].CBDR.R = 0x00000C80;     /* Channel 0 B Data Register - CBDR0 */
  EMIOS.CH[0].CCR.R = 0x0200061B;      /* Channel Control 0 Register - CCR0 */

  /* Unified Channel 1 Setup */
  EMIOS.CH[1].CADR.R = 0x00000000;     /* Channel 1 A Data Register - CADR1 */
  EMIOS.CH[1].CBDR.R = 0x00000000;     /* Channel 1 B Data Register - CBDR1 */
  EMIOS.CH[1].CCR.R = 0x00000000;      /* Channel Control 1 Register - CCR1 */

  /* Unified Channel 2 Setup */
  EMIOS.CH[2].CADR.R = 0x00000000;     /* Channel 2 A Data Register - CADR2 */
  EMIOS.CH[2].CBDR.R = 0x00000000;     /* Channel 2 B Data Register - CBDR2 */
  EMIOS.CH[2].CCR.R = 0x0000000B;      /* Channel Control 2 Register - CCR2 */

  /* Unified Channel 3 Setup */
  EMIOS.CH[3].CADR.R = 0x00000000;     /* Channel 3 A Data Register - CADR3 */
  EMIOS.CH[3].CBDR.R = 0x00000000;     /* Channel 3 B Data Register - CBDR3 */
  EMIOS.CH[3].CCR.R = 0x00000000;      /* Channel Control 3 Register - CCR3 */

  /* Unified Channel 4 Setup */
  EMIOS.CH[4].CADR.R = 0x00000000;     /* Channel 4 A Data Register - CADR4 */
  EMIOS.CH[4].CBDR.R = 0x00000000;     /* Channel 4 B Data Register - CBDR4 */
  EMIOS.CH[4].CCR.R = 0x00000000;      /* Channel Control 4 Register - CCR4 */

  /* Unified Channel 5 Setup */
  EMIOS.CH[5].CADR.R = 0x00000000;     /* Channel 5 A Data Register - CADR5 */
  EMIOS.CH[5].CBDR.R = 0x00000000;     /* Channel 5 B Data Register - CBDR5 */
  EMIOS.CH[5].CCR.R = 0x00000000;      /* Channel Control 5 Register - CCR5 */

  /* Unified Channel 6 Setup */
  EMIOS.CH[6].CADR.R = 0x00000000;     /* Channel 6 A Data Register - CADR6 */
  EMIOS.CH[6].CBDR.R = 0x00000000;     /* Channel 6 B Data Register - CBDR6 */
  EMIOS.CH[6].CCR.R = 0x00000000;      /* Channel Control 6 Register - CCR6 */

  /* Unified Channel 7 Setup */
  EMIOS.CH[7].CADR.R = 0x00000000;     /* Channel 7 A Data Register - CADR7 */
  EMIOS.CH[7].CBDR.R = 0x00000000;     /* Channel 7 B Data Register - CBDR7 */
  EMIOS.CH[7].CCR.R = 0x00000000;      /* Channel Control 7 Register - CCR7 */

  /* Unified Channel 8 Setup */
  EMIOS.CH[8].CADR.R = 0x00000000;     /* Channel 8 A Data Register - CADR8 */
  EMIOS.CH[8].CBDR.R = 0x00000000;     /* Channel 8 B Data Register - CBDR8 */
  EMIOS.CH[8].CCR.R = 0x00000000;      /* Channel Control 8 Register - CCR8 */

  /* Unified Channel 9 Setup */
  EMIOS.CH[9].CADR.R = 0x00000000;     /* Channel 9 A Data Register - CADR9 */
  EMIOS.CH[9].CBDR.R = 0x00000000;     /* Channel 9 B Data Register - CBDR9 */
  EMIOS.CH[9].CCR.R = 0x00000000;      /* Channel Control 9 Register - CCR9 */

  /* Unified Channel 10 Setup */
  EMIOS.CH[10].CADR.R = 0x00000000;    /* Channel 10 A Data Register - CADR10 */
  EMIOS.CH[10].CBDR.R = 0x00000000;    /* Channel 10 B Data Register - CBDR10 */
  EMIOS.CH[10].CCR.R = 0x00000000;     /* Channel Control 10 Register - CCR10 */

  /* Unified Channel 11 Setup */
  EMIOS.CH[11].CADR.R = 0x00000000;    /* Channel 11 A Data Register - CADR11 */
  EMIOS.CH[11].CBDR.R = 0x00000000;    /* Channel 11 B Data Register - CBDR11 */
  EMIOS.CH[11].CCR.R = 0x00000000;     /* Channel Control 11 Register - CCR11 */

  /* Unified Channel 12 Setup */
  EMIOS.CH[12].CADR.R = 0x00000040;    /* Channel 12 A Data Register - CADR12 */
  EMIOS.CH[12].CBDR.R = 0x00000080;    /* Channel 12 B Data Register - CBDR12 */
  EMIOS.CH[12].CCR.R = 0x0200001B;     /* Channel Control 12 Register - CCR12 */

  /* Unified Channel 13 Setup */
  EMIOS.CH[13].CADR.R = 0x00000000;    /* Channel 13 A Data Register - CADR13 */
  EMIOS.CH[13].CBDR.R = 0x00000000;    /* Channel 13 B Data Register - CBDR13 */
  EMIOS.CH[13].CCR.R = 0x00000000;     /* Channel Control 13 Register - CCR13 */

  /* Unified Channel 14 Setup */
  EMIOS.CH[14].CADR.R = 0x00000000;    /* Channel 14 A Data Register - CADR14 */
  EMIOS.CH[14].CBDR.R = 0x00000000;    /* Channel 14 B Data Register - CBDR14 */
  EMIOS.CH[14].CCR.R = 0x00000000;     /* Channel Control 14 Register - CCR14 */

  /* Unified Channel 15 Setup */
  EMIOS.CH[15].CADR.R = 0x00000000;    /* Channel 15 A Data Register - CADR15 */
  EMIOS.CH[15].CBDR.R = 0x00000000;    /* Channel 15 B Data Register - CBDR15 */
  EMIOS.CH[15].CCR.R = 0x00000000;     /* Channel Control 15 Register - CCR15 */

  /* Unified Channel 16 Setup */
  EMIOS.CH[16].CADR.R = 0x00000000;    /* Channel 16 A Data Register - CADR16 */
  EMIOS.CH[16].CBDR.R = 0x00000000;    /* Channel 16 B Data Register - CBDR16 */
  EMIOS.CH[16].CCR.R = 0x00000000;     /* Channel Control 16 Register - CCR16 */

  /* Unified Channel 17 Setup */
  EMIOS.CH[17].CADR.R = 0x00000000;    /* Channel 17 A Data Register - CADR17 */
  EMIOS.CH[17].CBDR.R = 0x00000000;    /* Channel 17 B Data Register - CBDR17 */
  EMIOS.CH[17].CCR.R = 0x00000000;     /* Channel Control 17 Register - CCR17 */

  /* Unified Channel 18 Setup */
  EMIOS.CH[18].CADR.R = 0x00000000;    /* Channel 18 A Data Register - CADR18 */
  EMIOS.CH[18].CBDR.R = 0x00000000;    /* Channel 18 B Data Register - CBDR18 */
  EMIOS.CH[18].CCR.R = 0x00000000;     /* Channel Control 18 Register - CCR18 */

  /* Unified Channel 19 Setup */
  EMIOS.CH[19].CADR.R = 0x00000000;    /* Channel 19 A Data Register - CADR19 */
  EMIOS.CH[19].CBDR.R = 0x00000000;    /* Channel 19 B Data Register - CBDR19 */
  EMIOS.CH[19].CCR.R = 0x00000000;     /* Channel Control 19 Register - CCR19 */

  /* Unified Channel 20 Setup */
  EMIOS.CH[20].CADR.R = 0x00000000;    /* Channel 20 A Data Register - CADR20 */
  EMIOS.CH[20].CBDR.R = 0x00000000;    /* Channel 20 B Data Register - CBDR20 */
  EMIOS.CH[20].CCR.R = 0x00000000;     /* Channel Control 20 Register - CCR20 */

  /* Unified Channel 21 Setup */
  EMIOS.CH[21].CADR.R = 0x00000000;    /* Channel 21 A Data Register - CADR21 */
  EMIOS.CH[21].CBDR.R = 0x00000000;    /* Channel 21 B Data Register - CBDR21 */
  EMIOS.CH[21].CCR.R = 0x00000000;     /* Channel Control 21 Register - CCR21 */

  /* Unified Channel 22 Setup */
  EMIOS.CH[22].CADR.R = 0x00000000;    /* Channel 22 A Data Register - CADR22 */
  EMIOS.CH[22].CBDR.R = 0x00000000;    /* Channel 22 B Data Register - CBDR22 */
  EMIOS.CH[22].CCR.R = 0x00000000;     /* Channel Control 22 Register - CCR22 */

  /* Unified Channel 23 Setup */
  EMIOS.CH[23].CADR.R = 0x00000000;    /* Channel 23 A Data Register - CADR23 */
  EMIOS.CH[23].CBDR.R = 0x00000000;    /* Channel 23 B Data Register - CBDR23 */
  EMIOS.CH[23].CCR.R = 0x00000000;     /* Channel Control 23 Register - CCR23 */
}

// ********************* eMIOS Software Trigger Function(s) *********************
void emios_trigger_ch2(unsigned int rappid, unsigned int regA, unsigned int regB)
{
  if (rappid == 1) {
    EMIOS.CH[2].CADR.R = 0x00000000;   /* Channel 2 A Data Register */
    EMIOS.CH[2].CBDR.R = 0x00000000;   /* Channel 2 B Data Register */
  } else {
    EMIOS.CH[2].CADR.R = regA;         /* Channel 2 A Data Register */
    EMIOS.CH[2].CBDR.R = regB;         /* Channel 2 B Data Register */
  }
}

/* **********************************************************************
 *
 *                           End of File
 *
 * ********************************************************************* */

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
 *  Part Errata Fixes: Errata 155, Errata 359, Errata 314
 *
 *  Project Last Save Date: 21-Sep-2017 13:34:28
 *
 *
 *  Date : 21-Sep-2017  Time : 16:8:26.715
 *
 * ####################################################################### */

// ************************** Pragma Section **************************

// ################### User Custom Code Section #########################
//  User Custom Code Section ::siu_init::custom_start::

//  ::custom_end::        User Custom Code Section ::siu_init::
// ################### User Custom Code Section #########################
// ******************  Dependent Include files Here **********************
#include "siu_init.h"

// ################### User Custom Code Section #########################
//  User Custom Code Section ::siu_init::includes_start::

//  ::includes_end::      User Custom Code Section ::siu_init::
// ################### User Custom Code Section #########################
// ********************* SIU Initialization Function *********************
void siu_init_fcn(void)
{
  /* SIU Initialization */
  siu_dspi_init_fcn();
  siu_gpio_init_fcn();
  siu_reset_init_fcn();
  siu_eqadc_init_fcn();
  siu_flex_init_fcn();
  siu_esci_init_fcn();
  siu_emios_init_fcn();
  siu_etpu_init_fcn();
  siu_ebi_init_fcn();
  siu_nexus_init_fcn();
}

// ********************* GPIO Initialization Function *********************
void siu_gpio_init_fcn(void)
{
  /* SIU General and GPIO Setup */
  SIU.SRCR.R = 0x00008000;             /* System Reset Control Register - SRCR */

  /* Bit 0 - Software System Reset: Do not generate a software system reset */
  /* Bit 1 - Software External Reset:  Do not generate a software external reset*/
  /* Bit 16 - Checkstop Reset Enable:Enabled*/
  SIU.DIRER.R = 0x00000000;            /* DMA/Interrupt Request Enable Register - DIRER */

  /* Bit 31 - IRQ0 DMA/Interrupt Request: Disabled */
  /* Bit 30 - IRQ1 DMA/Interrupt Request: Disabled */
  /* Bit 29 - IRQ2 DMA/Interrupt Request: Disabled */
  /* Bit 28 - IRQ3 DMA/Interrupt Request: Disabled */
  /* Bit 27 - IRQ4 DMA/Interrupt Request: Disabled */
  /* Bit 26 - IRQ5 DMA/Interrupt Request: Disabled */
  /* Bit 25 - IRQ6 DMA/Interrupt Request: Disabled */
  /* Bit 24 - IRQ7 DMA/Interrupt Request: Disabled */
  /* Bit 23 - IRQ8 DMA/Interrupt Request: Disabled */
  /* Bit 22 - IRQ9 DMA/Interrupt Request: Disabled */
  /* Bit 21 - IRQ10 DMA/Interrupt Request: Disabled */
  /* Bit 20 - IRQ11 DMA/Interrupt Request: Disabled */
  /* Bit 19 - IRQ12 DMA/Interrupt Request: Disabled */
  /* Bit 18 - IRQ13 DMA/Interrupt Request: Disabled */
  /* Bit 17 - IRQ14 DMA/Interrupt Request: Disabled */
  /* Bit 16 - IRQ15 DMA/Interrupt Request: Disabled */
  SIU.DIRSR.R = 0x00000000;            /* DMA/Interrupt Select Register - DIRSR */

  /* Bit 31 - IRQ0 DMA/Interrupt Select: Interrupt */
  /* Bit 30 - IRQ1 DMA/Interrupt Select: Interrupt */
  /* Bit 29 - IRQ2 DMA/Interrupt Select: Interrupt */
  /* Bit 28 - IRQ3 DMA/Interrupt Select: Interrupt */
  SIU.ORER.R = 0x00000000;             /* Overrun Request Enable Register - ORER */

  /* Bit 31 - IRQ0 Overrun Request: Disabled */
  /* Bit 30 - IRQ1 Overrun Request: Disabled */
  /* Bit 29 - IRQ2 Overrun Request: Disabled */
  /* Bit 28 - IRQ3 Overrun Request: Disabled */
  /* Bit 27 - IRQ4 Overrun Request: Disabled */
  /* Bit 26 - IRQ5 Overrun Request: Disabled */
  /* Bit 25 - IRQ6 Overrun Request: Disabled */
  /* Bit 24 - IRQ7 Overrun Request: Disabled */
  /* Bit 23 - IRQ8 Overrun Request: Disabled */
  /* Bit 22 - IRQ9 Overrun Request: Disabled */
  /* Bit 21 - IRQ10 Overrun Request: Disabled */
  /* Bit 20 - IRQ11 Overrun Request: Disabled */
  /* Bit 19 - IRQ12 Overrun Request: Disabled */
  /* Bit 18 - IRQ13 Overrun Request: Disabled */
  /* Bit 17 - IRQ14 Overrun Request: Disabled */
  /* Bit 16 - IRQ15 Overrun Request: Disabled */
  SIU.IREER.R = 0x00000000;            /* External IRQ Rising-Edge Event Enable Register - IREER */

  /* Bit 31 - IRQ0 Rising-Edge Event: Disabled */
  /* Bit 30 - IRQ1 Rising-Edge Event: Disabled */
  /* Bit 29 - IRQ2 Rising-Edge Event: Disabled */
  /* Bit 28 - IRQ3 Rising-Edge Event: Disabled */
  /* Bit 27 - IRQ4 Rising-Edge Event: Disabled */
  /* Bit 26 - IRQ5 Rising-Edge Event: Disabled */
  /* Bit 25 - IRQ6 Rising-Edge Event: Disabled */
  /* Bit 24 - IRQ7 Rising-Edge Event: Disabled */
  /* Bit 23 - IRQ8 Rising-Edge Event: Disabled */
  /* Bit 22 - IRQ9 Rising-Edge Event: Disabled */
  /* Bit 21 - IRQ10 Rising-Edge Event: Disabled */
  /* Bit 20 - IRQ11 Rising-Edge Event: Disabled */
  /* Bit 19 - IRQ12 Rising-Edge Event: Disabled */
  /* Bit 18 - IRQ13 Rising-Edge Event: Disabled */
  /* Bit 17 - IRQ14 Rising-Edge Event: Disabled */
  /* Bit 16 - IRQ15 Rising-Edge Event: Disabled */
  SIU.IFEER.R = 0x00000000;            /* External IRQ Falling-Edge Event Enable Register - IFEER */

  /* Bit 31 - IRQ0 Falling-Edge Event: Disabled */
  /* Bit 30 - IRQ1 Falling-Edge Event: Disabled */
  /* Bit 29 - IRQ2 Falling-Edge Event: Disabled */
  /* Bit 28 - IRQ3 Falling-Edge Event: Disabled */
  /* Bit 27 - IRQ4 Falling-Edge Event: Disabled */
  /* Bit 26 - IRQ5 Falling-Edge Event: Disabled */
  /* Bit 25 - IRQ6 Falling-Edge Event: Disabled */
  /* Bit 24 - IRQ7 Falling-Edge Event: Disabled */
  /* Bit 23 - IRQ8 Falling-Edge Event: Disabled */
  /* Bit 22 - IRQ9 Falling-Edge Event: Disabled */
  /* Bit 21 - IRQ10 Falling-Edge Event: Disabled */
  /* Bit 20 - IRQ11 Falling-Edge Event: Disabled */
  /* Bit 19 - IRQ12 Falling-Edge Event: Disabled */
  /* Bit 18 - IRQ13 Falling-Edge Event: Disabled */
  /* Bit 17 - IRQ14 Falling-Edge Event: Disabled */
  /* Bit 16 - IRQ15 Falling-Edge Event: Disabled */
  SIU.IDFR.R = 0x00000000;             /* External Digital Filter Register - IDFR */

  /* BITS 28 - 31: Digital Filter Length = 0 */
  SIU.ETISR.R = 0x00000000;            /* IMUX 0 Register - ISELO */

  /* BITS 10 & 11: EQADC Trigger 0 - Disabled */
  /* BITS 8 & 9: EQADC Trigger 1 - Disabled */
  /* BITS 6 & 7: EQADC Trigger 2 - Disabled */
  /* BITS 4 & 5: EQADC Trigger 3 - Disabled */
  /* BITS 2 & 3: EQADC Trigger 4 - Disabled */
  /* BITS 0 & 1: EQADC Trigger 5 - Disabled */
  SIU.EIISR.R = 0x00000000;            /* IMUX 1 Register - ISEL1 */

  /* BITS 30 & 31: IRQ input 0 - IRQ[0] pin */
  /* BITS 28 & 29: IRQ input 1 - IRQ[1] pin */
  /* BITS 26 & 27: IRQ input 2 - IRQ[2] pin */
  /* BITS 24 & 25: IRQ input 3 - IRQ[3] pin */
  /* BITS 22 & 23: IRQ input 4 - IRQ[4] pin */
  /* BITS 20 & 21: IRQ input 5 - IRQ[5] pin */
  /* BITS 18 & 19: IRQ input 6 - IRQ[6] pin */
  /* BITS 16 & 17: IRQ input 7 - IRQ[7] pin */
  /* BITS 14 & 15: IRQ input 8 - IRQ[8] pin */
  /* BITS 12 & 13: IRQ input 9 - IRQ[9] pin */
  /* BITS 10 & 11: IRQ input 10 - IRQ[10] pin */
  /* BITS 8 & 9: IRQ input 11 - IRQ[11] pin */
  /* BITS 6 & 7: IRQ input 12 - IRQ[12] pin */
  /* BITS 4 & 5: IRQ input 13 - IRQ[13] pin */
  /* BITS 2 & 3: IRQ input 14 - IRQ[14] pin */
  /* BITS 0 & 1: IRQ input 15 - IRQ[15] pin */
  SIU.DISR.R = 0x00000000;             /* IMUX 2 Register - ISEL2 */

  /* BITS 30 & 31: DSPI-D Trigger Input - Reserved */
  /* BITS 28 & 29: DSPI-D Clock Input - PCS_A[2]_SCK_D_GPIO[98] pin */
  /* BITS 26 & 27: DSPI-D Slave Select Input - PCS_B[1]_PCS_D[0]_GPIO[106] pin */
  /* BITS 24 & 26: DSPI-D Data Input - PCS_A[3]_SIN_D_GPIO[99] pin */
  /* BITS 22 & 23: DSPI-C Trigger Input - Reserved */
  /* BITS 20 & 21: DSPI-C Clock Input - PCS_B[4]_SCK_C_GPIO[109] pin */
  /* BITS 18 & 19: DSPI-C Slave Select Input - PCS_B[5]_PCS_C[0]_GPIO[110] pin */
  /* BITS 16 & 17: DSPI-C Data Input - PCS_A[2]_SIN_C_GPIO[108] pin */
  /* BITS 14 & 15: DSPI-B Trigger Input - Reserved */
  /* BITS 12 & 13: DSPI-B Clock Input - PCS_C[1]_SCK_B_GPIO[102] pin */
  /* BITS 10 & 11: DSPI-B Slave Select Input - PCS_B[0]_PCS_D[2]_GPIO[105] pin */
  /* BITS 8 & 9: DSPI-B Data Input - PCS_C[2]_SIN_B_GPIO[103] pin */
  /* BITS 6 & 7: DSPI-A Trigger Input - Reserved */
  /* BITS 4 & 5: DSPI-A Clock Input - SCK_A_GPIO[93] pin */
  /* BITS 2 & 3: DSPI-A Slave Select Input - PCS_A[0]_GPIO[96] pin */
  /* BITS 0 & 1: DSPI-A Data Input - SIN_A_GPIO[94] pin */
  SIU.CARH.R = 0x00000000;             /* Compare A Register High - CARH */

  /* BITS 0 - 31: Compare A Register High = 0 */
  SIU.CARL.R = 0x00000000;             /* Compare A Register Low - CARL */

  /* BITS 0 - 31: Compare A Register Low = 0 */
  SIU.CBRH.R = 0x00000000;             /* Compare B Register High - CBRH */

  /* BITS 0 - 31: Compare B Register High = 0 */
  SIU.CBRL.R = 0x00000000;             /* Compare B Register High - CBRL */

  /* BITS 0 - 31: Compare B Register Low = 0 */
  SIU.ECCR.R = 0x00003F01;             /* Engineering Clock Control Register - ECCR */

  /* BITS 18 - 23: Engineering Clock Divider = 63 */
  /* BIT 28: External Bus Tap Select = Zero Output Hold Times */
  /* BITS 30 - 31: External Bus Division Factor = Divide by 2 */
  SIU.PCR[203].R = 0x0003;             /* Pad Configuration Register - PCR[203] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[204].R = 0x0003;             /* Pad Configuration Register - PCR[204] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[205].R = 0x0203;             /* Pad Configuration Register - PCR[205] */

  /* BIT 6: Output Buffers - Enabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[206].R = 0x0003;             /* Pad Configuration Register - PCR[206] */

  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 10pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[207].R = 0x0003;             /* Pad Configuration Register - PCR[207] */

  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 10pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[214].R = 0x02C0;             /* Pad Configuration Register - PCR[214] */

  /* BIT 6: Output Buffers - Engineering Clock is Enabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  SIU.PCR[229].R = 0x02C0;             /* Pad Configuration Register - PCR[229] */

  /* BIT 6: Output Buffers - System Clock is Enabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  SIU.PCR[230].R = 0x0000;             /* Pad Configuration Register - PCR[230] */

  /* BITS 12 & 13: Slew Rate - Minimum */
}

// ********************* ESCI Initialization Function *********************
void siu_esci_init_fcn(void)
{
  /* ESCI PAD Configuration */
  SIU.PCR[89].R = 0x0600;              /* Pad Configuration Register - PCR[89] */

  /* BIT 5: Primary Function - TXDA - ESCI Transmit A */
  /* BIT 6: Output Buffers - Enabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[90].R = 0x0403;              /* Pad Configuration Register - PCR[90] */

  /* BIT 5: Primary Function - RXDA - ESCI Receive A */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[91].R = 0x0C00;              /* Pad Configuration Register - PCR[91] */

  /* BIT 5: Primary Function - TXDB - ESCI Transmit B */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[92].R = 0x0C03;              /* Pad Configuration Register - PCR[92] */

  /* BIT 5: Primary Function - RXDB - ESCI Receive B */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
}

// ********************* FlexCAN Initialization Function *********************
void siu_flex_init_fcn(void)
{
  /* FlexCAN PAD Configuration */
  SIU.PCR[83].R = 0x0520;              /* Pad Configuration Register - PCR[83] */

  /* BIT 5: Primary Function - CNTXA - CAN Transmit A */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Enabled */
  /* BIT 10: Output Drain - Asserted */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[84].R = 0x0503;              /* Pad Configuration Register - PCR[84] */

  /* BIT 5: Primary Function - CNRXA - CAN Receive A */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Enabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[85].R = 0x0003;              /* Pad Configuration Register - PCR[85] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[86].R = 0x0003;              /* Pad Configuration Register - PCR[86] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[87].R = 0x0003;              /* Pad Configuration Register - PCR[87] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[88].R = 0x0003;              /* Pad Configuration Register - PCR[88] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
}

// ********************* EQADC Initialization Function *********************
void siu_eqadc_init_fcn(void)
{
  /* EQADC PAD Configuration */
  SIU.PCR[215].R = 0x0C00;             /* Pad Configuration Register - PCR[215] */

  /* BITS 4 & 5: Primary Function - Analog Input 12 */
  /* BIT 10: Output Drain - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  SIU.PCR[216].R = 0x0C00;             /* Pad Configuration Register - PCR[216] */

  /* BITS 4 & 5: Primary Function - Analog Input 13 */
  /* BIT 10: Output Drain - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  SIU.PCR[217].R = 0x0C00;             /* Pad Configuration Register - PCR[217] */

  /* BITS 4 & 5: Primary Function - Analog Input 14 */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[218].R = 0x0400;             /* Pad Configuration Register - PCR[218] */

  /* BIT 5: Primary Function - Analog Input 15 */
  /* BIT 10: Output Drain - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  SIU.PCR[111].R = 0x0003;             /* Pad Configuration Register - PCR[111] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[112].R = 0x0003;             /* Pad Configuration Register - PCR[112] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
}

// ********************* Reset Initialization Function *********************
void siu_reset_init_fcn(void)
{
  /* Reset PAD Configuration */
  SIU.PCR[208].R = 0x0C13;             /* Pad Configuration Register - PCR[208] */

  /* BITS 4 & 5: Primary Function - PLLCFG0 - function only applies during reset when the RSTCFG pin is asserted during reset */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Asserted */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[209].R = 0x0C13;             /* Pad Configuration Register - PCR[209] */

  /* BITS 3, 4, & 5: Primary Function - PLLCFG1 - function only applies during reset when the RSTCFG pin is asserted during reset */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Asserted */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[210].R = 0x0413;             /* Pad Configuration Register - PCR[210] */

  /* BIT 5: Primary Function - RSTCFG - function only applies during reset */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Asserted */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[211].R = 0x0C12;             /* Pad Configuration Register - PCR[211] */

  /* BITS 4 & 5: Primary Function - BOOTCFG0 - function only applies during reset when the RSTCFG pin is asserted during reset */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Asserted */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[212].R = 0x0C12;             /* Pad Configuration Register - PCR[212] */

  /* BITS 4 & 5: Primary Function - BOOTCFG1 - function only applies during reset when the RSTCFG pin is asserted during reset */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Asserted */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[213].R = 0x0413;             /* Pad Configuration Register - PCR[213] */

  /* BIT 5: Primary Function - WKPCFG - function only applies during reset */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Asserted */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
}

// ********************* DSPI Initialization Function *********************
void siu_dspi_init_fcn(void)
{
  /* DSPI PAD Configuration */
  SIU.PCR[93].R = 0x0003;              /* Pad Configuration Register - PCR[93] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[94].R = 0x0003;              /* Pad Configuration Register - PCR[94] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[95].R = 0x0003;              /* Pad Configuration Register - PCR[95] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[96].R = 0x0003;              /* Pad Configuration Register - PCR[96] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[97].R = 0x0003;              /* Pad Configuration Register - PCR[97] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[98].R = 0x0003;              /* Pad Configuration Register - PCR[98] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[99].R = 0x0003;              /* Pad Configuration Register - PCR[99] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[100].R = 0x0003;             /* Pad Configuration Register - PCR[100] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[101].R = 0x0003;             /* Pad Configuration Register - PCR[101] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[102].R = 0x0003;             /* Pad Configuration Register - PCR[102] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[103].R = 0x0003;             /* Pad Configuration Register - PCR[103] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[104].R = 0x0003;             /* Pad Configuration Register - PCR[104] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[105].R = 0x0003;             /* Pad Configuration Register - PCR[105] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[106].R = 0x0003;             /* Pad Configuration Register - PCR[106] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[107].R = 0x0003;             /* Pad Configuration Register - PCR[107] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Enabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[108].R = 0x0003;             /* Pad Configuration Register - PCR[108] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[109].R = 0x0003;             /* Pad Configuration Register - PCR[109] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[110].R = 0x0003;             /* Pad Configuration Register - PCR[110] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
}

// ********************* eMIOS Initialization Function *********************
void siu_emios_init_fcn(void)
{
  /* eMIOS PAD Configuration */
  SIU.PCR[179].R = 0x0E00;             /* Pad Configuration Register - PCR[179] */

  /* BITS 4 & 5: Primary Function - eMIOS Channel 0 to be used as an Output */
  /* BIT 6: Output Buffers - Enabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[180].R = 0x0003;             /* Pad Configuration Register - PCR[180] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[181].R = 0x0003;             /* Pad Configuration Register - PCR[181] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[182].R = 0x0003;             /* Pad Configuration Register - PCR[182] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[183].R = 0x0003;             /* Pad Configuration Register - PCR[183] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[184].R = 0x0003;             /* Pad Configuration Register - PCR[184] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[185].R = 0x0003;             /* Pad Configuration Register - PCR[185] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[186].R = 0x0003;             /* Pad Configuration Register - PCR[186] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[187].R = 0x0003;             /* Pad Configuration Register - PCR[187] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[188].R = 0x0003;             /* Pad Configuration Register - PCR[188] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[189].R = 0x0003;             /* Pad Configuration Register - PCR[189] */

  /* BIT 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[190].R = 0x0003;             /* Pad Configuration Register - PCR[190] */

  /* BIT 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[191].R = 0x0E00;             /* Pad Configuration Register - PCR[191] */

  /* BITS 4 & 5: Primary Function - eMIOS Channel 12 (Output Only) */
  /* BIT 6: Output Buffers - Enabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[192].R = 0x0003;             /* Pad Configuration Register - PCR[192] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[193].R = 0x0003;             /* Pad Configuration Register - PCR[193] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[194].R = 0x0003;             /* Pad Configuration Register - PCR[194] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[195].R = 0x0003;             /* Pad Configuration Register - PCR[195] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[196].R = 0x0003;             /* Pad Configuration Register - PCR[196] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[197].R = 0x0003;             /* Pad Configuration Register - PCR[197] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[198].R = 0x0003;             /* Pad Configuration Register - PCR[198] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[199].R = 0x0003;             /* Pad Configuration Register - PCR[199] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[200].R = 0x0003;             /* Pad Configuration Register - PCR[200] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[201].R = 0x0003;             /* Pad Configuration Register - PCR[201] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[202].R = 0x0003;             /* Pad Configuration Register - PCR[202] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
}

// ********************* eTPU Initialization Function *********************
void siu_etpu_init_fcn(void)
{
  /* eTPU PAD Configuration */
  SIU.PCR[113].R = 0x0003;             /* Pad Configuration Register - PCR[113] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[114].R = 0x0003;             /* Pad Configuration Register - PCR[114] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[115].R = 0x0003;             /* Pad Configuration Register - PCR[115] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[116].R = 0x0003;             /* Pad Configuration Register - PCR[116] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[117].R = 0x0D03;             /* Pad Configuration Register - PCR[117] */

  /* BITS 4 & 5: Primary Function - eTPU A Channel 3 configured as Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Enabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[118].R = 0x0D03;             /* Pad Configuration Register - PCR[118] */

  /* BITS 4 & 5: Primary Function - eTPU A Channel 4 configured as Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Enabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[119].R = 0x0D03;             /* Pad Configuration Register - PCR[119] */

  /* BITS 4 & 5: Primary Function - eTPU A Channel 5 configured as Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Enabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[120].R = 0x0003;             /* Pad Configuration Register - PCR[120] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[121].R = 0x0003;             /* Pad Configuration Register - PCR[121] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[122].R = 0x0003;             /* Pad Configuration Register - PCR[122] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[123].R = 0x0003;             /* Pad Configuration Register - PCR[123] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[124].R = 0x0003;             /* Pad Configuration Register - PCR[124] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[125].R = 0x0003;             /* Pad Configuration Register - PCR[125] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[126].R = 0x0003;             /* Pad Configuration Register - PCR[126] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[127].R = 0x0003;             /* Pad Configuration Register - PCR[127] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[128].R = 0x0603;             /* Pad Configuration Register - PCR[128] */

  /* BIT 5: Primary Function - eTPU A Channel 14 configured as Output */
  /* BIT 6: Output Buffers - Enabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[129].R = 0x0603;             /* Pad Configuration Register - PCR[129] */

  /* BIT 5: Primary Function - eTPU A Channel 15 configured as Output */
  /* BIT 6: Output Buffers - Enabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[130].R = 0x0603;             /* Pad Configuration Register - PCR[130] */

  /* BIT 5: Primary Function - eTPU A Channel 16 configured as Output */
  /* BIT 6: Output Buffers - Enabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[131].R = 0x0003;             /* Pad Configuration Register - PCR[131] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[132].R = 0x0003;             /* Pad Configuration Register - PCR[132] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[133].R = 0x0003;             /* Pad Configuration Register - PCR[133] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[134].R = 0x0003;             /* Pad Configuration Register - PCR[134] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[135].R = 0x0003;             /* Pad Configuration Register - PCR[135] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[136].R = 0x0003;             /* Pad Configuration Register - PCR[136] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[137].R = 0x0003;             /* Pad Configuration Register - PCR[137] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[138].R = 0x0003;             /* Pad Configuration Register - PCR[138] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[139].R = 0x0003;             /* Pad Configuration Register - PCR[139] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[140].R = 0x0003;             /* Pad Configuration Register - PCR[140] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[141].R = 0x0003;             /* Pad Configuration Register - PCR[141] */

  /* BITS 4 & 5: Primary Function - GPO - General Purpose Output */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[142].R = 0x0003;             /* Pad Configuration Register - PCR[142] */

  /* BIT 5: Primary Function - GPI - General Purpose Input*/
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[143].R = 0x0003;             /* Pad Configuration Register - PCR[143] */

  /* BIT 5: Primary Function - GPI - General Purpose Input*/
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[144].R = 0x0003;             /* Pad Configuration Register - PCR[144] */

  /* BIT 5: Primary Function - GPI - General Purpose Input*/
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[145].R = 0x0003;             /* Pad Configuration Register - PCR[145] */

  /* BIT 5: Primary Function - GPI - General Purpose Input*/
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[146].R = 0x0003;             /* Pad Configuration Register - PCR[146] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[147].R = 0x0003;             /* Pad Configuration Register - PCR[147] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[148].R = 0x0003;             /* Pad Configuration Register - PCR[148] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[149].R = 0x0003;             /* Pad Configuration Register - PCR[149] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[150].R = 0x0003;             /* Pad Configuration Register - PCR[150] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[151].R = 0x0003;             /* Pad Configuration Register - PCR[151] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[152].R = 0x0003;             /* Pad Configuration Register - PCR[152] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[153].R = 0x0003;             /* Pad Configuration Register - PCR[153] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[154].R = 0x0003;             /* Pad Configuration Register - PCR[154] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[155].R = 0x0003;             /* Pad Configuration Register - PCR[155] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[156].R = 0x0003;             /* Pad Configuration Register - PCR[156] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[157].R = 0x0003;             /* Pad Configuration Register - PCR[157] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[158].R = 0x0003;             /* Pad Configuration Register - PCR[158] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[159].R = 0x0003;             /* Pad Configuration Register - PCR[159] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[160].R = 0x0003;             /* Pad Configuration Register - PCR[160] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[161].R = 0x0003;             /* Pad Configuration Register - PCR[161] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[162].R = 0x0003;             /* Pad Configuration Register - PCR[162] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[163].R = 0x0003;             /* Pad Configuration Register - PCR[163] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[164].R = 0x0003;             /* Pad Configuration Register - PCR[164] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[165].R = 0x0003;             /* Pad Configuration Register - PCR[165] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[166].R = 0x0003;             /* Pad Configuration Register - PCR[166] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[167].R = 0x0003;             /* Pad Configuration Register - PCR[167] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[168].R = 0x0003;             /* Pad Configuration Register - PCR[168] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[169].R = 0x0003;             /* Pad Configuration Register - PCR[169] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[170].R = 0x0003;             /* Pad Configuration Register - PCR[170] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[171].R = 0x0003;             /* Pad Configuration Register - PCR[171] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[172].R = 0x0003;             /* Pad Configuration Register - PCR[172] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[173].R = 0x0003;             /* Pad Configuration Register - PCR[173] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[174].R = 0x0003;             /* Pad Configuration Register - PCR[174] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[175].R = 0x0003;             /* Pad Configuration Register - PCR[175] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[176].R = 0x0003;             /* Pad Configuration Register - PCR[176] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minimum */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[177].R = 0x0003;             /* Pad Configuration Register - PCR[177] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[178].R = 0x0003;             /* Pad Configuration Register - PCR[178] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BITS 12 & 13: Slew Rate - Minium */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
}

// ********************* Nexus/JTAG Initialization Function *********************
void siu_nexus_init_fcn(void)
{
  /* Nexua/JTAG PAD Configuration */
  SIU.PCR[75].R = 0x00C0;              /* Pad Configuration Register - PCR[75] */

  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[76].R = 0x00C0;              /* Pad Configuration Register - PCR[76] */

  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[77].R = 0x00C0;              /* Pad Configuration Register - PCR[77] */

  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[78].R = 0x00C0;              /* Pad Configuration Register - PCR[78] */

  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[79].R = 0x00C0;              /* Pad Configuration Register - PCR[79] */

  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[80].R = 0x00C0;              /* Pad Configuration Register - PCR[80] */

  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[81].R = 0x00C0;              /* Pad Configuration Register - PCR[81] */

  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[82].R = 0x00C0;              /* Pad Configuration Register - PCR[82] */

  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Disabled */
  /* BIT 15: Weak Pull Up/Dn Select - Down */
  SIU.PCR[219].R = 0x00C0;             /* Pad Configuration Register - PCR[219] */

  /* BITS 8 & 9: Drive Strength Control - 50pf */
  SIU.PCR[220].R = 0x00C0;             /* Pad Configuration Register - PCR[220] */

  /* BITS 8 & 9: Drive Strength Control - 50pf */
  SIU.PCR[221].R = 0x00C0;             /* Pad Configuration Register - PCR[221] */

  /* BITS 8 & 9: Drive Strength Control - 50pf */
  SIU.PCR[222].R = 0x00C0;             /* Pad Configuration Register - PCR[222] */

  /* BITS 8 & 9: Drive Strength Control - 50pf */
  SIU.PCR[223].R = 0x00C0;             /* Pad Configuration Register - PCR[223] */

  /* BITS 8 & 9: Drive Strength Control - 50pf */
  SIU.PCR[224].R = 0x00C0;             /* Pad Configuration Register - PCR[224] */

  /* BITS 8 & 9: Drive Strength Control - 50pf */
  SIU.PCR[225].R = 0x00C0;             /* Pad Configuration Register - PCR[225] */

  /* BITS 8 & 9: Drive Strength Control - 50pf */
  SIU.PCR[226].R = 0x00C0;             /* Pad Configuration Register - PCR[226] */

  /* BITS 8 & 9: Drive Strength Control - 50pf */
  SIU.PCR[227].R = 0x00C0;             /* Pad Configuration Register - PCR[227] */

  /* BITS 8 & 9: Drive Strength Control - 50pf */
  SIU.PCR[228].R = 0x00C0;             /* Pad Configuration Register - PCR[228] */

  /* BITS 8 & 9: Drive Strength Control - 50pf */
}

// ********************* Nexus/JTAG Initialization Function *********************
void siu_ebi_init_fcn(void)
{
  /* EBI PAD Configuration */
  SIU.PCR[0].R = 0x00C3;               /* Pad Configuration Register - PCR[0] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[1].R = 0x00C3;               /* Pad Configuration Register - PCR[1] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[2].R = 0x00C3;               /* Pad Configuration Register - PCR[2] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[3].R = 0x00C3;               /* Pad Configuration Register - PCR[3] */

  /* BITS 4 & 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[4].R = 0x00C3;               /* Pad Configuration Register - PCR[4] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[5].R = 0x00C3;               /* Pad Configuration Register - PCR[5] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[6].R = 0x00C3;               /* Pad Configuration Register - PCR[6] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[7].R = 0x00C3;               /* Pad Configuration Register - PCR[7] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[8].R = 0x00C3;               /* Pad Configuration Register - PCR[8] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[9].R = 0x00C3;               /* Pad Configuration Register - PCR[9] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[10].R = 0x00C3;              /* Pad Configuration Register - PCR[10] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[11].R = 0x00C3;              /* Pad Configuration Register - PCR[11] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[12].R = 0x00C3;              /* Pad Configuration Register - PCR[12] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[13].R = 0x00C3;              /* Pad Configuration Register - PCR[13] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[14].R = 0x00C3;              /* Pad Configuration Register - PCR[14] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[15].R = 0x00C3;              /* Pad Configuration Register - PCR[15] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[16].R = 0x00C3;              /* Pad Configuration Register - PCR[16] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[17].R = 0x00C3;              /* Pad Configuration Register - PCR[17] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[18].R = 0x00C3;              /* Pad Configuration Register - PCR[18] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[19].R = 0x00C3;              /* Pad Configuration Register - PCR[19] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[20].R = 0x00C3;              /* Pad Configuration Register - PCR[20] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[21].R = 0x00C3;              /* Pad Configuration Register - PCR[21] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[22].R = 0x00C3;              /* Pad Configuration Register - PCR[22] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[23].R = 0x00C3;              /* Pad Configuration Register - PCR[23] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[24].R = 0x00C3;              /* Pad Configuration Register - PCR[24] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[25].R = 0x00C3;              /* Pad Configuration Register - PCR[25] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[26].R = 0x00C3;              /* Pad Configuration Register - PCR[26] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[27].R = 0x00C3;              /* Pad Configuration Register - PCR[27] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[28].R = 0x00C3;              /* Pad Configuration Register - PCR[28] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[29].R = 0x00C3;              /* Pad Configuration Register - PCR[29] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[30].R = 0x00C3;              /* Pad Configuration Register - PCR[30] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[31].R = 0x00C3;              /* Pad Configuration Register - PCR[31] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[32].R = 0x00C3;              /* Pad Configuration Register - PCR[32] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[33].R = 0x00C3;              /* Pad Configuration Register - PCR[33] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[34].R = 0x00C3;              /* Pad Configuration Register - PCR[34] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[35].R = 0x00C3;              /* Pad Configuration Register - PCR[35] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[36].R = 0x00C3;              /* Pad Configuration Register - PCR[36] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[37].R = 0x00C3;              /* Pad Configuration Register - PCR[37] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[38].R = 0x00C3;              /* Pad Configuration Register - PCR[38] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[39].R = 0x00C3;              /* Pad Configuration Register - PCR[39] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[40].R = 0x00C3;              /* Pad Configuration Register - PCR[40] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[41].R = 0x00C3;              /* Pad Configuration Register - PCR[41] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[42].R = 0x00C3;              /* Pad Configuration Register - PCR[42] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[43].R = 0x00C3;              /* Pad Configuration Register - PCR[43] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[44].R = 0x00C3;              /* Pad Configuration Register - PCR[44] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[45].R = 0x00C3;              /* Pad Configuration Register - PCR[45] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[46].R = 0x00C3;              /* Pad Configuration Register - PCR[46] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[47].R = 0x00C3;              /* Pad Configuration Register - PCR[47] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[48].R = 0x00C3;              /* Pad Configuration Register - PCR[48] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[49].R = 0x00C3;              /* Pad Configuration Register - PCR[49] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[50].R = 0x00C3;              /* Pad Configuration Register - PCR[50] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[51].R = 0x00C3;              /* Pad Configuration Register - PCR[51] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[52].R = 0x00C3;              /* Pad Configuration Register - PCR[52] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[53].R = 0x00C3;              /* Pad Configuration Register - PCR[53] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[54].R = 0x00C3;              /* Pad Configuration Register - PCR[54] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[55].R = 0x00C3;              /* Pad Configuration Register - PCR[55] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[56].R = 0x00C3;              /* Pad Configuration Register - PCR[56] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[57].R = 0x00C3;              /* Pad Configuration Register - PCR[57] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[58].R = 0x00C3;              /* Pad Configuration Register - PCR[58] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[59].R = 0x00C3;              /* Pad Configuration Register - PCR[59] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[60].R = 0x00C3;              /* Pad Configuration Register - PCR[60] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[61].R = 0x00C3;              /* Pad Configuration Register - PCR[61] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[62].R = 0x00C3;              /* Pad Configuration Register - PCR[62] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[63].R = 0x00C3;              /* Pad Configuration Register - PCR[63] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[64].R = 0x00C3;              /* Pad Configuration Register - PCR[64] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[65].R = 0x00C3;              /* Pad Configuration Register - PCR[65] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[66].R = 0x00C3;              /* Pad Configuration Register - PCR[66] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[67].R = 0x00C3;              /* Pad Configuration Register - PCR[67] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[68].R = 0x00C3;              /* Pad Configuration Register - PCR[68] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[69].R = 0x00C3;              /* Pad Configuration Register - PCR[69] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[70].R = 0x00C3;              /* Pad Configuration Register - PCR[70] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[71].R = 0x00C3;              /* Pad Configuration Register - PCR[71] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 50pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[72].R = 0x0003;              /* Pad Configuration Register - PCR[72] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 10pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[73].R = 0x0003;              /* Pad Configuration Register - PCR[73] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 10pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
  SIU.PCR[74].R = 0x0003;              /* Pad Configuration Register - PCR[74] */

  /* BIT 5: Primary Function - GPI - General Purpose Input */
  /* BIT 6: Output Buffers - Disabled */
  /* BIT 7: Input Buffers - Disabled */
  /* BITS 8 & 9: Drive Strength Control - 10pf */
  /* BIT 10: Output Drain - Negated */
  /* BIT 11: Input Hysteresis - Negated */
  /* BIT 14: Weak Pull Up/Dn - Enabled */
  /* BIT 15: Weak Pull Up/Dn Select - Up */
}

/* **********************************************************************
 *
 *                           End of File
 *
 * ********************************************************************* */

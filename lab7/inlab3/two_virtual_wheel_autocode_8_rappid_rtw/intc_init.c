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
 *  FunctionName::intc_init::FunctionName
 *
 *  Date : 21-Sep-2017  Time : 16:40:37.432
 *
 * ####################################################################### */

// ************************** Pragma Section **************************

// ################### User Custom Code Section #########################
//  User Custom Code Section ::intc_init::custom_start::

//  ::custom_end::        User Custom Code Section ::intc_init::
// ################### User Custom Code Section #########################
// ******************  Dependent Include files Here **********************
#include "mpc5554.h"
#include "intc_init.h"

// ################### User Custom Code Section #########################
//  User Custom Code Section ::intc_init::includes_start::

//  ::includes_end::      User Custom Code Section ::intc_init::
// ################### User Custom Code Section #########################

// ################### User Custom Code Section #########################
//  User Custom Code Section ::intc_init::custom_start::

//  ::custom_end::        User Custom Code Section ::intc_init::
// ################### User Custom Code Section #########################
// ********************* INTC Initialization Function *********************
void intc_init_fcn(void)
{
  /* INTC General Setup */
  INTC.MCR.R = 0x00000000;             /* Block Control Register - BCR */

  /* Bit 26 - The vector table size is: 4 bytes */
  /* Bit 31 - The module is in Software Vector Mode */
  INTC.IACKR.R = 0x40000000;           /* Interrupt Acknowledge Register - IACKR */

  /* Bits 0-21 - The vector base address is: 4*/
  INTC.PSR[0].R = 0x00;                /* Prioirty Set Register - PSR */

  /* Software Settable Flag 0 Priority is: 0*/
  INTC.PSR[1].R = 0x00;                /* Prioirty Set Register - PSR */

  /* Software Settable Flag 1 Priority is: 0*/
  INTC.PSR[2].R = 0x00;                /* Prioirty Set Register - PSR */

  /* Software Settable Flag 2 Priority is: 0*/
  INTC.PSR[3].R = 0x00;                /* Prioirty Set Register - PSR */

  /* Software Settable Flag 3 Priority is: 0*/
  INTC.PSR[4].R = 0x00;                /* Prioirty Set Register - PSR */

  /* Software Settable Flag 4 Priority is: 0*/
  INTC.PSR[5].R = 0x00;                /* Prioirty Set Register - PSR */

  /* Software Settable Flag 5 Priority is: 0*/
  INTC.PSR[6].R = 0x00;                /* Prioirty Set Register - PSR */

  /* Software Settable Flag 6 Priority is: 0*/
  INTC.PSR[7].R = 0x00;                /* Prioirty Set Register - PSR */

  /* Software Settable Flag 7 Priority is: 0*/
  INTC.PSR[8].R = 0x00;                /* Prioirty Set Register - PSR */

  /* Watchdog Priority is: 0*/
  INTC.PSR[9].R = 0x00;                /* Prioirty Set Register - PSR */

  /* RAM/Flash Non-correctable Error Priority is: 0*/
  INTC.PSR[10].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel Error Flags 31-0 Priority is: 0*/
  INTC.PSR[11].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 0 Priority is: 0*/
  INTC.PSR[12].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 1 Priority is: 0*/
  INTC.PSR[13].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 2 Priority is: 0*/
  INTC.PSR[14].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 3 Priority is: 0*/
  INTC.PSR[15].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 4 Priority is: 0*/
  INTC.PSR[16].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 5 Priority is: 0*/
  INTC.PSR[17].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 6 Priority is: 0*/
  INTC.PSR[18].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 7 Priority is: 0*/
  INTC.PSR[19].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 8 Priority is: 0*/
  INTC.PSR[20].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 9 Priority is: 0*/
  INTC.PSR[21].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 10 Priority is: 0*/
  INTC.PSR[22].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 11 Priority is: 0*/
  INTC.PSR[23].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 12 Priority is: 0*/
  INTC.PSR[24].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 13 Priority is: 0*/
  INTC.PSR[25].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 14 Priority is: 0*/
  INTC.PSR[26].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 15 Priority is: 0*/
  INTC.PSR[27].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 16 Priority is: 0*/
  INTC.PSR[28].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 17 Priority is: 0*/
  INTC.PSR[29].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 18 Priority is: 0*/
  INTC.PSR[30].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 19 Priority is: 0*/
  INTC.PSR[31].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 20 Priority is: 0*/
  INTC.PSR[32].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 21 Priority is: 0*/
  INTC.PSR[33].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 22 Priority is: 0*/
  INTC.PSR[34].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 23 Priority is: 0*/
  INTC.PSR[35].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 24 Priority is: 0*/
  INTC.PSR[36].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 25 Priority is: 0*/
  INTC.PSR[37].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 26 Priority is: 0*/
  INTC.PSR[38].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 27 Priority is: 0*/
  INTC.PSR[39].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 28 Priority is: 0*/
  INTC.PSR[40].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 29 Priority is: 0*/
  INTC.PSR[41].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 30 Priority is: 0*/
  INTC.PSR[42].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eDMA Channel 31 Priority is: 0*/
  INTC.PSR[43].R = 0x00;               /* Prioirty Set Register - PSR */

  /* PLL Loss of Clock Priority is: 0*/
  INTC.PSR[44].R = 0x00;               /* Prioirty Set Register - PSR */

  /* PLL Loss of Lock Priority is: 0*/
  INTC.PSR[45].R = 0x00;               /* Prioirty Set Register - PSR */

  /* SIU Combined Overrun Priority is: 0*/
  INTC.PSR[46].R = 0x00;               /* Prioirty Set Register - PSR */

  /* SIU External Flag 0 Priority is: 0*/
  INTC.PSR[47].R = 0x00;               /* Prioirty Set Register - PSR */

  /* SIU External Flag 1 Priority is: 0*/
  INTC.PSR[48].R = 0x00;               /* Prioirty Set Register - PSR */

  /* SIU External Flag 2 Priority is: 0*/
  INTC.PSR[49].R = 0x00;               /* Prioirty Set Register - PSR */

  /* SIU External Flag 3 Priority is: 0*/
  INTC.PSR[50].R = 0x00;               /* Prioirty Set Register - PSR */

  /* SIU External Flag 4 Priority is: 0*/
  INTC.PSR[51].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 0 Priority is: 0*/
  INTC.PSR[52].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 1 Priority is: 0*/
  INTC.PSR[53].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 2 Priority is: 0*/
  INTC.PSR[54].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 3 Priority is: 0*/
  INTC.PSR[55].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 4 Priority is: 0*/
  INTC.PSR[56].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 5 Priority is: 0*/
  INTC.PSR[57].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 6 Priority is: 0*/
  INTC.PSR[58].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 7 Priority is: 0*/
  INTC.PSR[59].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 8 Priority is: 0*/
  INTC.PSR[60].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 9 Priority is: 0*/
  INTC.PSR[61].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 10 Priority is: 0*/
  INTC.PSR[62].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 11 Priority is: 0*/
  INTC.PSR[63].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 12 Priority is: 0*/
  INTC.PSR[64].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 13 Priority is: 0*/
  INTC.PSR[65].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 14 Priority is: 0*/
  INTC.PSR[66].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eMIOS Channel 15 Priority is: 0*/
  INTC.PSR[67].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU Global Exception Priority is: 0*/
  INTC.PSR[68].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 0 Priority is: 0*/
  INTC.PSR[69].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 1 Priority is: 0*/
  INTC.PSR[70].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 2 Priority is: 0*/
  INTC.PSR[71].R = 0x04;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 3 Priority is: 4*/
  INTC.PSR[72].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 4 Priority is: 0*/
  INTC.PSR[73].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 5 Priority is: 0*/
  INTC.PSR[74].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 6 Priority is: 0*/
  INTC.PSR[75].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 7 Priority is: 0*/
  INTC.PSR[76].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 8 Priority is: 0*/
  INTC.PSR[77].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 9 Priority is: 0*/
  INTC.PSR[78].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 10 Priority is: 0*/
  INTC.PSR[79].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 11 Priority is: 0*/
  INTC.PSR[80].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 12 Priority is: 0*/
  INTC.PSR[81].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 13 Priority is: 0*/
  INTC.PSR[82].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 14 Priority is: 0*/
  INTC.PSR[83].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 15 Priority is: 0*/
  INTC.PSR[84].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 16 Priority is: 0*/
  INTC.PSR[85].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 17 Priority is: 0*/
  INTC.PSR[86].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 18 Priority is: 0*/
  INTC.PSR[87].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 19 Priority is: 0*/
  INTC.PSR[88].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 20 Priority is: 0*/
  INTC.PSR[89].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 21 Priority is: 0*/
  INTC.PSR[90].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 22 Priority is: 0*/
  INTC.PSR[91].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 23 Priority is: 0*/
  INTC.PSR[92].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 24 Priority is: 0*/
  INTC.PSR[93].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 25 Priority is: 0*/
  INTC.PSR[94].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 26 Priority is: 0*/
  INTC.PSR[95].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 27 Priority is: 0*/
  INTC.PSR[96].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 28 Priority is: 0*/
  INTC.PSR[97].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 29 Priority is: 0*/
  INTC.PSR[98].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 30 Priority is: 0*/
  INTC.PSR[99].R = 0x00;               /* Prioirty Set Register - PSR */

  /* eTPU 1 Channel 31 Priority is: 0*/
  INTC.PSR[100].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Combined Overrun Priority is: 0*/
  INTC.PSR[101].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 0 Non-Coherency Priority is: 0*/
  INTC.PSR[102].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 0 Pause Flag Priority is: 0*/
  INTC.PSR[103].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 0 Command Queue End Of Queue Flag Priority is: 0*/
  INTC.PSR[104].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 0 Fill Flag Priority is: 0*/
  INTC.PSR[105].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 0 Drain Flag Priority is: 0*/
  INTC.PSR[106].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 1 Non-Coherency Priority is: 0*/
  INTC.PSR[107].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 1 Pause Flag Priority is: 0*/
  INTC.PSR[108].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 1 Command Queue End Of Queue Flag Priority is: 0*/
  INTC.PSR[109].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 1 Fill Flag Priority is: 0*/
  INTC.PSR[110].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 1 Drain Flag Priority is: 0*/
  INTC.PSR[111].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 2 Non-Coherency Priority is: 0*/
  INTC.PSR[112].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 2 Pause Flag Priority is: 0*/
  INTC.PSR[113].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 2 Command Queue End Of Queue Flag Priority is: 0*/
  INTC.PSR[114].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 2 Fill Flag Priority is: 0*/
  INTC.PSR[115].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 2 Drain Flag Priority is: 0*/
  INTC.PSR[116].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 3 Non-Coherency Priority is: 0*/
  INTC.PSR[117].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 3 Pause Flag Priority is: 0*/
  INTC.PSR[118].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 3 Command Queue End Of Queue Flag Priority is: 0*/
  INTC.PSR[119].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 3 Fill Flag Priority is: 0*/
  INTC.PSR[120].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 3 Drain Flag Priority is: 0*/
  INTC.PSR[121].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 4 Non-Coherency Priority is: 0*/
  INTC.PSR[122].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 4 Pause Flag Priority is: 0*/
  INTC.PSR[123].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 4 Command Queue End Of Queue Flag Priority is: 0*/
  INTC.PSR[124].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 4 Fill Flag Priority is: 0*/
  INTC.PSR[125].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 4 Drain Flag Priority is: 0*/
  INTC.PSR[126].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 5 Non-Coherency Priority is: 0*/
  INTC.PSR[127].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 5 Pause Flag Priority is: 0*/
  INTC.PSR[128].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 5 Command Queue End Of Queue Flag Priority is: 0*/
  INTC.PSR[129].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 5 Fill Flag Priority is: 0*/
  INTC.PSR[130].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 2 Fill Flag Priority is: 0*/
  INTC.PSR[131].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eQADC Command FIFO 5 Drain Flag Priority is: 0*/
  INTC.PSR[132].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-B Transmit FIFO End Of Queue Priority is: 0*/
  INTC.PSR[133].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-B Transmit FIFO Fill Flag Priority is: 0*/
  INTC.PSR[134].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-B Transmit FIFO Complete Flag Priority is: 0*/
  INTC.PSR[135].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-B Receive FIFO Drain Flag Priority is: 0*/
  INTC.PSR[136].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-C Overrun Priority is: 0*/
  INTC.PSR[137].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-C Transmit FIFO End Of Queue Priority is: 0*/
  INTC.PSR[138].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-C Transmit FIFO Fill Flag Priority is: 0*/
  INTC.PSR[139].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-C Transmit FIFO Complete Flag Priority is: 0*/
  INTC.PSR[140].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-C Receive FIFO Drain Flag Priority is: 0*/
  INTC.PSR[141].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-D Overrun Priority is: 0*/
  INTC.PSR[142].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-D Transmit FIFO End Of Queue Priority is: 0*/
  INTC.PSR[143].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-D Transmit FIFO Fill Flag Priority is: 0*/
  INTC.PSR[144].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-D Transmit FIFO Complete Flag Priority is: 0*/
  INTC.PSR[145].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-D Receive FIFO Drain Flag Priority is: 0*/
  INTC.PSR[146].R = 0x00;              /* Prioirty Set Register - PSR */

  /* SCI A Combined Priority is: 0*/
  INTC.PSR[149].R = 0x00;              /* Prioirty Set Register - PSR */

  /* SCI B Combined Priority is: 0*/
  INTC.PSR[152].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Bus Off Priority is: 0*/
  INTC.PSR[153].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Error Priority is: 0*/
  INTC.PSR[155].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 0 Priority is: 0*/
  INTC.PSR[156].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 1 Priority is: 0*/
  INTC.PSR[157].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 2 Priority is: 0*/
  INTC.PSR[158].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 3 Priority is: 0*/
  INTC.PSR[159].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 4 Priority is: 0*/
  INTC.PSR[160].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 5 Priority is: 0*/
  INTC.PSR[161].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 6 Priority is: 0*/
  INTC.PSR[162].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 7 Priority is: 0*/
  INTC.PSR[163].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 8 Priority is: 0*/
  INTC.PSR[164].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 9 Priority is: 0*/
  INTC.PSR[165].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 10 Priority is: 0*/
  INTC.PSR[166].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 11 Priority is: 0*/
  INTC.PSR[167].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 12 Priority is: 0*/
  INTC.PSR[168].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 13 Priority is: 0*/
  INTC.PSR[169].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 14 Priority is: 0*/
  INTC.PSR[170].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 15 Priority is: 0*/
  INTC.PSR[171].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 31-0 Priority is: 0*/
  INTC.PSR[172].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN A Buffer 63-32 Priority is: 0*/
  INTC.PSR[173].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Bus Off Priority is: 0*/
  INTC.PSR[174].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Error Priority is: 0*/
  INTC.PSR[176].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 0 Priority is: 0*/
  INTC.PSR[177].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 1 Priority is: 0*/
  INTC.PSR[178].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 2 Priority is: 0*/
  INTC.PSR[179].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 3 Priority is: 0*/
  INTC.PSR[180].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 4 Priority is: 0*/
  INTC.PSR[181].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 5 Priority is: 0*/
  INTC.PSR[182].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 6 Priority is: 0*/
  INTC.PSR[183].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 7 Priority is: 0*/
  INTC.PSR[184].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 8 Priority is: 0*/
  INTC.PSR[185].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 9 Priority is: 0*/
  INTC.PSR[186].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 10 Priority is: 0*/
  INTC.PSR[187].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 11 Priority is: 0*/
  INTC.PSR[188].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 12 Priority is: 0*/
  INTC.PSR[189].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 13 Priority is: 0*/
  INTC.PSR[190].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 14 Priority is: 0*/
  INTC.PSR[191].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 15 Priority is: 0*/
  INTC.PSR[192].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 31-0 Priority is: 0*/
  INTC.PSR[193].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN C Buffer 63-32 Priority is: 0*/
  INTC.PSR[202].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eMIOS Channel 16 Priority is: 0*/
  INTC.PSR[203].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eMIOS Channel 17 Priority is: 0*/
  INTC.PSR[204].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eMIOS Channel 18 Priority is: 0*/
  INTC.PSR[205].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eMIOS Channel 19 Priority is: 0*/
  INTC.PSR[206].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eMIOS Channel 20 Priority is: 0*/
  INTC.PSR[207].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eMIOS Channel 21 Priority is: 0*/
  INTC.PSR[208].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eMIOS Channel 22 Priority is: 0*/
  INTC.PSR[209].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eMIOS Channel 23 Priority is: 0*/
  INTC.PSR[210].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel Error Flags 63-32 Priority is: 0*/
  INTC.PSR[211].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 32 Priority is: 0*/
  INTC.PSR[212].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 33 Priority is: 0*/
  INTC.PSR[213].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 34 Priority is: 0*/
  INTC.PSR[214].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 35 Priority is: 0*/
  INTC.PSR[215].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 36 Priority is: 0*/
  INTC.PSR[216].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 37 Priority is: 0*/
  INTC.PSR[217].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 38 Priority is: 0*/
  INTC.PSR[218].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 39 Priority is: 0*/
  INTC.PSR[219].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 40 Priority is: 0*/
  INTC.PSR[220].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 41 Priority is: 0*/
  INTC.PSR[221].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 42 Priority is: 0*/
  INTC.PSR[222].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 43 Priority is: 0*/
  INTC.PSR[223].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 44 Priority is: 0*/
  INTC.PSR[224].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 45 Priority is: 0*/
  INTC.PSR[225].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 46 Priority is: 0*/
  INTC.PSR[226].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 47 Priority is: 0*/
  INTC.PSR[227].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 48 Priority is: 0*/
  INTC.PSR[228].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 49 Priority is: 0*/
  INTC.PSR[229].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 50 Priority is: 0*/
  INTC.PSR[230].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 51 Priority is: 0*/
  INTC.PSR[231].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 52 Priority is: 0*/
  INTC.PSR[232].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 53 Priority is: 0*/
  INTC.PSR[233].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 54 Priority is: 0*/
  INTC.PSR[234].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 55 Priority is: 0*/
  INTC.PSR[235].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 56 Priority is: 0*/
  INTC.PSR[236].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 57 Priority is: 0*/
  INTC.PSR[237].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 58 Priority is: 0*/
  INTC.PSR[238].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 59 Priority is: 0*/
  INTC.PSR[239].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 60 Priority is: 0*/
  INTC.PSR[240].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 61 Priority is: 0*/
  INTC.PSR[241].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 62 Priority is: 0*/
  INTC.PSR[242].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eDMA Channel 63 Priority is: 0*/
  INTC.PSR[243].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 0 Priority is: 0*/
  INTC.PSR[244].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 1 Priority is: 0*/
  INTC.PSR[245].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 2 Priority is: 0*/
  INTC.PSR[246].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 3 Priority is: 0*/
  INTC.PSR[247].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 4 Priority is: 0*/
  INTC.PSR[248].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 5 Priority is: 0*/
  INTC.PSR[249].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 6 Priority is: 0*/
  INTC.PSR[250].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 7 Priority is: 0*/
  INTC.PSR[251].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 8 Priority is: 0*/
  INTC.PSR[252].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 9 Priority is: 0*/
  INTC.PSR[253].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 10 Priority is: 0*/
  INTC.PSR[254].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 11 Priority is: 0*/
  INTC.PSR[255].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 12 Priority is: 0*/
  INTC.PSR[256].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 13 Priority is: 0*/
  INTC.PSR[257].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 14 Priority is: 0*/
  INTC.PSR[258].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 15 Priority is: 0*/
  INTC.PSR[259].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 16 Priority is: 0*/
  INTC.PSR[260].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 17 Priority is: 0*/
  INTC.PSR[261].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 18 Priority is: 0*/
  INTC.PSR[262].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 19 Priority is: 0*/
  INTC.PSR[263].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 20 Priority is: 0*/
  INTC.PSR[264].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 21 Priority is: 0*/
  INTC.PSR[265].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 22 Priority is: 0*/
  INTC.PSR[266].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 23 Priority is: 0*/
  INTC.PSR[267].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 24 Priority is: 0*/
  INTC.PSR[268].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 25 Priority is: 0*/
  INTC.PSR[269].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 26 Priority is: 0*/
  INTC.PSR[270].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 27 Priority is: 0*/
  INTC.PSR[271].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 28 Priority is: 0*/
  INTC.PSR[272].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 29 Priority is: 0*/
  INTC.PSR[273].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 30 Priority is: 0*/
  INTC.PSR[274].R = 0x00;              /* Prioirty Set Register - PSR */

  /* eTPU 2 Channel 31 Priority is: 0*/
  INTC.PSR[275].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-A Overrun Priority is: 0*/
  INTC.PSR[276].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-A Transmit FIFO End Of Queue Priority is: 0*/
  INTC.PSR[277].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-A Transmit FIFO Fill Flag Priority is: 0*/
  INTC.PSR[278].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-A Transmit FIFO Complete Flag Priority is: 0*/
  INTC.PSR[279].R = 0x00;              /* Prioirty Set Register - PSR */

  /* DSPI-D Receive FIFO Drain Flag Priority is: 0*/
  INTC.PSR[280].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Bus Off Priority is: 0*/
  INTC.PSR[281].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Error Priority is: 0*/
  INTC.PSR[283].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 0 Priority is: 0*/
  INTC.PSR[284].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 1 Priority is: 0*/
  INTC.PSR[285].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 2 Priority is: 0*/
  INTC.PSR[286].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 3 Priority is: 0*/
  INTC.PSR[287].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 4 Priority is: 0*/
  INTC.PSR[288].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 5 Priority is: 0*/
  INTC.PSR[289].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 6 Priority is: 0*/
  INTC.PSR[290].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 7 Priority is: 0*/
  INTC.PSR[291].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 8 Priority is: 0*/
  INTC.PSR[292].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 9 Priority is: 0*/
  INTC.PSR[293].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 10 Priority is: 0*/
  INTC.PSR[294].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 11 Priority is: 0*/
  INTC.PSR[295].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 12 Priority is: 0*/
  INTC.PSR[296].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 13 Priority is: 0*/
  INTC.PSR[297].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 14 Priority is: 0*/
  INTC.PSR[298].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 15 Priority is: 0*/
  INTC.PSR[299].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 31-0 Priority is: 0*/
  INTC.PSR[300].R = 0x00;              /* Prioirty Set Register - PSR */

  /* FlexCAN B Buffer 31-0 Priority is: 0*/
  /* FlexCAN B Buffer 63-32 Priority is: 0*/
}

// ********************* Interrupt Enable Function *********************
void en_int_fcn(vuint32_t priority)
{
  /* Enable Routine - Priority equal 0-15 (0 - Enable All interrupts, 15 - Disable All interrupts) */
  INTC.CPR.B.PRI = priority;           /* Set the current priority equal to input */
  asm(" wrteei 1");                    /*  Compiler specific to Metroworks  */
}

/* **********************************************************************
 *
 *                           End of File
 *
 * ********************************************************************* */

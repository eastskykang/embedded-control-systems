/**************************************************************************
 *
 * Title: Functions to Read and Write EQADC data
 *
 * Filename: eQADC_library.c
 *
 *
 * First used on: MPC5554
 *
 * Compiler:
 *
 * Creation date:		02/21/06
 * $Author: B04496 $
 *
 * Copyright Freescale Semiconductor Inc
 * 2006 All Rights Reserved
 *
 * Notes :
 * <RELEVANT information only - leave blank if none>
 *
 *
 * Revision History :
 *  $Date: 2006/09/13 20:16:20 $
 *
 *
 *************************************************************************/

#include "eTPU_library.h"

/****************************************************************************
 // @Function      void etpu_clear_isr_flag_fnc(uint8_t chan)
 //
 //----------------------------------------------------------------------------
 // @Description   Clears ISR Flag for PC overflow/underflow
 //
 //----------------------------------------------------------------------------
 // @Returnvalue   None
 //
 //----------------------------------------------------------------------------
 // @Parameters    :
 //                Number of the message object (0-63)
 //
 //----------------------------------------------------------------------------
 // @Date          12/23/2005
 //
 ****************************************************************************
 */
void etpu_clear_isr_flag_fnc(uint8_t chan)
{
  ETPU.CHAN[chan].SCR.B.CIS= 1;
}

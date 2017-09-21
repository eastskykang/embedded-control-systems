/**************************************************************************
 *
 * Title: Functions to Read and Write GPIO data
 *
 * Filename: GPIO_library.c
 *
 *
 * First used on: MPC5554
 *
 * Compiler:
 *
 * Creation date:		12/20/05
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

#include "GPIO_library.h"

/* GPI Read Data function */
uint8_t gpi_readdata_fnc(uint8_t pin_no)
{
  uint8_t inputdata = 0;

  /* Read data from GPIO Pin Data Input Registers  */
  inputdata = SIU.GPDI[pin_no].R;
  return(inputdata);
}

/* GPO Write Data function */
void gpo_writedata_fnc(uint8_t pin_no, uint8_t data)
{
  /* Write data to GPIO Pin Data output Registers  */
  SIU.GPDO[pin_no].R = data;
}

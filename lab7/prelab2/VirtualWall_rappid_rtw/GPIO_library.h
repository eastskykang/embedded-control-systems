/**************************************************************************
 *
 * Title: Declarations for GPIO_library.c file and GPIO Registers
 *
 * Filename: GPIO_library.h
 *
 *
 * First used on: MPC5554
 *
 * Compiler:
 *
 * Creation date:		05/20/05
 * Date last modified:	$Author: r61406 $
 *
 *
 *
 * Notes :
 * <RELEVANT information only - leave blank if none>
 *
 *
 * Revision History :
 *
 *
 *
 *************************************************************************/

#ifndef _GPIO_LIBRARY_H
#define _GPIO_LIBRARY_H
#include "RAppID_Blockset.h"

/* GPI Read Data function */
uint8_t gpi_readdata_fnc(uint8_t);

/* GPO Write Data function */
void gpo_writedata_fnc(uint8_t, uint8_t);

#endif

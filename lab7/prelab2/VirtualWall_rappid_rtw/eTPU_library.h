/**************************************************************************
 *
 * Title: Declarations for eTPU_library.c file and TPU Registers
 *
 * Filename: eTPU_library.h
 *
 *
 * First used on: MPC5554
 *
 * Compiler:
 *
 * Creation date:		02/21/06
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

#ifndef _ETPU_LIBRARY_H
#define _ETPU_LIBRARY_H
#include "typedefs.h"

typedef uint32_t ufract24_t;
typedef int32_t fract24_t;
typedef uint32_t uint24_t;
typedef int32_t int24_t;

#include "RAppID_Blockset.h"

/* eTPU pc Overflow Clear ISR Flag function */
void etpu_clear_isr_flag_fnc(uint8_t);

#endif

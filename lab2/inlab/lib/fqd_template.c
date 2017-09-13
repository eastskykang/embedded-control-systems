/**************************************************************************
 * FILE NAME:  fqd_template.c
 *
 * EECS461 at the University of Michigan
 * Quadrature Decode Library File (template)
 *
 * Created 6-23-06, Jeff Lovell
 *
 * Revision History:
 *   7-27-06 lovelljc
 *   8-28-06 ericjw
 *   9-08-06 ericjw, gdasika
 *
 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * See Chapter 18 in MPC5553/5554 Reference Manual and eTPU Preliminary Reference Manual (ETPURM.pdf)
 *
 * Revision History:
 *	2008-09-04		Marianne Schmid
 *  2011-02-07		Thomas Schneider
 *  2012-06-06		Pascal Lutz
 **************************************************************************/

#include <fqd.h>
#include <mpc5553_vars.h>
#include <mpc5553.h>
#include <etpu_set.h>
#include <etpu_util.h>
#include <etpu_qd.h>
#include <etpu_ppa.h>

#define etpu_tcr1_frq 20000000      /* 20 MHz */
#define INITIAL_POSITION 0x0000     /* Position counter start value (24-bit signed integer) */
#define ECS_QD_CHANNEL /* Fill in */    /* Primary eTPU channel: Use eTPU channel 3 for QD and ECS interface board that corresponds to connector Encoder 2 */


void init_FQD()
{
    static int32_t error_code;
	int i;

    /* See etpu_util.c/h and document AN2864 for eTPU setup descriptions */
    struct etpu_config_t my_etpu_config = {
		FS_ETPU_MISC_ENABLE,    /*MCR register*/
		FS_ETPU_MISC,           /*MISC value from eTPU compiler link file*/
								/*Configure eTPU engine A*/
		FS_ETPU_FILTER_CLOCK_DIV8 +
		FS_ETPU_CHAN_FILTER_3SAMPLE +
		FS_ETPU_ENTRY_TABLE,
								/*Configure eTPU engine A timebases*/
		FS_ETPU_TCR2CTL_DIV8 +
		( 7 << 16) +            /*TCR2 prescaler of 8 (7+1)*/
		FS_ETPU_TCR1CTL_DIV2 +
		0,                      /*TCR1 prescaler of 1 */
		0,                      /* STAC not used */
								/*Configure eTPU engine B*/
		FS_ETPU_FILTER_CLOCK_DIV4 +
		FS_ETPU_CHAN_FILTER_3SAMPLE +
		FS_ETPU_ENTRY_TABLE,
								/*Configure eTPU engine B timebases*/
		FS_ETPU_TCR2CTL_DIV8 +
		( 7 << 16) +            /*TCR2 prescaler of 8 (7+1)*/
		FS_ETPU_TCR1CTL_DIV2 +
		3,                      /* TCR2 prescaler of 4 */
		0                       /* STAC not used */
	};


    /* etpu_code and etpu_globals from etpu_set3.h */
    fs_etpu_init( my_etpu_config, (uint32_t *)etpu_code, sizeof(etpu_code),
                  (uint32_t *)etpu_globals, sizeof(etpu_globals));

    /* Using eTPU(A) channels defined above */
    /* See etpu_qd.h and document AN2842 for QD function descriptions */
    error_code = fs_etpu_qd_init(
		/* Fill in */,           		 /* Set primary channel here: <set above> */
		ETPU_CHAN_NOT_USED,              /* Home channel is not used */
		ETPU_CHAN_NOT_USED,	             /* Index channel is not used */
		/* Fill in  */,             	 /* signals */
		FS_ETPU_PRIORITY_HIGH,           /* priority: High */
		FS_ETPU_QD_CONFIGURATION_0,      /* configuration: 0 */
		FS_ETPU_TCR1,                    /* timer: TCR1 */
		0,                               /* pc_max: 0 */
									     /* we operate only in slow mode */
		/* Fill in */,         			 /* slow_normal_threshold */
		/* Fill in */,            		 /* normal_slow_threshold */
		/* Fill in */,            		 /* normal_fast_threshold */
		/* Fill in */,            		 /* fast_normal_threshold */
		0x733333,		             	 /* window ratio 1: 0.9 * 2^23 */
		0x8CCCCC,                   	 /* window ratio 2: 1.1 * 2^23 */
		FS_ETPU_QD_HOME_TRANS_LOW_HIGH,  /* Detect. of low-high transition on Home chan.*/
		FS_ETPU_QD_INDEX_PULSE_POSITIVE, /* Index pulse of positive polarity */
		FS_ETPU_QD_INDEX_PC_NO_RESET,    /* PC is NOT reset to pc_init on Index transition */
		/* Fill in */,      			 /* frequency of eTPU engine A - TCR1 */
		/* Fill in */);		             /* qd_pc_per_rev (we use a 1000-pulse encoder with 2 channels) */



    /* initialize the position counter by calling the appropriate function */
    fs_etpu_qd_set_pc(ECS_QD_CHANNEL, INITIAL_POSITION);


    /* set pads 117 and 118 for TPU-function pins */
    /* Keep in mind that these pins are input to the SIU */

	/* Fill in */



    /* Start timers */
    fs_timer_start();

    return;
}



uint16_t ReadFQD_pc()
{
    /* This function returns the lower 16 bits of the current QD PC value */
    /* The PC is a 24-bit register but we will only use the least significant 16 bits */
	/* Fill in the body for the ReadFQD_pc() function here */
}

int32_t updateCounter()
{
	/* Fill in the body for the updateCounter() function here */
}

float updateAngle()
{
  /* Fill in the body for the updateAngle() function here */
}

/* EOF */

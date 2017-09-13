/**************************************************************************
 * FILE NAME:  ecs.c     
 *
 * EECS461 at the University of Michigan
 * System configuration and startup library
 * 
 * Created November 24, 2003 by David Thorsley for MPC555
 * 
 * Revision History:
 *   7-25-05 ericjw  for MPC5553
 *   8-9-06  lovelljc
 *   8-28-06 ericjw
 *
 * Revised and adapted to use at IMRT ETH Zurich 
 * 151-0593-00 Embedded Conrol Systems (ECS) 
 *
 * Revision History:
 *	2008-08-20		Marianne Schmid
 *	2010-03-26		Gregor Ochsner		Adding Lab8
 *  2012-05-09		Pascal Lutz			Changing Clock Rate to 120MHz for
 *										all Labs.
 **************************************************************************/

#include <ecs.h>
#include <mpc5553.h>

/* should be called as first function in main */
void init_ECS(int labno)
{
	init_speed(120); 	/*120 MHz CPU clock frequency*/

    switch(labno)
    {
    case 4:
        /* Set to 0 to enable the motor */
	    SIU.PCR[205].B.PA = 0b00;
	    SIU.PCR[205].B.OBE = 1;   /* enable output buffer */
	    SIU.GPDO[205].B.PDO = 0;  /* write bit */
		break;
 	case 6:
		/* Set to 0 to enable the motor */
		SIU.PCR[205].B.PA = 0b00;
	    SIU.PCR[205].B.OBE = 1;   /* enable output buffer */
	    SIU.GPDO[205].B.PDO = 0;  /* write bit */
		break;
	case 8:
		/* Set to 0 to enable the motor */
		SIU.PCR[205].B.PA = 0b00;
	    SIU.PCR[205].B.OBE = 1;   /* enable output buffer */
	    SIU.GPDO[205].B.PDO = 0;  /* write bit */
		break;	
    }
	init_fp();

    /* Enable External interrupts (MSR.EE=1) */
    asm("wrteei 1");
}

/* returns (in Hz) the current clock frequency */
uint32_t get_sys_freq(void)
{
    /* fsys = fref*(mfd+4)/((prediv+1)*2^rfd) */
    /* fsys = (8 * mfd + 32) MHz */
	return 8000000 * (FMPLL.SYNCR.B.MFD + 4) / ((FMPLL.SYNCR.B.PREDIV + 1) * (1 << FMPLL.SYNCR.B.RFD));
}

/* set the clock speed in units of 8 MHz, min 32 MHz, max 128 MHz
 *  with a 8 MHz crystal the maximum rate is 128 MHz. */
void init_speed(long mhz)
{
    /* must have lock (check just in case) */
    while (!FMPLL.SYNSR.B.LOCK) 
    {}
	
    FMPLL.SYNCR.B.LOLRE = 0;
    FMPLL.SYNCR.B.PREDIV = 0;
    FMPLL.SYNCR.B.RFD = 0;
    FMPLL.SYNCR.B.MFD = (mhz-32)/8;
	
    /* wait for lock again */
    while (!FMPLL.SYNSR.B.LOCK)
    {}
	  
    FMPLL.SYNCR.B.LOLRE = 1;
}

/* initialize floating point unit */
void init_fp()
{
	/* inline assembler */
    asm("    mfmsr r3        "); /*search for floating point unit*/
    asm("    ori r3,r3,0x2000"); 
    asm("    mtmsr r3        ");
    asm("    isync           ");
}

/* EOF */

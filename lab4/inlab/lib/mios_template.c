/**************************************************************************
 * FILE NAME: mios.c
 *
 * EECS461 at the University of Michigan
 * MPC5553 eMIOS Library File - Template
 *
 * Created July 2005 by Ron Hagiz
 *
 * Revision History:
 *  8-7-06  lovelljc
 *  8-28-06 ericjw  formatting
 *  9-1-06  ericjw  changed OPWM to OPWFM
 *
 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *  2008-09-11      Marianne Schmid
 *  2011-02-10      Thomas Schneider
 *  2012-08-15      Patrick Müller
 *  2013-09-02      Manuel Gehlen & Mathias Rebholz - line 33 substitue "= prescaler" with " = /* Fill in here * /
 *  2014-01-11      Stijn van Dooren - cleaned comments
 **************************************************************************/

#include <mios.h>
#include <mpc5553.h>

/* Preserve duty cycle while set_PWMPeriod_ns*/
static float DutyCycle[24]={0.5};                               /* Static initialization */

void init_MIOS_clock(uint8_t prescaler)
{
    EMIOS.MCR.B.GPRE = /* Fill in here */;                      /* Clock divider , divided by 1 --> max. frequency equal to system clock 120 MHz */
    EMIOS.MCR.B.GPREN = 1;                                      /* Enable global prescaler */
    EMIOS.MCR.B.GTBE = 1;                                       /* Global time base enable , out signal negated */
    EMIOS.MCR.B.FRZ = 0;                                        /* Do not stop channels when in debug mode */
}

/* This function calculates the number of eMIOS counter ticks from a given period of time in ns, see Time Base Generation (17.5.3) in Reference Manual*/
static uint32_t ns_to_ticks(int miosChannel, uint32_t T_ns)
{
   /*assert(T_ns < 139748061164) ;                              /* This function only returns correct results if the parameter T_ns is smaller than 2^64/132e6 */
   uint64_t ticks =
        (uint64_t)((uint64_t)T_ns*(uint64_t)get_sys_freq())
        / (1+EMIOS.MCR.B.GPRE)
        / (1+EMIOS.CH[miosChannel].CCR.B.UCPRE)
        / 1000000000u;                                          /* Leading u tells the compiler that the integer constant is unsigned rather than signed */
    return (uint32_t)ticks;
}

void init_PWM(int miosChannel, uint32_t newPeriod_ns)
{
    DutyCycle[miosChannel]=0.5;

    /* Our channel outputs high for internal counter values between 0 and CADR (Channel A Data Register) */
    EMIOS.CH[miosChannel].CCR.B.UCPRE = /* Fill in */;          /* Select a prescaler that allows you the maximum duty cycle resolution */
    EMIOS.CH[miosChannel].CCR.B.UCPREN = /* Fill in */;         /* Turn on channel prescaler to have internal clock */
    EMIOS.CH[miosChannel].CCR.B.BSL = /* Fill in */;            /* Must use internal counter in this mode */
    EMIOS.CH[miosChannel].CCR.B.EDPOL = /* Fill in */;          /* Match CADR clears output, match CBDR sets output */
    EMIOS.CH[miosChannel].CCR.B.MODE = /* Fill in */;           /* OPWFMB Output Pulse Width and Frequency Modulation, Buffered Mode
                                                                 * (FLAG set at match of internal counter and comparator A or comparator B) */
    /* Set initial Dutycycle */
    set_PWMPeriod_ns(miosChannel, newPeriod_ns);

    /* Turn on the output pads for our PWM channel */
    SIU.PCR[/* Fill in */].B.PA = /* Fill in */;
    SIU.PCR[/* Fill in */].B.OBE = /* Fill in */;
}


void set_PWMPeriod_ns(int miosChannel, uint32_t newPeriod_ns)
{
    uint32_t ticks = ns_to_ticks(miosChannel, newPeriod_ns);
    /* Adjust the PWM period for this channel to the input value
     You must also make sure that the duty cycle is preserved
    */
    EMIOS.CH[miosChannel].CADR.R = ticks * DutyCycle[miosChannel];
    /* Fill in here */                                          /* set PWM period (ticks)*/

}

#define MINIMUM 0
#define MAXIMUM 1
static float DutyCycleLimits[2]={0.1,0.9};
int8_t set_PWMDutyCycleLimits(int miosChannel, float minimum, float maximum)
{
    if (minimum < 0.1 || maximum > 0.9 || minimum > maximum) return(-1);
    DutyCycleLimits[MINIMUM]=minimum;
    DutyCycleLimits[MAXIMUM]=maximum;
    return(0);
}

void set_PWMDutyCycle(int miosChannel, float dutyCycle)
{
    /* Apply the input duty cycle to the input mios channel.*/
    /* Be sure to keep in mind the haptic wheel's PWM limits defined in set_PWMDutyCycleLimits */
    /* Fill in Duty Cycle Limits*/
    DutyCycle[miosChannel] = dutyCycle;
    /* Write value to eMIOS register here */
    /* Fill in here */
    return;
}

/* EOF */

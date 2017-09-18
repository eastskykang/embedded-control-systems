/**************************************************************************
 * FILE NAME:  lab5.c
 *
 * EECS461 at the University of Michigan
 * Lab 5 - Template
 *
 * Created July 2005 Eric Williams
 *
 * Revision History:
 *   8-9-06  lovelljc
 *  10-4-06  ericjw
 *
 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *	2008-09-04		Marianne Schmid
 *	2009-09-13		Marianne Schmid (different name for MiosChannel)
 *	2011-02-14		Thomas Schneider
 **************************************************************************/

#include <mpc5553.h>
#include <math.h>
#include <ecs.h>
#include <mios.h>
#include <qadc.h>
#include <isr.h>

#define SCF_MIOS_CHANNEL	12		/* The haptic interface uses eMIOS[12]  for the sc-Filter*/
#define SINUS_MIOS_CHANNEL   1       /* The haptic interface uses eMIOS[0]. Use eMIOS[1] for this lab */
#define PWM_PERIOD_ns       50000   /* 50000 Initialize PWM at 20 kHz */
#define MIOS_CLOCK_SCALER   0b0000  /* Divide by (SCALER + 1) = 1 */

#define SINGLE_SCAN_CHANNEL     0   /* Use AN0 for external input, AN1 for ECS interface board potentiometer */
#define NUM_CONTINUOUS_CHANNELS 0   /* Can scan up to 8 input channels continuously */

#define INTERRUPT_FREQUENCY_A 20000     /* Fixed-Interval Interrupts frequency (Hz) for IsrA*/
#define INTERRUPT_FREQUENCY_B 1000      /* Fixed-Interval Interrupts frequency (Hz) for IsrB*/
#define INTERRUPT_FREQUENCY_C 1000      /* Fixed-Interval Interrupts frequency (Hz) for IsrC*/

#define LED_PIN                 29
#define DIP_PIN                 122     // 122 for PWM frequency / 123 for PWM dutycycle limits

#define LED_ON                  1
#define LED_OFF                 0
#define PI                      3.1415926

/* Use the appropriate interrupt frequency when calling an ISR */

// for IsrB & IsrC
uint32_t i_B;
uint32_t i_C;

// for IsrC
double sin_precal[10];

void IsrA(void)
{
    /* fill in here */
    unsigned short an_in0 = 0;
    float an_in0_scaled = 0.0;

    float max_dutycycle = 1.0;
    float min_dutycycle = 0.0;

    // turn on the light
    SIU.GPDO[LED_PIN].B.PDO = LED_ON;

    // read ANin0 
    an_in0 = qadcReadQ1();

    // read GPI (DIP)
    if (SIU.GPDO[DIP_PIN + 1].B.PDI) {
        // high
        max_dutycycle = 0.6;
        min_dutycycle = 0.4;
    }
    else {
        // low
        max_dutycycle = 0.9;
        min_dutycycle = 0.1;
    }

    // scale input 
    an_in0_scaled = (max_dutycycle - min_dutycycle) / (16060 - 120) * (an_in0 - 120) + min_dutycycle; 

    if (SIU.GPDO[DIP_PIN].B.PDI) {
        // high 
        set_PWMPeriod_ns(SINUS_MIOS_CHANNEL, 16667);
    }
    else {
        // low
        set_PWMPeriod_ns(SINUS_MIOS_CHANNEL, 50000);
    }

    // set duty cycle limit and duty cycle
    set_PWMDutyCycleLimits(SINUS_MIOS_CHANNEL, min_dutycycle, max_dutycycle);     
    set_PWMDutyCycle(SINUS_MIOS_CHANNEL, an_in0_scaled);

    // turn on the light
    SIU.GPDO[LED_PIN].B.PDO = LED_OFF;
}

void IsrB(void)
{
    /* fill in here */  
    float an_in0_scaled = 0.0;

    double max_dutycycle = 0.9;
    double min_dutycycle = 0.1;
    
    double sampled_sin = 0.0;

    // turn on the light
    SIU.GPDO[LED_PIN].B.PDO = LED_ON;

    // read ANin0 
    sampled_sin = sin(2*M_PI*i_B/10);

    // scale input 
    an_in0_scaled = (float) (max_dutycycle - min_dutycycle) / 2  * (sampled_sin + 1) + min_dutycycle; 

    set_PWMPeriod_ns(SINUS_MIOS_CHANNEL, 16667);

    // set duty cycle limit and duty cycle
    set_PWMDutyCycleLimits(SINUS_MIOS_CHANNEL, min_dutycycle, max_dutycycle);     
    set_PWMDutyCycle(SINUS_MIOS_CHANNEL, an_in0_scaled);

    // turn on the light
    SIU.GPDO[LED_PIN].B.PDO = LED_OFF;

    // make i_B zero again 
    if (++i_B >= 10)     i_B = 0;
}

void IsrC(void)
{
    /* fill in here */
    float an_in0_scaled = 0.0;

    double max_dutycycle = 0.9;
    double min_dutycycle = 0.1;
    
    double sampled_sin = 0.0;

    // turn on the light
    SIU.GPDO[LED_PIN].B.PDO = LED_ON;

    // read ANin0 
    sampled_sin = sin_precal[i_C];

    // scale input 
    an_in0_scaled = (float) (max_dutycycle - min_dutycycle) / 2  * (sampled_sin + 1) + min_dutycycle; 

    set_PWMPeriod_ns(SINUS_MIOS_CHANNEL, 16667);

    // set duty cycle limit and duty cycle
    set_PWMDutyCycleLimits(SINUS_MIOS_CHANNEL, min_dutycycle, max_dutycycle);     
    set_PWMDutyCycle(SINUS_MIOS_CHANNEL, an_in0_scaled);

    // turn on the light
    SIU.GPDO[LED_PIN].B.PDO = LED_OFF;

    // make i_B zero again 
    if (++i_C >= 10)     i_C = 0;
}

int main() {
    
    uint32_t i;

    /* initialize processor */
    init_ECS(5);
    init_MIOS_clock(MIOS_CLOCK_SCALER);
    init_PWM(SINUS_MIOS_CHANNEL,PWM_PERIOD_ns);
    init_PWM(SCF_MIOS_CHANNEL,1000); /* 1 MHz */
    qadcInit_single(SINGLE_SCAN_CHANNEL);

    /* initialize GPIO */
    /* fill in here */
    // init gpo
    for (i=0; i < 1; i++) {
        SIU.PCR[LED_PIN + i].B.PA = 0b000;
        SIU.PCR[LED_PIN + i].B.OBE = 0b1;
        SIU.PCR[LED_PIN + i].B.IBE = 0b0;
        SIU.PCR[LED_PIN + i].B.WPE = 0b0;
    }	

    // init gpi
    for (i = 0; i < 2; i ++) {
        SIU.PCR[DIP_PIN + i].B.PA = 0b000;
        SIU.PCR[DIP_PIN + i].B.OBE = 0b0;
        SIU.PCR[DIP_PIN + i].B.IBE = 0b1;
        SIU.PCR[DIP_PIN + i].B.WPE = 0b0;
    }	

    // init i_B for IsrB
    i_B = 0;

    // init sin_precal
    for (i = 0; i < 10; i++) {
        sin_precal[i] = sin((double)i / 10 * 2 * M_PI);
    }

    /* init interrupts */
    init_interrupts(IsrA, INTERRUPT_FREQUENCY_A);
    /* enable interrupts */
    /* fill in here */
    init_interrupts(IsrB, INTERRUPT_FREQUENCY_B);
    init_interrupts(IsrC, INTERRUPT_FREQUENCY_C);

    while(1)
    {
        /* Loop forever */
    }
    return(0);
}

/* EOF */

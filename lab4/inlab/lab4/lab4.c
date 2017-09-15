/**************************************************************************
 * FILE NAME:  lab4.c
 *
 * EECS461 at the University of Michigan
 * Lab 4 Template
 *
 * Created July 2005
 *
 * Revision History:
 *   8-3-06  lovelljc
 *
 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *  2008-09-04      Marianne Schmid
 **************************************************************************/
#include <ecs.h>
#include <mios.h>
#include <fqd.h>
#include <worlds.h>
#include <motor.h>
#include <qadc.h>
#include <mpc5553.h>
#include <serial.h>

#define SCF_MIOS_CHANNEL        12                      /* The haptic interface uses eMIOS[12]  for the sc-Filter*/
#define HAPTIC_MIOS_CHANNEL     0                       /* The ECS interface board sends eMIOS[0] to the haptic interface motor */
#define PWM_PERIOD_ns           (25000)                 /* 25000 Initialize PWM at 40 kHz */
//#define PWM_PERIOD_ns           (500000)                 /* 25000 Initialize PWM at 40 kHz */
#define MIOS_CLOCK_SCALER       0                       /* Select a clock prescalar that allows the eMIOS to run at the maximum possible frequency */
#define SINGLE_SCAN_CHANNEL     3                       /* Use AN3 for input of the potentiometer */
#define NUM_CONTINUOUS_CHANNELS 0                       /* Can scan up to 8 input channels continuously */+
#define LED_PIN                 28

#define LAB 4

// test mode
#define PROBLEM_9

int main()
{
    /* Variable declarations here */
    unsigned short cnt = 0;
    unsigned short i = 0;
    int cnt_fqd = 0;

    char buff[32];
    unsigned char flag = 0;

    float scaled_cnt = 0.0;
    float spring_angle = 0.0;
    float outputT = 0.0;

#ifdef TEST_MAX_MIN
    unsigned short max = 0;
    unsigned short min = -1;
#endif

    /* Initializations */
    init_ECS(LAB);                                      /* Set the system clock to 40 MHz, enable the motor */
    init_MIOS_clock(MIOS_CLOCK_SCALER);                 /* Set the clock prescaler */
    init_PWM(HAPTIC_MIOS_CHANNEL, PWM_PERIOD_ns);
    init_PWM(SCF_MIOS_CHANNEL,1000);                    /* The sc-filter is run with 1 MHz*/
    set_PWMDutyCycleLimits(HAPTIC_MIOS_CHANNEL, 0.24, 0.76);
    init_FQD();
    qadcInit_single(3);
    
#ifdef SERIAL
    // init serial port
    /* In all labs, we use ESCI_A that corresponds to port 1
     * and a baud rate of 115200 */
    init_COM(1,115200);
    serial_puts(1,"\n\n\n\n\n\n\n\n\rSerial Output Enabled.");
#endif

    // init gpo
    for (i=0; i < 1; i++) {
        SIU.PCR[LED_PIN + i].B.PA = 0b000;
        SIU.PCR[LED_PIN + i].B.OBE = 0b1;
        SIU.PCR[LED_PIN + i].B.IBE = 0b0;
        SIU.PCR[LED_PIN + i].B.WPE = 0b0;
    }	

    /* Fill in lab4.c code here */
    while(1) {
        cnt = qadcReadQ1();
        scaled_cnt = (0.76 - 0.24) / (16060 - 120) * (cnt - 120) + 0.24; 

#ifdef TEST_MAX_MIN
        if (cnt > max) max = cnt;
        if (cnt < min) min = cnt;
#endif 

        // output torque cal
#ifdef PROBLEM_7
        outputT = outputTorque(200.0);
#endif 
#ifdef PROBLEM_8
        cnt_fqd = updateCounter();
        spring_angle = cnt_fqd * 0.09;
        outputT = outputTorque(virtualSpring(spring_angle));

#ifdef SERIAL
        // serial output
        sprintf(buff, "\f%f %f\r", 
                outputT,
                spring_angle);
        serial_puts(1, buff);
#endif
#endif

#ifdef PROBLEM_9
        cnt_fqd = updateCounter();
        spring_angle = cnt_fqd * 0.09;
        outputT = outputTorque(virtualWall(spring_angle));

#ifdef SERIAL
        // serial output
        sprintf(buff, "\f%f %f\r", 
                outputT,
                spring_angle);
        serial_puts(1, buff);
#endif
#endif
        // set duty cycle
#ifdef PROBLEM_4 
        set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, scaled_cnt);
#endif 
#ifdef PROBLEM_6
        set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, 0.5);
#endif 
#if defined(PROBLEM_7) || defined(PROBLEM_8) || defined(PROBLEM_9)
        set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, outputT);

        // indicate sampling rate (LED)
        flag = !flag;
        SIU.GPDO[LED_PIN].B.PDO = flag;
#endif 
    }
    
    return(0);
}

/* EOF */

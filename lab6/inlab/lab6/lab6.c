/**************************************************************************
 * FILE NAME:  lab6.c
 *
 * EECS461 at the University of Michigan
 * Lab 6 - Template
 *
 * Revision History:
 * 	8-16-06	lovelljc
 *
 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *	2008-09-04		Marianne Schmid
 *	2011-03-29		Thomas Schneider
 *  2012-08-15		Patrick Müller
 *  2015-02-18      Fabian Byland
 **************************************************************************/

#include <mpc5553.h>
#include <ecs.h>
#include <mios.h>
#include <fqd.h>
#include <motor.h>
#include <serial.h>
#include <isr.h>
#include <worlds.h>

#define SCF_MIOS_CHANNEL	12		/* The haptic interface uses eMIOS[12]  for the SC-Filter*/
#define HAPTIC_MIOS_CHANNEL	0		/* The haptic interface uses eMIOS[0]  for the PWM Signal*/
#define PWM_PERIOD_ns       (25000) /* 25000 Initialize PWM at 40 kHz */
#define MIOS_CLOCK_SCALER	0b000	/* Divide by (SCALER + 1) */

#define KNOB

#if defined(WD)
#define INTERRUPT_FREQUENCY	1000	/* Fixed-Interval Interrupts frequency (Hz) */
#elif defined(SD)
#define INTERRUPT_FREQUENCY	10000	/* Fixed-Interval Interrupts frequency (Hz) */
#elif defined(S)
#define INTERRUPT_FREQUENCY	10000	/* Fixed-Interval Interrupts frequency (Hz) */
#elif defined(SM)
#define INTERRUPT_FREQUENCY	1000	/* Fixed-Interval Interrupts frequency (Hz) */
#elif defined(SMD)
#define INTERRUPT_FREQUENCY	1000	/* Fixed-Interval Interrupts frequency (Hz) */
#elif defined(SMD_EX)
#define INTERRUPT_FREQUENCY	1000	/* Fixed-Interval Interrupts frequency (Hz) */
#elif defined(KNOB)
#define INTERRUPT_FREQUENCY	1000	/* Fixed-Interval Interrupts frequency (Hz) */
#endif

/* TIMESTEP defined in worlds.h - should be 1 / INTERRUPT_FREQUENCY */

float prev_angle;

void sdIsr(void) {
    /* ISR for the spring-damper system */
    /* Calculate the wheel's velocity */
    /* Calculate and apply the correct torque to haptic wheel */
    float angle = 0.0;
    float velocity = 0.0;
    float torque_pwm = 0.0;

    int cnt_fqd = updateCounter();
    
    // calculate angle and velocity
    angle = cnt_fqd * 0.09;
    velocity = (angle - prev_angle) * INTERRUPT_FREQUENCY;
    prev_angle = angle;

    torque_pwm = outputTorque(virtualSpringDamper(angle, velocity));

    // set pwd
    set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, torque_pwm);
}

void sIsr(void) {
    /* ISR for the spring-damper system */
    /* Calculate the wheel's velocity */
    /* Calculate and apply the correct torque to haptic wheel */
    float angle = 0.0;
    float torque_pwm = 0.0;

    int cnt_fqd = updateCounter();
    
    // calculate angle and velocity
    angle = cnt_fqd * 0.09;

    torque_pwm = outputTorque(virtualSpring(angle));

    // set pwd
    set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, torque_pwm);
}


void wdIsr(void) {
    /* ISR for the wall-damper system */
    /* Calculate the wheel's velocity */
    /* Calculate and apply the correct torque to haptic wheel */
    float angle = 0.0;
    float velocity = 0.0;
    float torque_pwm = 0.0;

    int cnt_fqd = updateCounter();
    
    // calculate angle and velocity
    angle = cnt_fqd * 0.09;
    velocity = (angle - prev_angle) * INTERRUPT_FREQUENCY;
    prev_angle = angle;

    torque_pwm = outputTorque(virtualWallDamper(angle, velocity));

    // set pwd
    set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, torque_pwm);
}

void smIsr(void) {
    /* ISR for the spring-mass system */
    float angle = 0.0;
    float torque_pwm = 0.0;

    int cnt_fqd = updateCounter();
  
    // calculate angle and velocity
    angle = cnt_fqd * 0.09;

    torque_pwm = outputTorque(virtualSpringMass(angle));

    // set pwd
    set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, torque_pwm);
}

void smdIsr(void) {
    /* ISR for the spring-mass-damper system */
    float angle = 0.0;
    float velocity = 0.0;
    float torque_pwm = 0.0;

    int cnt_fqd = updateCounter();
  
    // calculate angle and velocity
    angle = cnt_fqd * 0.09;
    velocity = (angle - prev_angle) * INTERRUPT_FREQUENCY;
    prev_angle = angle;

    torque_pwm = outputTorque(virtualSpringMassDamper(angle, velocity));

    // set pwd
    set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, torque_pwm);
}

#define ENTER_CRITICAL()  asm (" wrteei 0");
#define LEAVE_CRITICAL()  asm (" wrteei 1");

/*shared variables between main and interrupt service routine*/
static float K = 17.78;
static float J = 0.4503;

void smdIsrEx(void) {
    /* ISR for the spring-mass-damper system with adaptable K and J */
    float angle = 0.0;
    float velocity = 0.0;
    float torque_pwm = 0.0;

    int cnt_fqd = updateCounter();
  
    // calculate angle and velocity
    angle = cnt_fqd * 0.09;
    velocity = (angle - prev_angle) * INTERRUPT_FREQUENCY;
    prev_angle = angle;

    torque_pwm = outputTorque(virtualSpringMassDamperEx(angle, velocity, K, J));

    // set pwd
    set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, torque_pwm);
}

void knobIsr(void) {
    /* ISR for the virtual knob system */
    float angle = 0.0;
    float velocity = 0.0;
    float torque_pwm = 0.0;

    int cnt_fqd = updateCounter();
  
    // calculate angle and velocity
    angle = cnt_fqd * 0.09;
    velocity = (angle - prev_angle) * INTERRUPT_FREQUENCY;
    prev_angle = angle;

    torque_pwm = outputTorque(virtualKnob(angle, velocity));

    // set pwd
    set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, torque_pwm);
}

int main()
{
    float *inc_var;
    char input = 0;

    float factor = 1.0;

    init_ECS(6);
    init_MIOS_clock(MIOS_CLOCK_SCALER);
    init_PWM(HAPTIC_MIOS_CHANNEL,PWM_PERIOD_ns);
    set_PWMDutyCycleLimits(HAPTIC_MIOS_CHANNEL, 0.24, 0.76);
    init_PWM(SCF_MIOS_CHANNEL,1000);  /* 1 MHz */

    init_FQD();
    init_COM(1,115200);

    /* used for smdIsrEx(void) */
    serial_puts(1,"\r\nEnter k,j\r\n");

    /* Initialize GPIO */
    /* Fill in here */

    // init gloabal variables
    prev_angle = 0;

    /* init interrupts */
#if defined(WD)
    init_interrupts(wdIsr, INTERRUPT_FREQUENCY);
#elif defined(SD)
    init_interrupts(sdIsr, INTERRUPT_FREQUENCY);
#elif defined(S)
    init_interrupts(sIsr, INTERRUPT_FREQUENCY);
#elif defined(SM)
    init_interrupts(smIsr, INTERRUPT_FREQUENCY);
#elif defined(SMD)
    init_interrupts(smdIsr, INTERRUPT_FREQUENCY);
#elif defined(SMD_EX)
    init_interrupts(smdIsrEx, INTERRUPT_FREQUENCY);
#elif defined(KNOB)
    init_interrupts(knobIsr, INTERRUPT_FREQUENCY);
#endif 

    /* Enable interrupts */
    enable_interrupts();

    while(1){
        input = serial_getchar(1);

        if (input == 'k') {
            inc_var = &K;
            serial_puts(1,"\r\nK selected. Enter +,-\r\n");
            input = serial_getchar(1);

        }
        else if (input == 'j') {
            inc_var = &J;
            serial_puts(1,"\r\nJ selected. Enter +,-\r\n");
            input = serial_getchar(1);
        }

        if (input == '+') {
            serial_puts(1,"\r\n+ selected.\r\n");
            factor = 1.1;
        }
        else if (input == '-') {
            serial_puts(1,"\r\n- selected.\r\n");
            factor = 0.9;
        }

        ENTER_CRITICAL();
        *inc_var = *inc_var * factor;
        LEAVE_CRITICAL();
    }
    return(0);
}

//EOF

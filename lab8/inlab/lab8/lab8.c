/**************************************************************************
 *
 * EECS461 at the University of Michigan
 * Lab 8 Template
 *
 * Created October 2004 by Paul Griffiths for MPC555
 *
 * Revision History:
 * 	10-12-06	lovelljc	for 5553 micro
 * 	10-13-06	ericjw	file consolidation
 *  10-16-06    lovelljc
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *	2010-03-26		Gregor Ochsner
 *  2011-08-30		Thomas Schneider - Interrupts
 **************************************************************************/


#include <mpc5553.h>
#include <ecs.h>
#include <motor.h>
#include <mios.h>
#include <isr.h>
#include <flexcan.h>
#include <fqd.h>


#ifdef VWALLA
void virt_wall_A(void);
#endif

#ifdef VWALLB
void virt_wall_B(void);
#endif

#ifdef VCHAIN
void virt_chain();
#endif


/* Messages from this lab station start at STATIONBASEID */
#define STATIONBASEID   	20 		/* ID of your lab station */
#define VWPARTNERID     	90 		/* ID of your partner's lab station for the virtual wall */
#define CHAIN_A_ID      	30 		/* ID of the station to your "left" */
#define CHAIN_B_ID      	10 		/* ID of the station to your "right" */

#define SCF_MIOS_CHANNEL	12			/* The haptic interface uses eMIOS[12]  for the sc-Filter*/
#define HAPTIC_MIOS_CHANNEL	0			/* The haptic interface uses eMIOS[0] */
#define PWM_PERIOD_ns       20000   	/* 20'000 Initialize PWM at 50 kHz */
#define MIOS_CLOCK_SCALER	0			/* Divide by (SCALER + 1) */


uint16_t vwA_tx_ID = 0 + STATIONBASEID;
uint16_t vwA_rx_ID = 1 + VWPARTNERID;
uint16_t vwB_tx_ID = 1 + STATIONBASEID;
uint16_t vwB_rx_ID = 0 + VWPARTNERID;

const uint8_t vwA_tx_buffnum = 0;		/* virt. wall A transmit  */
const uint8_t vwA_rx_buffnum = 1;		/* virt. wall A receive */
const uint8_t vwB_tx_buffnum = 2;		/* virt. wall B transmit */
const uint8_t vwB_rx_buffnum = 3;		/* virt. wall B receive  */

uint16_t chain_tx_ID = 2 + STATIONBASEID;
uint16_t chainA_rx_ID = 2 + CHAIN_A_ID;
uint16_t chainB_rx_ID = 2 + CHAIN_B_ID;

const uint8_t chain_tx_buffnum = 0;		/* virt. chain transmit		      */
const uint8_t chainA_rx_buffnum = 1;	/* virt. chain receive (posA & velA) */
const uint8_t chainB_rx_buffnum = 2;	/* virt. chain receive (posB & velB) */


/* Shared Global Data: the CAN message-received ISR copies new data into
 * the following global variables */
static volatile float vw_torque = 0;			/* wall torque (FLOAT32, N-mm) */
static volatile float posA = 0;				/* chain position A (FLOAT32, N-mm) */
static volatile float velA = 0;				/* chain velocity A (FLOAT32, N-mm) */
static volatile float posB = 0;				/* chain position B (FLOAT32, N-mm) */
static volatile float velB = 0;				/* chain velocity B (FLOAT32, N-mm) */


/* rx_ISR() - an ISR that is called when a CAN message is received.
 * We must figure out which buffer (possibly multiple) has received a message
 * and copy the data into the appropriate shared data.
 */
void rx_ISR(void)
{

    int ret;
    CAN_RXBUFF rxbuff;
    double temp;

#ifdef VWALLA
    /* Message for: Virtual Wall A */
    /* First check to see if there is a new message in the buffer */
    if( can_get_buff_flag(&CAN_A, vwA_rx_buffnum) == 1 )
    {
        /* Read the CAN message and copy torque to global variable */
        /* is the read successful and is the message the right length? */
        rxbuff.buff_num = vwA_rx_buffnum;

        ret = can_rxmsg(&CAN_A, &rxbuff, 1/*renew TODO*/);
        if (ret != 0)
            exit(-2); // error
        if (ret == 0 && rxbuff.length == sizeof(vw_torque))
            // receive the message
            memcpy( &vw_torque, rxbuff.data, sizeof(vw_torque));
    }
#endif


#ifdef VWALLB
    /* Message for: Virtual Wall B */
    /* First check to see if there is a new message in the buffer */
    if( can_get_buff_flag(&CAN_A, vwB_rx_buffnum) == 1 )
    {
        /* Let virt_wall_B() handle this */
        virt_wall_B();
    }
#endif


#ifdef VCHAIN
    /* Message for: Virtual Chain (from A) */
    /* First check to see if there is a new message in the buffer */
    if( can_get_buff_flag(&CAN_A, chainA_rx_buffnum) == 1 )
    {
        /* Read the CAN message and copy position and velocity to global variable */
        rxbuff.buff_num = chainA_rx_buffnum;

        ret = can_rxmsg(&CAN_A, &rxbuff, 1/*renew TODO*/);
        if (ret != 0)
            exit(-2); // error
        if (ret == 0 && rxbuff.length == sizeof(temp)) {
            // receive the message
            memcpy( &posA, rxbuff.data, sizeof(posA));
            memcpy( &velA, rxbuff.data + 4, sizeof(velA));
        }
    }

    /* Message for: Virtual Chain (from B) */
    /* First check to see if there is a new message in the buffer */
    if( can_get_buff_flag(&CAN_A, chainB_rx_buffnum) == 1 )
    {
        /* Read the CAN message & copy position and velocity to global variable */
        rxbuff.buff_num = chainB_rx_buffnum;

        ret = can_rxmsg(&CAN_A, &rxbuff, 1/*renew TODO*/);
        if (ret != 0)
            exit(-2); // error
        if (ret == 0 && rxbuff.length == sizeof(temp)) {
            memcpy( &posB, rxbuff.data, sizeof(posB));
            memcpy( &velB, rxbuff.data + 4, sizeof(velB));
        }
    }
#endif
}


/* virt_wall_A() - implements the sensing and actuation
 * of the virtual wall. It reads the wheel position and
 * applies the calculated torque, however the position (deg)
 * is sent across the CAN bus and the torque is calculated
 * remotely and transmitted back.
 */
#ifdef VWALLA
void virt_wall_A(void)
{
    CAN_TXBUFF txbuff;		/* buffer to tx wheel angle & velocity */
    float curr_angle = 0;
    float torque_pwm = 0.0;
    int cnt_fqd = 0;

    /* 1. Apply the current torque value (last received) */
    /* 2. Read the wheel position */
    /* 3. Transmit the wheel position in a CAN message */

    // apply current torque value
    torque_pwm = outputTorque(vw_torque);
    set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, torque_pwm);

    // read wheel position 
    cnt_fqd = updateCounter();
  
    // calculate angle and velocity
    curr_angle = cnt_fqd * 0.09;

    // tramsmission CAN msg
    txbuff.buff_num = vwA_tx_buffnum;
    memcpy(txbuff.data, &curr_angle, sizeof(curr_angle));
    txbuff.length = sizeof(curr_angle);
    txbuff.id = can_build_std_ID(vwA_tx_ID);

    if (can_txmsg(&CAN_A, &txbuff) != 0)
        exit(-3); // error

    return;
}
#endif


/* virt_wall_B() - implements the computation
 * of the virtual wall. This function is called when a
 * message from the partner station is received.
 */
#ifdef VWALLB
void virt_wall_B(void)
{
    CAN_RXBUFF	rxbuff;
    CAN_TXBUFF	txbuff;

    float curr_angle;
    float k_vw = 500;		/* spring constant of the wall (N-mm/deg) */
    int ret;

    // new variables 
    float angle_0 = 0;      // deg
    float torque = 0;       // N mm

    /* 1. Read the CAN message */
    /**** is the read successful and is the message the right length? ***/
    /* 2. Calculate the torque */
    /* 3. Transmit the torque back */

    rxbuff.buff_num = vwB_rx_buffnum;
    
    ret = can_rxmsg(&CAN_A, &rxbuff, 1 /*renew TODO*/);
    if (ret != 0)
        exit(-2); // error
    if (ret == 0 && rxbuff.length == sizeof(curr_angle))
        // receive the message
        memcpy( &curr_angle, rxbuff.data, sizeof(curr_angle));

    /* Compute the torque for the virtual wall based
     on the current angle (lab 4)  */

    if (curr_angle > angle_0)
        torque = k_vw * (curr_angle - angle_0);
    else
        torque = 0.0;

    txbuff.buff_num = vwB_tx_buffnum;
    memcpy(txbuff.data, &torque, sizeof(torque));
    txbuff.length = sizeof(torque);
    txbuff.id = can_build_std_ID(vwB_tx_ID);

    if (can_txmsg(&CAN_A, &txbuff) != 0)
        exit(-3); // error

}
#endif


/* virt_chain() - implements one station in part of a chain. The position
 * and velocity of neighboring stations are received and the
 * appropriate spring and damper torques from each station are applied
 * to this station's wheel.  Additionally, we must transmit this  stations position
 * and velocity. */
#ifdef VCHAIN
const uint32_t vc_f = 250;		/* frequency of the chain wall (Hz) */
const float k = 25.0;			/* spring-rate (N-mm/deg) */
const float b = 0.2;			/* damping (N-mm/(deg/s)) */

void virt_chain()
{
    CAN_TXBUFF		txbuff;		/* buffer to transmit position and velocity */
    float curr_angle;
    float velocity;
    float torque;
    static float prev_angle = 0;

    // new variable
    float torque_pwm = 0.0;

    /* 1. Read wheel angle (deg) */
    /* 2. Calculate wheel velocity (deg/s) */
    /* 3. Calculate & apply torque  */
    /* 4. Transmit your wheel position and velocity */
    /**** 8-bytes (first 4 for position and second 4 for velocity) ****/
    
    // read wheel position 
    int cnt_fqd = updateCounter();
  
    // calculate angle and velocity
    curr_angle = cnt_fqd * 0.09;
    velocity = (curr_angle - prev_angle) / 0.004;

    // calculate torque
    torque = k * (posA - curr_angle) + k * (posB - curr_angle) 
        + b * (velA - velocity) + b * (velB - velocity);

    // apply torque 
    torque_pwm = outputTorque(torque);
    set_PWMDutyCycle(HAPTIC_MIOS_CHANNEL, torque_pwm);

    // transmit position and velocity 
    txbuff.buff_num = chain_tx_buffnum;
    memcpy(txbuff.data, &curr_angle, sizeof(curr_angle));
    memcpy(txbuff.data + 4, &velocity, sizeof(velocity));
    txbuff.length = sizeof(curr_angle) + sizeof(velocity);
    txbuff.id = can_build_std_ID(chain_tx_ID);

    if (can_txmsg(&CAN_A, &txbuff) != 0)
        exit(-3); // error

    prev_angle = curr_angle;
    return;
}
#endif



int main()
{
    init_ECS(8);
    init_MIOS_clock(MIOS_CLOCK_SCALER);
    init_PWM(HAPTIC_MIOS_CHANNEL,PWM_PERIOD_ns);
    init_PWM(SCF_MIOS_CHANNEL,1000);
    set_PWMDutyCycleLimits(HAPTIC_MIOS_CHANNEL, 0.24, 0.76);
    init_FQD();


    /* Initialize CAN A */
    can_init(&CAN_A);

    /* Set the CAN receive ISR */
    can_set_rxisr(rx_ISR);

#ifdef VWALLA
    /* Setup the receive buffers for virtual wall user A */
    can_rxbuff_init(&CAN_A, vwA_rx_buffnum, can_build_std_ID(vwA_rx_ID), 1 /*TODO*/);
#endif

#ifdef VWALLB
    /* Setup the receive buffers for virtual wall user B */
    can_rxbuff_init(&CAN_A, vwB_rx_buffnum, can_build_std_ID(vwB_rx_ID), 1 /*TODO*/);
#endif

#ifdef VCHAIN
    /* Setup the receive buffers for the virtual chain */
    can_rxbuff_init(&CAN_A, chainA_rx_buffnum, can_build_std_ID(chainA_rx_ID), 1);
    can_rxbuff_init(&CAN_A, chainB_rx_buffnum, can_build_std_ID(chainB_rx_ID), 1);
#endif

    /* Initialize the shared global variables */
    vw_torque = 0 ;	/* wall torque (FLOAT32, N-mm) */
    posA = 0 ;		/* chain position A (FLOAT32, N-mm) */
    velA = 0 ;		/* chain velocity A (FLOAT32, N-mm) */
    posB = 0 ;		/* chain position B (FLOAT32, N-mm) */
    velB = 0 ;		/* chain velocity B (FLOAT32, N-mm) */


    /* Select whether to run the virtual wall or the
     * virtual chain and start interrupts*/

#ifdef VWALLA
    init_interrupts( virt_wall_A, 200 /*Hz*/);
    enable_interrupts();
#endif

#ifdef VWALLB
    enable_interrupts(); // VWALLB interrupted by CAN Rx only
#endif

#ifdef VCHAIN
    init_interrupts( virt_chain, vc_f /*Hz*/);
    enable_interrupts();
#endif


    /* loop forever */
    while(1)
    {}

}

// EOF

/**************************************************************************
 * FILE NAME: flexcan.h
 * Created by Paul Griffiths  on Oct '04
 *
 * Revision History:
 *      2005    rhagiz      for 55xx micro
 *      10-16-06 lovelljc
 *
 *
 * Revised and adapted to use at IDSC ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *	2010-03-26		Gregor Ochsner
 **************************************************************************/

#ifndef __FLEXCAN_H__
#define __FLEXCAN_H__

#include <mpc5553.h>
#include <typedefs.h>

typedef struct can_rxbuff {
                                                /* IN *************************/
        uint8_t buff_num;         /* buffer to be filled */

                                                /* OUT ************************/
        uint8_t isFilled;         /* was a message received? */
        uint8_t timestamp;        /* timestamp field - high byte of FRT */
        uint8_t length;           /* length of data (bytes) */
        uint32_t id;              /* id registers */
        uint8_t data[8];          /* data received */
        uint16_t frt;                     /* free running-timer */
} CAN_RXBUFF;

typedef struct can_txbuff {
                                                /* IN *************************/
        uint8_t buff_num;         /* buffer to use for sending */
        uint32_t id;              /* id registers */
        uint8_t length;           /* length of data to tx (bytes) */
        uint8_t data[8];          /* data to transmit */
} CAN_TXBUFF;


/* Driver Functions ***************************************/
/* Initialization: */

/* Initialize one of the CAN modules. */
int can_init(struct FLEXCAN2_tag *can);

/* Initialize a buffer to receive a CAN message. */
int can_rxbuff_init(struct FLEXCAN2_tag *can, int buff_num, int id, int doIRQ);

/* Message transmission: */
int can_txmsg(struct FLEXCAN2_tag *can, CAN_TXBUFF *buff);

/* Allow a user ISR to be called in response to receiving CAN message */
int can_set_rxisr(void (*fctn_ptr)());

/* Poll one of the CAN receive buffers for a message.
 *  Set renew to 0 to deactivate the receive buffer, or set to renew to 1
 *  to continue receiving messages with the specified buffer. */
int can_rxmsg(struct FLEXCAN2_tag *can, CAN_RXBUFF *buff, uint8_t renew);


/* Deactivate a CAN buffer
 * This function is provided as a replacement for stop_transmission(). It
 * sets the buffer code to inactive and clears its corresponding bit in IFLAG.
 * This call could interrupt the transmission or reception of a message.
 * The function returns 0 upon success and -1 or -2 upon failure.
 */
int can_deactivate_buffer(struct FLEXCAN2_tag *can, int buff);

/* Get and clear one bit of the IFLAG register
 * These functions access the bit of the IFLAG
 * register that corresponds to the buffer specified by buff.
 */
int can_get_buff_flag(struct FLEXCAN2_tag *can, int buff);
int can_clear_buff_flag(struct FLEXCAN2_tag *can, int buff);

/* Build the 32-bit ID value for a standard ID */
uint32_t can_build_std_ID( uint16_t id /*11-bit (0-2047)*/);


#endif /* FLEXCAN_H_ */

// EOF

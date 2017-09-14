/**************************************************************************
* FILE NAME: qadc_template.c
*
* University of Michigan
* EECS-461, Embedded Systems
* Queued Analog-to-Digital Converter Module (eQADC) (Template)
* See Chapter 19 in MPC5553 User's Manual
* Created: 7/16/02 by Eric Castle (for MPC555)
*
* Revision History:
* as qadc64.c:
* 9/26/02 by David Thorsley
* 1/22/04 by Ganesh Dasika
* 9/18/04 by Ganesh Dasika
* 1/17/05 by Ankur Khandelwal
* 7/18/05 by Eric Williams (to 55xx series micro)
*
* as qadc.c:
* 8/7/06 lovelljc, ericjw
* 8/28/06 ericjw
* 1/24/07 ericjw
* 9/22/10 wangyef, zcong

* Revised and adapted to use at IMRT ETH Zurich
* 151-0593-00 Embedded Control Systems (ECS)
*
* Revision History:
* 2008-09-04    Marianne Schmid
* 2011-02-08    Thomas Schneider (updated to new lab version)
* 2011-03-29    Flavio Fontana added comments and updated initialize routines
* 2012-06-06    Pascal Lutz (all labs set to 120 MHz clock rate)
* 2015-02-16    Fabian Byland (deleted remains of old clock rates and comments, corrected spell errors)
*
**************************************************************************/

/***************************** NOTE ***************************************
* The following graph shows the basic principle on how the eQADC module works.
* A request message is placed by the user in the CFPR0 Command FIFO queue.
* Writing the SSE bit in the CFCR Register, triggers the message to be sent to the ADC.
* The ADC then performs the measurement and sends the result to the RFPR0 ResultFIFO queue.
* The FISR register holds the interrupt flags and can be checked to see if result data is
* available in the ResultFIFO
*
*                           [CFCR]
*                              |
*                              |        AN0 AN39
* can be written by user ---[CFPR0   ]     | |      [RFPR0   ]--- can accessed by user
*                           [Push    ]    \MUX/     [Pop     ]
*                           [Register]      |       [Register]
*                           [ 32 bit ]----[ADC1]--->[ 32 bit ]
*                                                      |
*                                                      |
*                                                   [ FISR ]
*
* For more details refer to the MPC 5553 manual chapter 19.
* EQADC_MCR    eQUADC config register          p760
* EQADC_CFPR   CommandFIFO register            p763 for the functionality and how events are triggered p808
* EQADC_CFCR   CommandFIFO control register    p766
* EQADC_RFPR   ResultFIFO register             p764
* EQADC_FISR   Interrupt flag register         p769
* EQADC_IDCR   Interrupt eDMA control register p767
* ADC0_CR      ADC internal config register    p785
*
* command message format                       p796
* configuration message format                 p799
*
**************************************************************************/

#include <qadc.h>
#include <mpc5553.h>

vuint32_t CONT_SCAN_QUEUE[8];                                           /* global variable that will hold the continuous scan commands to feed the eDMA */
vuint32_t CONT_SCAN_RESULTS[8];                                         /* global variable that will hold the scan results will be populated by the eDMA */
vuint32_t SINGLE_SCAN_COMMAND;                                          /* global variable that will hold a command for a single measurement */


/* Initialize the qadc single scan module
 * --------------------------
 * Specify single-scan channel number
 */
void qadcInit_single(int single_channel)
{
    cfifo_msg cmd;                                                      /* Variable that will hold a message to request a regular AD conversion */
    adc_config_msg config;                                              /* Variable that will hold a message to write the ADC configuration */
    uint16_t temp;

    /* Configure the eQADC */
    EQADC.MCR.R = 0;                                                    /* Disable the serial interface, normal mode (do not enter debug mode) */

    /* Disable the FIFO 0 */
    EQADC.CFCR[0].B.MODE = /* Fill in here */;                          /* disabled */

    /***************************** NOTE ***************************************
    *
    *  It is not possible to directly access the ADC configuration register,
    *  instead the configuration needs to be packed in a special message.
    *  This message is then written to the CFIFO like a regular command.
    *  The ADC receives this message, detects the configuration settings
    *  and writes them to its own register.
    *
    **************************************************************************/

    /* Build the message to write the ADC configuration to the ADC configuration register ADC0_CR */
    config.R = 0;                                                       /* Clear all bits (VERY IMPORTANT) */
    config.B.BN = 0;                                                    /* Command is for ADC 0 */
    config.B.ADC_REG_ADDRESS = 0x01;                                    /* ADC0_CR address, tell the ADC to write this message in its config register */
    config.B.HIGH_BYTE = 0x80;                                          /* Enable ADC module */

    /*************************** IMPORTANT ***************************
    *
    * The ADC clock is restricted to a maximum of 12 MHz.
    * For the course it will generally run at 10 MHz.
    * The CPU system clock is set to 120 MHz, for all labs.
    * Set clock prescaler values appropriately.
    * See table 19-28 of MPC5553 manual
    *
    *****************************************************************/

    config.B.LOW_BYTE = /* Fill in here */;                             /* Use clock prescaler for ADC module */

    /* Next, send the configuration command to the ADC using FIFO 0 and clear the result buffer RFPR */
    EQADC.CFPR[0].R = config.R;                                         /* Write config instruction message for ADC 0 to CFIFO0*/
    EQADC.CFCR[0].B.MODE = /* Fill in here */;                          /* Software-triggered, single-scan mode */
    EQADC.CFCR[0].B.SSE = 1;                                            /* Trigger sending the command from the FIFO to the ADC */

    /* clear result FIFO (just in case) */
    while (EQADC.FISR[0].B.RFDF)                                        /* Check if the FIFO has valid entries */
    {
        temp = EQADC.RFPR[0].R;                                         /* Pop result from RFIFO 0 */
        EQADC.FISR[0].B.RFDF = 1;                                       /* Clear flag (should turn on * again if another entry present) */
    }
    /* Build the message to trigger a single scan and store it in a global variable */
    cmd.R = 0;                                                          /* Clear all bits (VERY IMPORTANT) */
    /* Fill in here */
                                                                        /* End-of-queue True, tells the FIFO to halt after this message, FIFO will still remain in singlecan mode */
                                                                        /* Do not use external buffer */
                                                                        /* Send commands to ADC0 */
                                                                        /* Do not calibrate the result */
                                                                        /* Return result to RFIFO RFPR0 */
                                                                        /* Sample during 64 clock cycles */
                                                                        /* Do not request a time stamp */
                                                                        /* Conversion data format right justified unsigned */
                                                                        /* Tell the mux to use the channel which was passed as an argument to the qadcInit_single */
    /* Fill in end */
    SINGLE_SCAN_COMMAND = cmd.R;                                        /* Save command to a global variable for later usage in qadcReadQ1 */
}



/* Initialize the qadc continuous scan module
 * --------------------------
 * Specify number of continuous-scan channels (0-8)
 * and an array containing those channel numbers
 */
void qadcInit_conti(int channels, uint32_t *inputs)
{
    cfifo_msg cmd;
    adc_config_msg config;
    uint16_t temp;
    int x;

    /* Configure the eQADC */
    EQADC.MCR.R = 0;                                                    /* Disable the serial interface, normal mode (do not enter debug mode) */

    /* Disable the FIFO 1 */
    EQADC.CFCR[1].B.MODE = /* Fill in here */;                          /* disabled */

    /***************************** NOTE ***************************************
    *
    *  It is not possible to directly access the ADC configuration register,
    *  instead the configuration needs to be packed in a special message.
    *  This message is then written to the CFIFO like a regular command.
    *  The ADC receives this message, detects the configuration settings
    *  and writes them to its own register.
    *
    **************************************************************************/

    /* Build the message to write the ADC configuration to the ADC configuration register ADC0_CR */
    config.R = 0;                                                       /* Clear all bits (VERY IMPORTANT)*/
    config.B.BN = 0;                                                    /* Command is for ADC 0 */
    config.B.ADC_REG_ADDRESS = 0x01;                                    /* ADC0_CR address, tell the ADC to write this message in its config register */
    config.B.HIGH_BYTE = 0x80;                                          /* Enable ADC module */

    /*************************** IMPORTANT ***************************
    *
    * The ADC clock is restricted to a maximum of 12 MHz.
    * For the course it will generally run at 10 MHz.
    * For Lab3, CPU clock is set to 120 MHz, while for other labs
    * CPU clock is 40 MHz. Set clock prescalar values appropriately.
    * See table 19-28 of MPC5553 manual
    *
    *****************************************************************/

    config.B.LOW_BYTE = /* Fill in here */;                             /* Use clock prescaler for ADC module */

    /* Next, send the configuration command to the ADC using FIFO 1 and clear the result buffer RFPR */
    EQADC.CFPR[1].R = config.R;                                         /* Write config instruction message for ADC 0 to CFIFO1*/
    EQADC.CFCR[1].B.MODE = /* Fill in here */;                          /* Software-triggered, single-scan mode */
    EQADC.CFCR[1].B.SSE = 1;                                            /* Trigger sending the command from the FIFO to the ADC */
    EQADC.CFCR[1].B.MODE =  /* Fill in here */;                         /* Disable queue again until everything is prepared, later it will be activated it in continuous mode */

    /* clear result FIFO (just in case) */
    while (EQADC.FISR[1].B.RFDF)                                        /* Check if the FIFO has valid entries */
    {
        temp = EQADC.RFPR[1].R;                                         /* Retrieve the entry */
        EQADC.FISR[0].B.RFDF = 1;                                       /* Clear flag (should turn on * again if another entry present) */
    }

    /* Build the messages for continuous scanning and store them in a global CONT_SCAN_QUEUE */
    for (x = 0; x < channels; x++)
    {
        cmd.R = 0;                                                      /* Clear all bits (VERY IMPORTANT)*/
        /* Fill in here */
                                                                        /* End-of-queue is for software-triggered continuous-scan mode ignored */
                                                                        /* Do not use external buffer */
                                                                        /* Send commands to ADC0 */
                                                                        /* Do not calibrate the result */
                                                                        /* Return result to RFIFO RFPR1 */
                                                                        /* Sample during 64 clock cycles */
                                                                        /* Do not request a time stamp */
                                                                        /* Conversion data format right justified unsigned */
        /* Fill in end */
        cmd.B.CHANNEL_NUMBER = inputs[x];                               /* Tell the mux which pin to use, passed as an argument to the qadcInit_conti */

        CONT_SCAN_QUEUE[x] = cmd.R;                                     /* Save command to a global queue, so that the eDMA can access it later on */
    }

    /* Setup the eDMA */
        /* Fill in here */                                              /* Call a function to set up DMA requests to fill CFIFO and read RFIFO */

    /* Enable dma-triggering for command and result FIFO  */
    EQADC.IDCR[1].B.CFFE = 1;                                           /* Enable interrupt or eDMA request if CFIFO 1 is read */
    EQADC.IDCR[1].B.CFFS = 1;                                           /* Select between interrupt or eDMA, here eDMA */
    EQADC.IDCR[1].B.RFDE = 1;                                           /* Enable interrupt or eDMA request if RFIFO is populated */
    EQADC.IDCR[1].B.RFDS = 1;                                           /* Select between interrupt or eDMA, here eDMA */

    /* Start conversions for continuous-scan CFIFO */
    EQADC.CFCR[1].B.MODE = /* Fill in here */;                          /* software-triggered, continuous-scan mode, the CFIFO is triggered immediately */
}


/* Read the single-scan analog input
 * ---------------------------------
 * From the qadc module A, FIFO 0, channel is specified in init_single
 * This function must initiate a scan, and wait for completion
 * before reading of the digital number
 */
vuint16_t qadcReadQ1()
{
    uint16_t temp;                                                      /* Temp variable that will be used to drain the RFIFO */
    uint16_t result;                                                    /* Variable that will hold the result */
    /* clear result FIFO0 (just in case) */
    while (EQADC.FISR[0].B.RFDF)                                        /* Check if the FIFO has valid entries */
    {
        temp = EQADC.RFPR[0].R;                                         /* Pop result from RFIFO 0 */
        EQADC.FISR[0].B.RFDF = 1;                                       /* Clear the notification flag */
    }

    /* Fill CFIFO, trigger CFIFO0, and retrieve the result from RFIFO0 */
        /* Fill in here */                                              /* Writing the previously generated command to CFIFO0 */
        /* Fill in here */                                              /* Trigger sending the command from the FIFO to the ADC */

    while (!EQADC.FISR[0].B.RFCTR)                                      /* Wait until the FIFO has valid entries */
        {}
    /* Fill in here */                                                  /* Read the result from the RFIFO, we emptied it before so the first result that will pop up is ours */
    EQADC.FISR[0].B.RFDF = 1;                                           /* Clear the notification flag */

    return result;
}


/* Read a continuous-scan result
 * -----------------------------
 * Read an analog input from the qadc module A, Queue 2.  Valid
 * choices for the channel are from 0 through 7.
 */
vuint16_t qadcReadQ2(vuint8_t channel)
{
/* If the requested channel is valid, return its results*/

    /* Fill in here */

}


/* Configures the DMA Module to move data into and out of FIFOs
 * -----------------------------
 */
void setupDMARequests(int channel_count)
{
    /* PUSH COMMAND FIFO */
    EDMA.CPR[2].B.ECP = 1;                                              /* enable channel 0 preemption */

    /* set up dma request.  channel 2 for QADC FIFO 1 push. */
    /* commands come from CONT_SCAN_QUEUE, defined above */
    EDMA.TCD[2].SADDR = (vuint32_t)(&CONT_SCAN_QUEUE);
    EDMA.TCD[2].SMOD = 0;
    EDMA.TCD[2].SSIZE = 0b010;                                          /* 32 bit */
    EDMA.TCD[2].DMOD = 0;
    EDMA.TCD[2].DSIZE = 0b010;
    EDMA.TCD[2].SOFF = 4;                                               /* 4 bit offset */
    EDMA.TCD[2].NBYTES = 4;                                             /* 4*8 = 32 bits */
    EDMA.TCD[2].SLAST = -(4*channel_count);
    EDMA.TCD[2].DADDR = (vuint32_t)(&EQADC.CFPR[1].R);
    EDMA.TCD[2].CITERE_LINK = 0;
    EDMA.TCD[2].CITER = channel_count;
    EDMA.TCD[2].DOFF = 0;
    EDMA.TCD[2].DLAST_SGA = 0;
    EDMA.TCD[2].BITERE_LINK = 0;
    EDMA.TCD[2].BITER = channel_count;
    EDMA.TCD[2].BWC = 0;
    EDMA.TCD[2].MAJORLINKCH = 0;
    EDMA.TCD[2].DONE = 0;
    EDMA.TCD[2].ACTIVE = 0;
    EDMA.TCD[2].MAJORE_LINK = 0;
    EDMA.TCD[2].E_SG = 0;
    EDMA.TCD[2].D_REQ = 0;
    EDMA.TCD[2].INT_HALF = 0;
    EDMA.TCD[2].INT_MAJ = 0;
    EDMA.TCD[2].START = 0;

    EDMA.SERQR.R = 2;                                                   /* enable channel 2 now that it is configured */

    /* POP RESULT FIFO */
    /* set channel 1 preemption */
    EDMA.CPR[3].B.ECP = 1;

    /* set up dma request.  channel 3 for QADC FIFO 1 pop. */
    /* results go into CONT_SCAN_RESULTS, defined above */
    EDMA.TCD[3].SADDR = (vuint32_t)(&EQADC.RFPR[1].R);                  // source address
    EDMA.TCD[3].SMOD = 0;                                               // source address modulo
    EDMA.TCD[3].SSIZE = 0b10;                                           // source data transfer size
    EDMA.TCD[3].DMOD = 0;                                               // destination address modulo
    EDMA.TCD[3].DSIZE = 0b10;                                           // destination data transfer size
    EDMA.TCD[3].SOFF = 0;                                               // source offset
    EDMA.TCD[3].NBYTES = 4;                                             // number of bytes to be transferred in each service request of channel
    EDMA.TCD[3].SLAST = 0;                                              // last source address adjustment
    EDMA.TCD[3].DADDR = (vuint32_t)(&CONT_SCAN_RESULTS[0]);             // destination address
    EDMA.TCD[3].CITERE_LINK = 0;                                        // channel to channel linking
    EDMA.TCD[3].CITER = channel_count;                                  // iteration count
    EDMA.TCD[3].DOFF =  4;                                              // destination address signed offset
    EDMA.TCD[3].DLAST_SGA = -(4*channel_count);                         // last destination address adjustment
    EDMA.TCD[3].BITERE_LINK = 0;                                        // starting channel to channel linking - must equal citere_link
    EDMA.TCD[3].BITER = channel_count;                                  // Starting major iteration count - must equal citer
    EDMA.TCD[3].BWC = 0;                                                // bandwidth control
    EDMA.TCD[3].MAJORLINKCH = 0;                                        // link channel number
    EDMA.TCD[3].DONE = 0;                                               // channel done
    EDMA.TCD[3].ACTIVE = 0;                                             // channel active
    EDMA.TCD[3].MAJORE_LINK = 0;                                        // enable channel to channel linking on major loop complete
    EDMA.TCD[3].E_SG = 0;                                               // enable scatter/gather processing
    EDMA.TCD[3].D_REQ = 0;                                              // disable hardware request
    EDMA.TCD[3].INT_HALF = 0;                                           // enable an interrupt when major counter is half complete
    EDMA.TCD[3].INT_MAJ = 0;                                            // enable an interrupt when major counter is complete
    EDMA.TCD[3].START = 0;                                              // channel start

    EDMA.SERQR.R = 3;                                                   /* enable channel 3 now that it is configured */
}

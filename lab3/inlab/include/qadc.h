/**************************************************************************
 * FILE NAME: qadc.h

*University of Michigan
*EECS-461, Embedded Systems
*Queued Analog-Digital Converter Module (eQADC)
*Read Chapter 19 in MPC5553 User's Manual
*Created: ? by Noah Cowan (as qadc64.h for MPC555)
*
*Revision History:
*	2000-09-22	Chris Kellum
*	2001-09-27	David Thorsley
*	2002-08-28	Eric Castle
*	2002-09-26	David Thorsley
*	2005-07-18	Eric Williams (to MPC5553 micro)
*	2006-07-25	Jeff Lovell (as qadc.h)
*	2007-01-24           Eric Williams

 * Revised and adapted to use at IMRT ETH Zurich
 * 151-0593-00 Embedded Control Systems (ECS)
 *
 * Revision History:
 *	2008-06-11		Marianne Schmid
 *	2011-02-08		Thomas Schneider (new version)
 *  2012-06-06		Pascal Lutz (all labs set to 120 MHz clock rate)
 *
 **************************************************************************/
#ifndef __QADC_H__
#define __QADC_H__

#include <mpc5553.h>

#ifdef __cplusplus
  extern "C" {
#endif

/* Table 19-34 (Conversion Command Message Format)
  * qadc read configuration command message;
  * important to set .R to zero before using. */
typedef union {
  vuint32_t R;
  struct{
	/*Figure 19-26*/
    vuint32_t header:6;      	/*CFIFO Header*/
    vuint32_t command:26;    	/*ADC Header*/
  } BB;
  struct{
    vuint32_t EOQ:1;         	/*End-of-queue*/
    vuint32_t PAUSE:1;       	/*Pause*/
    vuint32_t :3;				/*Reserved*/
    vuint32_t EB:1;          	/*External buffer bit*/
    vuint32_t BN:1;          	/*Buffer number*/
    vuint32_t CAL:1;         	/*Calibration*/
    vuint32_t MESSAGE_TAG:4; 	/*Message-Tag field*/
    vuint32_t LST:2;         	/*Long sampling time*/
    vuint32_t TSR:1;         	/*Time stamp request*/
    vuint32_t FMT:1;         	/*Conversion data format*/
    vuint32_t CHANNEL_NUMBER:8; /*Channel number*/
    vuint32_t :8;            	/*Reserved*/
  } B;
} cfifo_msg;

/* Table 19-35 (Write configuration)
  * qadc module configuration command message;
  * important to set .R to zero before using. */
typedef union {
  vuint32_t R;
  struct
  {
	/*Figure 19-27*/
    vuint32_t header:6;      	/*CFIFO Header*/
    vuint32_t command:26;    	/*ADC Header*/
  } BB;
  struct
  {
    vuint32_t EOQ:1;         	/*End-of-queue*/
    vuint32_t PAUSE:1;       	/*Pause*/
    vuint32_t :3;            	/*Reserved*/
    vuint32_t EB:1;          	/*External buffer bit*/
    vuint32_t BN:1;          	/*Buffer number*/
    vuint32_t RW:1;          	/*Read/write*/
    vuint32_t HIGH_BYTE:8;   	/*ADC register high byte*/
    vuint32_t LOW_BYTE:8;    	/*ADC register low byte*/
    vuint32_t ADC_REG_ADDRESS:8;/*ADC register address*/
  } B;
} adc_config_msg;

/* Initialize the qadc single scan module
 * --------------------------
 * Specify single-scan channel number
 */
void qadcInit_single(int single_channel);


/* Initialize the qadc continuous scan module
 * --------------------------
 * Specify number of continuous-scan channels (0-8)
 * and an array containing those channel numbers
 */
void qadcInit_conti(int channels, uint32_t *inputs);


/* Read the single-scan analog input
 * ---------------------------------
 * From the qadc module A, FIFO 0, channel is specified in init_single
 * This function must initiate a scan, and wait for completion
 * before reading of the digital number
 */
vuint16_t qadcReadQ1();



/* Read a continuous-scan result
 * -----------------------------
 * Read an analog input from the qadc module A, Queue 2.  Valid
 * choices for the channel are from 0 through 7.
 */
vuint16_t qadcReadQ2(vuint8_t channel);

/* Configures the DMA Module to move data into and out of FIFOs */
void setupDMARequests(int channel_count);



#ifdef __cplusplus
  }
#endif

#endif /* __QADC_H__*/

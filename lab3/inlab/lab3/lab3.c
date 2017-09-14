#include <qadc.h>
#include <isr.h>
#include <serial.h>

#define LED_PIN     28
#define LAB4_4

int main() {

#ifdef LAB4_1
    volatile unsigned short iAnalogQ1 = 0;
    unsigned char i = 0;
    unsigned char flag = 0;

    // init single scan
    init_ECS(3);
    qadcInit_single(1);

    SIU.PCR[LED_PIN].B.PA = 0b000;
    SIU.PCR[LED_PIN].B.OBE = 0b1;
    SIU.PCR[LED_PIN].B.IBE = 0b0;
    SIU.PCR[LED_PIN].B.WPE = 0b0;

    while(1) {
        SIU.GPDO[LED_PIN].B.PDO = 1;
        //flag = !flag;
        iAnalogQ1 = qadcReadQ1();
        SIU.GPDO[LED_PIN].B.PDO = 0;
    }
#endif
#ifdef LAB4_2
    volatile unsigned int inputs[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    volatile unsigned short iAnalogQ2[8] = {0};

    unsigned char i = 0;
    char buff[32];

    init_ECS(3);


    // init serial port
    /* In all labs, we use ESCI_A that corresponds to port 1
     * and a baud rate of 115200 */
    init_COM(1,115200);
    serial_puts(1,"\n\n\n\n\n\n\n\n\rSerial Output Enabled.");

    // init continuous scan
    qadcInit_conti(8, (uint32_t *)inputs);

    while(1) {

        for (i = 0; i < 8; i++) {
            iAnalogQ2[i] = qadcReadQ2(i);
        }

        sprintf(buff, "\f%i %i %i %i %i %i %i %i\r", 
                iAnalogQ2[0],
                iAnalogQ2[1],
                iAnalogQ2[2],
                iAnalogQ2[3],
                iAnalogQ2[4],
                iAnalogQ2[5],
                iAnalogQ2[6],
                iAnalogQ2[7]);
        serial_puts(1, buff);
    }

#endif
#ifdef LAB4_4
    volatile unsigned short iAnalogQ1 = 0;
    unsigned char i = 0;
    unsigned char flag = 0;

    // init single scan
    init_ECS(3);
    qadcInit_single(1);

    // init gpi
    for (i=0; i < 2; i++) {
        SIU.PCR[LED_PIN + i].B.PA = 0b000;
        SIU.PCR[LED_PIN + i].B.OBE = 0b1;
        SIU.PCR[LED_PIN + i].B.IBE = 0b0;
        SIU.PCR[LED_PIN + i].B.WPE = 0b0;
    }	

    while(1) {
        
        iAnalogQ1 = qadcReadQ1();

        if (iAnalogQ1 > 0x1FFC) {
            SIU.GPDO[LED_PIN + 1].B.PDO = 1;
        }
        else {
            SIU.GPDO[LED_PIN + 1].B.PDO = 0;
        }

        flag = !flag;
        SIU.GPDO[LED_PIN].B.PDO = flag;
    }
#endif
    return 0;
}

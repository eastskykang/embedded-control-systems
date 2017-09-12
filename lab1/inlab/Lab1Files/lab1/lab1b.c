#include <mpc5553.h>
#include <serial.h>

#define LED_NO 16

void main() {


    unsigned int time_array[16] = {500, 1500, 2500, 3500, 4500, 5500, 6500, 7500, 8000, 6500, 5500, 4500, 3500, 2500, 1500, 500}; 

    char byte_in;
    int finished=0;

    unsigned char cnt = 0;
    unsigned char inc = 0;
    unsigned int time_cnt = 0;
    unsigned int i = 0;

    unsigned char input_1 = 0;
    unsigned char input_2 = 0;
    unsigned char result = 0;

    // input/output pin number
    unsigned int n_o = 28;

    // reading values
    unsigned char reading_val_1 = 0;
    unsigned char reading_val_2 = 0;

    // output PCR initialization
    for (i=0; i < LED_NO; i++) {
        SIU.PCR[n_o + i].B.PA = 0b000;
        SIU.PCR[n_o + i].B.OBE = 0b1;
        SIU.PCR[n_o + i].B.IBE = 0b0;
        SIU.PCR[n_o + i].B.WPE = 0b0;
    }

    init_ECS(1);
    /* In all labs, we use ESCI_A that corresponds to port 1
     * and a baud rate of 115200 */
    init_COM(1,115200);
    serial_puts(1,"\n\n\n\n\n\n\n\n\rSerial Output Enabled.");

    input_1 = 0;
    input_2 = 0;
    result = 0;

    // control loop 
    while(!finished)
    {

        if (serial_readyToReceive(1)) {
            byte_in = serial_getchar(1);
            
            switch (byte_in) {
                case '0':
                    break;
                case '1':
                    inc = 1;
                    break;
                case '2':
                    inc = 2;
                    break;
                case '3':
                    inc = 3;
                    break;
                case '4':
                    inc = 4;
                    break;
                case '5':
                    inc = 5;
                    break;
                case '6':
                    inc = 6;
                    break;
                case '7':
                    inc = 7;
                    break;
                case '8':
                    inc = 8;
                    break;
                case '9':
                    inc = 9;
                    break;
            }

        }

        // increase counter
        if (time_cnt % 10000 == 0)
            cnt = cnt + inc;

        // make all led 0 
        for (i = 0; i < LED_NO; i++) {
            SIU.GPDO[n_o + i].B.PDO = 1;

            if (time_array[(i + cnt) % LED_NO] / 2 < (time_cnt % 4000)) {
                SIU.GPDO[n_o + i].B.PDO = 0;
            }
        }


        // turn on
        /*
        SIU.GPDO[n_o + cnt].B.PDO = 1;
        SIU.GPDO[n_o + LED_NO - cnt].B.PDO = 1;
        */
        time_cnt++;
    }
}

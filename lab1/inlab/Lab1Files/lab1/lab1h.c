#include <mpc5553.h>
#include <serial.h>

void main() {

    char byte_in;
    int finished=0;

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
    for (i=0; i < 5; i++) {
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
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    input_2 = byte_in - '0';            // new input
                    result = input_1 + input_2;         // add
                    break;
            }

            // output 2
            for (i = 0; i < 5; i++) {
                SIU.GPDO[n_o + i].B.PDO = result % 2;
                result = result >> 1;	
            }

            // prev input update 
            input_1 = input_2;
        }
    }
}

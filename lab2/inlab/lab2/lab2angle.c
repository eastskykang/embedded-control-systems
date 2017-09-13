#include <mpc5553.h>
#include <fqd.h>
#include <serial.h>

int main() {

    int32_t led_output = 0;

    // input/output pin number
    unsigned int n_o = 28;
    unsigned int i = 0;

    char buff[32];
    float serial_output = 0.0f;

    // init 
    init_FQD();
    init_ECS(1);
    /* In all labs, we use ESCI_A that corresponds to port 1
     * and a baud rate of 115200 */
    init_COM(1,115200);
    serial_puts(1,"\n\n\n\n\n\n\n\n\rSerial Output Enabled.");
    
    // output initialization
    for (i=0; i < 16; i++) {
        SIU.PCR[n_o + i].B.PA = 0b000;
        SIU.PCR[n_o + i].B.OBE = 0b1;
        SIU.PCR[n_o + i].B.IBE = 0b0;
        SIU.PCR[n_o + i].B.WPE = 0b0;
    }	

    while(1) {

        led_output = updateCounter();
        // led_output = led_output >> 8;    // for question 10

        // serial output
        serial_output = 0.09 * led_output;
        
        // LED output
        for (i = 0; i < 16; i++) {

            SIU.GPDO[n_o + i].B.PDO = led_output % 2;
            led_output = led_output >> 1;	
        }
        
        sprintf(buff, "\fvalue = %3.2f\r", serial_output);
        serial_puts(1, buff);
    }

    return 0;
}

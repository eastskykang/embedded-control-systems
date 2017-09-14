#include <mpc5553.h>
#include <fqd.h>

int main() {

    /*
    // counter 
    uint16_t counter;
    uint16_t prev_counter;

    // pc variables
    uint32_t last_total;
    */
    uint32_t led_output = 0;

    // input/output pin number
    unsigned int n_o = 28;

    unsigned int i = 0;

    /*
    // variable init
    counter = 0;
    prev_counter = 0;
    last_total = 0;
    */

    // init 
	init_ECS(2);
    init_FQD();
    
    // output initialization
    for (i=0; i < 16; i++) {
        SIU.PCR[n_o + i].B.PA = 0b000;
        SIU.PCR[n_o + i].B.OBE = 0b1;
        SIU.PCR[n_o + i].B.IBE = 0b0;
        SIU.PCR[n_o + i].B.WPE = 0b0;
    }	

    while(1) {
        /*
        // read counter (return 16 bit)
        counter = ReadFQD_pc();

        // calculate total
        
        last_total = last_total + (int16_t) (counter - prev_counter);
        led_output = last_total;

        // calculation 
        prev_counter = counter;
        */

        led_output = updateCounter();
        led_output = led_output >> 8;    // for question 10
        
        // LED output
        for (i = 0; i < 16; i++) {

            SIU.GPDO[n_o + i].B.PDO = led_output % 2;
            led_output = led_output >> 1;	
        }
    }

    return 0;
}

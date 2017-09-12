#include <mpc5553.h>

void main() {
   
    unsigned int i = 0;

    unsigned char input_val_1 = 0;
    unsigned char input_val_2 = 0;
    unsigned char result = 0;

    // input/output pin number
    unsigned int n_1 = 122;		// input 1
    unsigned int n_2 = 126;		// input 2
    unsigned int n_o = 28;

    // reading values
    unsigned char reading_val_1 = 0;
    unsigned char reading_val_2 = 0;

    // input initialization
    for (i = 0; i < 4; i ++) {
        SIU.PCR[n_1 + i].B.PA = 0b000;
        SIU.PCR[n_1 + i].B.OBE = 0b0;
        SIU.PCR[n_1 + i].B.IBE = 0b1;
        SIU.PCR[n_1 + i].B.WPE = 0b0;
    }
    for (i =0; i < 4; i ++) {
        SIU.PCR[n_2 + i].B.PA = 0b000;
        SIU.PCR[n_2 + i].B.OBE = 0b0;
        SIU.PCR[n_2 + i].B.IBE = 0b1;
        SIU.PCR[n_2 + i].B.WPE = 0b0;
    }		

    // output initialization
    for (i=0; i < 5; i++) {
        SIU.PCR[n_o + i].B.PA = 0b000;
        SIU.PCR[n_o + i].B.OBE = 0b1;
        SIU.PCR[n_o + i].B.IBE = 0b0;
        SIU.PCR[n_o + i].B.WPE = 0b0;
    }	

    // control loop 
    while(1)
    {
        // init input_val variables for each loop
        input_val_1 = 0;
        input_val_2 = 0;

        // input_1
        for (i = 3; i > 0; i--) 
        {
            input_val_1 += SIU.GPDI[n_1 + i].B.PDI;
            input_val_1 = input_val_1 << 1;	
        }
        input_val_1 += SIU.GPDI[n_1 + i].B.PDI;

        // input 2
        for (i = 3; i > 0; i--) {
            input_val_2 += SIU.GPDI[n_2 + i].B.PDI;
            input_val_2 = input_val_2 << 1;	
        }
        input_val_2 += SIU.GPDI[n_2 + i].B.PDI;

        // adder 
        result = input_val_1 + input_val_2;

        // output 2
        for (i = 0; i < 5; i++) {
            SIU.GPDO[n_o + i].B.PDO = result % 2;
            result = result >> 1;	
        }
    }
}

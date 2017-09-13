#include "lab1.h"

void main() {
    volatile SIC_PCR *input_1;
    volatile SIC_PCR *input_2;
    volatile SIC_PCR *output;

    unsigned int BASE = 0xC3F90000; 
    unsigned int i = 0;

    unsigned char input_val_1 = 0;
    unsigned char input_val_2 = 0;
    unsigned char result = 0;

    // input/output pin number
    unsigned int n_1 = 122;		// input 1
    unsigned int n_2 = 126;		// input 2
    unsigned int n_o = 28;

    // GPDO / GPDI
    unsigned char *input_gpdi_1 = BASE + 0x0800 + (unsigned char*)n_1;
    unsigned char *input_gpdi_2 = BASE + 0x0800 + (unsigned char*)n_2;
    unsigned char *output_gpdo = BASE + 0x0600 + (unsigned char*)n_o;

    // reading values
    unsigned char reading_val_1 = 0;
    unsigned char reading_val_2 = 0;

    // PCR
    input_1 = (SIC_PCR*)(BASE + 0x0040 + n_1 * 2);
    input_2 = (SIC_PCR*)(BASE + 0x0040 + n_2 * 2);
    output = (SIC_PCR*)(BASE + 0x0040 + n_o * 2);

    // input initialization
    for (i =0; i < 4; i ++) {
        (input_1 + i)->SIU_PCR_122_129.PA = 0b000;
        (input_1 + i)->SIU_PCR_122_129.OBE = 0b0;
        (input_1 + i)->SIU_PCR_122_129.IBE = 0b1;
        (input_1 + i)->SIU_PCR_122_129.WPE = 0b0;
    }
    for (i =0; i < 4; i ++) {
        (input_2 + i)->SIU_PCR_122_129.PA = 0b000;
        (input_2 + i)->SIU_PCR_122_129.OBE = 0b0;
        (input_2 + i)->SIU_PCR_122_129.IBE = 0b1;
        (input_2 + i)->SIU_PCR_122_129.WPE = 0b0;
    }		

    // output initialization
    for (i=0; i < 5; i++) {
        (output + i)->SIU_PCR_28_59.PA = 0b0;
        (output + i)->SIU_PCR_28_59.OBE = 0b1;
        (output + i)->SIU_PCR_28_59.IBE = 0b0;
        (output + i)->SIU_PCR_28_59.WPE = 0b0;
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
            input_val_1 += *(input_gpdi_1 + i);
            input_val_1 = input_val_1 << 1;	
        }
        input_val_1 += *input_gpdi_1;

        // input 2
        for (i = 3; i > 0; i--) {
            input_val_2 += *(input_gpdi_2 + i);
            input_val_2 = input_val_2 << 1;	
        }
        input_val_2 += *input_gpdi_2;

        // adder 
        result = input_val_1 + input_val_2;

        // output 2
        for (i = 0; i < 5; i++) {
            *(output_gpdo + i)  = result % 2;
            result = result >> 1;	
        }
    }
}

#include "lab1.h"

void main() {
	volatile SIC_PCR *input_1;
	volatile SIC_PCR *input_2;
	volatile SIC_PCR *output;

	unsigned int BASE = 0xC3F9; 
	unsigned int i = 0;
	unsigned int input_val_1 = 0;
	unsigned int input_val_2 = 0;
	unsigned int result = 0;
	
	// input/output pin number
	unsigned int n_1 = 122;		// input 1
	unsigned int n_2 = 126;		// input 2
	unsigned int n_o = 28;
	
	// GPDO / GPDI
	unsigned int *input_gpdi_1 = BASE + 0x0800 + (unsigned int*)n_1;
	unsigned int *input_gpdi_2 = BASE + 0x0800 + (unsigned int*)n_2;
	unsigned int *output_gpdo = BASE + 0x0600 + (unsigned int*)n_o;
	
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
		(output + i)->SIU_PCR_122_129.PA = 0b000;
		(output + i)->SIU_PCR_122_129.OBE = 0b1;
		(output + i)->SIU_PCR_122_129.IBE = 0b0;
		(output + i)->SIU_PCR_122_129.WPE = 0b0;
	}	
	
	// control loop 
	while(1)
	{
		// input_1
		for (i = 0; i < 4; i++) {
			input_val_1 += *(input_gpdi_1 + i);
			input_val_1 << 1;	
		}
		
		// input 2
		for (i = 0; i < 4; i++) {
			input_val_2 += *(input_gpdi_2 + i);
			input_val_2 << 1;	
		}
		
		result = input_val_1 + input_val_2;
		
		// output 2
		for (i = 0; i < 4; i++) {
			output_gpdo = result[;
			input_val_2 << 1;	
		}
	}
}
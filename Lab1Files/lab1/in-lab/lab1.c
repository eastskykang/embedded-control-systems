#include "lab1.h"

void main() {
	volatile SIC_PCR input_1[4];
	volatile SIC_PCR input_2[4];
	volatile SIC_PCR output[4];

	unsigned int BASE = 0xC3F9_0000; 
	unsigned int i = 0;
	unsigned int input_val_1 = 0;
	unsigned int input_val_2 = 0;
	unsigned int result = 0;
	
	// input/output pin number
	unsigned int n_1 = 122;		// input 1
	unsigned int n_2 = 126;		// input 2
	unsigned int n_o = 28;
	
	// GPDO / GPDI
	unsigned int input_gpdi_1 = BASE + 0x0800 + n_1;
	unsigned int input_gpdi_2 = BASE + 0x0800 + n_2;
	unsigned int input_gpdo = BASE + 0x0600 + n_o;
	
	// PCR
	input1 = (SIC_PCR*)(BASE + 0x0040 + n_1 * 2);
	input2 = (SIC_PCR*)(BASE + 0x0040 + n_2 * 2);
	output = (SIC_PCR*)(BASE + 0x0040 + n_o * 2);
	
	// input initialization
	for (i =0; i < 8; i ++) {
		(input + i)->SIU_PCR_122_129.PA = 0b000;
		(input + i)->SIU_PCR_122_129.OBE = 0b0;
		(input + i)->SIU_PCR_122_129.IBE = 0b1;
		(input + i)->SIU_PCR_122_129.WPPE = 0b0;
	}	
	
	// output initialization
	for (i=0; i < 5; i++) {
		(input + i)->SIU_PCR_122_129.PA = 0b000;
		(input + i)->SIU_PCR_122_129.OBE = 0b1;
		(input + i)->SIU_PCR_122_129.IBE = 0b0;
		(input + i)->SIU_PCR_122_129.WPPE = 0b0;
	}	
	
	// control loop 
	while(1)
	{
		// input_1
		for (i = 0; i < 4; i++) {
			input_val_1 += *(input_gpdi_1 + i);
			input_val_1 << `1;	
		}
		
		// input 2
		for (i = 0; i < 4; i++) {
			input_val_2 += *(input_gpdi_2 + i);
			input_val_2 << `1;	
		}
		
		result = input_val_1 + input_val_2;
	}
}
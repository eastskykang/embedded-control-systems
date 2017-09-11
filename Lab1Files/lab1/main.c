#include "lab1.h"

void main() {
	volatile SIC_PCR input[8];
	volatile SIC_PCR output[5];

	unsigned int BASE = 0xC3F9_0000; 
	unsigned int i = 0;
	
	input = (SIC_PCR*)(BASE + 0x0040 + 244);
	output = (SIC_PCR*)(BASE + 0x0040 + 56);
	
	// input 
	for (i =0; i < 8; i ++) {
		(input + i)->SIU_PCR_122_129.PA = 0b000;
		(input + i)->SIU_PCR_122_129.OBE = 0b0;
		(input + i)->SIU_PCR_122_129.IBE = 0b1;
		(input + i)->SIU_PCR_122_129.WPPE = 0b0;
	}	
	
	// output
	for (i=0; i < 5; i++) {
		(input + i)->SIU_PCR_122_129.PA = 0b000;
		(input + i)->SIU_PCR_122_129.OBE = 0b1;
		(input + i)->SIU_PCR_122_129.IBE = 0b0;
		(input + i)->SIU_PCR_122_129.WPPE = 0b0;
	}	
}
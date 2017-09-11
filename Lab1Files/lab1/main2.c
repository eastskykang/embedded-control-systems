#include "mpc5553.h"

void main() {
	volatile PCR input[8];
	volatile PCR output[5];

	unsigned int BASE = 0xC3F9_0000; 
	unsigned int i = 0;
	
	input = (SIC_PCR*)(BASE + 0x0040 + 244);
	output = (SIC_PCR*)(BASE + 0x0040 + 56);
	
	// input 
	for (i =0; i < 8; i ++) {
		(input + i)->B.PA = 0b000;
		(input + i)->B.OBE = 0b0;
		(input + i)->B.IBE = 0b1;
		(input + i)->B.WPPE = 0b0;
	}	
	
	// output
	for (i=0; i < 5; i++) {
		(input + i)->B.PA = 0b000;
		(input + i)->B.OBE = 0b1;
		(input + i)->B.IBE = 0b0;
		(input + i)->B.WPPE = 0b0;
	}	
}
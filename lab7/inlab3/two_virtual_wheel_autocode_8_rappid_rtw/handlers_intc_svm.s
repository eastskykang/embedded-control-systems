# handlers_intc_svm.s - INTC software vector mode example
# Description:  Creates prolog, epilog for C ISR and enables nested interrupts
# Rev 1.0: April 23, 2004, Steve Mihalik Freescale Semiconductor Inc,- SM
# Rev 1.1 Aug 2, 2004 SM - delayed writing to EOIR until after EE is disabled in epilog
# Rev 1.2 Sept 8 2004 SM - optimized & corrected r3,r4 restore sequence from rev 1.1 change
# Rev 1.3 Sept 21 2004 SM - optimized by minimizing time interrupts are disabled
# Rev 1.4 Dec 9 2004 SM - substitued code for CodeWarrior hiadj bug work arounds
# Rev 1.5 Maych 24 2005 SM - removed @ha alternative code required for CW beta

# STACK FRAME DESIGN: Depth: 20 words (0xA0, or 80 bytes)
#            ************* ______________
#   0x88     *  GPR12    *    ^
#   0x80     *  GPR11    *    |
#   0x78     *  GPR10    *    |
#   0x70     *  GPR9     *    |
#   0x68     *  GPR8     *    |
#   0x60     *  GPR7     *  GPRs (64 bit)
#   0x58     *  GPR6     *    |
#   0x50     *  GPR5     *    |
#   0x48     *  GPR4     *    |
#   0x40     *  GPR3     *    |
#   0x38     *  GPR0     * ___v__________
#   0x34     *  ACC@l    *    ^
#   0x30     *  ACC@h    *  SPE and FP
#   0x2C     *  FPSCR    * ___v__________
#   0x28     *  CR       * __CR__________
#   0x24     *  XER      *    ^
#   0x20     *  CTR      *    |
#   0x1C     *  LR       * locals & padding for 16 B alignment
#   0x18     *  SRR1     *    |
#   0x14     *  SRR0     *    |
#   0x10     *  padding  *    |
#   0x0C     *  padding  *    |
#   0x08     *  padding  * ___v__________
#   0x04     * resvd- LR * Reserved for calling function
#   0x00     *  SP       * Backchain (same as gpr1 in GPRs)
#            *************

  .text
  .globl	IVOR4Handler
  .align 16			# Align IVOR handlers on a 16 byte boundary
                	    # GHS, Cygnus, Diab(default) use .align 4; Metrowerks .align 16

  .equ	INTC_IACKR, 0xfff48010	# Interrupt Acknoledge Register address
  .equ	INTC_EOIR,	0xfff48018	# End Of Interrupt Register address

IVOR4Handler:
prologINTC:							# PROLOGUE
	stwu	  r1, -0x90 (r1)	    # Create stack frame and store back chain

	stw		r3,  0x44 (r1)	# Store R3[32:63]	
	mfspr		r3, SPEFSCR		# SPEFSCR
	stw		r3, 0x2C (r1)

	lis		r3,0x0200		# enable SPE
	mtmsr		r3			# store SPE-enabled word to msr	

	mfsrr0	r3			# Store SRR0:1 (must be done before enabling EE)
	stw		r3,  0x14 (r1)
	mfsrr1	r3
	stw		r3,  0x18 (r1)
	lwz		r3, 0x44 (r1)	# Restore R3[32:63]
	evstdw	r3, 0x40 (r1)	# Store R3[0:63]
	evxor		r3, r3, r3
	evaddumiaaw	r3, r3
	evstdw	r3, 0x30 (r1)	# save accum

	lis		r3, INTC_IACKR@ha  	# Read pointer into ISR Vector Table & store in r3
	lwz		r3, INTC_IACKR@l(r3)
	lwz		r3, 0x0(r3) 		    # Read ISR address from ISR Vector Table using pointer
	wrteei	1			              # Set MSR[EE]=1	(must wait a couple clocks after reading IACKR)

	evstdw	r4,  0x48 (r1)		  # Store R4[0:63]
	mflr  	r4				  # Store LR (LR will be used for ISR Vector)
	stw		r4,  0x1C (r1)
	mtlr	  	r3				          # Store ISR address to LR to use for branching later

	evstdw	  	r12, 0x88 (r1) 		  # Store rest of gprs
	evstdw	  	r11, 0x80 (r1)
	evstdw	  	r10, 0x78 (r1)
	evstdw	  	r9, 0x70 (r1)
	evstdw	  	r8, 0x68 (r1)
	evstdw	  	r7, 0x60 (r1)
	evstdw	  	r6, 0x58 (r1)
	evstdw	  	r5, 0x50 (r1)
	evstdw	  	r0, 0x38 (r1)
	mfcr  	r3				           # Store CR
	stw	  	r3,  0x28 (r1)
	mfxer	  	r3				           # Store XER
	stw	  	r3,  0x24 (r1)
	mfctr	  	r3				           # Store CTR
	stw		r3,  0x20 (r1)

	blrl						             # Branch to ISR, but return here

epilogINTC:							# EPILOGUE
	lwz	  	r3,  0x1C (r1)	     # Restore LR
	mtlr  	r3
	lwz		  r3,  0x20 (r1)       # Restore CTR
	mtctr	  r3
	lwz		  r3,  0x24 (r1)	     # Restore XER
	mtxer   r3
	lwz	  	r3,  0x28 (r1)	  	 # Restore CR
	mtcrf	  0xff, r3
	evldw		r0,  0x38 (r1)	     # Restore other gprs except working registers
	evldw	  	r5,  0x50 (r1)
	evldw	  	r6,  0x58 (r1)
	evldw	  	r7,  0x60 (r1)
	evldw	  	r8,  0x68 (r1)
	evldw		  r9,  0x70 (r1)
	evldw		  r10, 0x78 (r1)
	evldw	  	r11, 0x80 (r1)
	evldw	  	r12, 0x88 (r1)
	lwz		r3, 0x2C (r1)
	mtspr		SPEFSCR, r3		# SPEFSCR
	evldw		r3, 0x30 (r1)	#restore accum
	evmra		r3, r3

 	mbar   	0			   # Ensure store to clear interrupt flag bit has completed
	lis	  	r3, INTC_EOIR@ha     # Load upper half of EIOR address to r3
	li	  	r4, 0
	wrteei	0				             # Disable interrupts for rest of handler
	stw	  	r4, INTC_EOIR@l(r3)	 # Write 0 to INTC_EOIR (address 0xFFF4 8018)
	lwz	  	r3,  0x14 (r1)   	   # Restore SRR0
	mtsrr0	r3
	lwz	  	r3,  0x18 (r1)	     # Restore SRR1
	mtsrr1	r3
	evldw	  	r4,  0x48 (r1)	     # Restore R4[0:63]
	evldw	  	r3,  0x40 (r1)	     # Restore R3[0:63]
	addi  	r1, r1, 0x90	     # Delete stack frame
	rfi							             # End of Interrupt



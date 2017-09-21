# handlers_fit.s - INTC software vector mode example
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
  .globl	IVOR11Handler
  .globl FitISR		# Needed for CodeWarrior compile
  .align 16			# Align IVOR handlers on a 16 byte boundary
                	    	# GHS, Cygnus, Diab(default) use .align 4; Metrowerks .align 16

IVOR11Handler:
prologFIT:					# PROLOGUE
	stwu		r1, -0x90 (r1)	# Create stack frame and store back chain

	stw		r0,  0x3C (r1)	# Store R0[32:63]
	mfsrr0		r0		# Store SRR0:1 (must be done before enabling EE)
	stw		r0,  0x14 (r1)
	mfsrr1		r0
	stw		r0,  0x18 (r1)
	mfspr		r0, SPEFSCR		# SPEFSCR
	stw		r0, 0x2C (r1)
	mfmsr		r0
	oris		r0,r0,0x0200	# enable SPE
	mtmsr		r0
	lwz		r0,  0x3C (r1)	# Restore R0[32:63]
	evstdw	r0, 0x38 (r1)	# Store R0[0:63]
	evxor		r0, r0, r0
	evaddumiaaw	r0, r0
	evstdw	r0, 0x30 (r1)	# save accum
	mflr  	r0			# Store LR (LR will be used for ISR Vector)
	stw		r0,  0x1C (r1)
	evstdw	r12, 0x88 (r1)
	evstdw	r11, 0x80 (r1)
	evstdw	r10, 0x78 (r1)
	evstdw	r9, 0x70 (r1)
	evstdw	r8, 0x68 (r1)
	evstdw	r7, 0x60 (r1)
	evstdw	r6, 0x58 (r1)
	evstdw	r5, 0x50 (r1)
	evstdw	r4, 0x48 (r1)
	evstdw	r3, 0x40 (r1)
	mfcr  	r0			# Store CR
	stw	  	r0,  0x28 (r1)
	mfxer	  	r0			# Store XER
	stw	  	r0,  0x24 (r1)
	mfctr	  	r0			# Store CTR
	stw		r0,  0x20 (r1)

	bl	FitISR			# Execute Decrementer ISR, but return here	# Branch to ISR, but return here

epilogFIT:					# EPILOGUE
	lwz	  	r0,  0x1C (r1)	# Restore LR
	mtlr  	r0
	lwz		  r0,  0x20 (r1)  # Restore CTR
	mtctr	  r0
	lwz		  r0,  0x24 (r1)	# Restore XER
	mtxer   r0
	lwz	  	r0,  0x28 (r1)	# Restore CR
	mtcrf	  0xff, r0
	evldw		r3, 0x40 (r1)
	evldw		r4, 0x48 (r1)
	evldw		r5, 0x50 (r1)
	evldw		r6, 0x58 (r1)
	evldw		r7, 0x60 (r1)
	evldw		r8, 0x68 (r1)
	evldw		r9, 0x70 (r1)
	evldw		r10, 0x78 (r1)
	evldw		r11, 0x80 (r1)
	evldw		r12, 0x88 (r1)
	lwz		r0, 0x2C (r1)
	mtspr		SPEFSCR, r0		# SPEFSCR
	evldw		r0, 0x30 (r1)	# restore accumulator
	evmra		r0, r0
  	mbar   	0			# Ensure store to clear interrupt flag bit has completed
	lwz	  	r0,  0x14 (r1)   	# Restore SRR0
	mtsrr0	r0
	lwz	  	r0,  0x18 (r1)	# Restore SRR1
	mtsrr1	r0
	evldw		r0, 0x38 (r1)	# Restore R0[0:63]
	addi  	r1, r1, 0x90	# Delete stack frame
	rfi					# End of Interrupt


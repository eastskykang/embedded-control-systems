/* IntcIsrVectors.c - table of ISRs for INTC in SW vector Mode */
/* Description:  Contains addresses for 310 ISR vectors */
/*			     Table address starts at base of L2SRAM */
/* Copyright Freescale Semiconductor Inc 2006.  All rights reserved. */
/*
 *######################################################################
 *                           Start of File
 *######################################################################
 */
#include "typedefs.h"                  /* Use with CodeWarrior */

void interrupt_handler (void);

/*************************** Pragma_1 Section **************************/
#pragma section data_type ".abs.40000000" ".abs.40000000"

uint32_t IntcIsrVectorTable[] = {
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : sw INT 0 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : sw INT 1 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : sw INT 2 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : sw INT 3 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : sw INT 4 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : sw INT 5 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : sw INT 6 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : sw INT 7 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 8 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 9 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 10 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 11 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 12 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 13 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 14 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 15 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 16 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 17 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 18 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 19 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 20 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 21 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 22 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 23 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 24 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 25 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 26 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 27 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 28 */
  (uint32_t)&interrupt_handler,        /* DMA Channel 18 for ESCIA Transmit IRQ Service Function, vector Address :29 */
  (uint32_t)&interrupt_handler,        /* DMA Channel 19 for ESCIA Receive IRQ Service Function, vector Address :30 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 31 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 32 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 33 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 34 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 35 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 36 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 37 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 38 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 39 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 40 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 41 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 42 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 43 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 44 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 45 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 46 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 47 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 48 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 49 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 50 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 0 IRQ Service Function, vector Address :51 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 1 IRQ Service Function, vector Address :52 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 2 IRQ Service Function, vector Address :53 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 3 IRQ Service Function, vector Address :54 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 4 IRQ Service Function, vector Address :55 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 5 IRQ Service Function, vector Address :56 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 6 IRQ Service Function, vector Address :57 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 7 IRQ Service Function, vector Address :58 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 8 IRQ Service Function, vector Address :59 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 9 IRQ Service Function, vector Address :60 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 10 IRQ Service Function, vector Address :61 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 11 IRQ Service Function, vector Address :62 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 12 IRQ Service Function, vector Address :63 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 13 IRQ Service Function, vector Address :64 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 14 IRQ Service Function, vector Address :65 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 15 IRQ Service Function, vector Address :66 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 67 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :68 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :69 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :70 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :71 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :72 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :73 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :74 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :75 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :76 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :77 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :78 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :79 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :80 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :81 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :82 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :83 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :84 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :85 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :86 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :87 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :88 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :89 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :90 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :91 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :92 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :93 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :94 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :95 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :96 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :97 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :98 */
  (uint32_t)&interrupt_handler,        /* ETPU A IRQ Service Function "interrupt_handler", vector Address :99 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 100 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 101 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 102 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 103 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 104 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 105 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 106 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 107 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 108 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 109 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 110 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 111 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 112 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 113 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 114 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 115 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 116 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 117 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 118 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 119 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 120 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 121 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 122 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 123 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 124 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 125 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 126 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 127 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 128 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 129 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 130 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 131 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 132 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 133 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 134 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 135 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 136 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 137 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 138 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 139 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 140 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 141 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 142 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 143 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 144 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 145 */
  (uint32_t)&interrupt_handler,        /* ESCI A IRQ Service Function "interrupt_handler", vector Address :146 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 147 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 148 */
  (uint32_t)&interrupt_handler,        /* ESCI B IRQ Service Function "interrupt_handler", vector Address :149 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 150 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 151 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BOFF IRQ Service Function, vector Address :152 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A ERR IRQ Service Function, vector Address :153 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 154 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF0 IRQ Service Function, vector Address :155 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF1 IRQ Service Function, vector Address :156 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF2 IRQ Service Function, vector Address :157 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF3 IRQ Service Function, vector Address :158 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF4 IRQ Service Function, vector Address :159 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF5 IRQ Service Function, vector Address :160 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF6 IRQ Service Function, vector Address :161 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF7 IRQ Service Function, vector Address :162 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF8 IRQ Service Function, vector Address :163 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF9 IRQ Service Function, vector Address :164 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF10 IRQ Service Function, vector Address :165 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF11 IRQ Service Function, vector Address :166 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF12 IRQ Service Function, vector Address :167 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF13 IRQ Service Function, vector Address :168 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF14 IRQ Service Function, vector Address :169 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF15 IRQ Service Function, vector Address :170 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF31_16 IRQ Service Function, vector Address :171 */
  (uint32_t)&interrupt_handler,        /* FlexCAN A BUF63_32 IRQ Service Function, vector Address :172 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BOFF IRQ Service Function, vector Address :173 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  ERR IRQ Service Function, vector Address :174 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 175 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF0 IRQ Service Function, vector Address :176 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF1 IRQ Service Function, vector Address :177 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF2 IRQ Service Function, vector Address :178 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF3 IRQ Service Function, vector Address :179 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF4 IRQ Service Function, vector Address :180 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF5 IRQ Service Function, vector Address :181 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF6 IRQ Service Function, vector Address :182 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF7 IRQ Service Function, vector Address :183 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF8 IRQ Service Function, vector Address :184 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF9 IRQ Service Function, vector Address :185 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF10 IRQ Service Function, vector Address :186 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF11 IRQ Service Function, vector Address :187 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF12 IRQ Service Function, vector Address :188 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF13 IRQ Service Function, vector Address :189 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF14 IRQ Service Function, vector Address :190 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF15 IRQ Service Function, vector Address :191 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF31_16 IRQ Service Function, vector Address :192 */
  (uint32_t)&interrupt_handler,        /* FlexCAN C  BUF63_32 IRQ Service Function, vector Address :193 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 194 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 195 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 196 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 197 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 198 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 199 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 200 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 201 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 16 IRQ Service Function, vector Address :202 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 17 IRQ Service Function, vector Address :203 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 18 IRQ Service Function, vector Address :204 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 19 IRQ Service Function, vector Address :205 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 20 IRQ Service Function, vector Address :206 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 21 IRQ Service Function, vector Address :207 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 22 IRQ Service Function, vector Address :208 */
  (uint32_t)&interrupt_handler,        /* eMIOS Channel 23 IRQ Service Function, vector Address :209 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 210 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 211 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 212 */
  (uint32_t)&interrupt_handler,        /* DMA Channel 34 for ESCIB Transmit IRQ Service Function, vector Address :213 */
  (uint32_t)&interrupt_handler,        /* DMA Channel 35 for ESCIB Receive IRQ Service Function, vector Address :214 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 215 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 216 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 217 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 218 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 219 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 220 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 221 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 222 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 223 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 224 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 225 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 226 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 227 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 228 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 229 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 230 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 231 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 232 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 233 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 234 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 235 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 236 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 237 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 238 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 239 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 240 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 241 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 242 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :243 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :244 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :245 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :246 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :247 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :248 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :249 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :250 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :251 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :252 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :253 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :254 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :255 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :256 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :257 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :258 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :259 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :260 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :261 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :262 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :263 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :264 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :265 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :266 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :267 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :268 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :269 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :270 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :271 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :272 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :273 */
  (uint32_t)&interrupt_handler,        /* ETPU B IRQ Service Function "interrupt_handler", vector Address :274 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 275 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 276 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 277 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 278 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 279 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BOFF IRQ Service Function, vector Address :280 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   ERR IRQ Service Function, vector Address :281 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 282 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF0 IRQ Service Function, vector Address :283 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF1 IRQ Service Function, vector Address :284 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF2 IRQ Service Function, vector Address :285 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF3 IRQ Service Function, vector Address :286 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF4 IRQ Service Function, vector Address :287 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF5 IRQ Service Function, vector Address :288 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF6 IRQ Service Function, vector Address :289 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF7 IRQ Service Function, vector Address :290 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF8 IRQ Service Function, vector Address :291 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF9 IRQ Service Function, vector Address :292 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF10 IRQ Service Function, vector Address :293 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF11 IRQ Service Function, vector Address :294 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF12 IRQ Service Function, vector Address :295 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF13 IRQ Service Function, vector Address :296 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF14 IRQ Service Function, vector Address :297 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF15 IRQ Service Function, vector Address :298 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF31_16 IRQ Service Function, vector Address :299 */
  (uint32_t)&interrupt_handler,        /* FlexCAN B   BUF63_32 IRQ Service Function, vector Address :300 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 301 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 302 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 303 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 304 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 305 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 306 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 307 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 308 */
  (uint32_t)&interrupt_handler,        /* ISR Vector Address : 309 */
};

/********************** DUMMY INTERRUPT HANDLER **********************/
void interrupt_handler (void)
{
}

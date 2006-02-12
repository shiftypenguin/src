/*	$OpenBSD: keyboard.h,v 1.2 2006/02/12 18:06:24 miod Exp $	*/
/*	$NetBSD: keyboard.h,v 1.1 1998/05/15 10:15:54 tsubai Exp $	*/

/*-
 * Copyright (C) 1993	Allen K. Briggs, Chris P. Caputo,
 *			Michael L. Finch, Bradley A. Grantham, and
 *			Lawrence A. Kesteloot
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the Alice Group.
 * 4. The names of the Alice Group or any of its members may not be used
 *    to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE ALICE GROUP ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE ALICE GROUP BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define ADBK_CAPSLOCK	0x39
#define	ADBK_RESET	0x7f

#define ADBK_KEYVAL(key)	((key) & 0x7f)
#define ADBK_PRESS(key)		(((key) & 0x80) == 0)
#define ADBK_KEYDOWN(key)	(key)
#define ADBK_KEYUP(key)		((key) | 0x80)
#define ADBK_MODIFIER(key)	((((key) & 0x7f) == ADBK_SHIFT) || \
				 (((key) & 0x7f) == ADBK_CONTROL) || \
				 (((key) & 0x7f) == ADBK_FLOWER) || \
				 (((key) & 0x7f) == ADBK_OPTION))

#ifndef KEYBOARD_ARRAY
extern unsigned char keyboard[128][4];
#else
unsigned char keyboard[128][4] = {
	  /* Scan code      Normal     Shifted     Controlled   XT */
	{ /*   0x00, */       'a',       'A',         0x01,	 30 },
	{ /*   0x01, */       's',       'S',         0x13,	 31 },
	{ /*   0x02, */       'd',       'D',         0x04,	 32 },
	{ /*   0x03, */       'f',       'F',         0x06,	 33 },
	{ /*   0x04, */       'h',       'H',         0x08,	 35 },
	{ /*   0x05, */       'g',       'G',         0x07,	 34 },
	{ /*   0x06, */       'z',       'Z',         0x1A,	 44 },
	{ /*   0x07, */       'x',       'X',         0x18,	 45 },
	{ /*   0x08, */       'c',       'C',         0x03,	 46 },
	{ /*   0x09, */       'v',       'V',         0x16,	 47 },
#ifdef FIX_SV_X_KBDBUG
	{ /*   0x0A, */      0x00,      0x00,         0x00,	 41 },
#else
	{ /*   0x0A, */      0x00,      0x00,         0x00,	 86 },
#endif
	{ /*   0x0B, */       'b',       'B',         0x02,	 48 },
	{ /*   0x0C, */       'q',       'Q',         0x11,	 16 },
	{ /*   0x0D, */       'w',       'W',         0x17,	 17 },
	{ /*   0x0E, */       'e',       'E',         0x05,	 18 },
	{ /*   0x0F, */       'r',       'R',         0x12,	 19 },
	{ /*   0x10, */       'y',       'Y',         0x19,	 21 },
	{ /*   0x11, */       't',       'T',         0x14,	 20 },
	{ /*   0x12, */       '1',       '!',         0x00,	  2 },
	{ /*   0x13, */       '2',       '@',         0x00,	  3 },
	{ /*   0x14, */       '3',       '#',         0x00,	  4 },
	{ /*   0x15, */       '4',       '$',         0x00,	  5 },
	{ /*   0x16, */       '6',       '^',         0x1E,	  7 },
	{ /*   0x17, */       '5',       '%',         0x00,	  6 },
	{ /*   0x18, */       '=',       '+',         0x00,	 13 },
	{ /*   0x19, */       '9',       '(',         0x00,	 10 },
	{ /*   0x1A, */       '7',       '&',         0x00,	  8 },
	{ /*   0x1B, */       '-',       '_',         0x1F,	 12 },
	{ /*   0x1C, */       '8',       '*',         0x00,	  9 },
	{ /*   0x1D, */       '0',       ')',         0x00,	 11 },
	{ /*   0x1E, */       ']',       '}',         0x1D,	 27 },
	{ /*   0x1F, */       'o',       'O',         0x0F,	 24 },
	{ /*   0x20, */       'u',       'U',         0x15,	 22 },
	{ /*   0x21, */       '[',       '{',         0x1B,	 26 },
	{ /*   0x22, */       'i',       'I',         0x09,	 23 },
	{ /*   0x23, */       'p',       'P',         0x10,	 25 },
	{ /*   0x24, */      0x0D,      0x0D,         0x0D,	 28 },
	{ /*   0x25, */       'l',       'L',         0x0C,	 38 },
	{ /*   0x26, */       'j',       'J',         0x0A,	 36 },
	{ /*   0x27, */       '\'',      '"',         0x00,	 40 },
	{ /*   0x28, */       'k',       'K',         0x0B,	 37 },
	{ /*   0x29, */       ';',       ':',         0x00,	 39 },
	{ /*   0x2A, */      '\\',       '|',         0x1C,	 43 },
	{ /*   0x2B, */       ',',       '<',         0x00,	 51 },
	{ /*   0x2C, */       '/',       '?',         0x00,	 53 },
	{ /*   0x2D, */       'n',       'N',         0x0E,	 49 },
	{ /*   0x2E, */       'm',       'M',         0x0D,	 50 },
	{ /*   0x2F, */       '.',       '>',         0x00,	 52 },
	{ /*   0x30, */      0x09,      0x09,         0x09,	 15 },
	{ /*   0x31, */       ' ',       ' ',         0x00,	 57 },
#ifdef FIX_SV_X_KBDBUG
	{ /*   0x32, */       '`',       '~',         0x00,	 86 },
#else
	{ /*   0x32, */       '`',       '~',         0x00,	 41 },
#endif
	{ /*   0x33, */      0x7F,      0x7F,         0x7F,	211 }, /* Delete */
	{ /*   0x34, */      0x00,      0x00,         0x00,	105 }, /* MODE/KP_Enter */
	{ /*   0x35, */      0x1B,      0x1B,         0x1B,	  1 },
	{ /*   0x36, */      0x00,      0x00,         0x00,	 29 },
	{ /*   0x37, */      0x00,      0x00,         0x00,	219 },
	{ /*   0x38, */      0x00,      0x00,         0x00,	 42 },
	{ /*   0x39, */      0x00,      0x00,         0x00,	 58 },
	{ /*   0x3A, */      0x00,      0x00,         0x00,	 56 }, /* L Alt */
	{ /*   0x3B, */       'h',      0x00,         0x00,	203 },  /* Left */
	{ /*   0x3C, */       'l',      0x00,         0x00,	205 },  /* Right */
	{ /*   0x3D, */       'j',      0x00,         0x00,	208 },  /* Down */
	{ /*   0x3E, */       'k',      0x00,         0x00,	200 },  /* Up */
	{ /*   0x3F, */      0x00,      0x00,         0x00,	  0 }, /* Fn */
	{ /*   0x40, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x41, */       '.',       '.',         0x00,	 83 },
	{ /*   0x42, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x43, */       '*',       '*',         0x00,	 55 },
	{ /*   0x44, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x45, */       '+',       '+',         0x00,	 78 },
	{ /*   0x46, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x47, */      0x00,      0x00,         0x00,	 69 },
	{ /*   0x48, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x49, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x4A, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x4B, */       '/',       '/',         0x00,	181 },
	{ /*   0x4C, */      0x0D,      0x0D,         0x0D,	156 },
	{ /*   0x4D, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x4E, */       '-',       '-',         0x00,	 74 },
	{ /*   0x4F, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x50, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x51, */       '=',       '=',         0x00,	118 },
	{ /*   0x52, */       '0',       '0',         0x00,	 82 },
	{ /*   0x53, */       '1',       '1',         0x00,	 79 },
	{ /*   0x54, */       '2',       '2',         0x00,	 80 },
	{ /*   0x55, */       '3',       '3',         0x00,	 81 },
	{ /*   0x56, */       '4',       '4',         0x00,	 75 },
	{ /*   0x57, */       '5',       '5',         0x00,	 76 },
	{ /*   0x58, */       '6',       '6',         0x00,	 77 },
	{ /*   0x59, */       '7',       '7',         0x00,	 71 },
	{ /*   0x5A, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x5B, */       '8',       '8',         0x00,	 72 },
	{ /*   0x5C, */       '9',       '9',         0x00,	 73 },
	{ /*   0x5D, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x5E, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x5F, */      0x00,      0x00,         0x00,	 51 },
	{ /*   0x60, */      0x00,      0x00,         0x00,	 63 }, /* F5 */
	{ /*   0x61, */      0x00,      0x00,         0x00,	 64 }, /* F6 */
	{ /*   0x62, */      0x00,      0x00,         0x00,	 65 }, /* F7 */
	{ /*   0x63, */      0x00,      0x00,         0x00,	 61 }, /* F3 */
	{ /*   0x64, */      0x00,      0x00,         0x00,	 66 }, /* F8 */
	{ /*   0x65, */      0x00,      0x00,         0x00,	 67 }, /* F9 */
	{ /*   0x66, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x67, */      0x00,      0x00,         0x00,	 87 }, /* F11 */
	{ /*   0x68, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x69, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x6A, */      0x00,      0x00,         0x00,	156 },
	{ /*   0x6B, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x6C, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x6D, */      0x00,      0x00,         0x00,	 68 }, /* F10 */
	{ /*   0x6E, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x6F, */      0x00,      0x00,         0x00,	 88 }, /* F12 */
	{ /*   0x70, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x71, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x72, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x73, */      0x00,      0x00,         0x00,	199 },
	{ /*   0x74, */      0x00,      0x00,         0x00,	201 },
	{ /*   0x75, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x76, */      0x00,      0x00,         0x00,	 62 }, /* F4 */
	{ /*   0x77, */      0x00,      0x00,         0x00,	207 },
	{ /*   0x78, */      0x00,      0x00,         0x00,	 60 }, /* F2 */
	{ /*   0x79, */      0x00,      0x00,         0x00,	209 },
	{ /*   0x7A, */      0x00,      0x00,         0x00,	 59 }, /* F1 */
	{ /*   0x7B, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x7C, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x7D, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x7E, */      0x00,      0x00,         0x00,	  0 },
	{ /*   0x7F, */      0x00,      0x00,         0x00,	  0 } /* pwr */
};
#endif /* KEYBOARD_ARRAY */

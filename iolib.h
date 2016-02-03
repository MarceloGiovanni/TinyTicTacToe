/*
 *
 * Tiny Tic Tac Toe
 *
 * Copyright (c) 2004-2016 Marcelo DeCastro
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
 *
 * THIS SOFTWARE IS PROVIDED BY ANDREW GILLHAM ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANDREW GILLHAM BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 */


#ifndef ttt_iolib
#define ttt_iolib

// Globals 
extern unsigned char display_green; // green LED display 
extern unsigned char display_red;   // red LED display
extern unsigned char display_rg_ex; // last bit red/green LED display

// Keypad Scan InputFunctions
unsigned char codescan(unsigned char _key_wait_time);

// I/O MAP                                         

// PA0 - LED_Col1                                          
// PA1 - LED_Col2                                                 
// PA2 - LED_Col3                                                 
// PA3 - Red_Row1                                                 
// PA4 - Red_Row2                                                 
// PA5 - Red_Row3                                                 
// PA6 - Green_Row1                                               
// PA7 - Green_Row2                                               

// PB0 - ButtonR3                                                 
// PB1 - ButtonR2                                                 
// PB2 - ButtonR1                                                 
// PB3 - BittpmC3                                                 
// PB4 - BittpmC2                                                 
// PB5 - BittpmC1                                                 
// PB6 - Green_Row3                                               
// PB7 - Reset                                                          

#endif

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

// INCLUDES
#include <avr/io.h>
#include <avr/interrupt.h>

#include "mcu.h"

//
// Function     : init_MCU()      
//
void init_MCU(void) {

     cli();
   
     // Port Init
   
     PORTA = 0x00;  // 00000000
     PORTB = 0x3F;  // 00111111 high on PortB
     DDRA  = 0xFF;  // 11111111 output pins on PortA
     DDRB  = 0x47;  // 01000111 output pins on PortB
 
     // Timer Init
   
     TIMSK |= (1<<TOIE0); // Set interrupt on timer0 overflow
     TCCR0 |= (1<<CS00);  // Start timer 0
   
     sei();
}

//
// Function    : wait(Wait Time)  
//
void wait(unsigned char _wait_Time) {
unsigned char i=0;

     do { 
	 
     WTime = _wait_Time;
	 
     do { } while ( WTime > 0 );

     i++;
	 
     } while (i<10);

     return;
}


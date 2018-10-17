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


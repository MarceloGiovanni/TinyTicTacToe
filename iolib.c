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



// INCLUDES =========================================================
#include <avr/io.h>
#include <avr/signal.h>

#include "ttt.h"
#include "iolib.h"
#include "mcu.h"

//
// Function : Code Scan
//
unsigned char codescan(unsigned char _key_wait_time){
unsigned char Code,j,i;

     for (i=0;i<=_key_wait_time;i++){ // this tells how many scans before giving up.
 
     Code=0;j=0;
     
     // PORTB |= 0x7;
	 // because this generates "LOAD PORTB / OR WITH |=0X7 / SAVE PORTB " if the display interrupt occours 
     // after the load PORTB and before the set PORTB  it could generate a glitch on the code
	 // so, with individual setbits everything will go flawlessly.
	 
     PORTB |= (1<<PB0);
     PORTB |= (1<<PB1);
     PORTB |= (1<<PB2);
   
     do{
	
     // LOW to scan row.
     // A "switch" statement in this case generates much more code than if/clearbit.
     // Usually with more than 6 switch options switch is a better option.
     
     if (j==0) {PORTB &= ~(1<<PB0);}
     if (j==1) {PORTB &= ~(1<<PB1);}
     if (j==2) {PORTB &= ~(1<<PB2);}
     
     Code=3-j; // lets do this first since a NOP would be neccesary to wait for the io PORTB sync anyway. 
     
     if (!(PINB & (1<<PINB3))) {return Code  ;}
     if (!(PINB & (1<<PINB4))) {return Code+3;}
     if (!(PINB & (1<<PINB5))) {return Code+6;}
     
     PORTB |= (1<<PB0);
     PORTB |= (1<<PB1);
     PORTB |= (1<<PB2);
     
     j++;
     
     } while (j<3);
     wait(1);
     }
 
     return 0; 
}

//
// Overflow interrupt
// Display refresh
//
SIGNAL(SIG_OVERFLOW0){
volatile static unsigned char RefreshCol;

// 
//  Wait function. 
//
     if ( WTime > 0 ) WTime--;
	 
// 
//  Display output
//
     RefreshCol++; // Refresh Column 
	 
     if (RefreshCol > 5) RefreshCol=0;
	 
     // Display Refresh
	 
     PORTA |= 0x7;  // LED COLUMN 0 1 2 = 1
      
	 if(RefreshCol==0){
     PORTA &= ~(1<<PA5); // GREEN ROW2
     if(display_red   & _0x0_)PORTA &= ~(1<<PA0);
	 if(display_red   & _0x1_)PORTA &= ~(1<<PA1);
	 if(display_red   & _0x2_)PORTA &= ~(1<<PA2);
	 PORTA |= (1<<PA6); // RED ROW0
	 return;
     }
	 
	 if(RefreshCol==1){
	 PORTA &= ~(1<<PA6); // RED ROW0
	 if(display_red   & _1x0_)PORTA &= ~(1<<PA0);
	 if(display_red   & _1x1_)PORTA &= ~(1<<PA1);
	 if(display_red   & _1x2_)PORTA &= ~(1<<PA2);	 
	 PORTA |= (1<<PA7); // RED ROW1
	 return;
     }
	 
	 if(RefreshCol==2){
	 PORTA &= ~(1<<PA7); // RED ROW0
	 if(display_red   & _2x0_)PORTA &= ~(1<<PA0);
	 if(display_red   & _2x1_)PORTA &= ~(1<<PA1);
	 if(display_rg_ex & _2o2_)PORTA &= ~(1<<PA2);
	 PORTB |= (1<<PB6); // RED ROW2
 	 return;
     }
	 
  	 if(RefreshCol==3){
	 PORTB &= ~(1<<PB6); // RED ROW0
  	 if(display_green & _0x0_)PORTA &= ~(1<<PA0);
	 if(display_green & _0x1_)PORTA &= ~(1<<PA1);
	 if(display_green & _0x2_)PORTA &= ~(1<<PA2);
  	 PORTA |= (1<<PA3); // GREEN ROW0
	 return;
     }	
	 
	 if(RefreshCol==4){
	 PORTA &= ~(1<<PA3); // RED ROW0
	 if(display_green & _1x0_)PORTA &= ~(1<<PA0);
	 if(display_green & _1x1_)PORTA &= ~(1<<PA1);
	 if(display_green & _1x2_)PORTA &= ~(1<<PA2);
  	 PORTA |= (1<<PA4); // GREEN ROW1
	 return;
     }	
	 
     if(RefreshCol==5){
	 PORTA &= ~(1<<PA4); // RED ROW0
     if(display_green & _2x0_)PORTA &= ~(1<<PA0);
	 if(display_green & _2x1_)PORTA &= ~(1<<PA1);
	 if(display_rg_ex & _2x2_)PORTA &= ~(1<<PA2);
  	 PORTA |= (1<<PA5); // GREEN ROW2
	 return;
     }

}

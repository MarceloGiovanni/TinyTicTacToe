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
#include "ttt.h"
#include "iolib.h"
#include "mcu.h"

//
// Function : MAIN                                               
//
int main(void) { 

     init_MCU();

     // Main Loop

     for(;;) {
	     
     // Computer Starts
     
     initgame();
         
         for(;;) { 
	    
         getcomputurn();
         
		 // Wait to give the impression it is taking some time to think.
		 wait(150); 
		 
		 // Load display buffer
         display_red=play_red; 
         display_rg_ex = play_rg_ex;
     
         if (check()) break;
		 
         gethumanturn();
         
         if (check()) break; 
         } 

     // Human Starts
     
     initgame();

         for(;;) { 
	      
         gethumanturn();
         
         if (check()) break;
	     
	     getcomputurn();
	     
	     // Wait to give the impression it is taking some time to think.
		 wait(150); 
		 
         display_red=play_red; // Load display buffer
         display_rg_ex = play_rg_ex;
         
         if (check()) break;
	     
		}
     }
}

//
// Function    : Init Game
//
void initgame(void) {

         // Blank TTT table
     play_green=0;
     play_red=0;
     play_rg_ex=0;

         // Balank display buffer
     display_green=0;
     display_red=0;     
     display_rg_ex=0;

     Display_Pre_Game();
  
         // Balank display buffer
     display_green=0;
     display_red=0;     
     display_rg_ex=0;
  
     wait(150);

}

//
// Function    : Get Computer Turn
//
void getcomputurn(void) {
unsigned char i=0;

     //  Check if the board is empty if so, pick a corner 
     if ((play_red==0) && (play_green==0) && (play_rg_ex==0)){  

     i=TCNT0 % 4;
     
     if(i==0) { play_red   |= _0x0_; return; }
     if(i==1) { play_red   |= _2x0_; return; }
     if(i==2) { play_red   |= _0x2_; return; } 
     if(i==3) { play_rg_ex |= _2o2_; return; } 
    
     }
  
     //  Search for 2s Attack (RED) 

         // 0x0 0x1 0x2
     if((*(solution+8)==2) && (*(solution)==0)){
	     
     if(!(play_red & _0x1_)) {play_red |= _0x1_; return;}
     if(!(play_red & _0x2_)) {play_red |= _0x2_; return;}
     play_red |= _0x0_; return;
	 
     }
             
         // 1x0 1x1 1x2
     if((*(solution+9)==2) && (*(solution+1)==0)){
	    
     if(!(play_red & _1x1_)) {play_red |= _1x1_; return;}
     if(!(play_red & _1x2_)) {play_red |= _1x2_; return;}
     play_red |= _1x0_; return;
	 
     }
             
         // 2x0 2x1 2x2
     if((*(solution+10)==2) && (*(solution+2)==0)){
	     
     if(!(play_red   & _2x1_))   {play_red |= _2x1_; return;}
     if(!(play_rg_ex & _2o2_))   {play_rg_ex |= _2o2_; return;}
     play_red |= _2x0_; return;
	 
     }
             
         // 0x0 1x1 2x2        
     if((*(solution+11)==2) && (*(solution+3)==0)){
	     
     if(!(play_red   & _1x1_)) {play_red |= _1x1_; return;}
     if(!(play_rg_ex & _2o2_)) {play_rg_ex |= _2o2_; return;}
     play_red |= _0x0_; return;
	 
     }
             
         // 2x0 1x1 0x2
     if((*(solution+12)==2) && (*(solution+4)==0)){
	         
     if (!(play_red & _2x0_)) {play_red |= _2x0_; return;}
     if (!(play_red & _0x2_)) {play_red |= _0x2_; return;}
     play_red |= _1x1_; return;
	 }
             
         // 0x0 1x0 2x0
     if((*(solution+13)==2) && (*(solution+5)==0)){
	     
     if (!(play_red & _1x0_)) {play_red |= _1x0_; return;}
     if (!(play_red & _2x0_)) {play_red |= _2x0_; return;}
     play_red |= _0x0_; return;
	 }
             
         // 0x1 1x1 2x1
     if((*(solution+14)==2) && (*(solution+6)==0)){
	 
     if (!(play_red & _1x1_)) {play_red |= _1x1_; return;}
     if (!(play_red & _2x1_)) {play_red |= _2x1_; return;}
     play_red |= _0x1_; return;
     }
     
         // 0x2 1x2 2x2
     if((*(solution+15)==2) && (*(solution+7)==0)){
	         
     if (!(play_red   & _1x2_)) {play_red   |= _1x2_; return;}
     if (!(play_rg_ex & _2o2_)) {play_rg_ex |= _2o2_; return;}
     play_red |= _0x2_; return;
     }
      
     //  Search for 2s Defence (Green)
    
		 // 0x0 0x1 0x2	   
	 if((*(solution+8)==0) && (*(solution)==2)){
     
     if (!(play_green & _0x1_)) {play_red   |= _0x1_; return;}
     if (!(play_green & _0x2_)) {play_red   |= _0x2_; return;}           
     play_red |= _0x0_; return;
     }    
       
         // 1x0 1x1 1x2
     if((*(solution+9)==0) && (*(solution+1)==2)){
     
     if (!(play_green & _1x1_)) {play_red   |= _1x1_; return;}
     if (!(play_green & _1x2_)) {play_red   |= _1x2_; return;}             
     play_red |= _1x0_; return;
	 }    
             
         // 2x0 2x1 2x2
     if((*(solution+10)==0) && (*(solution+2)==2)){

     if (!(play_green & _2x1_))  {play_red   |= _2x1_; return;}
     if (!(play_rg_ex & _2x2_))  {play_rg_ex |= _2o2_; return;}
     play_red |= _2x0_; return;
     }     
         // 0x0 1x1 2x2
     if((*(solution+11)==0) && (*(solution+3)==2)){

     if (!(play_green & _1x1_))  {play_red   |= _1x1_; return;}
     if (!(play_rg_ex & _2x2_))  {play_rg_ex |= _2o2_; return;}
     play_red |= _0x0_; return;
     }     
             
         // 2x0 1x1 0x2
     if((*(solution+12)==0) && (*(solution+4)==2)){             
     
     if(!(play_green & _2x0_))  {play_red   |= _2x0_; return;}
     if(!(play_green & _0x2_))  {play_red   |= _0x2_; return;}
     play_red |= _1x1_; return;
     }     

         // 0x0 1x0 2x0                         
     if((*(solution+13)==0) && (*(solution+5)==2)){             
    
     if(!(play_green & _1x0_))  {play_red   |= _1x0_; return;}
     if(!(play_green & _2x0_))  {play_red   |= _2x0_; return;}
     play_red |= _0x0_; return;
     }     
       
         // 0x1 1x1 2x1
     if((*(solution+14)==0) && (*(solution+6)==2)){             
     if(!(play_green & _1x1_))  {play_red   |= _1x1_; return;}
     if(!(play_green & _2x1_))  {play_red   |= _2x1_; return;}
     play_red |= _0x1_; return;
     } 
	 
         // 0x2 1x2 2x2
     if((*(solution+15)==0) && (*(solution+7)==2)){
     if(!(play_green & _1x2_))  {play_red   |= _1x2_; return;}
     if(!(play_rg_ex & _2x2_))  {play_rg_ex |= _2o2_; return;}
     play_red |= _0x2_; return;
     }

     // If not empty try the center
     if (!((play_red & _1x1_) || (play_green & _1x1_))){
     play_red |= _1x1_; 
     return;
     }
        
     // Block L winning move.
 
         // !0x2 && 0x1 1x2==green
     if ((play_green & _0x1_) && (play_green & _1x2_) && !(play_green & _0x2_) && !(play_red & _0x2_)){
     play_red |= _0x2_; 
     return;
     }

         // !0x0 && 1x0 0x1==green
     if ((play_green & _0x1_) && (play_green & _1x0_) && !(play_green & _0x0_) && !(play_red & _0x0_)){
     play_red |= _0x0_; 
     return;
     }
	 
         // !2x2 && 1x2 2x1==green
     if ((play_green & _1x2_) && (play_green & _2x1_) && !(play_rg_ex)){
     play_rg_ex |= _2o2_; 
     return;
     }
         // !2x0 && 1x2 1x0==green
     if ((play_green & _1x0_) && (play_green & _2x1_) && !(play_green & _2x0_) && !(play_red & _2x0_)){
     play_red |= _2x0_; 
     return;
     }
      
     //  If no L cases found and all corners are free pick a random corner 
	 
         // 0x0 2x0 0x2 2x2 == 0 
     if (!((play_green & 0x45) || (play_red & 0x45) || (play_rg_ex))){

     i=TCNT0 % 4;
  
     if(i==0) { play_red   |= _0x0_; return; }
     if(i==1) { play_red   |= _2x0_; return; }
     if(i==2) { play_red   |= _0x2_; return; }
     if(i==3) { play_rg_ex |= _2o2_; return; }
     }

     // if any corner is marked check for oposing corners. 
	 
         // !2x2 && 0x0==red
     if ((play_red & _0x0_) && !(play_rg_ex)) {
     play_rg_ex |= _2o2_;
     return;
     }
	 
         // !0x0 && 2x2 == red
     if ((play_rg_ex & _2o2_) && !(play_red & _0x0_) && !(play_green & _0x0_)){
     play_red   |= _0x0_;
     return;
     }
	 
         // !2x0 && 0x2 == red
     if ((play_red & _0x2_) && !(play_red & _2x0_) && !(play_green & _2x0_)){
     play_red   |= _2x0_;
     return;
     }
	 
         // !0x2 && 2x0 == red
     if ((play_red & _2x0_) && !(play_red & _0x2_) && !(play_green & _0x2_)){
     play_red   |= _0x2_; 
     return;
     }
 
     // Else pick a free center line attack to prevent defeat from the corners.

     if (play_red & _1x1_){
	 
         // 1x2 | 1x0
     if(*(solution+1)==0 && *(solution+9)==1){
	 
	     if(TCNT0 % 2){
		 play_red |= _1x2_; 
	     } else {
	     play_red |= _1x0_;     
         }
         return;
     }

         // 2x1 | 0x1
     if(*(solution+6)==0 && *(solution+14)==1){
	     if (TCNT0 % 2){
		 play_red |= _2x1_;
	     } else {
	     play_red |= _0x1_;
         }
         return;
     }
     }
    
     // If center is lost keep the opponent busy picking a free corner if there is one.
     // This will eventually make the 3rd corner winning move. 
  
     if (play_green & _1x1_){
 
     if (!(play_rg_ex)){
     play_rg_ex |= _2o2_;
     return;
     } 
	 
     if (!(play_red & _2x0_) && !(play_green & _2x0_)){
     play_red |= _2x0_; 
     return;
     } 
	 
     if (!(play_red & _0x2_) && !(play_green & _0x2_)){
     play_red |= _0x2_; 
     return;
     }
	 
     if (!(play_red & _0x0_) && !(play_green & _0x0_)){
     play_red |= _0x0_; 
     return;
     }
     } 
   
     //  Else Pick a free Random place, its going to be a tie anyway.
     for (;;){

         i=TCNT0 % 9;
		 
         if (i==8) { if (!play_rg_ex) { play_rg_ex |= _2o2_; return;} } else {
		 
         i=(0x1<<i);

         if (!(play_red & i) && !(play_green & i)) { play_red |= i; return; }
         }
     }
  
}


//
// Function : Get Human Turn
//                                         
void gethumanturn(void) {
volatile unsigned char scan_Code=0;
unsigned char sCode;
     for (;;) {
	     
     do {scan_Code=codescan(0);} while(!scan_Code);

     scan_Code--;

     if (scan_Code==8) {
	     
	     if (!play_rg_ex) {
	     play_rg_ex = _2x2_;
	     display_rg_ex= play_rg_ex;
         return;
         } else {
         Display_Already_Marked(8);
         }
         
	 } else {
         sCode = (0x1<<(scan_Code));
         if (!(play_green & sCode) && !(play_red & sCode)){
         play_green |= sCode;   // Assign the chosen move 	
         display_green=play_green;  // Load display buffer
         return;
         }
    
         Display_Already_Marked(scan_Code);
     }
	 }
}


//
// Function : Check                                             
//
unsigned char check(void){ 
unsigned char i;

     loadcheck();
  
     for (i=0;i<8;i++) { 
	     
         if((*(solution+i)==3) || (*(solution+(i+8))==3)) {
	         
         Display_End_Game(i);
         return 1;
         }
     }
	 
	     // if board is full
         if (play_red+play_green==0xff && play_rg_ex) { 
	 
         Display_End_Game(Its_a_tie);
         return 1;
     }
     
     return 0; 
}

//
// Function : loadcheck                                        
//
void loadcheck(void) { 
 
/*

    1|2|3     0x0|0x1|0x2
    -----     -----------
    4|5|6     1x0|1x1|1x2
    -----     -----------
    7|8|9     2x0|2x1|2x2
    

   bit variables play_green/play_red == 87 654 321
   bit variable play.gr_ex == 00000099   red/green   2x2==Green 2o2==Red

*/

// Solution 0 Green= 123
solution[0] =  ((play_green & _0x0_)&&1) + ((play_green & _0x1_)&&1) + ((play_green & _0x2_)&&1);

// Solution 1 Green= 456
solution[1] =  ((play_green & _1x0_)&&1) + ((play_green & _1x1_)&&1) + ((play_green & _1x2_)&&1);

// Solution 2 Green= 789
solution[2] =  ((play_green & _2x0_)&&1) + ((play_green & _2x1_)&&1) + ((play_rg_ex & _2x2_)&&1);

// Solution 3 Green= 159
solution[3] =  ((play_green & _0x0_)&&1) + ((play_green & _1x1_)&&1) + ((play_rg_ex & _2x2_)&&1);

// Solution 4 Green= 357
solution[4] =  ((play_green & _0x2_)&&1) + ((play_green & _1x1_)&&1) + ((play_green & _2x0_)&&1);

// Solution 5 Green= 147
solution[5] =  ((play_green & _0x0_)&&1) + ((play_green & _1x0_)&&1) + ((play_green & _2x0_)&&1);

// Solution 6 Green= 258
solution[6] =  ((play_green & _0x1_)&&1) + ((play_green & _1x1_)&&1) + ((play_green & _2x1_)&&1);

// Solution 7 Green= 369
solution[7] =  ((play_green & _0x2_)&&1) + ((play_green & _1x2_)&&1) + ((play_rg_ex & _2x2_)&&1);

// Solution 8 Red= 123
solution[8] =  ((play_red & _0x0_)&&1) + ((play_red & _0x1_)&&1) + ((play_red & _0x2_)&&1);

// Solution 9 Red= 456
solution[9] =  ((play_red & _1x0_)&&1) + ((play_red & _1x1_)&&1) + ((play_red & _1x2_)&&1);

// Solution 10 Red= 789
solution[10] = ((play_red & _2x0_)&&1) + ((play_red & _2x1_)&&1) + ((play_rg_ex & _2o2_)&&1);

// Solution 11 Red= 159
solution[11] = ((play_red & _0x0_)&&1) + ((play_red & _1x1_)&&1) + ((play_rg_ex & _2o2_)&&1);

// Solution 12 Red= 357
solution[12] = ((play_red & _0x2_)&&1) + ((play_red & _1x1_)&&1) + ((play_red & _2x0_)&&1);

// Solution 13 Red= 147
solution[13] = ((play_red & _0x0_)&&1) + ((play_red & _1x0_)&&1) + ((play_red & _2x0_)&&1);

// Solution 14 Red= 258
solution[14] = ((play_red & _0x1_)&&1) + ((play_red & _1x1_)&&1) + ((play_red & _2x1_)&&1);

// Solution 15 Red= 369
solution[15] = ((play_red & _0x2_)&&1) + ((play_red & _1x2_)&&1) + ((play_rg_ex & _2o2_)&&1);

}

//
// Function: Display Pre Game
//
void Display_Pre_Game(void) {

     for(;;){
     
	 // 101010101  GREEN X
	 display_green = 0x55; 
     display_rg_ex = _2x2_; 
     display_red = 0;
     
     if (codescan(120)) return;
     
	 // Blank
     display_red=0;
     display_green=0;
     display_rg_ex=0;
     
     if (codescan(140)) return;
     
	 // 111101111  RED O
     display_red = 0xef;   
     display_rg_ex = _2o2_; 
     
     if (codescan(120)) return;
     
	 // Blank
     display_red=0;
     display_green=0;
     display_rg_ex=0;
     
     if (codescan(140)) return;
	 
     }
}

//
// Function: Display End Game
//
void Display_End_Game(unsigned char _solution) {
unsigned char i=0;
    
     do {
   
     // Load display buffer

     display_green=play_green;
     display_red=play_red;     
     display_rg_ex=play_rg_ex;

     wait(40);
	 
     switch (_solution) {
	 
     case 0: display_red   &= 0xf8;  // 123 
             display_green &= 0xf8;  // _0x0_ _0x1_ _0x2
             break;              
     case 1: display_red   &= 0xc7;  // 456
             display_green &= 0xc7;  // _1x0_ _1x1_ _1x2_
             break;              
     case 2: display_red   &= 0x3f;  // 789
             display_green &= 0x3f;  // _2x0_ _2x1_ _2x2_
             display_rg_ex = 0;
             break;              
     case 3: display_red   &= 0xee;  // 159
             display_green &= 0xee;  // _0x0_ _1x1_ _2x2_
             display_rg_ex = 0;
             break;              
     case 4: display_red   &= 0xab;  // 753
             display_green &= 0xab;  // _2x0_ _1x1_ _0x2_
             break;                       
     case 5: display_red   &= 0xB6;  // 147 
             display_green &= 0xB6;  // _0x0_ _1x0_ _2x0_
             break;                                 
     case 6: display_red   &= 0x6D;  // 258
             display_green &= 0x6D;  // _0x1_ _1x1_ _2x1_
             break;
     case 7: display_red   &= 0xDB;  // 369
             display_green &= 0xDB;  // _0x2_ _1x2_ _2x2_
             display_rg_ex = 0;
             break;
     case Its_a_tie: display_red=0;
                     display_green=0;
                     display_rg_ex=0;
             break;
     }
	 
     wait(40);
     
     i++;
	 
     } while (i<7);
      
     wait(160);
}
 
//
// Function: Display Space Already Marked
//
void Display_Already_Marked(unsigned char _position) { 
unsigned char i=0;

     do {

     // Blink led already marked. 
      
     if (_position==8) {
	 
	     display_rg_ex=0; 
		 
     } else {
	 
	     display_red   &= ~(0x1<<_position);
         display_green &= ~(0x1<<_position);
		 
     }
     wait(20);
 
     // Reload display buffer
      
     display_green=play_green;
     display_red=play_red;     
     display_rg_ex=play_rg_ex;

     wait(20);
       
     i++; 
	 
     } while (i<3); 
}


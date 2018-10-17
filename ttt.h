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
 *
 */


#ifndef ttt_ttt
#define ttt_ttt

// Globals
register unsigned char play_green    asm("r10"); // green move state
register unsigned char play_red      asm("r11"); // red move state
register unsigned char play_rg_ex    asm("r12"); // last bit red/green move state
register unsigned char display_green asm("r13"); // green LED display
register unsigned char display_red   asm("r14"); // red LED display 
register unsigned char display_rg_ex asm("r15"); // last bit red/green LED display
unsigned char solution[16]; // Winning solution totals.

// Display LED Sequence Functions
void Display_Pre_Game(void);
void Display_End_Game(unsigned char _solution);
void Display_Already_Marked(unsigned char _position);

// Logic Functions
void initgame(void);       // Clears variables and displays pre-game.
void gethumanturn(void);   // Gets Human's turn
void getcomputurn(void);   // Gets Computer's turn
unsigned char check(void);// Checks if it is the end of the game. 
void loadcheck(void);      // Loads the winning totals into the solution[] global. 

// Tic-Tac-Toe Matrix declaration
#define  _0x0_ 0x01  // 0x0
#define  _0x1_ 0x02  // 0x1
#define  _0x2_ 0x04  // 0x2
#define  _1x0_ 0x08  // 1x0
#define  _1x1_ 0x10  // 1x1
#define  _1x2_ 0x20  // 1x2
#define  _2x0_ 0x40  // 2x0
#define  _2x1_ 0x80  // 2x1
#define  _2x2_ 0x01  // 2x2 for Green
#define  _2o2_ 0x02  // 2x2 for Red
#define  Its_a_tie 8 // Display its a tie
#endif

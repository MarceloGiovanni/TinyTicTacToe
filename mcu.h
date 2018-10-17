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

#ifndef ttt_mcu
#define ttt_mcu

// Globals 
register unsigned char WTime asm("r9"); // Wait time

// House Cleaning Functions
void init_MCU(void);                  // Initialize the MCU
void wait(unsigned char _wait_Time); // Wait function. 

#endif

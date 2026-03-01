# TINY Tic Tac Toe

This project was developed back in 2004 for the Atmel ATTINY Circuit Cellar Contest.

This Tic Tac Toe game has a 3x3 dual-color LED matrix, a 3x3 keypad scan, and the algorithm necessary to make the game impossible to beat. Everything was designed to fit on an ATTINY26 AVR with 2KB of flash.

Here is a video of the game in action. 
https://www.youtube.com/watch?v=x-JH1wQzx94

# Losing the Game

As is commonly known, Tic Tac Toe is a solved game. If you aren't the first to play, there is no way to win; you can only tie.

The winning and blocking rules are easy to figure out.

The software follows these rules from top to bottom:

  - If the board is empty: Pick a corner.
  - If you've already marked 2 positions on a line and the third one is free: Mark the third to win.
  - If your opponent has already marked 2 positions on a line and the third one is free: Mark the third to defend.
  - If the center is free: Mark the center.
  - If the opponent has marked 2 adjacent lateral middle positions: Mark the corner in between.
  - If all corners are still free (may happen if the opponent went first): Mark a random corner.
  - If you've already marked a corner: Mark an opposing free corner.
  - If you have the center: Mark on a line to keep the opponent busy and prevent them from winning with the three-corners move.
  - Try to conquer three corners: Mark a random free corner.
  - It is going to be a tie anyway: Mark a random free position.

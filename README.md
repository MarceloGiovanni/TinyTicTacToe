# TINY Tic Tac Toe

This project was developed back in 2004 for the Atmel ATTINY Circuit Cellar Contest.

This Tic Tac Toe game has a 3x3 dual color LED matrix, a 3x3 keypad scan, and the algorithm necessary to make the game impossible to beat. Everything was designed to fity on an ATTINY26 AVR with 2Kb of flash.

Here is a video of the game in action. 
https://www.youtube.com/watch?v=x-JH1wQzx94

# Losing the Game

As it is commonly known,  Tic Tac Toe is no mystery, if you aren't the first to start the game there is no way to win it, you can only tie the game.

The winning and blocking rules are easy to figure out. 

The software follows the these rules top to bottom:

  - If the board is empty: Pick a corner.
  - If You've already marked 2 positions on a line and the third one is free: Mark the third  to win.
  - If your opponent has already marked 2 positions on a line and the third one is free: Mark the third to defend.
  - If the center is free: Mark the center. 
  - If the opponent has marked 2 adjacent lateral middle positions: Mark the corner in between.
  - If all corners are still free (may happen if  the opponent began): Mark a random corner.
  - If you've already marked a corner: Mark an opposing free corner. 
  - If you have the center: Mark on a line to keep the opponent busy. And prevent the opponent from winning with the three corners move.
  - Try to conquer three corners: Mark a random free corner.
  -  It is going to be a tie anyway: Mark on a random free position.

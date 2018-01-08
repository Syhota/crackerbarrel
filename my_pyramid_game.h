/* 
 * File:   my_pyramid_game.h
 * Author: 	Connor S
 *
 */

#ifndef MY_PYRAMID_GAME_H
#define MY_PYRAMID_GAME_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stdio.h>
  

/*
 * THIS FUNCTION WILL BE CALLED DURING TEST ASSESSMENTS.
 * 
 * solve: This is the game 'engine', in which the logic is based.
 *        It takes a board in any valid state, and determines
 *        if the game is solvable.
 * 
 * Parameters:
 *        board - an integer array of size 15, with contents either 0 or 1.
 * 
 * Returns:
 *        1  -  If the board is solvable;
 *        0  -  otherwise.
 */
int solve(int board[]);


/* 
 * main_pyramid:  This is the entry point to your pyramid game implementation.
 * 
 * Pretend this is the main() function as you are use to writing,
 * i.e. the function where your program logic begins and terminates.
 */

int main_pyramid();


#ifdef __cplusplus
}
#endif

#endif /* MY_PYRAMID_GAME_H */


/* 
 * File:   pyramid_helpers.h
 * Author: Connor S
 *
 */

#ifndef PYRAMID_HELPERS_H
#define PYRAMID_HELPERS_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include<stdbool.h>

/* 
 * set_quiet: Used to stop boards being printed to the screen
 *            when file-input is set.
 * 
 * Parameters:
 *      b      - boolean, true for quiet; false, otherwise.
 */
void set_quiet(bool b);
    
/* 
 * pyramid_print:  Prints the pyramid game represented by <board>
 *                 to standard output in a visually pleasing manner.
 *
 * Parameters:
 *      board[] - An array of 15 integers.  Non-zero values 
 *                indicate a peg in that position.
 */

void pyramid_print(const int board[]);


/* 
 * pyramid_input:  Takes a starting position as input from the user. 
 *
 * Parameters:
 *      board[] - An array of 15 integers.
 *                The array will contain the board upon completion.
 */

void pyramid_input(int board[]);

#ifdef __cplusplus
}
#endif

#endif /* PYRAMID_HELPERS_H */


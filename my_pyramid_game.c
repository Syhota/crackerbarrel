/* 
 * Cracker barrel pyramid game in C
 * file: my_pyramid_game.c
 * Author: Connor S
 */
 
#include "my_pyramid_game.h"
#include "pyramid_helpers.h"
#define TOTAL_MOVES 36
#define TOTAL_PEGS 15
#define MOVE 3

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

// List of total possible moves
const int possMoves[TOTAL_MOVES][MOVE] = {{0,1,3}, {0,2,5}, {1,3,6}, {1,4,8}, {2,4,7}, {2,5,9},
                                          {3,1,0}, {3,4,5}, {3,6,10}, {3,7,12}, {4,7,11}, {4,8,13},
                                          {5,8,12}, {5,9,14}, {5,2,0}, {5,4,3}, {6,3,1}, {6,7,8}, {7,4,2},
                                          {7,8,9}, {8,7,6}, {8,4,1}, {9,5,2}, {9,8,7}, {10,6,3}, {10,11,12},
                                          {11,7,4}, {11,12,13}, {12,7,3}, {12,11,10}, {12,8,5},
                                          {12,13,14}, {13,8,4}, {13,12,11}, {14,9,5}, {14,13,12}};


/*
 * Checks if the current peg, the peg in between, and the destination peg are
 * full, full and empty respectively, thus meaning the move is legal
 */
bool checkMove(int moves[], int board[]) {
    if (board[moves[0]] == 1 && board[moves[1]] == 1 && board[moves[2]] == 0) {
        return true;
    }
}

/*
 * Iterates through the board, if it finds that a peg is full then it increases the peg amount
 */
int pegChecker(int board[]) {
    int i;
    int pegAmount = 0;
    for (i = 0; i <= TOTAL_PEGS; i++) {
        if (board[i] == 1) {
            pegAmount++;
        }
    }
    return pegAmount;
}

/*
 * Sets the board at:
 * Start position to be empty
 * Middle (jumped over) position to be empty
 * Destination position to be filled
 */
void makeJump(int board[], int moves[]) {
    board[moves[0]] = 0;
    board[moves[1]] = 0;
    board[moves[2]] = 1;
}

/*
 * Resets the board to its previous state when it finds there are no more legal moves and the board is not solved
 */
void undoJump(int board[], int moves[]) {
    board[moves[0]] = 1;
    board[moves[1]] = 1;
    board[moves[2]] = 0;
}

/*
 * Recursive function that carries out the moves and undoes moves if they aren't legal
 * until the board is solved.
 */
int solve(int board[])
{
    pyramid_print(board);
    int recursiveReturn = 0;

    if (pegChecker(board) == TOTAL_PEGS) {
        printf("Too many pegs! Must have at least one peg free!\n");
        return 0; // board is unsolvable
    } else if (pegChecker(board) == 1) {
        return 1; // if the pegChecker finds only one peg left, the board is solved
    } else if (pegChecker(board) == 0) {
        return 0; // board is unsolvable
    }

    int movePos[3]; // array to store the peg positions whilst doing jumps or undoing jumps

    for (int i = 0; i < TOTAL_MOVES; i++) {
        movePos[0] = possMoves[i][0]; // assigns starting peg to first element in possible move
        movePos[1] = possMoves[i][1]; // assigns middle peg to second element of a possible move
        movePos[2] = possMoves[i][2]; // assigns destination peg to third element of a possible move

        if (checkMove(movePos, board) == true) {
            // these set starting, middle, and destination peg as empty, empty and full respectively
            makeJump(board, movePos);
            printf("Move carried out: %d over %d to %d\n", movePos[0], movePos[1], movePos[2]);
            recursiveReturn = solve(board); // variable for recursively calling the function
            undoJump(board, movePos);
            if (recursiveReturn == 1) {
                return 1;
            }
        }
    }
}

/*
 * main_pyramid:  This is the entry point to your pyramid game implementation.
 *
 * Pretend this is the main() function as you are use to writing,
 * i.e. the function where your program logic begins and terminates.
 */
int main_pyramid()
{
    int board[15];

    pyramid_input(board);

    printf("Here is the board you entered:\n");
    pyramid_print(board);
    int solved = solve(board);
    printf(solved ? "Board has been solved." : "Board is unsolvable."); // ternary which prints true or false condition
    return solved;
}
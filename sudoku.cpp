#include <iostream>
#include "sudoku.h"
using namespace std;



// Checks if a number can go in a specific cell without breaking the rules
bool isNumberAllowed(int board[SIZE][SIZE], int row, int col, int number) {
    // check row
    for (int c = 0; c < SIZE; c++) {
        if (board[row][c] == number) return false;
    }

    // check column
    for (int r = 0; r < SIZE; r++) {
        if (board[r][col] == number) return false;
    }

    // check 3x3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int r = startRow; r < startRow + 3; r++) {
        for (int c = startCol; c < startCol + 3; c++) {
            if (board[r][c] == number) return false;
        }
    }

    return true;
}

// Tries to fill the board using backtracking
bool solveBoard(int board[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; ++r) {
        for (int c = 0; c < SIZE; ++c) {
            if (board[r][c] == 0) { // empty cell found
                for (int guess = 1; guess <= 9; ++guess) {
                    if (isNumberAllowed(board, r, c, guess)) {
                        board[r][c] = guess;

                        // recursive call: keep trying
                        if (solveBoard(board)) return true;

                        // if we’re here, that guess failed — backtrack
                        board[r][c] = 0;
                    }
                }

                // no valid number worked here — need to backtrack further
                return false;
            }
        }
    }

    // if we finish the whole loop without hitting any "0", board is solved
    return true;
}

// Displays the board nicely
void showBoard(int board[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; ++r) {
        for (int c = 0; c < SIZE; ++c) {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}





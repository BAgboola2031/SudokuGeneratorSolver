

#ifndef SUDOKU_H
#define SUDOKU_H

const int SIZE = 9;

// function declarations
bool isNumberAllowed(int board[SIZE][SIZE], int row, int col, int number);
bool solveBoard(int board[SIZE][SIZE]);
void showBoard(int board[SIZE][SIZE]);



#endif //SUDOKU_H

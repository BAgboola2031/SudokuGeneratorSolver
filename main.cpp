// Comment this out to run submission mode (file output only)
// #define DEBUG

#include <iostream>
#include "sudoku.h"
#include "generator.h"
#include "sudoku_io.h"

using namespace std;

int main() {
    int board[9][9];

#ifdef DEBUG
    // DEV MODE: Load puzzle from file, solve it, print it
    if (!readPuzzle("sample_puzzle.txt", board)) {
        cout << "Failed to load puzzle.\n";
        return 1;
    }

    cout << "Loaded Puzzle:\n";
    showBoard(board);

    cout << "\nSolving...\n";
    if (solveBoard(board)) {
        cout << "Solved Puzzle:\n";
        showBoard(board);
    } else {
        cout << "Couldn't solve the puzzle.\n";
    }

#else
    // SUBMISSION MODE: Generate, solve, and save puzzle
    createSolvedGrid(board);
    carvePuzzle(board, 45);

    if (solveBoard(board)) {
        cout << "Puzzle solved successfully.\n"; // TEMP: For confirmation
        writePuzzle("data/solved_output.txt", board);
    } else {
        cout << "Failed to solve generated puzzle.\n";
    }
#endif

    return 0;
}

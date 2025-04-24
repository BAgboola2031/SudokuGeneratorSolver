#ifndef SUDOKU_IO_H
#define SUDOKU_IO_H

#include <string>
#include "sudoku.h"


// Reads a board from a file into the grid array
bool readPuzzle(const std::string& filename, int grid[SIZE][SIZE]);

// Saves the board to a text file
bool writePuzzle(const std::string& filename, int grid[SIZE][SIZE]);

#endif

#include <fstream>
#include <iostream>
#include "sudoku_io.h"

using namespace std;

// Reads board values from a file and stores them into the grid array
bool readPuzzle(const string& filename, int grid[SIZE][SIZE]) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Couldn't open file: " << filename << endl;
        return false;
    }

    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            file >> grid[row][col];
        }
    }

    file.close();
    return true;
}

// Writes the current board to a text file
bool writePuzzle(const string& filename, int grid[SIZE][SIZE]) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Couldn't create file: " << filename << endl;
        return false;
    }

    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            file << grid[row][col] << " ";
        }
        file << endl;
    }

    file.close();
    return true;
}

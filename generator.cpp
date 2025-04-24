#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "generator.h"
#include "sudoku.h"  // uses your isNumberAllowed()

using std::vector;
using std::random_device;
using std::mt19937;
using std::shuffle;

// 🔥 Global random number generator so we get different results every run
random_device rd;
mt19937 rng(rd());

// Helper: returns shuffled numbers 1 through 9
vector<int> getRandomOrder() {
    vector<int> values = {1,2,3,4,5,6,7,8,9};
    shuffle(values.begin(), values.end(), rng);
    return values;
}

// Recursive fill using randomized values
bool tryFill(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] == 0) {
                vector<int> options = getRandomOrder();
                for (int val : options) {
                    if (isNumberAllowed(grid, r, c, val)) {
                        grid[r][c] = val;
                        if (tryFill(grid)) return true;
                        grid[r][c] = 0;  // backtrack
                    }
                }
                return false;  // no valid value fit
            }
        }
    }
    return true;  // board is full
}

// Creates a full valid Sudoku board
void createSolvedGrid(int grid[N][N]) {
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            grid[r][c] = 0;

    tryFill(grid);
}

// Removes random cells to create a playable puzzle
void carvePuzzle(int grid[N][N], int cellsToRemove) {
    std::uniform_int_distribution<> dist(0, N - 1);

    int count = 0;
    while (count < cellsToRemove) {
        int row = dist(rng);
        int col = dist(rng);

        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            count++;
        }
    }
}

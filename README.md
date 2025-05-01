# SudokuGeneratorSolver

A complete C++ Sudoku puzzle generator and solver that supports both basic backtracking and optimized solving strategies. Designed for CS2308: Data Structures, this project demonstrates core object-oriented principles, recursion, file I/O, and modular C++ programming.

---

## Features

- **Puzzle Generation**: Randomly generates a fully valid 9x9 Sudoku board.
- **Puzzle Carving**: Removes numbers to create solvable puzzles with difficulty control.
- **Basic Solver**: Uses recursive backtracking to solve the puzzle.
- **Optimized Solver**: (Optional) Adds logic for improved solving performance.
- **DEBUG Mode**: Loads puzzles from file and prints to console for testing.
- **Non-DEBUG Mode**: Auto-generates puzzles and writes output to file.
- **Modular Design**: Separated into multiple `.cpp` and `.h` files following OOP principles.

---

## File Structure

- `main.cpp` — Handles program execution flow and toggles between DEBUG and non-DEBUG.
- `generator.cpp/.h` — Functions for board generation, carving, and shuffling.
- `sudoku.cpp/.h` — Solving logic and board validation.
- `sudoku_io.cpp/.h` — Input/output file operations and board display.
- `sample_puzzle.txt` — Sample puzzle for DEBUG testing.
- `data/solved_output.txt` — Output file generated during non-DEBUG mode.

---

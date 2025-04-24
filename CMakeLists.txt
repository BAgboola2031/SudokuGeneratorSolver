cmake_minimum_required(VERSION 3.30)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(SudokuSolver main.cpp
        sudoku.cpp
        sudoku.h
        generator.cpp
        generator.h
        sudoku_io.h
        sudoku_io.cpp)

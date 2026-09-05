cmake_minimum_required(VERSION 3.10)
project(SudokuGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sudoku
    main.cpp
    Board.cpp
    Generator.cpp
    Solver.cpp
)

target_include_directories(sudoku PRIVATE .)

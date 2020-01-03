cmake_minimum_required(VERSION 3.15)
project(N_Puzzle)

set(CMAKE_CXX_STANDARD 14)

add_executable(N_Puzzle main.cpp src/ErrorManager.cpp src/ArgumentHandler.cpp src/Node.cpp src/Puzzle.cpp)
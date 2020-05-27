cmake_minimum_required(VERSION 3.16)
project(OKMD)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS -pthread)
add_executable(OKMD main.cpp Matrix.cpp Matrix.h Controller.cpp Controller.h TripleMatrix.cpp TripleMatrix.h)
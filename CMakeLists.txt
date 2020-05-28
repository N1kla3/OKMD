cmake_minimum_required(VERSION 3.16)
project(OKMD)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS -pthread)
add_executable(OKMD main.cpp src/Matrix.cpp src/Matrix.h src/Controller.cpp src/Controller.h src/TripleMatrix.cpp src/TripleMatrix.h)
add_subdirectory(test)
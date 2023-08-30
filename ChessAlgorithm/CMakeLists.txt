cmake_minimum_required(VERSION 3.19)
project(ChessAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChessAlgorithm main.cpp ChessBoard.cpp ChessBoard.h BoardData.cpp BoardData.h Coordinates.cpp Coordinates.h ChessInputHandling.cpp ChessInputHandling.h)
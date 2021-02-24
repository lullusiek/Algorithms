cmake_minimum_required(VERSION 3.16)

project(ChessAlgorithms CXX C)

add_executable(ChessAlgorithms main.cpp algorithms.cpp)

target_include_directories(ChessAlgorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
cmake_minimum_required(VERSION 3.10)

project(mergesort VERSION 1.0.0)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
message(STATUS "EXECUTABLE_OUTPUT_PATH = ${EXECUTABLE_OUTPUT_PATH}")
message(STATUS "LIBRARY_OUTPUT_PATH = ${LIBRARY_OUTPUT_PATH}")
message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

add_library(merge_sort_lib STATIC "mergesort.h")
#add executable
add_executable(demo_mergesort ${PROJECT_SOURCE_DIR}/demo_mergesort.cpp)
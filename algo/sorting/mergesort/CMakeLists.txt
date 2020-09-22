cmake_minimum_required(VERSION 3.10)

project(mergesort VERSION 1.0.0)

add_library(merge_sort_lib STATIC "mergesort.h")
#add executable
add_executable(demo_mergesort ${PROJECT_SOURCE_DIR}/demo_mergesort.cpp)
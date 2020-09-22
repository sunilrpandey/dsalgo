cmake_minimum_required(VERSION 3.10)

project(demo_linklist VERSION 1.0.0)

set(CMAKE_CXX_FLAGS "-std=c++17")

set(SOURCES demo_linklist.cpp linklist.cpp)

add_executable(demo_linklist ${SOURCES})

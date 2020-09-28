cmake_minimum_required(VERSION 3.10)

project(demo_queue VERSION 1.0.0)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(SOURCES demo_queue.cpp)

add_executable(demo_queue ${SOURCES})
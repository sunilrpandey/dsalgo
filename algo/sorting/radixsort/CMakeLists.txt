cmake_minimum_required(VERSION 3.10)

project(radixsort VERSION 1.0.0)
add_definitions(-DLOG_ENABLED)

add_executable(demo_radixsort ${PROJECT_SOURCE_DIR}/demo_radixsort.cpp)
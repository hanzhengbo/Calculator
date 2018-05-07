cmake_minimum_required(VERSION 3.7)
project(MyCalculator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Stack.h MyCalculator.cpp)
add_executable(MyCalculator ${SOURCE_FILES})
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")  # Replace with the path to your gcc
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")  # Replace with the path to your g++

cmake_minimum_required(VERSION 3.10)

# Project name
project(SimpleSentenceProcessor)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the src directory for header files
include_directories(src)

# Specify the executable and add all .cpp files in src
add_executable(main src/main.cpp src/input_processor.cpp src/output_processor.cpp)

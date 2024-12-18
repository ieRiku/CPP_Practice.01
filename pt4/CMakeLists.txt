cmake_minimum_required(VERSION 3.10)

# Project name
project(ComposeApp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the executable's location
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Add the source files
add_executable(main
    src/run.cpp
    src/compose.cpp
)

# Include the headers directory
target_include_directories(main PRIVATE src)

cmake_minimum_required(VERSION 3.10)
project(FlappyBirdClone)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Specify the path to SDL2 and SDL_image
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/pak64/")
set(SDL2_IMAGE_DIR "${CMAKE_SOURCE_DIR}/pak64-img")

# Include directories
include_directories(${SDL2_DIR}/include)
include_directories(${SDL2_DIR}/include/SDL2)
include_directories(${SDL2_IMAGE_DIR}/include)

# Link directories
link_directories(${SDL2_DIR}/lib)
link_directories(${SDL2_IMAGE_DIR}/lib)

# Add source files
add_executable(FlappyBirdClone src/main.cpp)

# Set output directory
set_target_properties(FlappyBirdClone PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")

# Link SDL2 and SDL_image libraries
target_link_libraries(FlappyBirdClone mingw32 SDL2main SDL2 SDL2_image)
cmake_minimum_required(VERSION 3.10)

# Project name
project(RedBlock)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directories
include_directories(pak/include/SDL2)

# Add the library directories
link_directories(pak/lib)

# Add the executable
add_executable(main red_block.cpp)

# Link the SDL2 libraries in the correct order
target_link_libraries(main mingw32 SDL2main SDL2)

# Ensure SDL2.dll is copied to the output directory for runtime
add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/SDL2.dll $<TARGET_FILE_DIR:main>)

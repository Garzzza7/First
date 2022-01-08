cmake_minimum_required(VERSION 3.4)

project(Program)

set(SOURCE_FILES src/main.cpp)
add_executable(Program ${SOURCE_FILES})

target_link_libraries(Program
        Library
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window)

target_include_directories(Program PUBLIC include)

target_compile_options(Program PRIVATE -Wall)

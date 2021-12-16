cmake_minimum_required(VERSION 3.4)
project(Library)
set(SOURCE_FILES
        include/Player.h src/Player.cpp)
add_library(Library ${SOURCE_FILES})
target_include_directories(Library PUBLIC include)

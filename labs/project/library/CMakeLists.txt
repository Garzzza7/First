cmake_minimum_required(VERSION 3.4)
project(Library)
set(SOURCE_FILES
        include/Container.h)
add_library(Library ${SOURCE_FILES})
target_include_directories(Library PUBLIC include)

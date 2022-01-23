cmake_minimum_required(VERSION 3.21)
project(Library)

set(SOURCE_FILES
        include/Tiles/ObjectBase.h src/Tiles/ObjectBase.cpp
        include/Tiles/Tile.h src/Tiles/Tile.cpp
        include/Player.h src/Player.cpp
        include/Game.h src/Game.cpp
        include/Level.h src/Level.cpp
        include/Tiles/ObjectRegistry.h src/Tiles/ObjectRegistry.cpp
        include/Enemies/Enemy.h src/Enemies/Enemy.cpp
        include/Enemies/Goomba.h src/Enemies/Goomba.cpp
        include/Enemies/PPlant.h src/Enemies/PPlant.cpp)
add_library(Library ${SOURCE_FILES})

target_link_libraries(Library stb)
target_include_directories(Library PUBLIC include)

#Unit Tests section

# Check if generating Visual Studio 14 2015 project
if(MSVC)
    if(NOT BOOST_ROOT)
        set(BOOST_ROOT "C:/local/boost_1_60_0")
    endif()
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib32-msvc-14.0")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)


    if(NOT EXISTS ${Boost_LIBRARY_DIR})
        message(WARNING "Boost library requires manual installation in Windows")
        message("1) Browse: https://sourceforge.net/projects/boost/files/boost-binaries/1.60.0/")
        message("2) Download: boost_1_60_0-msvc-14.0-32.exe")
        message("3) Install into default directory: C:\\local")
        message("")
        message(FATAL_ERROR "Boost libraries not found at ${Boost_LIBRARY_DIR}")
    endif()

    find_package(Boost COMPONENTS unit_test_framework REQUIRED)

    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})

else()
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()
    #find_package(X11 REQUIRED)
    #target_link_libraries(Library X11)
#[[

set(SOURCE_TEST_PLAYER_FILES
        test/Player.cpp
        test/PlayerTest.cpp)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

add_executable (TestHuman ${SOURCE_TEST_PLAYER_FILES})]]

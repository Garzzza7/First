cmake_minimum_required(VERSION 3.4)

project(Library)

set(SOURCE_FILES
        include/Container.h
        src/Container.cpp
        include/ContainerStack.h
        src/ContainerStack.cpp
        include/Crane.h
        src/Crane.cpp
        include/Loadable.h
        src/Loadable.cpp
        include/Truck.h
        src/Truck.cpp
        include/Strategies/LoadStrategy.h
        src/Strategies/LoadStrategy.cpp
        include/Strategies/CheckFreePlaceStrategy.h
        src/Strategies/CheckFreePlaceStrategy.cpp
        include/Strategies/CheckPlaceAndWeightStrategy.h
        src/Strategies/CheckPlaceAndWeightStrategy.cpp)
add_library(Library ${SOURCE_FILES})
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

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

set(SOURCE_TEST_CONTAINER_FILES
        test/master.cpp
        test/ContainerTest.cpp)

add_executable (ContainerTest ${SOURCE_TEST_CONTAINER_FILES})

target_link_libraries (ContainerTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )


set(SOURCE_TEST_CONTAINER_STACK_FILES
        test/master.cpp
        test/ContainerStackTest.cpp
)

add_executable (ContainerStackTest ${SOURCE_TEST_CONTAINER_STACK_FILES})

target_link_libraries (ContainerStackTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

set(SOURCE_TEST_CRANE_FILES
        test/master.cpp
        test/CraneTest.cpp
        )

add_executable (CraneTest ${SOURCE_TEST_CRANE_FILES})

target_link_libraries (CraneTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

set(SOURCE_TEST_TRUCK_FILES
        test/master.cpp
        test/TruckTest.cpp)

add_executable (TruckTest ${SOURCE_TEST_TRUCK_FILES})

target_link_libraries (TruckTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

set(SOURCE_TEST_LOAD_STRATEGY_FILES
        test/master.cpp
        test/LoadStrategyTest.cpp)

add_executable (LoadStrategyTest ${SOURCE_TEST_LOAD_STRATEGY_FILES})

target_link_libraries (LoadStrategyTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

enable_testing()

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

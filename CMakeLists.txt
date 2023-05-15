cmake_minimum_required(VERSION 3.14)
project(OTOP)

# Compile Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "CXX Standard: ${CMAKE_CXX_STANDARD}")

# Build Type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(BUILD_UNIT_TESTS ON)

file(GLOB_RECURSE OTOP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)

add_library(otop_static STATIC ${OTOP_SRC})

target_include_directories(otop_static PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if (BUILD_UNIT_TESTS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif ()
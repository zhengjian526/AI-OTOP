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

find_package(OpenMP)

set(BUILD_UNIT_TESTS ON)

file(GLOB_RECURSE OTOP_SRC_NATIVE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/kernel/native/*.cc
)
file(GLOB_RECURSE OTOP_SRC_X86 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/kernel/x86/*.cc
)
add_library(otop_native_static STATIC ${OTOP_SRC_NATIVE})
target_link_libraries(otop_native_static OpenMP::OpenMP_CXX)
add_library(otop_x86_static STATIC ${OTOP_SRC_X86})
target_link_libraries(otop_x86_static OpenMP::OpenMP_CXX)


target_include_directories(otop_native_static PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(otop_x86_static PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if (BUILD_UNIT_TESTS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif ()
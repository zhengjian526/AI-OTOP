cmake_minimum_required(VERSION 3.14)
project(OTOP)

# Compile Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "CXX Standard: ${CMAKE_CXX_STANDARD}")

# Build Type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

find_package(OpenMP)

option(BUILD_UNIT_TESTS "build all tests" ON)
option(BUILD_TOOLS "build tools" ON)

include(cmake/depends.cmake)

# file(GLOB_RECURSE OTOP_SRC_NATIVE 
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/common/*.cc
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime/*.cc
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/kernel/native/*.cc
# )
file(GLOB_RECURSE OTOP_SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/kernel/*.cc
)
file(GLOB_RECURSE OTOP_SRC_X86 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/kernel/x86/*.cc
)

# add_library(otop_native_static STATIC ${OTOP_SRC_NATIVE})
# target_link_libraries(otop_native_static OpenMP::OpenMP_CXX)

add_library(otop_static STATIC ${OTOP_SRC})
set_source_files_properties(${OTOP_SRC_X86} PROPERTIES
    COMPILE_FLAGS "${SSE_ENABLED_FLAGS} ${FMA_ENABLED_FLAGS}")
target_link_libraries(otop_static OpenMP::OpenMP_CXX)


target_include_directories(otop_static PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
# target_include_directories(otop_x86_static PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if (BUILD_UNIT_TESTS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif ()
if (BUILD_TOOLS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tools)
endif ()
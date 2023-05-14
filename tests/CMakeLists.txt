file(GLOB_RECURSE TEST_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
    )

add_executable(unittest ${TEST_SRC})

target_link_libraries(unittest PRIVATE otop_static gtest)

target_include_directories(unittest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${googletest_SOURCE_DIR}/include)
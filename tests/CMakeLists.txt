file(GLOB_RECURSE TEST_SRC_RUNTIME
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime_test.cc
    )
# test
add_executable(test_runtime ${TEST_SRC_RUNTIME})


target_include_directories(test_runtime PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${googletest_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../thirdlib/yaml-cpp/include
    )
target_link_directories(test_runtime PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../thirdlib/yaml-cpp/lib
    )
target_link_libraries(test_runtime PRIVATE otop_static gtest yaml-cpp)
file(GLOB_RECURSE TEST_SRC_RUNTIME
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime_native_test.cc
    )
# native test
add_executable(test_native ${TEST_SRC_RUNTIME})

target_link_libraries(test_native PRIVATE otop_native_static gtest)

target_include_directories(test_native PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${googletest_SOURCE_DIR}/include)

# x86 accelerate test
add_executable(test_x86 ${TEST_SRC_RUNTIME})

target_link_libraries(test_x86 PRIVATE otop_x86_static gtest)

target_include_directories(test_x86 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${googletest_SOURCE_DIR}/include)

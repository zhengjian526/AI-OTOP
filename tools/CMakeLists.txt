file(GLOB_RECURSE GEN_RANDOM_INPUT
    ${CMAKE_CURRENT_SOURCE_DIR}/gen_random_input.cc
    )
# gen_random_input
add_executable(gen_random_input ${GEN_RANDOM_INPUT})

target_include_directories(gen_random_input PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../thirdlib/yaml-cpp/include
    )

target_link_directories(gen_random_input PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../thirdlib/yaml-cpp/lib
    )

target_link_libraries(gen_random_input PRIVATE otop_native_static yaml-cpp)




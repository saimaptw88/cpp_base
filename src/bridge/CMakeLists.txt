add_library(bridge SHARED bridge.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(bridge_test ${CMAKE_CURRENT_SOURCE_DIR}/bridge_test.cpp)
target_link_libraries(bridge_test bridge gtest gtest_main pthread)

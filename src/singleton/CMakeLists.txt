add_library(singleton SHARED singleton.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(singleton_test ${CMAKE_CURRENT_SOURCE_DIR}/singleton_test.cpp)
target_link_libraries(singleton_test singleton gtest gtest_main pthread)

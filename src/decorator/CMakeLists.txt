add_library(decorator SHARED decorator.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(decorator_test ${CMAKE_CURRENT_SOURCE_DIR}/decorator_test.cpp)
target_link_libraries(decorator_test decorator gtest gtest_main pthread)

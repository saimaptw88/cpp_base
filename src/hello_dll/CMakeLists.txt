add_library(hello SHARED hello.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(hello_test ${CMAKE_CURRENT_SOURCE_DIR}/hello_test.cpp)
target_link_libraries(hello_test hello gtest gtest_main pthread)

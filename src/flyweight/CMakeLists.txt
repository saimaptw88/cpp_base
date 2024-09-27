add_library(flyweight SHARED flyweight.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(flyweight_test ${CMAKE_CURRENT_SOURCE_DIR}/flyweight_test.cpp)
target_link_libraries(flyweight_test flyweight gtest gtest_main pthread)

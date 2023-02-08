add_library(my_math SHARED my_math.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(my_math_test ${CMAKE_CURRENT_SOURCE_DIR}/my_math_test.cpp)
target_link_libraries(my_math_test my_math gtest gtest_main pthread)

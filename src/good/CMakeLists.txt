add_library(good SHARED good.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(good_test ${CMAKE_CURRENT_SOURCE_DIR}/good_test.cpp)
target_link_libraries(good_test good gtest gtest_main pthread)

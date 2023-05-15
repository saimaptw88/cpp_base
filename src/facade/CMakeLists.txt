add_library(facade SHARED facade.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(facade_test ${CMAKE_CURRENT_SOURCE_DIR}/facade_test.cpp)
target_link_libraries(facade_test facade gtest gtest_main pthread)

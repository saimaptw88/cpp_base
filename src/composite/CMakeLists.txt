add_library(composite SHARED composite.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(composite_test ${CMAKE_CURRENT_SOURCE_DIR}/composite_test.cpp)
target_link_libraries(composite_test composite gtest gtest_main pthread)

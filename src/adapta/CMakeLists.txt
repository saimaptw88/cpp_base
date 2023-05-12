add_library(adapta SHARED adapta.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(adapta_test ${CMAKE_CURRENT_SOURCE_DIR}/adapta_test.cpp)
target_link_libraries(adapta_test adapta gtest gtest_main pthread)

add_library(factory_method SHARED factory_method.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(factory_method_test ${CMAKE_CURRENT_SOURCE_DIR}/factory_method_test.cpp)
target_link_libraries(factory_method_test factory_method gtest gtest_main pthread)

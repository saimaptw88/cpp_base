add_library(builder SHARED builder.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(builder_test ${CMAKE_CURRENT_SOURCE_DIR}/builder_test.cpp)
target_link_libraries(builder_test builder gtest gtest_main pthread)

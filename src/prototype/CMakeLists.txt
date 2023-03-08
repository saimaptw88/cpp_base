add_library(prototype SHARED prototype.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(prototype_test ${CMAKE_CURRENT_SOURCE_DIR}/prototype_test.cpp)
target_link_libraries(prototype_test prototype gtest gtest_main pthread)

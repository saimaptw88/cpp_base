add_library(abstract_factory SHARED abstract_factory.cpp)

# test
set(GTEST_ROOT /usr/local/)
include_directories(${GTEST_ROOT}/include/)
link_directories(${GTEST_ROOT}/lib/)

add_executable(abstract_factory_test ${CMAKE_CURRENT_SOURCE_DIR}/abstract_factory_test.cpp)
target_link_libraries(abstract_factory_test abstract_factory gtest gtest_main pthread)

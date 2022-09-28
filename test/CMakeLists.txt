cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

# set runtime directory
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# declare GTEST_ROOT
set(GTEST_ROOT /usr/local/)

# Include files directory
include_directories(${GTEST_ROOT}/include/)

# Library directory
link_directories(${GTEST_ROOT}/lib/)

# Generate executable file
add_executable(Test ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)

# Link libraries
target_link_libraries(Test my_math gtest gtest_main pthread)

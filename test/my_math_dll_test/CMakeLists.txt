# declare GTEST_ROOT
set(GTEST_ROOT /usr/local/)

# Include files directory
include_directories(${GTEST_ROOT}/include/)

# Library directory
link_directories(${GTEST_ROOT}/lib/)

# Generate executable file
add_executable(MyMathDllTest ${CMAKE_CURRENT_SOURCE_DIR}/my_math_test.cpp)

# Link libraries
target_link_libraries(MyMathDllTest my_math gtest gtest_main pthread)

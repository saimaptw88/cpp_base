cmake_minimum_required(VERSION 3.10)
project(MYTEST)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

enable_testing()
add_test(NAME MyTest COMMAND bash -c
"./src/hello_test;
./src/my_math_test;
")

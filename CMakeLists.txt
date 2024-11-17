cmake_minimum_required(VERSION 3.20)
project(MYTEST)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

enable_testing()
add_test(NAME MyTest COMMAND bash -c
"
")

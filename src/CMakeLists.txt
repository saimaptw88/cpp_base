cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

add_library(my_math STATIC my_math.cpp)
add_executable(my_app main.cpp)
target_link_libraries(my_app my_math)

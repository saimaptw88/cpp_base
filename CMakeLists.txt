cmake_minimum_required(VERSION 3.10)
project(MYTEST)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

enable_testing()
add_test(NAME MyTest COMMAND bash -c
"./src/adapta_test;
./src/singleton_test;
./src/decorator_test;
./src/composite_test;
./src/bridge_test;
./src/builder_test;
./src/prototype_test;
./src/factory_method_test;
./src/abstract_factory_test;
")

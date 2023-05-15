cmake_minimum_required(VERSION 3.10)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(exe)

add_subdirectory(abstract_factory)
add_subdirectory(factory_method)
add_subdirectory(prototype)
add_subdirectory(builder)
add_subdirectory(singleton)
add_subdirectory(adapta)

add_subdirectory(bridge)
add_subdirectory(composite)
add_subdirectory(decorator)

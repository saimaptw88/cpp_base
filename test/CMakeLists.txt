include_directories("${CMAKE_SOURCE_DIR}/my_math_dll_test" [ "${CMAKE_SOURCE_DIR}/hello_dll_test" ])

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(my_math_dll_test)
add_subdirectory(hello_dll_test)

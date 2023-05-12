add_executable(my_app main.cpp)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(
my_app
PUBLIC "-pthread"
singleton
builder
prototype
factory_method
abstract_factory
adapta
my_math
hello
)

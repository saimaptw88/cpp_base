# CMake generated Testfile for 
# Source directory: /cpp-dev
# Build directory: /cpp-dev/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyTest "/cpp-dev/build/test/Test")
subdirs("src")
subdirs("test")

#!/bin/sh

# check argument
if [ $# -ne 1 ]; then
  echo "Need only one argument for directory name."
  exit 1
fi

# handle command line argument
DELETE_DIR=$1
HOME_DIR=/cpp-dev

# delete directory
rm -rf $HOME_DIR/src/$DELETE_DIR

# delete line from $HOME_DIR/src/CMakeLists.txt
FILE="$HOME_DIR/src/CMakeLists.txt"
sed -i -e "s/^.*add_subdirectory($DELETE_DIR)//g" $FILE

# delete line from $HOME_DIR/src/exe/CMakeLists.txt
FILE=$HOME_DIR/src/exe/CMakeLists.txt
sed -i -e /$DELETE_DIR/d $FILE

# delete line from $HOME_DIR/CMakeLists.txt
FILE=$HOME_DIR/CMakeLists.txt
TEXT=$DELETE_DIR'_test;'

sed -i -e /$TEXT/d $FILE

#!/bin/sh

HOME_DIR=/cpp-dev
cd $HOME_DIR/build/src

for file in `find . -name '*_test'`;
do
$file
done

cd $HOME_DIR/build

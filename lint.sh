#!/bin/bash

export CMAN_DEBUG=1 
unset CMAN_RELEASE

clang-format src/main.cpp --verbose -i
clang-format src/tests/*.cpp --verbose -i
clang-format src/lib/utils.cpp --verbose -i
clang-format src/lib/**/*.cpp --verbose -i
clang-format src/lib/**/*.hpp --verbose -i

if [ ! -d "./build" ]; then
   mkdir build
   cd build
   cmake ..
   cd ..
fi

cd build
make

if [ -d "./data" ]; then
    rm -r data 
fi

cp -r ../src/data data

command ./cman-ut

exit 0

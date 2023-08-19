#!/bin/bash

clang-format src/main.cpp --verbose -i
clang-format src/tests/*.cpp --verbose -i
clang-format src/lib/**/*.cpp --verbose -i
clang-format src/lib/**/*.h --verbose -i

if [ ! -d "./build" ]; then
   mkdir build
   cd build
   cmake ..
   cd ..
fi

cd build
make
command ./cman-ut

exit 0

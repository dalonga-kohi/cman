#!/bin/bash

clang-format src/*.cpp --verbose -i
clang-format src/lib/**/*.cpp --verbose -i
clang-format src/lib/**/*.h --verbose -i

# rm -rf build
# mkdir build
cd build
# cmake ..
make
command ./cman-ut

exit 0

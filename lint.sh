#!/bin/bash

export CMAN_DEBUG=1 
unset CMAN_RELEASE

clang-format src/main.cpp --verbose -i
clang-format src/tests/*.cpp --verbose -i
clang-format src/lib/utils.hpp --verbose -i
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

if [ -d "/etc/cman" ]; then
    sudo rm -rf /etc/cman 
fi

sudo cp -r ../src/data /etc/cman

command ./cman-ut

exit 0

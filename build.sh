#!/bin/bash

unset CMAN_DEBUG
export CMAN_RELEASE = 1

if [ ! -d "./tmp" ]; then
    mkdir tmp
fi

cd tmp
cmake ..
make

if [ -d "/usr/bin/cman" ]; then
    rm -f /usr/bin/cman
fi

sudo mv cman /usr/bin/cman

cd ..
rm -rf tmp
echo "Succesfully compiled"

exit 0

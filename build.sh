#!/bin/bash

unset CMAN_DEBUG
export CMAN_RELEASE=1

if [ ! -d "./tmp" ]; then
    mkdir tmp
fi

cd tmp
cmake ..
make

if [ -e "/usr/share/cman" ]; then
    sudo rm -rf /usr/share/cman
fi

if [ -e "/usr/bin/cman" ]; then
   sudo rm -f /usr/bin/cman 
fi

sudo mkdir /usr/share/cman
sudo cp -r ../src/data /usr/share/cman/data
sudo mv ./cman /usr/share/cman/cman 
sudo ln /usr/share/cman/cman /usr/bin/cman

cd ..
rm -rf tmp
echo "Succesfully compiled"

exit 0

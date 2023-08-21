#!/bin/bash

unset CMAN_DEBUG
export CMAN_RELEASE=1

if [ ! -d "./tmp" ]; then
    mkdir tmp
fi

cd tmp
cmake ..
make

if [ -e "/usr/bin/cman" ]; then
    sudo rm -f /usr/bin/cman
fi

if [ -d "/etc/cman" ]; then
   sudo rm -rf /etc/cman 
fi

sudo cp -r ../src/data /etc/cman
sudo mv ./cman /usr/bin/cman

cd ..
rm -rf tmp
echo "Succesfully compiled"

exit 0

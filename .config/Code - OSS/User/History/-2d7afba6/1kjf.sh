#!/bin/bash

[ -d ~/Development/space/build ] || mkdir build
cd ~/Development/space/build
cmake ..
make clean 
make
./space

#!/bin/bash

[ -d ~/Development/space/build ] || mkdir build
cd ~/Development/space/build
cmake ~/Development/space/
make clean 
make
./space

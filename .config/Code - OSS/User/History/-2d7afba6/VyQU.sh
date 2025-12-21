#!/bin/bash

[ -d build ] || mkdir build
cd build
cmake ..
make clean 
make
./space

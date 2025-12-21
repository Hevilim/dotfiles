#!/bin/bash

[ -d build ] || mkdir build
cd build
cmake ..
make clean 
make
mv space /usr/local/bin

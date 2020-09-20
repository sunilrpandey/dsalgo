#!/bin/bash
cd build
cmake ..
make
cd ../bin
./$1
cd ../
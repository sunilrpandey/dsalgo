#!/bin/bash
cd build
cmake ..
make
./$1
cd ../
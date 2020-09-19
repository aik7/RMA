#!/bin/bash

#  Build PEBBL

mkdir external/pebbl/build
cd    external/pebbl/build
cmake -Denable_mpi=ON -Denable_examples=OFF ..
make


# Build RMA

cd ../../../  # go back to the RMA root directory

mkdir build
cd build
cmake ..
make

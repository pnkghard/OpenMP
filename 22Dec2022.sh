#!/bin/bash
gcc -fopenmp 06Dec2022_Lab2_P2.c -o 06Dec2022_Lab2_P2
export OMP_NUM_THREADS=2
echo "For Two Thread"
time ./06Dec2022_Lab2_P2
echo "For Five Thread"
export OMP_NUM_THREADS=5
time ./06Dec2022_Lab2_P2

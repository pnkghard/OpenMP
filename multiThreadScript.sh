#!/bin/bash


gcc -fopenmp 28Dec2022_Assignment.c -o 28Dec2022_Assignment
clear
export OMP_NUM_THREADS=1
./28Dec2022_Assignment

export OMP_NUM_THREADS=5
./28Dec2022_Assignment

export OMP_NUM_THREADS=7
./28Dec2022_Assignment

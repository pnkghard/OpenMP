#include<stdio.h>
#include<mpi.h>
#define N 10

int main (int argc, char* argv[]){

    MPI_Init(&argc, &argv); // initializtion of mpi
    int i;
    int arr[N];
    for(i=0; i<N; i++){
        arr[i] = i + 1;
    }
    for(i=0; i<N/2; i++){
        printf("Array[%d]=%d\n", i, arr[i]+arr[N-1-i]);
    }

    MPI_Finalize(); //finalised and close mpi

    return 0;
}
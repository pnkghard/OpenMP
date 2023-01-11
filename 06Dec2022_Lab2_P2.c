/* 
Lab-1:
    Initialise 2 arrays A and B of integers with random
    numbers. During development use 10 as size, for final
    setup use 1000. Parameterise the size. 

    Third array C is A + B using single for loop. Write,
    compile, run and test the program.

    Now, use O0 and o2 optimisation and compare its time
    taken with and without vectorization. Look at compile logs
    to make sure its vectorized.

Lab-2/Program-2:
    1. Add (parametrise number of threads) 2 threads, and
    share work-load explictly (#pragma omp parallel for)
    measure the time taken.
    2. Modify the program for 5 threads. Measure time for
    1000 / 5000/ 10000 array size.
*/

#include<stdio.h>
#include<omp.h>


int main(){
    int size;
    printf("Enter size of array : ");
    scanf("%d", &size);
    int A[size], B[size], C[size];

    // initializing A = i + 1 and B = i * 2
    for(int i=0; i<size; i++){
        A[i] = rand()%3;
        B[i] = rand()%3;
        C[i] = 0;
    }
    #pragma omp parallel for shared(A, B, C)
        for(int i=0; i<size; i++){
            C[i] = A[i] + B[i];
        }
    for(int i=0; i<size; i++){
        printf("C[%d]=%d\n", i, C[i]);
    }
    return 0;
}
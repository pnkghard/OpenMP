/*
	Program-2
		1. Add (parametrise number of threads) 2 threads, and
        share work-load implicitly (#pragma omp parallel for)
        measure the time taken. Thread the outer loop, vectorize
        the inner loop.
        2. Modify the program for 5 threads. Measure time for
        1000 / 5000/ 10000 array size.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]){
    printf("Arguments: m=%s, n=%s, p=%s and Number of Threads=%s\n", argv[1], argv[2], argv[3], argv[4]);

    // check if input is valid or not
    if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] == NULL){
        printf("Invalid Arguments. Please provide A valid arguments\n");
        return 0;
    }

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    int p = atoi(argv[3]);
    int t = atoi(argv[4]);

    int A[m][n], B[n][p], C[m][p];

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            A[i][j] = rand()%10;
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<p; j++){
            B[i][j] = rand()%10;
        }
    }

    // Calculate excecution time for multiplication only
    clock_t begin = clock();

    omp_set_num_threads(t);
    #pragma omp parallel for shared(A, B, C)
    for (int i=0; i<m; i++) {
        for (int j=0; j<p; j++){
            for (int k=0; k<n; k++){
                C[i][j] += A[i][k] * B[k][j];                
            }
        }
    }
    clock_t end = clock();

    for (int i=0; i<m; i++){
        for (int j=0; j<p; j++){
            printf("%ld\t", C[i][j]);
        }
        printf("\n");
    }

    // calculate the time and print it
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken: %f secs\n", time_spent);
    return 0;
}
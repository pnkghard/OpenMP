/*
	Program-1
		1. Add (parametrise number of threads) 2 threads, and
		share work-load explictely (#pragma omp parallel)
		measure the time taken. Thread the outer loop, vectorize
		the inner loop.
		2. Modify the program for 5 threads. Measure time for
		1000 / 5000/ 10000 array size.
*/
#include<stdio.h>
#include<omp.h>
#include<math.h>

#define M 3
#define N 4
#define P 2

int main(){
    int i, j, k;
    int mat1[M][N];
    int mat2[N][P];
    int result[M][P];
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            mat1[i][j]=rand()%100;
        }
    }
    for(i=0; i<N; i++){
        for(j=0; j<P; j++){
            mat2[i][j]=rand()%100;
        }
    }
    for(i=0; i<M; i++){
        for(j=0; j<P; j++){
            result[i][j] = 0;
        }
    }
    omp_set_num_threads(3);
    #pragma omp parallel
		for(i=0; i<N; ++i){
			for(j=0; j<N; ++j){
				for(k=0; k<N; ++k){
					//#pragma omp single
						result[i][j] += mat1[i][k] * mat2[k][j];
				}
			}
		}

    printf("\n");

//    for(i=0; i<M; i++){
//        for(j=0; j<P; j++){
//            printf("%d\t", result[i][j]);
//        }
//        printf("\n");
//    }
}

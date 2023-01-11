#include<stdio.h>
#include<omp.h>
#define N 100


int main() {
    double start, end;
    start = omp_get_wtime();
    int array[N], i;
	for(i=0; i<N; i++) {
		array[i] = i + 1;
	}
    #pragma omp parallel for firstprivate(array)     
        #pragma for single   
    	for(i=0; i<N/2; i++){
    		printf("ThreadID=%d\t%d\n", omp_get_thread_num(), (array[i]+array[N-i-1]));
    	}
    end = omp_get_wtime();
    printf("Execution Time = %lf in seconds\n", end - start);
    return 0;
}
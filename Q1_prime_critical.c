#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<omp.h>

#define N 1000000

int isprime(int x){
    int y;
    for(y=2; y<=x/2; y++){
        if((x%y)==0){
            return 0;
        }
    }
    return 1;
}

int main() {
    int i, j;
    int count, flag;

    double exe_time;
    struct timeval stop_time, start_time;

    count = 1;

    gettimeofday(&start_time, NULL);

    #pragma omp parallel for private(count)
        for(i=3; i<N; i++){
            flag += isprime(i);
        }
        #pragma omp critical
        {
            count += flag;
        }
    
    gettimeofday(&stop_time, NULL);
    exe_time=(stop_time.tv_sec+(stop_time.tv_usec/1000000.0))-(start_time.tv_sec+(start_time.tv_usec/1000000.0));
    printf("Number of prime numbers = %d\nExecution time is = %lf seconds\n", exe_time);
    return 0;
}
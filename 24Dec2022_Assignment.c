#include<stdio.h>

int main(){
    omp_set_num_threads(5);
    int num = 0;
    #pragma omp parallel
    {
        #pragma omp task 
        num++;
        printf("Hello Task @ ThreadID=%d\n", omp_get_thread_num());
        #pragma omp task 
        num++;
        printf("Hello Task @ ThreadID=%d\n", omp_get_thread_num());
        #pragma omp task 
        num++;
        printf("Hello Task @ ThreadID=%d\n", omp_get_thread_num());
        #pragma omp task 
        num++;
        printf("Hello Task @ ThreadID=%d\n", omp_get_thread_num());
        #pragma omp task 
        num++;
        printf("Hello Task @ ThreadID=%d\n", omp_get_thread_num());
        #pragma omp task 
        num++;
        printf("Hello Task @ ThreadID=%d\n", omp_get_thread_num());
        #pragma omp task 
        num++;
        printf("Hello Task @ ThreadID=%d\n", omp_get_thread_num());
        #pragma omp task 
        num++;
        printf("Hello Task @ ThreadID=%d\n", omp_get_thread_num());
        #pragma omp task 
        num++;
        printf("Hello Task @ ThreadID=%d\n", omp_get_thread_num());
        #pragma omp task 
        num++;
        printf("Hello Task @ ThreadID=%d\n", omp_get_thread_num());
    }
    printf("Number of performance = %d\n", num);
    return 0;
}
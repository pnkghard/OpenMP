#include<stdio.h>
#include<omp.h>
int a =1234;
#pragma omp threadprivate(a)
int main() {
    //omp_set_num_threads(4);
    #pragma omp parallel copyin(a)
    {
        #pragma omp master
        {
            printf("First parallel region Master thread changes the value of a to 67890.\n");
            a = 67890;
        }
        #pragma omp barrier
        printf("First parallel region -> Thread %d: a = %d.\n", omp_get_thread_num(), a);
    }
    #pragma omp parallel copyin(a)
    {
        #pragma omp single
        printf("Second parallel region -> Thread %d: a = %d.\n", omp_get_thread_num(), a);
    }
    return 0;
}
#include<stdio.h>
#include<omp.h>

int main(){
    int a = 100, b = 200;
    omp_set_num_threads(4);
    #pragma omp parallel sections
    {
        #pragma omp section 
        {
            printf("ThreadID=%d | Addition=%d\n", omp_get_thread_num(), a+b);
        }
        #pragma omp section 
        {
            printf("ThreadID=%d | Subtraction=%d\n", omp_get_thread_num(), b-a);
        }
        #pragma omp section 
        {
            printf("ThreadID=%d | Multiplication=%d\n", omp_get_thread_num(), a*b);
        }
        #pragma omp section
        {
            printf("ThreadID=%d | Division=%d\n", omp_get_thread_num(), b/a);
        }
    }
    return 0;
}

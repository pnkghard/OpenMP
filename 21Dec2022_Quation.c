#include<stdio.h>
#include<omp.h>

// program for update memory location one by one

int main() {
    int total = 0;
    omp_set_num_threads(4);
    #pragma omp parallel reduction(+:total)
    {
        for(int i=0; i<10; i++){            
            #pragma omp single
            total++;            
        }    
        printf("Total = %d & ThreadID=%d.\n", total, omp_get_thread_num());    
    }
    printf("Total = %d.\n", total);
    return 0;
}
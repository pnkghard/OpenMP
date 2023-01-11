#include<stdio.h>
#include<omp.h>

int main() {
    //omp_set_num_threads(4);
    #pragma omp parallel for ordered 
    for(int i=0; i<10; i++){
        #pragma omp ordered
        printf("ThreadID = %d -> Iteration=%d.\n", omp_get_thread_num(), i);
    }
    return 0;
}
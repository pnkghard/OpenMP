#include<stdio.h>
#include<omp.h>

int main(){
    omp_set_num_threads(4);
    int array[5] = {1, 2, 3, 4, 5};
    int i;
    #pragma omp parallel for shared(array)
        for(i=0; i<5; i++){
            #pragma omp critical
            {
                array[i]++;
                printf("Count=%d : ThreadID=%d\n", array[i], omp_get_thread_num());
            }
        }
}
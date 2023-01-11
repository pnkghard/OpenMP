#include<stdio.h>
#include<omp.h>

void f(int arr1[], int arr2[], int size, int a, int result[]){
    for(int i=0; i<size; i++){
        omp_set_dynamic(0);
        #pragma omp single
        {
            result[i] = a + arr1[i] + arr2[i];
            printf("ThreadID=%d->result[%d]=%d\n", omp_get_thread_num(), i, result[i]);
        }
    }
}
int main(){
    omp_set_num_threads(5);
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5] = {6, 7, 8, 9, 10};
    int result[5];
    int i;
    int a = 1;
    #pragma omp parallel
        f(array1, array2, 5, a, result);
    // for(int i=0; i<5; i++){
    //     printf("result[%d]=%d\n", i, result[i]);
    // }
}
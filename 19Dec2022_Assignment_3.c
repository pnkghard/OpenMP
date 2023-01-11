#include<stdio.h>
#include<omp.h>


int addition(int num) {
    if(num==0){
        return num;
    }
    return num + addition(num-1);
}

int multiplication(int num) {
    if(num==1){
        return num;
    }
    return num * multiplication(num-1);
}

int main(){
    omp_set_num_threads(2);
    #pragma omp parallel sections
    {
        #pragma omp section 
        {
            printf("ThreadID=%d | Addition=%d\n", omp_get_thread_num(), addition(10));
        }
        #pragma omp section 
        {
            printf("ThreadID=%d | Multiplication=%d\n", omp_get_thread_num(), multiplication(10));
        }
        #pragma omp section 
        {
            printf("ThreadID=%d | Multiplication=%d\n", omp_get_thread_num(), multiplication(10));
        }
    }
    return 0;
}

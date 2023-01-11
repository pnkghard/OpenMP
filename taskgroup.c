#include<stdio.h>
#include<omp.h>



void name(){
    printf("I am from name ThreadID=%d\n", omp_get_thread_num());
}

void sname(){
    printf("I am from sname ThreadID=%d\n", omp_get_thread_num());
}

void oname(){
    printf("I am from noname ThreadID=%d\n", omp_get_thread_num());
}




int main(){
    omp_set_num_threads(5);

    #pragma omp parallel if(omp_in_parallel)
    { 
        #pragma omp single
        {
            #pragma omp taskgroup
            {
                #pragma omp task priority(1)
                {
                    name();
                }
                #pragma omp task priority(2)
                {
                    sname();
                }
                #pragma omp task priority(3)
                {
                    oname();
                }
            }
        }
    }
    return 0;
}
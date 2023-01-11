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

int main() {
    omp_set_dynamic(0);
    omp_set_num_threads(10);
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            {
                name();
                #pragma omp task
                {
                    sname();
                }
                #pragma omp task untied
                {
                    oname();
                }
                #pragma omp task untied
                {
                    oname();
                }
                #pragma omp task
                {
                    sname();
                }
                name();
                sname();
                #pragma omp task untied
                {
                    name();
                }
                #pragma omp task untied
                {
                    sname();
                }
            }
        }
    }
}
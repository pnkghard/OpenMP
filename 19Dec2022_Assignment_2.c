#include<stdio.h>
#include<omp.h>


void firstname() {
    printf("ThreadID=%d | FirstName=%s\n", omp_get_thread_num(), "Pankaj");
}

void secondname() {
    printf("ThreadID=%d | SecondName=%s\n", omp_get_thread_num(), "Prasad");
}

void thirdname() {
    printf("ThreadID=%d | ThirdName=%s\n", omp_get_thread_num(), "Avishkar");
}

void fourthname() {
    printf("ThreadID=%d | FourthName=%s\n", omp_get_thread_num(), "Krushna");
}

int main(){
    omp_set_num_threads(4);
    #pragma omp parallel sections
    {
        #pragma omp section 
        {
            firstname();
        }
        #pragma omp section 
        {
            secondname();
        }
        #pragma omp section 
        {
            thirdname();
        }
        #pragma omp section
        {
            fourthname();
        }
    }
    return 0;
}

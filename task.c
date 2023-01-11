#include<stdio.h>

// int main(){
//     omp_set_num_threads(5);
//     #pragma omp parallel
//     {
//         #pragma omp task 
//         printf("Hello world! | ThreadID=%d\n", omp_get_thread_num());
//     }
//     return 0;
// }


// int main(){
//     omp_set_num_threads(5);
//     #pragma omp parallel
//     {
//         int number = 1;
//         #pragma omp task
//         {
//             printf("%d. I think number is %d\n", omp_get_thread_num(), number);
//             number++;
//         }
//     }
//     return 0;
// }


// int main(){
//     omp_set_num_threads(5);
//     #pragma omp parallel
//     {
//         int number = 1;
//         #pragma omp task shared(number)
//         {
//             printf("%d. I think number is %d\n", omp_get_thread_num(), number);
//             number++;
//             printf("%d. I think number is %d\n", omp_get_thread_num(), number);
//         }
//     }
//     return 0;
// }

int main(){
    omp_set_num_threads(15);
    int number = 0;
    #pragma omp parallel
    {
        #pragma omp task shared(number)
        {
            number++;
            printf("%d. I think number is %d\n", omp_get_thread_num(), number);
        }
    }
    return 0;
}
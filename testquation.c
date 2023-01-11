#include<stdio.h>
#include<omp.h>

// int main(){
//     omp_set_num_threads(4);
//     int i;
//     double sum;
//     #pragma omp parallel private(sum)
//     {
//         sum = 0.0;
//         for(i=1; i<=4; i++)
//             sum += i;
//         printf("Sum = %0.1f\n", sum);
//     }
//     return 0;
// }

// int main(){
//     int i;
//     int square[11];
//     omp_set_dynamic(0);
//     #pragma omp parallel if(omp_in_parallel) num_threads(4)
//     {
//         for(i=0; i<=10; i++)
//             square[i] = i * i;
//         #pragma omp single
//         for(i=0; i<=10; i++)
//             printf("ThreadID %d, square[%d] = %d\n", omp_get_thread_num(), i, square[i]); 
//     }
//     return 0;
// }

// int main(){
//     omp_set_num_threads(4);
//     int i;
//     int square[101];
//     omp_set_dynamic(0);
//     #pragma omp parallel for
    
//         for(i=0; i<101; i++)
//             square[i] = i * i;
//         for(i=0; i<101; i++)
//             printf("square[%d] = %d\n", i, square[i]); 
    
//     return 0;
// }

// int main(){
//     int i, sum;
//     omp_set_num_threads(4);
//     omp_set_dynamic(0);
//     #pragma omp parallel for lastprivate(sum)    
//         sum = 0;
//         for(i=0; i<=10; i++)
//             sum += i;
//             printf("ThreadID = %d : I = %d : Sum = %d\n", omp_get_thread_num(), i, sum);
//         #pragma omp single
//         printf("Sum = %d\n", sum);     
//     return 0;
// }

int main(){
    int i;
    double sum = 0.0;
    #pragma omp parallel for reduction(+:sum) 
        for(i=1; i<=4; i++)
            sum += i;
            //printf("ThreadID = %d : I = %d : Sum = %d\n", omp_get_thread_num(), i, sum);
        //#pragma omp single
        printf("Sum = %0.2f\n", sum);     
    return 0;
}
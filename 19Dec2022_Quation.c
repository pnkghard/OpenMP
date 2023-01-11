#include<stdio.h>
#include<math.h>
#include<omp.h>



// int main() {
//     double sum = 0.0;
//     omp_set_num_threads(4);
//     #pragma omp parallel for reduction(+:sum)
//     for(int i=1; i<=100; i++){
//         sum += i;
//     }
//     printf("Average = %0.2f\n", sum/100);
// }


// int main() {
//     double sum = 0.0;
//     omp_set_num_threads(4);
//     int y;
//     printf("Enter year : ");
//     scanf("%d", &y); 
//     if(y%4==0){   
//         #pragma omp parallel for reduction(+:sum) 
//         for(int i=1; i<=100; i++){
//             sum += i;
//         }
//         printf("Average = %0.2f\n", sum/100);
//     } else {
//         printf("%d is not leap year.\n", y);
//     }
// }

// int main() {
//     int sum = 0;
//     omp_set_num_threads(4);
//     #pragma omp parallel for reduction(+:sum) 
//     for(int i=1; i<=1000; i++){
//         if((i%2)!=0){
//             sum += i;
//         }
//     }
//     printf("Sum of odd number = %d\n", sum);
// }





int simpleinterst(int p, double r, double t){
    double interest = 0.0;
    interest = (p*r*t)/100;
    //printf("ThreadID=%d\n", omp_get_thread_num());
    return interest;
}

int compundinterst(double p, double r, double t){
    double interest = 0.0;
    interest = p*(1+(r/100))^t;
    //printf("ThreadID=%d\n", omp_get_thread_num());
    return interest;
}


int main() {
    // int sum = 0;
    // omp_set_num_threads(4);
    // #pragma omp parallel for reduction(+:sum) 
    // for(int i=1; i<=1000; i++){
    //     if((i%2)!=0){
    //         sum += i;
    //     }
    // }012
    // printf("Sum of odd number = %d\n", sum);
    printf("%d\n", compundinterst(1000, 10, 2));
}

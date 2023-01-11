#include<stdio.h>
#include<omp.h>
#define NUM 100000000

int isprime(int x){
    int y;
    for(y=2; y<=x/2; y++){
        if((x%y)==0){
            return 0;
        }
    }
    return 1;
}

int main() {
    int sum = 0;
    int i;
    #pragma omp parallel for reduction(+:sum)
    for(i=2; i<=NUM; i++){
        sum += isprime(i);
    }
    printf("Total prime numbers : %d\n", sum);
    return 0;
}
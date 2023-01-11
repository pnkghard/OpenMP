#include<stdio.h>
#include<omp.h>

// matrix multiplication using affinity 1. compact sheduling, 2. Round-Robin Sheduling, 3. Stupid Scheduling


int main(){
    printf("Enter the size of Matrix : ");
    int size, i, j, k;
    scanf("%d", &size);    
    int mat1[size][size];
    int mat2[size][size];
    int result[size][size];
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            mat1[i][j] = 1;
        }
    }
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            mat2[i][j] = 1;
        }
    }
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            result[i][j] = 0;
        }
    }
    omp_set_num_threads(12);
    #pragma omp shedule(static)
        for(i=0; i<size; ++i){
            for(j=0; j<size; ++j){
                for(k=0; k<size; ++k){
                        result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    #pragma omp shedule(compact,5)
        for(i=0; i<size; ++i){
            for(j=0; j<size; ++j){
                for(k=0; k<size; ++k){
                        result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    #pragma omp shedule(stupid,7)
        for(i=0; i<size; ++i){
            for(j=0; j<size; ++j){
                for(k=0; k<size; ++k){
                        result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

    printf("\n");
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}
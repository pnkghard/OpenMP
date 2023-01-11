#include<stdio.h>
#include<omp.h>
#include<math.h>

int main(){
    printf("Enter the size of Matrix : ");
    int size, i, j, k;
    scanf("%d", &size);    
    int mat1[size][size];
    int mat2[size][size];
    int result[size][size];
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            scanf("%d", &mat2[i][j]);
        }
    }
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            result[i][j] = 0;
        }
    }

    #pragma omp parallel shared(mat1, mat2, result) private(i, j, k)
            for(i=0; i<size; ++i){
                for(j=0; j<size; ++j){
                    for(k=0; k<size; ++k){
                        #pragma omp single
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
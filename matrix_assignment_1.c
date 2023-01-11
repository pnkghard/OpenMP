#include<stdio.h>
# include<time.h>


void print(int *p) {
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", *p++);
        }
        printf("\n");
    }
}

int main(){
    clock_t start, end;
    double execution_time;
    start = clock();
    int a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int b[3][3] = {{11,12,13}, {14,15,16}, {17,18,19}};
    int c[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                c[i][j] += a[i][k] * b[k][j]; 
            }
        }
    }
    print(&c);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Time : %lf seconds\n", execution_time);
    return 0;
}
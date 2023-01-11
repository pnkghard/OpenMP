#include <mpi.h>
#include <stdio.h>
#define N 10

int main(int argc, char** argv) {
        int rank, i;
        int buf, size;
        MPI_Status status;
        MPI_Init(&argc, &argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        int array[N];
        int worker;
        int res = 0, sum = 0, r;
        for(i=0; i<N; i++) {
	        array[i] = i + 1;
	}
        if(rank==0){
                for(i=0; i<3; i++){
                    int a = array[i] + array[N-1-i];
                    sum += a;
                    printf("Array[%d]+Array[%d]=%d\n", i, (N-1-i), a);
                }
                res = sum;
                MPI_Send(&array[3], 4, MPI_INT, 1, 0, MPI_COMM_WORLD);
                // MPI_Recv(&sum, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                // res += sum;
                // printf("Sum is %d\n", res);
        } else {
                MPI_Recv(&worker, 4, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                for(i=0; i<=4+worker; i++){
                    int a =  array[worker];
                    printf("array[%d]+array[%d]=%d\n", i, (4+worker-1), a);
                }
                printf("Process %d received number %d from process 0\n\n\n", rank, worker);
        }             
        MPI_Finalize();
        return 0;
}
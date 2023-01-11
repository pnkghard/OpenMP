#include <mpi.h>
#include <stdio.h>
#include<omp.h>
#define N 10000


void addition(int a, int n, int rank){
        double start, end;
        start = omp_get_wtime();
        omp_set_num_threads(10);
        #pragma omp parallel shared(a)
        {
                for(int i=0; i<n; i++){
                        #pragma omp single
                        printf("%d in Array[%d] in ThreadID %d in ProcessID %d\n", (a[i]+a[N-i-1]), i, omp_get_thread_num(), rank);
                }
        }
        end = omp_get_wtime();
        double execution_time = (end - start);
        printf("Parallel Process End at %lf seconds\n", execution_time);
}

int main(int argc, char** argv) {
        int rank, i;
        int buf, size;
        MPI_Status status;
        MPI_Init(&argc, &argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        int array[N];
        int job = 0;
        int worker;
        for(i=0; i<N; i++) {
	        array[i] = i + 1;
	}
        if(rank==0){
                for(i=1; i<size; i++){
                        MPI_Send(&array[job*(N/size)], N/size, MPI_INT, i, 0, MPI_COMM_WORLD);
                        job++;
                }
        } else {
                MPI_Recv(&worker, N/size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                addition(worker, N/size, rank);
                printf("Process %d received number %d from process 0\n\n\n", rank, worker);
        }
        MPI_Finalize();
        return 0;
}
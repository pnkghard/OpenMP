#include<stdio.h>
#include<omp.h>


double pi_function(long snum){
    double step = 1.0/(double)snum;
    double x, sum = 0.0;
    omp_set_num_threads(5);
    #pragma omp parallel for reduction(+:sum)
        for(int i=0; i<snum; i++) {
            x = (i + 0.5) * step;
            sum += 4.0/(1.0 + x*x);
        }
    return step * sum;
}

int main() {
    printf("%lf\n", pi_function(5));
}

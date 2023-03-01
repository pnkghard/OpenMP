#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<omp.h>

#define NR 100 
#define NC 200
#define itmax 300

//print layout
void printlayout(){
    int offset,b;
    for(int i=0;i<=NR+1;i++){
        offset=i*(NC+2);
        for(int j=0;j<=NC+1;j++){
            b=offset+j;    
            printf(" %d\t",b);
        }
        printf("\n");    
    }
}

//initialization upper boundry
void upperboundry(double *u1, double dx, double x){
    int j, b;
    for(j=0;j<=NC+1;j++){
        b=(NR+1)*(NC+2)+j;
        x=(double)j*dx;
        u1[b]=sin(2*3.14*x);
        printf("%d\t%f\t%f \n",b,x,u1[b]);
    }
}

//initializing u2 with sin(2*3.14*x)
void initu2_2(double *u2, double dx, double x){
    int j, b;
    for(j=0;j<=NC+1;j++){
        b=(NR+1)*(NC+2)+j;
        x=(double)j*dx;
        u2[b]=sin(2*3.14*x);
    }
}

//initializing right boundry
void rightboundry(double *u1, double dy, double y){
    int i, b;
    for(i=0;i<=NR+1;i++){
        b=i*(NC+2)+(NC+1);
        y=(double)i*dy;
        u1[b]=-sin(3.14*y);
        printf("%d\t%f\t%f \n",b,y,u1[b]);
    }
}

//initializing u2 with sin(2*3.14*x)
void initu2_1(double *u2, double dy, double y){
    int i, b;
    for(i=0;i<=NR+1;i++){
        b=i*(NC+2)+(NC+1);
        y=(double)i*dy;
        u2[b]=-sin(3.14*y);
    }
}

//jacobi interation
void jacobitr(double *u1, double *u2){

    int iter, i, j, b, bp=0;
    double *tmp;

    omp_set_dynamic(0);
    int thread = omp_get_num_procs();
    printf("Maximum threads=%d\n", thread);
    #pragma omp parallel shared(u1, u2)
    {   
        int tid = omp_get_thread_num();
        int maxThread = omp_get_num_threads();
        int s = tid * (itmax/maxThread);
        int e = s + (itmax/maxThread);
        #pragma omp for ordered
            for(iter=s; iter<e; iter++){ //Jacobi kernel
                for(i=1;i<=NR;i++){
                    b=i*(NC+2)+1;
                    for(j=1;j<=NC;j++){
                        u2[b]=0.25*(u1[b-1]+u1[b+1]+u1[b-(NC+2)]+u1[b+(NC+2)]);
                        printf("%d\t%d\t%d\t%d\n", i,j,b,bp);
                        b++;
                    }          
                }
                // Interchange READ & WRITE => u1<=>u2
                tmp=u1;
                u1=u2;
                u2=tmp;                    
            }
    }
}

//write in file
void writefile(double *u2, double dx, double dy, double x, double y){
    
    int i, j, b;
    FILE *file;

    file=fopen("stencil_out.dat", "w");

	for(i=0;i<=NR+1;i++){
	    b=i*(NC+2);
        y=(double)i*dy; 
	    for(j=0;j<=NC+1;j++){
            x=(double)j*dx;
	        fprintf(file,"%f\t%f\t%f\n",x,y,u2[b]);
            b++; 
	    }
	    fprintf(file,"\n");    
	}
}


int main(int argc, char** argv){

    double dx,dy, x, y;
    dx=1.0/(double)(NC+1);     
    dy=1.0/(double)(NR+1);

    double *u1;
    double *u2;

    u1=(double *)malloc((NR+2)*(NC+2)*sizeof(double));
    u2=(double *)malloc((NR+2)*(NC+2)*sizeof(double));

    printlayout();
    printf("\n\n\nUpper Boundry :\n");
    upperboundry(&u1[0], dx, x);
    initu2_2(&u2[0], dx, x);
    printf("\n\n\nRight Boundry :\n");
    rightboundry(&u1[0], dy, y);
    initu2_1(&u2[0], dy, y);
    printf("\n\n\nfinal out: \n");

    jacobitr(&u1[0], &u2[0]);

    writefile(&u2[0], dx, dy, x, y);
    free(u1);
    free(u2);
    return 0;
}
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

const char* dgemv_desc = "OpenMP dgemv.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

void my_dgemv(int n, double* A, double* x, double* y) {

   // #pragma omp parallel
   // {
   //    int nthreads = omp_get_num_threads();
   //    int thread_id = omp_get_thread_num();
   //    printf("my_dgemv(): Hello world: thread %d of %d checking in. \n", thread_id, nthreads);
   //    printf("my_dgemv(): For actual timing runs, please comment out these printf() and omp_get_*() statements. \n");
   // }
   // double sum=0.0;
   // #pragma omp parallel for reduction(+:sum)
   // for(int i=0;i<n;i++){
   //    sum+=i;
   // }
   // printf("sum: %f\n", sum);
   #pragma omp parallel for collapse(2) schedule(static)
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         y[i]+= A[i*n+j]*x[j];
      }
   }

   // insert your dgemv code here. you may need to create additional parallel regions,
   // and you will want to comment out the above parallel code block that prints out
   // nthreads and thread_id so as to not taint your timings
/*

#pragma omp parallel for collapse(2) on M2

Description:    OpenMP dgemv.

Working on problem size N=1024 
Elapsed time: 0.001056 seconds 
Working on problem size N=1024 
Elapsed time: 0.001034 seconds 
Working on problem size N=2048 
Elapsed time: 0.002348 seconds 
Working on problem size N=4096 
Elapsed time: 0.010325 seconds 
Working on problem size N=8192 
Elapsed time: 0.036994 seconds 
Working on problem size N=16384 
Elapsed time: 0.240934 seconds

*/

/*
#pragma omp parallel for collapse(2) schedule(static) on M2

Description:    OpenMP dgemv.

Working on problem size N=1024 
Elapsed time: 0.001117 seconds 
Working on problem size N=1024 
Elapsed time: 0.000731 seconds 
Working on problem size N=2048 
Elapsed time: 0.002380 seconds 
Working on problem size N=4096 
Elapsed time: 0.009104 seconds 
Working on problem size N=8192 
Elapsed time: 0.041443 seconds 
Working on problem size N=16384 
Elapsed time: 0.153487 seconds 

*/
/*

#pragma omp parallel for reduction(+:dot) on M2

Description:    OpenMP dgemv.

Working on problem size N=1024 
Elapsed time: 0.043176 seconds 
Working on problem size N=1024 
Elapsed time: 0.043111 seconds 
Working on problem size N=2048 
Elapsed time: 0.101133 seconds 
Working on problem size N=4096 
Elapsed time: 0.163196 seconds 
Working on problem size N=8192 
Elapsed time: 0.369310 seconds 
Working on problem size N=16384 
Elapsed time: 0.882434 seconds 

*/
}


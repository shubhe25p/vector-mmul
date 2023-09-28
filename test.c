#include "/opt/homebrew/opt/libomp/include/omp.h"
 
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char* argv[])
{
 
    // Beginning of parallel region
    #pragma omp parallel
    {
 
        printf("Hello World... from thread = %d\n",
               omp_get_thread_num());
    }
    // Ending of parallel region
}

// clang -Xclang -fopenmp -L/opt/homebrew/opt/libomp/lib -I/opt/homebrew/opt/libomp/include -lomp test.c -o omptest
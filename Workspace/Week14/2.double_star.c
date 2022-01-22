//兩個星號
#include <stdio.h>
#include <stdlib.h>

typedef float* FLT_ADDR;

float *malloc_float1(unsigned int sz){
    return (float*) malloc(sizeof(float)*sz);
}
void malloc_float2( FLT_ADDR * p , unsigned int sz){
    *p = (float *) malloc(sz*sizeof(float));
}

int main(void){
    
    FLT_ADDR ptr = NULL; //float * ptr = NULL;
    int i;
    int n = 100;
    // ptr = (float*) malloc (100*sizeof(float));
    // ptr = malloc_float1(n);

    malloc_float2(&ptr, n);

    for (i = 0; i < n; i++)
        ptr[i] = (float) rand()/RAND_MAX;

    for (i = 0; i < n; i++)
        printf("%5.2f", ptr[i]);
    free(ptr);

    return 0;
}
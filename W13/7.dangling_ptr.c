//memory leak : dangling pointer

#include <stdio.h>
#include <stdlib.h>
typedef float* FLT_ADDR; // 影藏其中一個星號

void malloc_float2( FLT_ADDR *p , unsigned int size){
    *p = (FLT_ADDR) malloc(size * sizeof(float));
}

int main(void){
    FLT_ADDR ptr = NULL;
    int i;
    int n = 100;

    malloc_float2( &ptr, n );

    for (i = 0 ; i < n ; i++){
        ptr[i] = (float) rand()/RAND_MAX;
    }
    for (i = 0 ; i < n ; i++){
       printf("%5.2f", ptr[i]);
    }
    free(ptr);

    return 0;
}

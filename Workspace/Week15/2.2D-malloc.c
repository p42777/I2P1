#include <stdio.h>
#include <stdlib.h>

int main(void){
    double *a;
    double* *b; // 指標陣列（兩個星號）
    int i, j;
    int M, N;

    scanf("%d %d", &M, &N);
    a = (double*) malloc (sizeof(double)* M* N); //第一次malloc：取得真實存放資料的空間
    b = (double**) malloc (sizeof(double*)* M); // 第二次malloc：抄寫對應門牌號碼

    for(i = 0 ; i < M ; ++i){
        b[i] = &a[i * N];
        for(j = 0 ; j < N ; ++j){
            a[i * N + j] = (double)rand() / RAND_MAX;
        }

    }
    for(i = 0 ; i < M ; ++i){
        for(j = 0 ; j < N ; ++j){
        printf("%6.2f", b[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
 
    return 0;
}
 
/*使用 qsort
void qsort (void *array, size_t count, size_t size, comparison_fn_t compare);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
int compare_int (const void *a, const void *b){
    // compare_int 轉乘int
    const int *va = (const int *) a;
    const int *vb = (const int *) b;
    return *va-*vb;
    // another way : 直接return *((int*)a)-*((int*)b);
}

int compare_double (const void *a, const void *b){
    
    const double *da = (const double *) a;
    const double *db = (const double *) b;
    return (*da > *db) - (*da < *db);
}

int main(void){
    
    int data1[SIZE];
    double data2[SIZE];
    int i;

    for (i=0; i<SIZE; i++) {
        data1[i] = rand()%SIZE;  // random number between 0 - RAND_MAX
        data2[i] = (double) rand()/RAND_MAX;
    }

    printf("original: ");
    for (i = 0 ; i < SIZE ; i++) {
        printf("%d ", data1[i]);
    }
    printf("\n");

    printf("  sorted: ");
    qsort(data1, SIZE, sizeof(int), compare_int);
    for (i = 0 ; i < SIZE ; i++) {
        printf("%d ", data1[i]);
    }
    printf("\n");

    printf("original: ");
    for (i = 0 ; i < SIZE ; i++) {
        printf("%.2f ", data2[i]);
    }
    printf("\n");

    printf("  sorted: ");
    qsort(data2, SIZE, sizeof(double), compare_double);
    for (i = 0 ; i < SIZE ; i++) {
        printf("%.2f ", data2[i]);
    }
    printf("\n");

    return 0;
}
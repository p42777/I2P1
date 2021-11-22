// 指標變數也可以接收函數位址！
#include <stdio.h>
#include <stdlib.h>
int sum         (int *a, int n);
int sum_squared (int *a, int n);
int middle      (int *a, int n);
/* 
int (*fp)       (int *a, int n);
sum, sum_squared, middle 皆符合(*fp)格式，可接收函數位址、傳給run
*/

int sum(int *a , int n){ // int *a = int a[]
    int i, ans = 0;
    for (i=0; i<n; i++) {
        ans += a[i]; // 等價的寫法：ans += *(a+i);
    }
    return ans;
}

int sum_squared(int *a, int n){
    int i, ans = 0;
    for (i=0; i<n; i++) {
        ans += a[i]*a[i];
    }
    return ans;
}

int middle(int *a, int n){
    return a[n/2];
}

int run (int (*fp) (int *, int )  , int a[], int n){ //
    return fp(a, n);
}

int main(void){
    int a[] = {1, 2, 3, 4};
    printf("%d\n", run(sum, a, 4));
    printf("%d\n", run(sum_squared, a, 4));
    printf("%d\n", run(middle, a, 4));
    return 0;
}
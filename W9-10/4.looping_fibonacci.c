#include <stdio.h> // 迴圈版

int main(void){

    int n, fib[100], i;
    scanf("%d", &n);

    fib[1] = 1;
    fib[2] = 1;
    for(i=3; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    printf("%d\n", fib[n]);
    return 0;
}
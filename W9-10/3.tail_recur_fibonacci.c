#include <stdio.h>
// Tail Recursion Version : 可以重複利用同一塊空間作函數呼叫，就不會浪費 stack 了

/*
fib(n==0, 0, 1) return previous = 0
fib(n==1, 0, 1) return current  = 1
fib(n==2, 0, 1) -> fib(n-1, current, current + previous) = fib(1, 1, 1) : return 1
.
.
.
fib(n==7, 0, 1) -> fib(6, 1, 1) -> fib(5, 1, 2) -> fib(4, 2, 3) -> fib(3, 3, 5) -> fib(2, 5, 8) -> fib(1, 8, 13) : return 13
*/


int fib(int n, int previous, int current){
    if(n == 0){
        return previous;
    }
    if(n == 1){
         return current;
    }
    else{
        return fib(n-1, current, current + previous);
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("Fibonacci(%d) : %d\n", n, fib(n, 0, 1));
    return 0;
}

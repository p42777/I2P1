#include <stdio.h> 

// 迴圈版 : 英文叫做 bottom up， 我們用一個陣列紀錄之前的答案，接著一個一個算到我們要的地方。

int main(void){
    
    int n, fib[100], i;
    scanf("%d", &n);

    fib[1] = 1;
    fib[2] = 1;

    for(i = 3 ; i <= n ; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("%d\n", fib[n]);
    return 0;
}

/*
Dynamic Programming:

之前有提到重複計算的問題，那又該如何解決呢?
既然不想一樣的東西算第二次，那我們就乾脆把答案存起來，下一次遇到就拿出來。

其實這個方法有個名字叫做動態規劃 dynamic programming (DP)，大部分有遞迴性質的問題，可以藉由 DP 壓縮大量重複的計算，增加效率。而這當中也有把大問題切割成多個小問題的特性，這種手法叫做分治法 (divide and conquer)，我們在之後的 merge sort 會看到這樣經典的例子。
雖然說這兩個問題用 DP 顯得大材小用，所以我們只要體會一下感覺就好了，大三的演算法會有更多神奇的DP。DP主要有兩個 coding 的方法，一個是用遞迴，一個用迴圈，沒有說哪個比較好，純粹是看哪個比較好思考或是比較好寫，當然如果都差不多的話，推薦選擇迴圈，一來效率比較好 (不用一直呼叫function)，也可以避免遞迴過深導致 stack overflow。
*/
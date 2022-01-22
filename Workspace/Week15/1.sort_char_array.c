/*
另一種方式
透過指標陣列
可以用在不同長度的字串排序
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

// |   5|   3|   8|...
// |aab0|abc0|aaa0|...
int compare_ptrs(const void *a, const void *b){
    char **pa = (char **) a;
    char **pb = (char **) b;
    return strcmp(*pa, *pb);
}


int main(void){
    char strs[SIZE][4] ={
        "aab", "abc", "aaa", "abb", "acb",
        "caab", "abc", "aaa", "abb", "acb" };

    char *ptrs[SIZE];
    int i;

    for (i = 0 ; i < SIZE ; i++) {
        ptrs[i] = strs[i];
    }

    for (i = 0 ; i < SIZE ; i++) {
       printf("%p: %s\n",ptrs[i],ptrs[i]);
    }
    printf("\n");

    qsort(ptrs, SIZE, sizeof(ptrs[0]), compare_ptrs);

    printf("via ptrs:\n");  
    for (i = 0 ; i < SIZE ; i++) {
        printf("%p: %p --> %s\n", &ptrs[i],ptrs[i],ptrs[i]);
    }
    printf("\n");
    printf("strs:\n");

    for (i = 0 ; i < SIZE ; i++) {
        printf("%p: %s\n", strs[i],strs[i]);
    }


    return 0;
}

/* 
為什麼用兩個星號(char **)?
    char **                  char **    第二個 * 代表指標變數(pointer)，而裡面放的資料的型態為 char* (打開一個門牌號碼又看到另一個門牌號碼)
    a=0x...                  b=0x...
|0x12345670 | 0x12345674 | 0x12345678 | ... 
    char *       char *      char *

char* ptrs[SIZE];

對照組：
    int *              int *              * 代表指標變數(pointer)，而裡面放的資料的型態為 int
    a=0x...            b=0x...
|    3    |    4    |    1    |    5    | ... 
    int       int       int       int

int arr [SIZE];

*/

/*
ptrs 是一個指標陣列
因此 ptrs 的每個元素都是一個指標  都可以用來記錄某個記憶體位置
我們先用 ptrs 的每個元素 ptrs[i] 分別記住每個字串的開始位址
for (i=0; i<SIZE; i++) {
    ptrs[i] = strs[i];
}

接下來對指標陣列做 qsort
依照 ptrs 的每個元素所指到的字串大小
將 ptrs 的元素搬動 
所以只是調換指標的順序
實際的資料 strs 不會被更改
請注意這時候 compare 函數的寫法
int compare_str_ptr(const void *a, const void *b)
{
    char * *pa;
    char * *pb;
    pa = (char **) a;
    pb = (char **) b;
    return strcmp(*pa, *pb);
}

請記住下面兩個重點:
1. 被搬動的東西是指標
2. 用來比較則是指標所指到的字串
我們可以換個格式顯示陣列內容
執行底下附的程式碼會輸出
strs: aab0|abc0|aaa0|abb0|acb0|aab0|abc0|aaa0|abb0|acb0|
ptrs: 0028FEE4|0028FEE8|0028FEEC|0028FEF0|0028FEF4|0028FEF8|0028FEFC|0028FF00|0028FF04|0028FF08|
after sorting
ptrs: 0028FF00|0028FEEC|0028FEE4|0028FEF8|0028FEF0|0028FF04|0028FEE8|0028FEFC|0028FF08|0028FEF4|
ptrs: aaa0|aaa0|aab0|aab0|abb0|abb0|abc0|abc0|acb0|acb0|
strs: aab0|abc0|aaa0|abb0|acb0|aab0|abc0|aaa0|abb0|acb0|

對照記憶體位址以及 strs 的內容就會看出端倪
*/
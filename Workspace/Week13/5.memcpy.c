/*
使用 memset, memcpy 設定、複製大量記憶體內容
void * memset(void *block, int c, size_t size);
void * memcpy(void *restrict to, const void *restrict from, size_t size);
*/
 
#include <stdio.h>
#include <string.h>
#define SIZE 100
int main(void){

    int a[SIZE];
    int b[SIZE];
    int i;

    // void * memset(void *block, int c, size_t size); 設定、多半填0 c=0 （清0）
    // void * memcpy(void *restrict to, const void *restrict from, size_t size); 複製
   
    memset(a, 0, SIZE * sizeof(int));
    for (i = 0 ; i < SIZE ; i++) {
        printf("%d ", a[i]);
        if ((i + 1) % 10 == 0){
            printf("\n");
        }
    }

    for (i = 0 ; i < SIZE ; i++) {
        a[i] = i * i;
    }

    memcpy(b, a, SIZE * sizeof(int));
    for (i = 0 ; i < SIZE ; i++) {
        printf("%5d", b[i]);
        if ((i + 1) % 10 == 0){
            printf("\n");
        } 
    }

    return 0;
}


#include <stdio.h>

int main(void){

    int i, j;
    int a[10][10] = {0}; 
    // 宣告一個10*10的二維陣列 (初值皆為0)
    
    i = 1;
    while (i<=9) {
        j = 1;
        // j = 1 要寫在第一層loop中 (原因：寫在外層無法更新j值)
        while (j<=9){
            a[i][j] = i * j; 
            j++;
        }
        i++;
    }
    // 利用雙層迴圈填入2D-array值

    i = 1;
    while (i<=9){
        j = 1;
        while (j<=9){
            printf("%3d ", a[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
 
    return 0;
}
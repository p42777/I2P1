#include<stdio.h>

int main(void){

    char ch;
    // 宣告一個字元(char)變數
    ch = 'A';
    // 字元(character)用單引號('')括住
    printf("%c %d\n",ch,ch);
    // %c吃字元A ; %d吃ASCII編碼(int)

    ch = '8';
    printf("%d %d %d %d\n", '0','1','2','3');
    printf("%c %d %d\n",ch,ch,ch-'0');

    return 0;
    
}

# include <stdio.h>

int main(void){

    float x = 5.23456;
    // 宣告一個float變數
    double y = -3.14;
    // 宣告一個double變數
    printf("%10.3f,%10.8f\n",x,y);
    // %10.3f : 共10格，小數點後留3位
    // %10.8f : 共10格，小數點後留8位
    
    return 0;

}
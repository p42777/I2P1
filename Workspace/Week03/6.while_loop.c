#include<stdio.h>
#include<string.h>

int main (void){
    int x, n, i, sum;
    int a[50];
    printf("How many numbers? (n<50)");
    scanf("%d",&n);

    i = 0;
    while (i<n){
        printf("Input a[%d]:",i);
        scanf("%d",&x);
        a[i]=x;
        i++;
    }
    // 當i < n [condition = true != 0] : 繼續跑while迴圈(執行 printf, scanf...並更新i值：i=i+1) 直到 i>=n [conditon = false = 0]
   
    i = 0;

    sum = 0;
    while (i<n){
    printf("%d + ", a[i]);
    sum += a[i];
    // 等價於 sum = sum + a[i]
    i++;
    }

    printf("\b\b= %d\n",sum);
    return 0;

}
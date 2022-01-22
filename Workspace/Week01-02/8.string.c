#include<stdio.h>
#include<string.h>

int main(void){

    char str[100] = "programming";
    //C語言中沒有 String 型態，只能以字元陣列表示 (char[])
    //宣告str : 一個提供100 index 的字元陣列放 string
    //programming\0 佔用11+1格
    int i;
    

    printf("%lu\n",strlen(str));
    // strlen() 為<string.h>函式庫的 method : 回傳字串長度(unsigned long)
    // %lu : 列印 unsigned long 值
    printf("%s\n",str);
    // %s : 列印 string
    
    // while-loop
    i = 0;
    while(i < strlen(str)){
         printf("%c\n",str[i]);
         i++;
    }
    // 當i<strlen(str) [condition = true != 0] : 繼續跑while迴圈(列印字元'p''r''o''g'...並更新i值：i=i+1) 直到 i>=strlen(str) [conditon = false = 0]
   
    char str1[100] = "prog\0ramming";
     // \0 represents the end of a string (此處使字串提早結束)
    printf("%lu\n",strlen(str1));
    printf("%s\n",str1);


    return 0;
}
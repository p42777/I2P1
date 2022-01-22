/*
使用 strcpy, strcat, strncpy
char * strcpy(char *restrict to, const char *restrict from);
char * strncpy(char *restrict to, const char *restrict from, size_t size);
char * strcat(char *restrict to, const char *restrict from);
*/
 
#include <stdio.h>
#include <string.h>

int main(void){

    char str1[30];
    char str2[30];
    char str3[60];

    scanf("%29s", str1);
    scanf("%29s", str2);

    // char * strcpy(char *restrict to, const char *restrict from); 複製 (因為 restrict to 會被修改，因此不能宣告const)
    // char * strncpy(char *restrict to, const char *restrict from, size_t size); 複製
    // char * strcat(char *restrict to, const char *restrict from); 串接

    strcpy(str3, str1); //複製 str3<--str1
    strcat(str3, str2); //串接 str3+str2
    printf("%s\n", str3);

    return 0;
}


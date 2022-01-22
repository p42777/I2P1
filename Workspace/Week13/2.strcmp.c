/*
使用 strcmp 和 strncmp (string compare)
int strcmp(const char *s1, const char *s2); 
[ 接受兩個 const char* 參數(字串)，比較後回傳一個 int，因為不會、也不能改變字串內容，因此宣告const ]
int strncmp(const char *s1, const char *s2, size_t size);
*/

#include <stdio.h>
#include <string.h>

int main(void){

    char str1[30];
    char str2[30];
    int n;

    scanf("%29s", str1);
    scanf("%29s", str2);

    // int strcmp(const char *s1, const char *s2);
    // int strncmp(const char *s1, const char *s2, size_t size); (只比前n位)
    // 透過ASCII比較s1&s2是否相同，回傳相等、大多少、小多少

    printf("strcmp(%s, %s) = %d\n", str1, str2, strcmp(str1, str2));
    n = 3;
    printf("strncmp(%s, %s, n) = %d\n", str1, str2, strncmp(str1, str2, n));

    return 0;
}



// char * strncpy(char *restrict to, const char *restrict from, size_t size);

#include <stdio.h>
#include <string.h>

int main(void){
    char str1[30];
    char str2[30];
    int n;

    scanf("%s", str1);

    n = 2;
    strncpy(str2, str1, n);
    str2[n] = '\0';
    printf("%s\n", str2);

    return 0;
}

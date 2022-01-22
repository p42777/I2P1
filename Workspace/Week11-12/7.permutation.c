#include <stdio.h>
#include <string.h>
// pointer + array + recursion
void show(char *p);
void swap(char *p, char *q);
void permutation(char *p);
// 輪流當頭，剩下的做排列(窮舉)
int main(void){
    char str[10];
    str[0] = '\0';
    scanf("%8s", str + 1);
    permutation(str + 1);
    return 0;
}
void show(char * p){
    if (*p!='\0') {
        // 這邊 *p = *(p + 0) = p[0]
        show(p-1);
        printf("%c", *p);
    }
}
void swap(char *p, char *q){
    char tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}
void permutation(char * p){
    int i;
    if (p[0] == '\0') {
        show(p-1);
        printf("\n");
    } 
    else {
        for (i = 0 ; i < strlen(p) ; i++) {
            swap(p, p+i);
            permutation(p+1);
            swap(p, p+i);
        }
    }
}
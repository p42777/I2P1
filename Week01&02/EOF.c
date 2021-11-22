#include <stdio.h>

int main(void){
    int x;

    while (scanf("%d", &x) != EOF) { 
        // EOF : control(^) + D 
        printf("x=%d\n", x);
    }
    while (getchar() != '\n'){}
    return 0;
}

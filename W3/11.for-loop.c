#include <stdio.h>
int b[10000][10000];
int main(void)
{
    int i, j;

    printf("Go!\n");
    for (i = 0; i < 10000; i++) {
        for (j = 0; j < 10000; j++) {
            b[i][j] = i*j;
        }
    }
    printf("Done.\n");

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            printf("%3d", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
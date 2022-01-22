#include <stdio.h>

int main(void){
    int x, y, z;
    int a, b, c;
    int i;
    scanf("%d%d%d", &x, &y, &z);
    scanf("%d%d%d", &a, &b, &c);

    for (i=1; i<=x*y*z; i++) {
        
          if (i%x==a && i%y==b && i%z==c) {
          printf("%d\n", i);

          break;
          }
    }

    return 0;
}
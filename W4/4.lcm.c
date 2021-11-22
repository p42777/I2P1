/*
Find the smallest N that satisfies
    N % x == a
    N % y == b
    N % z == c
For example,
if x=3, y=5, z=7, and a=2, b=3, c=4,
then, N is 53 since
    53 % 3 == 2
    53 % 5 == 3
    53 % 7 == 4
and 53<=3*5*7.

Another test case:
Input:
23 29 37
10 20 30
Output:
14201
 */

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
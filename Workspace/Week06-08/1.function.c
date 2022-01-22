#include<ctype.h>
#include<stdio.h>
#include<string.h>

int f (int a, int b);

int main (void){
    int x, y, z;
    scanf("%d%d", &x, &y);
    z = f(x,y);
    printf("%d%d%d", x, y, z);
    return 0;
}

int f (int a, int b){ //a = 3, b = 5
    a++; //a = 4
    b++; //b = 6
    // 但是(x,y)依舊等於(3,5),因為main裡面的區域變數和(a,b)無關 [call by value, 傳值呼叫]
    a += b;
    return a * a;
}

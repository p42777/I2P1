#include <stdio.h>

/*
十進位轉任意進位：
1.整數：連續除基底(base, b)得到的餘數得到的餘數由「低到高」(下到上)，由左到右得到答案
2.小數：連續乘績底(base, b)得到的乘積的整數部分由「高到低」(上到下)，由左到右得到答案
Decimal -> Binary : base = 2
*/

void binary(int n){
    if( n <= 0 ){
        return;
    } 
    else{
        binary(n/2);
        //連除取餘數：注意先遞迴再print，因為第一個 n%2 得到的 0 或 1 應該要是二進位表法的最後一位 (由低到高/下到上！)
        printf("%d", n%2 );
    }
  	
}

int main(void){
    int n;
    scanf("%d", &n);
    binary(n);
    return 0;
}

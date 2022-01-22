/*
用 recursion 產生下面的輸出

Input: 10 
Output: ((((1+2)*3+4)*5+6)*7+8)*9+10 = 4555 

Input: 11 
Output: (((((1+2)*3+4)*5+6)*7+8)*9+10)*11 = 50105
*/

#include<stdio.h>

int show (int n);

int main(void){
    double n;
    scanf("%lf",&n);
    printf("=%d\n",show(n));
    return 0;
}

int show(int n){
    int ans;
    if(n <= 1){
        printf("1");
        return 1;
    }
    else{
        if(n%2==0){
            printf("(");
            // show(n-1)本來就會印出東西，所以要記得在呼叫show(n-1)之前，先印出括號！
        }
        ans = show(n-1);
        if(n%2==0){
            printf("+%d)",n);
            //偶數前面印加號、後面印右括號
            return n + ans;
        }
        else{
            printf("*%d",n);
            //奇數前面印乘號
            return n * ans;
        }
    }
    
}
#include<stdio.h>

int A[10] = {1, 23, 44, 67, 9, 29, 104, 543, 996, 100};

int main(void){
    int i, j;
    int x;
    for (i = 1 ; i < 10 ; ++i){
        x = A[i];
        j = i;
    
        while(j > 0 && A[j - 1] > x){
            // 檢查目前所在的 x 有沒有比他前面的所有人都還大，如果有人比 x 大，就得把他往後推
            A[j] = A[j - 1];
            --j;
        }
        A[j] = x;
    }
    for (j = 1 ; j < 10 ; ++j){
        printf("%d ", A[j]);
    }

    return 0;
}

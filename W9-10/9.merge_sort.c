#include <stdio.h>
#define MAXN 1000000
int data[MAXN], buffer[MAXN];

/*
start_a : 1 3 5 8 9 
start_b : 2 4 7 10 11

step 1 : 1 跟 2 比，1 比較小，1 丟下來，start_a 往前一格變成 3
step 2 : 3 跟 2 比，2 比較小，2 丟下來，start_b 往前一格變成 4，以此類推

Output : 1 2 3 4 5 7 8 9 10 11
*/

void merge(int start_a, int length_a, int start_b, int length_b){
    
    int i = 0, j = 0, k = 0; // index for A, B, and buffer

    while( i < length_a && j < length_b ){
        // 找出比較小的填入buffer
        if( data[ start_a+i ] < data[ start_b+j ] ){ // use '<' to make merge sort stable
            // data[ start_a+i ] 比較小，填進buffer，k 往前一格提供下個數字填入，start_a+i 往前一格繼續比對
            buffer[ k++ ] = data[ start_a+i++ ];
        }
        else{
            // data[ start_b+j ] 比較小，填進buffer，k 往前一格提供下個數字填入，start_b+j 往前一格繼續比對
            bufer[ k++ ]f = data[ start_b+j++ ];
        }
    }

    // 當A、B其中一個已無元素，另一個就要做收尾，把剩下的填入 buffer 尾端
    while( i < length_a ){
        buffer[ k++ ] = data[ start_a+i++ ];
    } 
    while( j < length_b ){
        buffer[ k++ ] = data[ start_b+j++ ];
    } 
}

void merge_sort(int head, int tail){
    if( head >= tail ){
        // bound condition
        return; 
    } 
    int mid = head + (tail - head) / 2;  // 切成一半
    // recurtion
    merge_sort( head, mid ); // 把左半部排好 
    merge_sort( mid + 1, tail ); // 把右半部排好

    /* 
    利用寫好的 merge 函數進行比對
    讓左半部： start_a = head, length_a = mid - head + 1 
    右半部： start_b = mid + 1 ; length_b = tail - mid
    */

    merge( head, mid - head + 1, mid + 1, tail - mid );
    for( int i = 0 ; i < tail - head + 1 ; i++){
    	data[ head+i ] = buffer[i]; // 搬回到data
    }
}

int main(){

    int n, i;
    scanf("%d", &n);

    for(i = 0 ; i < n ; i++){
        scanf("%d", &data[i]);
    }

    merge_sort( 0, n-1 );

    for (i = 0 ; i < n ; ++i){
        printf("%d ", data[i]);
    }

    return 0;
}


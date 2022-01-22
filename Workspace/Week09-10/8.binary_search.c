#include <stdio.h>
int data[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
int find(int, int, int);

int main(void){

    int number;
    scanf("%d", &number);

    if( find(number,0,9) != 0 ){
        printf("Found!\n");
    }
    else{
        printf("Not found.\n");
    }
}

int find(int number, int head, int tail){
    int middle = head + (tail - head) / 2;
    // 寫 "(head + tail) / 2" 也可以，但數字一大就容易溢位(overflow)
    if(head > tail){
        // head > tail 已經不合理了，直接 return 0
        return 0;
    }

    if(number > data[middle]){
        // 在右半部找
        return find( number, middle + 1, tail ); // 記得用 middle + 1，而不是 middle
    }

    else if(number < data[middle]){
        // 在左半部找
        return find( number, head, middle - 1 ); // 記得用 middle - 1，而不是 middle
    }

    else{
        // head == tail : 找到了！
        return 1;
    }
}
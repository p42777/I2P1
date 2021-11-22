#include <stdio.h>

int main(void){
    char ch;
    for (ch = 'a'; ch <= 'z'; ch++) {
    // for (initialization ; ending condition ; update)
        printf("The ASCII value for %c is %d.\n", ch, ch);
        // %c吃字元A ; %d吃ASCII編碼(int)
    }
    return 0;
}


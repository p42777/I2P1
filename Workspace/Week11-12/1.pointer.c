#include <stdio.h>
typedef int* int_ptr;
// 什麼是指標變數？ Ans：用來記住記憶體位址的變數！

int main(void){

    int_ptr px;          // *px = int_ptr px 記住 x 的位址
    int   x = 3;
    double   y = 2.5; 
    double* py;          // *py 記住 y 的位址
    px = &x;  
    py = &y;  

    printf("%p, %p\n", &x, &y); // %p 這種格式是用來顯示記憶體位址[門牌號碼](十六進位)
    printf("%p, %p\n", &px, &py); // 指標變數也是佔空間的(也有自己的門牌號碼)
    printf("%lu, %lu\n", sizeof(px), sizeof(py)); 
    // sizeof() 用來計算用來計算變數大小：px, py 為指標變數，不論是int指標還是double指標，大小皆為 8B (64位元記憶體) [想法：不論你的房子坪數為何，門牌號碼都是一樣大的！]
    printf("%lu, %lu\n", sizeof(*px), sizeof(*py)); 
    // sizeof() 用來計算用來計算變數大小：*px 為 int type (4 bytes)，*py 為 double type (8 bytes) [想法：* 的功用就像鑰匙，找到門牌號碼、開門取值(value)]
    printf("%d %f\n",*px, *py);

    return 0;
}

/*
The difference between “&” and “*” operators : [ &取址，*取值 ]
& is a unary operator in C which returns the memory address of the passed operand. This is also known as address of operator.
* is a unary operator which returns the value of object pointed by a pointer variable. It is known as value of operator. It is also used for declaring pointer variable.
*/

#include <stdio.h>
#define STEP 10
#define LOWER 0
#define UPPER 100
// 在 preprocess 階段即定義 STEP, LOWER, UPPER 三個變數，後續遇到時直接以 10, 0, 100 取代

int main(void){
    int fahr, celsius;
    printf("Celsius    Fahrenheit\n");
    printf("---------------------\n");
    celsius = LOWER;
    // celsius 初值 = 0

    while (celsius <= UPPER) {
        fahr = 1.8 * celsius + 32;
        printf("%4d %12d\n", celsius, fahr);
        celsius = celsius + STEP;
        // 等價於 celsius+=STEP
    }
    printf("---------------------\n");

    return 0; 
}

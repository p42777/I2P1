/*
位元運算 Bit Operations
& AND  
| OR  
^ XOR  
~ NOT
>> RIGHT SHIFT
<< LEFT SHIFT

Example:
x = 0x1F          0001 1111
y = 0x2C          0010 1100
         ~x       1110 0000
         x ^ y    0011 0011
         x | y    0011 1111
         x & y    0000 1100
         x >> 3   0000 0011
         y << 2   1011 0000

*/

#include <stdio.h>

int mask[16] = {
    0x00001, 0x00002, 0x00004, 0x00008,
    0x00010, 0x00020, 0x00040, 0x00080,
    0x00100, 0x00200, 0x00400, 0x00800,
    0x01000, 0x02000, 0x04000, 0x08000
};

int main(void){
    int N, i, j, lim;
    int num[16];

    scanf("%d", &N);
    for (i = 0 ; i < N ; i++) {
        scanf("%d", &num[i]);
    }
    lim = 1<<N; // 乘2的N次
    for (i = 0 ; i < lim ; i++) {
        for (j = 0 ; j < N ; j++)  {
            if ((i&mask[j]) != 0) {
                printf("%d ", num[j]);
            }
        }
        printf("\n");
    }

    return 0;
}

/*
位元運算
& AND  | OR
^ XOR  ~ NOT
>> RIGHT SHIFT
<< LEFT SHIFT
應用
產生子集合
譬如集合中包含 100 200 300 三個數字
底下的程式碼可以產生所有可能的組合
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
    for (i=0; i<N; i++) {
        scanf("%d", &num[i]);
    }
    lim = 1<<N;
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

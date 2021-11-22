#include <stdio.h>

int main (void){
    char data[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    char* p;
    p = data;
    int* q;
    q = (int*)data;
    long long* r;
    r = (long long*)data;
    
    // part 1
    printf("p address\n");
    while(p < &data[16]){
        printf("%p %d\n", p, *p);
        // 共 16 組，一個 char 為 1 byte，相鄰兩門牌號碼差 1 號
        ++p;
    }

    printf("q address\n");
    while(q < (int*)&data[16]){
        printf("%p %08x\n", q, *q);
        // 共 4 組，一個 int 為 4 bytes，相鄰兩門牌號碼差 4 號
        ++q;
    }

    printf("r address\n");
    while(r < (long long*)&data[16]){
        printf("%p %016llx\n", r, *r);
        // 共 2 組，一個 long long 為 8 bytes，相鄰兩門牌號碼差 8 號
        ++r;
    }

    printf("------------------------\n");
    // part 2
    int i;
    printf("p address\n");
    i = 0;
    while(i < 16){
        printf("%p %d\n", p+i, *(p+i));
        // p + i = data + i = &p[i]...
        // *(p + i) = *(data + i) = p[i]... (唯一的區別：可以對ｐ[指標變數]作++，但不能對 data 作++)
        ++i;
    }

    return 0;

}


/*
part 1 : data in memory
90     91     92     93     94     95...
01  |  02  |  03  |  04  |  05  |  06  |
p[0]  p[1]   p[2]   p[3]   p[4]   p[5]...
->         q[0]         <-->      q[1]...
->             r[0] = 0807060504030201...
*/
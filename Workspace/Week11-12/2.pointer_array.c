#include <stdio.h>

/*
等價的寫法
a[i]  <--->  *(a+i)  // 用 * 打開 a + i (開頭位址：a，偏移量：i) 這個記憶體位址(門牌號碼)取值
&a[i] <--->  (a+i)   // 註： <---> (ptr + i)
*/

unsigned int mylen(char *s);

int main(void){
    
    // part 1
    char str[] = "Hello, world!";
    printf("%u, %s\n", mylen(str), str);

    printf("------------------------------------\n");

    // part 2
    int a[10] = {1, 2};
    a[5] = 100;
    int* p;
    p = a;
    printf("%lu\n", sizeof(a));
    printf("%d %p %p\n", a[0], &a[0], p + 0);
    printf("%d %p %p\n", a[1], &a[1], p + 1);
    printf("%d %p %p\n", a[2], &a[2], p + 2);
    printf("%d %p %p\n", a[5], &a[5], p + 5);
    // a[0] & a[5] (p + 0 & p + 5) 的門牌號碼差20號，因為中間相隔5個 integer [5 * 4 = 20 bytes]
    printf("%d %d %d %d %d\n", p[1], *(a + 1), *(1 + a), 1[a], 1[p]);
    // *(a + 1) = *(1 + a) = a[1] = p[1] = 1[a] = 1[p] = *(1 + p) = *(p + 1)
    return 0;
}

unsigned int mylen(char *s){

    unsigned int len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    return len;

}


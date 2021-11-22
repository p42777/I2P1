#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int main(void){
    char strs[SIZE][4] ={
        "aab", "abc", "aaa", "abb", "acb",
        "aab", "abc", "aaa", "abb", "acb"
    };
    int i;
    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]); // strs[i] = &strs[i][0] = & * (strs[i]+0) = & * strs[i] = strs[i]j
    }
    printf("\n");
    qsort(strs, SIZE, 4*sizeof(char), (int (*) (const void *, const void *))strcmp); // 第四個參數需做強制轉型(const char* --> const void*)，當然也可以自己寫compare_str
    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]);
    }

    return 0;
}

/* 
上面的方法可以正確運作的原因是字串長度固定而且規律地放置二維陣列 strs[SIZE][4] 的內容
strs[0] 對應到 "aab\0"
strs[1] 對應到 "abc\0"
但是其實這樣的二維陣列在記憶體中仍然是用一維方式循序放置
可以看成
|aab0|abc0|aaa0|abb0|acb0|aab0|abc0|aaa0|abb0|acb0|
陣列總共十個元素
每個陣列的元素包含三個英文字元外加後面跟著一個 '\0' 字元 總共 4 bytes
因此我們可以用 qsort(strs, SIZE, 4*sizeof(char), (int (*) (const void *, const void *))strcmp);
讓 qsort 以陣列元素為基本單位替我們排序 也就是以 4 bytes 為單位進行個別元素比對搬動
最後 strs 陣列的內容會直接被修改 並搬動成由小排到大
qsort 第四個參數要強制型別轉換 讓 strcmp 變成符合型別
原本 strcmp 的型別 int strcmp (const char *s1, const char *s2);
經過型別轉換之後變成 int strcmp (const void *s1, const void *s2);
*/
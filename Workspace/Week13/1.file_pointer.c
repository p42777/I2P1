/*
讀檔
練習如何使用陣列來儲存資料
練習如何開檔、讀檔、寫檔。

[前置作業]
下載附件檔案 data_50000.txt
檔案裏讀到的第一個整數代表後面總共有多少筆資料必須讀取(data_50000.txt 裏的第一個整數是50000，因此後面共五萬筆資料)，資料的格式是整數，有正有負。
讀取到的資料用一個 global 整數陣列來儲存。
global 陣列宣告在 function 之外，不屬於單一 function，每個 function 都可以存取 global 陣列。
需要這麼做的原因是因為 function 中宣告的陣列大小通常不能太大，
由於我們還沒學到動態記憶體管理，
因此目前先暫時用 global 的方式產生陣列，這樣才能夠處裡稍微大量一點的資料。

例如下面的程式碼，產生一個叫作 data 的整數陣列，用來儲存從檔案讀取到的資料:
*/

#include <stdio.h>
int data[100000];
int main(void){
    FILE *fin, *fout;
    int i, j, tmp;
    int num_data;

    fin = fopen("data_50000.txt", "r");
    if(fin == NULL) return -1; // 代表開啟檔案失敗，正確的處理方法：terminate the program

    fscanf(fin, "%d", &num_data); // fscanf 和 scanf 差別：可以自己決定資料讀取來源
    // fscanf(data input ; datatype representation ; data output)
    for (i = 0 ; i < num_data ; i++) {
        fscanf(fin, "%d", &data[i]);
    }
    fclose(fin);

    // Sort from small to large : By Insertion Sort
    for (i = 1 ; i < num_data ; i++) {
        j = i;
        tmp = data[j];
        while (j > 0 && data[j-1]>tmp) {
            data[j] = data[j-1];
            j--;
        }
        data[j] = tmp;
    }
    // Worst Case : 欲從小排到大，但資料恰巧由大至小，這樣雙層迴圈必須跑滿，時間複雜度為 num_data 的平方 (50000^2)



    fout = fopen("data_50000_sorted.txt", "w");
    if (fout == NULL) return -1;
    fprintf(fout, "%d\n", num_data);
    for (i = 0; i < num_data; i++) {
        fprintf(fout, "%d ", data[i]);
    }
    fclose(fout);

    return 0;
}


/*
這段程式碼會產生一個 FILE 指標 (變數名稱是 fin)，
fopen() 的用法是 fopen("檔案路徑和檔名", "開檔方式"); 若對照上面那段程式碼，其中我們用到的 "r"， 代表 read， 也就是只做讀取， 如果開檔成功會傳回指向檔案內容起始位置的指標。假如沒有指定路徑而只有給檔名，則要確定data_50000.txt 和你的程式執行檔是在同一個資料夾下，才會順利找到檔案並開啟。
fscanf()的用法是 fscanf(檔案指標, "讀取格式", 變數的位址); 和 scanf() 的用法完全一樣，只是前面要多傳一個指標，指向要讀取的資料。
*/
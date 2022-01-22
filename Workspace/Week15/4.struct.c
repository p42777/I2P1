// 封裝 encapsulation 的概念
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x;
    int y;
} Point;
/* 
定義一個新的type，取名為 Point 
裡面包含 x 和 y 兩個 members
定義Point之後可以被拿來當作一般的型別來使用
包括宣告新的 variables 或是宣告 function  
類似於 OOP 中的 class */ 

Point * ones_vec_1(int length); // ones_vec_1() 會傳回某個 Point 結構的位址，這個位址是由 Point 結構組成的陣列的開頭位址
void ones_vec_2(int length, Point **bp);

int main(void){
   Point *a, *b;
   int i, length;
   printf("The size of a Point is %lu bytes.\n", sizeof(Point));
   printf("vector length: ");
   scanf("%d", &length);

   /* 
   利用 ones_vec_1 取得一個陣列 
   陣列的每個元素是一個 Point
   陣列的開頭位址記錄在指標變數 a 裡面 */   

   a = ones_vec_1(length);
   ones_vec_2(length, &b);

   /* 
   a 是個指標變數   它記錄的是某個陣列的開頭位址
   陣列的每個元素是 a[i] (是個 Point)
   所以有兩個 members  分別是 a[i].x 和 a[i].y */   

   for (i=0; i<length; i++){
      printf("(%d, %d) ", (a+i)->x, (a+i)->y); // (a+i)->x 等價於 a[i].x = *(a+i).x  [ (*某個位址).欄位 = 某個位址->欄位 ]
    }
   printf("\n");
   
   for (i=0; i<length; i++){
      printf("(%d, %d) ", b[i].x, b[i].y); // b[i].x = *(b+i).x = (b+i)->x
    }
   printf("\n");
   
   return 0;
}

Point * ones_vec_1(int length){
   Point *a;
   int i;
   a = (Point *) malloc(length * sizeof(Point));
   for (i = 0 ; i < length; i++) {
      a[i].x = 1;
      a[i].y = 1;
    } 
   return a;
}

void ones_vec_2(int length, Point **bp){
   int i;
   
   *bp = (Point *) malloc(length * sizeof(Point));
   for (i = 0 ; i < length; i++) {
      (*bp)[i].x = 1;
      (*bp)[i].y = 1;      
    } 
}

/* 其他觀念
1. 
合併的寫法：
typedef struct {
    int x;
    int y;
} Point;

未合併的寫法：
struct t_point {
    int x;
    int y;
};
typedef struct t_point Point; 

2. [重點：'->'的用法]
Point pt = {5, 7};
Point *pp; ------------------指標變數
pp = &pt;
(*pp).x = 10; ---------------Point type 指標變數*pp .x
pp->x = 10; -----------------等價的寫法（只有指標變數可以這樣寫'->'！）

3. [重點：分辨 ‘.’ & '->']
“.“：僅開一道門
”->“：連開兩道門 ( * 開第一個門 + . 開第二個們的組合 )

*/

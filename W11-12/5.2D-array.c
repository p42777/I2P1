#include<stdio.h>
typedef int row_vector [5];


int main(void){
   
   int a[] [4] = { {1, 2, 3, 4}, {5, 6}, {9, 10, 11, 12}};
   // 每一個元素都是一個由 4 個元素組成的小陣列
   // {5, 6}裡面只有兩個元素，因此會被自動補 0：{5, 6, 0, 0}
   int b[] [4] = { 1, 2, 3, 4, 5, 6, 9, 10, 11, 12};
   // 每 4 個元素自動成組，但 0 會補在最後面：{11, 12, 0, 0}
   int i, j; 
   row_vector matrix[4]; 
   
   
   printf("a:       %lu bytes\n", sizeof(a));
   printf("a[0]:    %lu bytes\n", sizeof(a[0]));
   printf("a[0][0]: %lu bytes\n", sizeof(a[0][0]));
 
   printf("\n");
   for (i = 0 ; i < 3 ; i++) {
      for (j = 0 ; j < 4 ; j++) {
         printf("%3d ", a[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   for (i = 0 ; i < 3 ; i++) {
      for (j = 0 ; j < 4 ; j++) {
         printf("%3d ", b[i][j]);
      }
      printf("\n");     
   }
   printf("\n");
   for (i = 0 ; i < 3 ; i++) {
      for (j = 0 ; j < 4 ; j++) {
         printf("%p\t", &b[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   printf("%d %d %d\n", a[2][3], *(a[2]+ 3), *(*(a + 2) + 3));
   // a[2][3] = *(a[2]+ 3) = *(*(a + 2) + 3) [a 先跳 2 * 16 = 32 bytes 再加 3 bytes]
   int(*p) [4];
   p = a;
   // p 是一個指標變數，指向一個由 4 個元素組成的空間，當 p++ 時，一次就跳 4 * 4 = 16 bytes (這是宣告指標指向二維陣列的方式，必須知道下一個一個元素有多大)
   printf("%d %d %d\n", p[2][3], *(a[2]+ 3), *(*(p + 2) + 3));

   return 0;
}
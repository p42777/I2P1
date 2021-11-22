// 在程式執行期間動態取得記憶體：malloc
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
   double *ptd;
   int array_size, i;

   printf("How many doubles do you want? ");
   scanf("%d", &array_size);
   ptd = (double *) malloc(array_size * sizeof (double));
   if (ptd == NULL) {
      printf("Memory allocation failed.\n");
      exit(EXIT_FAILURE);
   }

   for (i = 0; i < array_size; i++) {
      ptd[i] = (double) rand() / RAND_MAX;
   }
   for (i = 0; i < array_size; i++) {
      if (*(ptd+i) > 0.5){ // *(ptd+i) = ptd[i]
         printf("%d: %f\n", i, ptd[i]);
         }
   }

   free(ptd);
   // malloc和free 為一個組合，當初從malloc要到的空間需用free釋放、還回 

   return 0;
}

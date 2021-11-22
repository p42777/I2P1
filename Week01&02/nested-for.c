#include <stdio.h>
int main(void){

   int i, j;   
   for(i = 0; i < 7; i++) { 
      for (j = 0; j < 25; j++) { 
         printf("*");
      }
      printf("\n");
   }  

   return 0;
}

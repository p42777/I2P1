#include <stdio.h>
int main(void){
   long num;
   long sum = 0;
   int status;

   printf("Please enter an integer to be summed (q to quit): ");
   status = scanf("%ld", &num); 
    // %ld 吃long值

   while (status == 1) {    
      sum = sum + num;
      // 等價於 sum += num
      printf("Please enter next integer (q to quit): ");
      status = scanf("%ld", &num);
   }
   printf("Those integers sum to %ld.\n", sum);

   return 0;
}

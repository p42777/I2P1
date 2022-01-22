#include <stdio.h>

#define MAX_SIZE 50
#define LOWER_LIMIT 0
#define UPPER_LIMIT 1000000

int main(void){
   
   int data[MAX_SIZE];
   int i, j, size;
   int maxval = LOWER_LIMIT, minval = UPPER_LIMIT;
   freopen("test.txt", "r", stdin);

   for (size = 0; size < MAX_SIZE; size++) {
      if (scanf("%d", &data[size]) != 1)
         break;
   }
   for (i = 0, j = size - 1; i <= j; i++, j--) {
        if(data[i] < data[j]){
            // 在data[j] 比 data[i] 大的狀況下：data[i] 要和 minval 比，data[j] 要和 maxval 比
            if(minval > data[i]) minval = data[i];
            if(maxval < data[j]) maxval = data[j];
        }
        else{
            // 在data[i] 比 data[j] 大的狀況下：data[i] 要和 maxval 比，data[j] 要和 minval 比
            if(minval > data[j]) minval = data[j];
            if(maxval < data[i]) maxval = data[i];
        }

   }
   printf("%d %d\n", minval, maxval);

   return 0;
}

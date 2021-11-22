#include <stdio.h>
void hanoi(char start, char end, char buffer, int n);
//start = 起始碟子 ; end = 目標碟子 ; buffer = 暫存碟子 ; n = 總碟子數

int main(void){
	int n;
	printf("Number of disks: ");
	scanf("%d", &n);
	hanoi('1', '3', '2', n);

	return 0;
}

/* move n disks from a to b using c as a buffer */

void hanoi(char a, char b, char c, int n){
	if (n == 0) {		
		return;
	}
	hanoi(a, c, b, n-1); 
    // move the top (n-1) disks from a to c 
	// 當目標是從a移到b：應該要先把最上面的(n-1)個移到buffer，才能把最下面的(第n個)移到b
	// 這時候針對那(n-1)個：start' = a, end' = buffer, buffer' = b, n' = n-1
	// 問題簡化的流程：hanoi(start, buffer, end, n-1)

	printf("Move the top disk from Tower %c to Tower %c\n", a, b); 
    // move the last disk from a to b 

	hanoi(c, b, a, n-1);
    // move the top (n-1) disks from c to b 
}

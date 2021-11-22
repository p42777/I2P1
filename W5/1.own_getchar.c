// 自己用 getchar() putchar() 寫出 scanf %d 和 printf %d 


#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){

	int x;
	char ch;
	char digits[20];
	int i;

	x = 0;
	while ((ch = getchar()) != EOF && isdigit(ch)) {
		x = x * 10 + ch - '0';
	}

	x = x * 2 ;

	i = 0;
	while (x > 0) {
		digits[i] =  (x%10) + '0';	
		x = x / 10;
		i++;
	}
	i--;
	while (i >= 0) {
		putchar(digits[i]);
		putchar('_');
		i--;
	}

	return 0;
}

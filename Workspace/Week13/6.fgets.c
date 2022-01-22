
#include <stdio.h>
#include <string.h>

void flip(char *s, int start, int end){
    int tmp;
	for (;start < end ; start++, end--) {
		// do swapping
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
	}
}

int main(void){
	char a[100];
	int i, j;
	fgets(a, 100, stdin);
	// fgets (f開頭)：可以決定從哪個 input 讀資料
	/*
	Example : fgets 輸入 abcd :
	0  1  2  3  4  5 
	a  b  c  d  \n \0 
	strlen == 5
	str[4] == str[5-1] == str[strlen(str) - 1] == \0
	*/
	a[strlen(a)-1] = '\0';
    //"this is a book \n \0 --> this is a book \0 \0

	j = 0;
	for (i = 0; a[i]!='\0'; i++) {
		if (a[i] == ' ') {
			flip(a, j, i - 1);
			j = i + 1;
		}
	}
	flip(a, 0, strlen(a)-2);
	printf("%s\n", a);
	// 每個單字被翻轉兩次，句子被翻轉一次
	return 0;
}

//軟體公司面試題目
/* 
不使用 scanf "%s" 讀取字串的原因是因為 scanf 讀到空白字元就會停止
用 fgets 則會讀到換行才停止
由於 fgets 會把換行字元也讀進來
所也要多一個步驟 a[strlen(a)-1] = '\0';  把換行字元去掉 
*/


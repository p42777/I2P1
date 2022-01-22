#include <stdio.h>
#define N 4

int q[N] = {0};
/*
以一維陣列表示：
q[0] = 1; (0,1)
q[1] = 3; (1,3)
q[2] = 2; (2,2)
q[3] = 0; (3,0)
q[r] = c; (row, column)
*/

void place(int row);
int valid(int row, int col);
void display(void);

int valid(int row, int col){
	int i;
	for (i = 0 ; i < row ; i++) {
		// 把把前面的row都檢查一遍：確保不能在同一個column
		if ( q[i] == col || row-i == col-q[i] || row-i == q[i]-col ){
			//在同一column或在斜的方向(正負45度)，有皇后則return 0
			// row-i == col-q[i] : 斜率 = 1
			// row-i == q[i]-col : 斜率 = -1
			return 0;
		}
	}
	return 1;
}

void display(void){
    int i, j;
    for (i = 0 ; i < N ; i++) {
	    for (j = 0 ; j < N ; j++) {
	        if (q[i] == j) {
				//代表有皇后在(i,j)的位子
				printf("@");
			}
	        else {
				printf("O");
			}
	    }
	    printf("\n");
	}
	printf("\n");
}

void place(int row){
    int j;
	if (row == N) {
		display();
	} 
	else {
		for (j = 0 ; j < N ; j++) {
			if (valid(row, j)) {
				q[row] = j; //把棋子放到(row,j)的位子
				place(row+1);
			}
		}
	}
}

int main(void){
	place(0);
	return 0;
}

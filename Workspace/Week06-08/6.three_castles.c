#include <stdio.h>

int board[5][5];
// start from row 1
void place(int row);

int valid(int row, int col){
    
	int i;
    for (i = 1 ; i < row ; i++) { //也可以由後至前：for(i = r - 1 ; i > 0 ; i--)
        if (board[i][col] != 0)
		// 檢查現在要擺的row(i)：比現在的row還小的所有row是否有人在同一個column，有的話return 0
		 return 0;
    }
    return 1;
}

void show(void){
	
	int i, j;
	for (i = 1 ; i <= 3 ; i++) {
		for (j = 1 ; j <= 3 ; j++) {
			printf(" %d", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void place(int row){
	
	int j;
	if (row > 3) {
		show();
	} 
	else {
		for (j = 1 ; j <= 3 ; j++) {
		    if (valid(row, j)) { // 檢查是否合法
			    board[row][j] = 1;
			    place(row+1); // 往下個row放棋子
			    board[row][j] = 0;
			}
		}
	}
}

int main(void){
	place(1);
	return 0;
}
/*
輸入不同面值的銅板，然後輸入一個金額
將全部可能的找零方式列出
譬如有 1 元、5元、10元銅板，要湊出 17 元
試將可能的組合表示成 "(1元個數,5元個數,10元個數)"

首先依序考慮使用 1元、5元、10元的情況
假設現在我們手邊有 amount 元需要換成銅板
從 1 元開始考慮，我們可以把問題區分成兩種可能
1. 使用 1 元，因此狀態變成手邊有 M-1 元，然後試著繼續用 1 元、5元、10元來湊
2. 完全不使用 1 元，因此狀態變成手邊還是有 M 元，但是只考慮用 5元 和 10元來湊
以上兩種可能都可以讓問題簡化
第一種是讓錢變少，另一種則是讓需要考慮的銅板面值變少
用這樣的方式繼續簡化下去，只會需要可慮幾種結束方式
1. 手邊剩下 0 元，表示成功湊出組合
2. 手邊剩下 m 元，m<0，表示這樣的組合不可能湊出需要的金額
3. 沒有任何可用的銅板面額可供組合
其餘情況就繼續遞迴
*/

#include <stdio.h>
#define MAXK 5
int values[MAXK];
int numbers[MAXK];

void show(int n);
void change(int amount, int smallest, int k);

int main(void){
	int i, k;  // k：銅板面值的個數(上限)：value[0], value[1]...value[k-1]
	int money; 
	scanf("%d", &k);
	if (k > MAXK || k < 1) {
		return 0;
	}
	for (i = 0 ; i < k ; i++) {
		scanf("%d", &values[i]); // 讀取各個銅板的面額
	}
	scanf("%d", &money);
	change(money, 0, k);
	return 0;
}

void show(int k){
	int i;
	printf("(%d", numbers[0]);
	for (i = 1 ; i < k ; i++) {
		printf(",%d", numbers[i]);
	}
	printf(")\n");
}

void change(int amount, int smallest, int k){
	int tmp;
	// 需要找開amount元，可用的銅板面值：value[0], value[1]...value[k-1]
	if (smallest < k) {
		/* 
		smallest : 0 ~ k-1 ; smallest < k : 已經沒有任何其他面值的銅板可以用
		*/
		if (amount == 0) {
			show(k);
		} 
		else if (amount > 0) {
			change(amount, smallest+1, k); 
			// 依舊amount元要找，面值：value[smallest+1]...value[k-1]
			
			tmp = numbers[smallest];

			{
			numbers[smallest]++;
			change(amount - values[smallest], smallest, k);
			// 變amount - value[smallest]元要找，面值：value[smallest]...value[k-1]
			}

			numbers[smallest] = tmp;
		}
	}
	
}

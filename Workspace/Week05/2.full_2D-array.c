#include <stdio.h>
#define MAP_SIZE 12
#define CAR_SIZE 3
/* #define ONLINE_JUDGE */

int map[MAP_SIZE][MAP_SIZE];
void map_reset(void);
void map_show(void);

int blocks[MAP_SIZE][MAP_SIZE];
void blocks_read(void);
void blocks_put_on_map(void);

int jewels[MAP_SIZE][MAP_SIZE];
void jewels_read(void);
void jewels_put_on_map(void);

int car[CAR_SIZE][CAR_SIZE] = {{'O', 'O', '@'}, {'O', 'O', 'O'}, {'O', 'O', '@'}};
int car_row = 3, car_col = 4;
int car_direction;
int car_earnings;
void car_rotate90(void);
void car_put_on_map(void);
void car_move(void);
void upgrade(void);
int speed = 1;
int valid(int,int);
void pick_jewels(int,int);


int main(void){
    int ch;
    blocks_read();
    jewels_read();

#ifndef ONLINE_JUDGE
    freopen("/Users/hsuehpo42777/vsc-C:CPP/109306061_OOP_C6/actions.txt", "r", stdin);
#endif

    while ((ch=getchar()) != EOF) {
        if (ch=='R') {
            car_rotate90();
        }
        else if (ch=='F') {
            car_move();
        }
        else{}

        map_reset();  //全部都是'.'

        blocks_put_on_map();  //放上障礙物：#
        jewels_put_on_map();  //放上寶物：$. &
        car_put_on_map();

#ifndef ONLINE_JUDGE
        map_show();
#endif
    }

    printf("Earnings: %d\n", car_earnings);
    printf("Position: row=%d, col=%d\n", car_row, car_col);

    char dirs[] = "RDLU";
    printf("Direction: %c\n", dirs[car_direction]);
    return 0;

}

void blocks_read(void){
    
    int n, i;
    int row, col;
#ifndef ONLINE_JUDGE
    freopen("/Users/hsuehpo42777/vsc-C:CPP/109306061_OOP_C6/blocks.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d%d", &row, &col);
        blocks[row][col] = 1;
    }
}

void jewels_read(void){
    
    int n, i;
    int row, col;
#ifndef ONLINE_JUDGE
    freopen("/Users/hsuehpo42777/vsc-C:CPP/109306061_OOP_C6/jewels.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d%d", &row, &col);
        jewels[row][col]++;   //同一格寶物可以不只一個
    }
}

void blocks_put_on_map(void){
    
    /* 
    把障礙物畫在地圖上：
    利用一個雙層回圈掃完block[i][j]
    如果block[i][j]!=0 (=block[i][j]=1, from blocks_read(void))
    代表有障礙物 列印＃
    */

    int i, j;
    for (i=0; i<MAP_SIZE; i++) {
        for (j=0; j<MAP_SIZE; j++) {
            if (blocks[i][j])
                map[i][j] = '#';
        }
    }
}

void jewels_put_on_map(){
    
     /* 
    把寶物畫在地圖上：
    利用一個雙層回圈掃完jewels[i][j]
    如果jewels[i][j]!=0
    代表有障礙物 列印$或＆
    */

    int i, j;
    for (i=0; i<MAP_SIZE; i++) {
        for (j=0; j<MAP_SIZE; j++) {
            if (jewels[i][j]==1){
                map[i][j] = '$';
            }
            else if(jewels[i][j]>=2){
                map[i][j] = '&';
            }
            else{}
        }
    }
}

void map_reset(void){
    /* 清除、重新整理地圖 */
    int i, j;
    for (i=0; i<MAP_SIZE; i++) {
        for (j=0; j<MAP_SIZE; j++) {
            map[i][j] = '.';
        }
    }
    /* 地圖四周畫上H作為牆壁*/
    for (i=0; i<MAP_SIZE; i++) {
        map[i][0] = 'H';
        map[i][MAP_SIZE-1] = 'H';
    }
    for (j=0; j<MAP_SIZE; j++) {
        map[0][j] = 'H';
        map[MAP_SIZE-1][j] = 'H';
    }
}

void map_show(void){
    /* 
    二維陣列把map走過一遍
    把map裡面的字一個一個show出來
    */
    int i, j;
    for (i = 0 ; i < MAP_SIZE ; i++) {
        for (j = 0 ; j < MAP_SIZE ; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void car_put_on_map(void){
    // 在3*3的範圍內畫出當時車子的樣子
    int i, j;
    for (i = 0 ; i < CAR_SIZE ; i++) {
        for (j = 0 ; j < CAR_SIZE ; j++) {
            map[i+car_row][j+car_col] = car[i][j];
        }
    }
}

void car_rotate90(void){
    /* 

    car direction : 
    0：rightwards
    1：downwards
    2：leftwards
    3：upwards

    00@                            000
    000  car direction == 0        000  car direction == 1 
    00@                            @0@

    @00                            @0@
    000  car direction == 2        000  car direction == 3 
    @00                            000 

    */
    int tmp;
    if(car_direction%2){
        //car direction為奇數：交換[0][0] <-> [2][2]
        tmp = car[0][0]; //tmp儲存car[0][0]，才可以安心地被蓋掉
        car[0][0] = car[2][2]; //cover
        car[2][2] = tmp; //再拿暫存器tmp把car[2][2]蓋掉，達成swap、車頭轉向
    }
    else{
        //car direction為偶數：交換[2][0] <-> [0][2]
        tmp = car[2][0];
        car[2][0] = car[0][2];
        car[0][2] = tmp;
    }
    car_direction = (car_direction+1)%4;
}

int valid (int r, int c){
    int i, j;
    for (i = 0 ; i < CAR_SIZE ; i++) {
		for (j = 0 ; j < CAR_SIZE ; j++) {
            if (blocks[r+i][c+j] != 0 || map[r+i][c+j] != 'H') {
                // 撞到牆壁(H)或障礙物(blocks[i][j]!=0)
                return 0;
            }
        }
    }
    return 1;
            
}

void pick_jewels(int r, int c){
    int i, j;
    for (i=0; i<CAR_SIZE; i++) {
		for (j=0; j<CAR_SIZE; j++) {
			if (jewels[r+i][c+j]>0){
			jewels[r+i][c+j]--;
			car_earnings++;
			}
		}
	}
}

void upgrade(void){
    int i, j;
    for (i=0; i<CAR_SIZE; i++) {
		for (j=0; j<CAR_SIZE; j++) {
            if(car[i][j]=='@'){
                car[i][j] = '*';
            }
            if(car[i][j]=='O'){
                car[i][j] = '0';
            }
        }
    }
    speed = 2;
}

void car_move(void){
    int i, j, valid;
	int car_row_new;
	int car_col_new;
	int diff_row[4] = {0, 1, 0, -1};
	int diff_col[4] = {1, 0, -1, 0};
    /*
    描述移動時row跟column的變化 (利用查表取代條件判斷)
    car direction : 0 (right) row不變，column+1
    car direction : 1 (down)  row +1，column不變
    car direction : 2 (left)  row不變，column-1
    car direction : 3 (up)    row-1，column不變
    */
	car_row_new = car_row + speed*diff_row[car_direction];
	car_col_new = car_col + speed*diff_col[car_direction];
    if(valid){
        car_row = car_row_new;
		car_col = car_col_new;
    }
    pick_jewels(car_row,car_col);
    if(car_earnings >= 5){
        car_earnings = car_earnings - 5;
        upgrade();

    }
}


/*
其中 #define ONLINE_JUDGE 
如果將註解移除
資料的輸入來源和輸出形式就會針對 ONLINE_JUDGE
如果保持註解狀態
則可以在自己的電腦上執行

map 是一個二維陣列
用來表示地圖的內容
map_reset() 的作用是清除地圖內容以及重設邊界
map_show() 則是把 map 的內容顯示到螢幕上

blocks 也是二維陣列
記錄磚牆的位置
會透過 blocks_read() 從檔案 blocks.txt 中讀取位置資訊
然後用 blocks_put_on_map() 在地圖 map 裡面的對應位置放置磚牆
磚牆是固定的
車子前進時如果遇到磚牆會被擋住

blocks.txt 的內容如下
4
2 2
9 9
9 2
2 9

jewels 二維陣列記錄寶物的位置
會藉由 jewels_read() 從檔案 jewels.txt 中讀取位置資訊
然後用 jewels_put_on_map() 在地圖 map 裡面的對應位置放置寶物
車子前進時如果遇到寶物就會撿起來

jewels.txt 內容如下
5
2 5
2 7
8 8
9 5
10 4

car 二維陣列記錄車子的外觀 @ @ 表示車頭方向
車子的起始位置是 (row: 3, column: 4)
用來記錄車子目前位置的變數是 car_row 和 car_col
車子的方向則是由 car_direction 表示
我們可以讓可以用 0, 1, 2, 3 來分別代表車子朝向 右、下、左、上
所以如果 car_direction 的值等於 2 表示車子目前朝左
car_earnings 則是記錄撿到的寶物數量

需要自行完成的函數是
car_rotate90() 和 car_move()
car_rotate90() 要將 car 二維陣列順時鐘旋轉 90 度
並且更新 car_direction 的值 讓它符合目前方向

car_move() 則要將 car 依照目前方向
向前移動一格
在移動之前必須先判斷是否會被磚牆擋住
也不能超出 map 原本的外牆
移動之後
要將碰到的寶物撿起來 (撿走之後就沒了  不能重複撿)

車子的移動是根據 action.txt 的指示
只有兩種動作
'R' 代表順時鐘旋轉九十度
'F' 代表前進一格
做完全部的動作之後
最後要輸出車子目前的狀態 */

/*
[註]
範例程式裡
#ifndef ONLINE_JUDGE
freopen("jewels.txt", "r", stdin);
#endif
和 #include 和 #define 一樣
都屬於 preprocessor directives
在程式碼被編譯之前會先做的前處理
#ifndef ONLINE_JUDGE 的作用是根據 ONLINE_JUDGE 是否被定義
決定是否要呼叫 freopen("jewels.txt", "r", stdin);
如果沒有被定義就會呼叫
反之
如果已經定義則不呼叫
(#ifndef 的字面意思可以想成是 if not defined)

這個技巧對於做 online judge 題目很有用
我們可以先將標準鍵盤輸入 stdin 導向為文字檔
文字檔裡面先填好要測試的資料
這樣就不用每次都重複輸入
等到真的要上傳的時候
就把程式碼最開頭的   #define ONLINE_JUDGE 
註解去掉變成
#define ONLINE_JUDGE
這樣由於 ONLINE_JUDGE 被定義了
所以 ifndef 條件不成立
不會呼叫 freopen()
標準輸入 stdin 的來源就會交給 Online Judge 系統決定  */
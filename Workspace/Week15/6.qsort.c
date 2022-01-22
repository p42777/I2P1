#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // 用於time_t & clock() & CLOCKS_PER_SEC
#define SIZE 50000

void qqsort(void * a, size_t num, size_t width, int (*f)(void *, void *) );

typedef struct {
	int x;
	int a[9];
} Type;

int cmp(void * a, void * b){ 
	Type *pa = (Type *) a;
	Type *pb = (Type *) b;
	if (pa->x > pb->x) {
        return -1;
    }
    else if (pa->x < pb->x) {
        return 1;
    }
	else {
        return 0;
    }
}

int main(void){
	
	Type *b;
	int i;
	time_t start, end;

	b = (Type *) malloc(sizeof(Type) * SIZE);

	for (i = 0 ; i < SIZE ; i++) {
		b[i].x =  rand();
	}

	printf("before sorting\n");

	for (i = 0 ; i < SIZE ; i++) {
        printf("%d\n", b[i].x);
    }
	start = clock();
	qqsort(b, SIZE, sizeof(Type), cmp);
	end = clock();

	printf("after sorting\n");

	for (i=0; i<SIZE; i++) {
        printf("%d\n", b[i].x);
    }

	printf("%f\n", (double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}

void qqsort(void * a, size_t num, size_t width, int (*f)(void *, void *) ){
	
	char * b = (char *) a;
	char *tmp;
	int mini;
	tmp = (char*) malloc(width);

	int i, j, k;
	// Selection Sort: 每次找最小的放在目前已排序完成放在目前已排序完成的陣列的最後面 ( Time Complexity: 1/2[n(n-1)], O(n平方) )
	for (i = 0 ; i < num ; i++) {
		mini = i;
		for (j = i + 1 ; j < num ; j++) {
			if ( f(b + mini * width, b + j * width) > 0 ) {
				// check whether cmp > 0
				mini = j; // 找最小的 (從i+1到num，看是否有元素比i小，若有則調換)
			}
		}
		if (mini != i) {

			memcpy(tmp, b + i * width, width);
            /*
            tmp |        |
            b          i * wd           v
            | | | | | | | | | | | | | | | | | | | | | | | | | | | | |...
            |Type         |Type         |Type         |Type         |...
            */
			memcpy(b + i *  width, b + mini * width, width);
			memcpy(b + mini * width, tmp, width); //swap
		}
	}

	free(tmp);
}

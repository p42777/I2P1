#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int cmp(const void*, const void*);

typedef struct {
	int x;
	int y;
	double speed;
} Car;



void showcar(Car * pc){
	printf("%d %d %lf\n", pc->x, pc->y , pc->speed);
}

int main(void){
	
	int i;
	Car * cars;
	Car * ptrs[100];

	cars = (Car*) malloc(100*sizeof(Car));
	for (i=0; i<100; i++) {
		cars[i].x = rand()%1000;
		cars[i].y = rand()%1000;
		cars[i].speed = 300*(double)rand()/RAND_MAX;
	}
	for (i=0; i<100; i++)
		ptrs[i] = &cars[i];

	for (i=0; i<100; i++) {
		showcar(ptrs[i]);
	}
	qsort(ptrs, 100, sizeof(Car*), cmp);
	// qsort(cars, 100, sizeof(Car), cmp2);

	/*
	cars 
				   Car* va =                   Cars* vb =
	               &cars[i]                    &cars[j]
	| Car : speed | Car : speed | Car : speed | Car : speed |...

	ptrs
				   Car ** pa =                 Car ** pb =
				   void* a =                   void* b =
				   &ptrs[i]                    &ptrs[j]
	|   &cars[0]  |   &cars[1]  |   &cars[2]  |   &cars[3]  |...
				   (*pa)->speed
				  = (*(*pa)).speed
	*/

	printf("===============\n");
	for (i=0; i<100; i++) {
		showcar(ptrs[i]);
	}

	printf("***************\n");
	for (i=0; i<100; i++) {
		showcar(&cars[i]);
	}

	
    return 0;
}

int cmp(const void* a, const void* b){
	
	Car* * pa = (Car **) a;
	Car* * pb = (Car **) b;
	if ( (*pa)->speed > (*pb)->speed) return 1;
	// (*pa) = ptrs[i] (記憶體位址) 再用->連開兩道門
	else if ((*pa)->speed < (*pb)->speed) return -1;
	else return 0;	
}

int cmp2(const void* a, const void* b){
	
	Car * va = (Car *) a;
	Car * vb = (Car *) b;
	if ( va->speed > (*vb).speed) return 1;
	else if ((*va).speed < vb->speed) return -1;
	else return 0;	
}
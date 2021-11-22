#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct {
	int x;
	int y;
	double speed;
} Car;

int cmp(const void*, const void*);

void showcar(Car * pc)
{
	printf("%d %d %lf\n", pc->x, pc->y , pc->speed);
}
int main(void)
{
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

int cmp(const void* a, const void* b)
{
	Car* * pa = (Car **) a;
	Car* * pb = (Car **) b;
	if ( (*pa)->speed > (*pb)->speed) return 1;
	else if ((*pa)->speed < (*pb)->speed) return -1;
	else return 0;	
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 2

void main() {
	int a[200 + 1];

	int x = 10;
	int y = 20;
	int* p = &x;
	int* q = &y;

	printf("%d", ++x);
	printf("%d", --(*p));
	printf("%d", (*q)++);
}
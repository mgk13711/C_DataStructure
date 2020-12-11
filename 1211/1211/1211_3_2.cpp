#include<stdio.h>
void swap(int* a, int* b) {
	int* tmp = a;
	a = b;
	b = tmp;
}
void main() {
	int a = 10;
	int b = 20;
	printf("a = %d, b = %d\n", a, b);

	swap(&a, &b);

	printf("a = %d, b = %d\n", a, b);
}
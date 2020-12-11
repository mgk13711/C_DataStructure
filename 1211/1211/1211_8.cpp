#include<stdio.h>
#include<stdlib.h>
void main() {
	int n = 3;
	int* arr = (int*)calloc(n, sizeof(int));
	// malloc와 다르게 0이 초기화되어 있다

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	free(arr);
}
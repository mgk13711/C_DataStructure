#include<stdio.h>
#include<stdlib.h>
void main() {
	int n = 3;
	int* arr = (int*)calloc(n, sizeof(int));
	// malloc�� �ٸ��� 0�� �ʱ�ȭ�Ǿ� �ִ�

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	free(arr);
}
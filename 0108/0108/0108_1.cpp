//버블 정렬 sorting: 01 12 23 34 ... 01 12 23 34
#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int* arr, int len) {
	// arr == &arr[0]
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
void main() {
	//1) 버블정렬
	//2) 삽입정렬
	//3) 선택정렬
	//4) 퀵 정렬

	int arr[5];

	for (int i = 0; i < 5; i++) {
		arr[i] = rand() % 100 + 1;
	}

	printf("정렬 전: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	bubble_sort(arr, 5);

	printf("정렬 후: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
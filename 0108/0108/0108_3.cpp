//선택 정렬 sorting: 제일 작은애를 찾아서 바꾸고, 그다음 진행
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selection_sort(int* arr, int len) {
	// arr == &arr[0]
	for (int i = 0; i < len; i++) {
		int min = arr[i];
		int minIndex = i;
		for (int j = i; j < len; j++) {
			if (arr[j] < min) {
				min = arr[j];
				minIndex = j;
			}
		}// finding minimum value
		int tmp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = tmp;
	}
}
void main() {
	//1) 버블정렬
	//2) 삽입정렬
	//3) 선택정렬
	//4) 퀵 정렬

	int arr[5];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++) {
		arr[i] = rand() % 100 + 1;
	}

	printf("정렬 전: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	selection_sort(arr, 5);

	printf("정렬 후: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
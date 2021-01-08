//삽입 정렬 sorting: 01 02 12 03 13 23 04 ... 순으로 비교 및 바꾸기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertion_sort(int* arr, int len) {
	// arr == &arr[0]
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
			printf("(j i):(%d %d) [ ", j, i);
			for (int k = 0; k < len; k++) {
				printf("%d ", arr[k]);
			}
			printf(" ]\n");
		}
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

	insertion_sort(arr, 5);

	printf("정렬 후: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
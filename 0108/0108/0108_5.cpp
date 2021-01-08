// 탐색, 검색, Search
// 정렬은 탐색을 하기위해 한것
// 이진탐색 == 이분탐색
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int* arr, int R, int L) {
	int tmp = arr[R];
	arr[R] = arr[L];
	arr[L] = tmp;
}
void quick_sort(int* data, int start, int end) {
	int pivot = data[start];
	int L = start + 1;
	int R = end;
	while (L <= R) {
		while (data[L] < pivot) {
			L++;
		}
		while (data[R] > pivot) {
			R--;
		}
		if (L <= R) {
			swap(data, L, R);
		}

	}
	if (start < end) {
		swap(data, start, R); // cross발생하면 피벗<->R 교환
		quick_sort(data, start, R - 1);
		quick_sort(data, R + 1, end);
	}

}
int binarySearch(int* arr, int len, int value){
	int left=0;
	int right=len-1;
	int middle=(left+right)/2;

	while (left <= right) {
		printf("현재 middle %d\n", middle);
		
		if (arr[middle] == value) {
			return middle;
		}

		if (arr[middle] >= value) {
			right = middle-1;
		}
		else if (arr[middle] < value) {
			left = middle+1;
		}
		middle = (right + left) / 2;		
	}
	return -1;
	}
void main() {
	int arr[20];
	int len = 20;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 1000 + 1;
	}

	quick_sort(arr, 0, len-1);

	printf("정렬 후: ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("찾으실 숫자를 입력: ");
	int value;
	scanf("%d", &value);

	int result = binarySearch(arr, len, value);
	if (result == -1) {
		printf("%d를 찾을 수 없습니다.", value);
	}
	else {
		printf("찾으시는 값은 %d입니다. arr[%d]에 있습니다.", value, result);
	}
}
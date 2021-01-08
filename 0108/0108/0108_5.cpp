// Ž��, �˻�, Search
// ������ Ž���� �ϱ����� �Ѱ�
// ����Ž�� == �̺�Ž��
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
		swap(data, start, R); // cross�߻��ϸ� �ǹ�<->R ��ȯ
		quick_sort(data, start, R - 1);
		quick_sort(data, R + 1, end);
	}

}
int binarySearch(int* arr, int len, int value){
	int left=0;
	int right=len-1;
	int middle=(left+right)/2;

	while (left <= right) {
		printf("���� middle %d\n", middle);
		
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

	printf("���� ��: ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("ã���� ���ڸ� �Է�: ");
	int value;
	scanf("%d", &value);

	int result = binarySearch(arr, len, value);
	if (result == -1) {
		printf("%d�� ã�� �� �����ϴ�.", value);
	}
	else {
		printf("ã���ô� ���� %d�Դϴ�. arr[%d]�� �ֽ��ϴ�.", value, result);
	}
}
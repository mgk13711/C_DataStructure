//���� ���� sorting: 01 02 12 03 13 23 04 ... ������ �� �� �ٲٱ�
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
	//1) ��������
	//2) ��������
	//3) ��������
	//4) �� ����

	int arr[5];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++) {
		arr[i] = rand() % 100 + 1;
	}

	printf("���� ��: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	insertion_sort(arr, 5);

	printf("���� ��: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
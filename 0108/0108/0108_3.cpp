//���� ���� sorting: ���� �����ָ� ã�Ƽ� �ٲٰ�, �״��� ����
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

	selection_sort(arr, 5);

	printf("���� ��: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
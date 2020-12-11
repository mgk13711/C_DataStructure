//1. ������ �Ѱ� �Է¹޾�
//2. main()�� 1���� �Է��� ����(int)��ŭ�� �迭������ ����
//3. 2���� �迭�� ���� ���� �Է�(scanf)
//4. �ش� �迭 ���, ����, ���(�Ҽ��� ��°�ڸ�) ���

#include<stdio.h>
#include<stdlib.h>

void show(int* arr, int N) {
	printf("[ ");
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

int show_sum(int* arr, int N) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}
	return sum;
}

void show_avg(int* arr, int N) {
	double avg = 0;
	int sum = show_sum(arr, N);

	avg = (double)sum / N;
	printf("���: %.2lf\n", avg);
}

void main() {
	int N;
	printf("�迭�� ũ�� �����Է�: ");
	scanf("%d", &N);

	int* arr = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++) {
		printf("%d��° �� �Է�: ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("\n\n");

	show(arr, N);
	printf("�հ�: %d\n", show_sum(arr, N));
	show_avg(arr, N);

	free(arr);
}
#include<stdio.h>
#include<stdlib.h>

//�迭�� ������ Ÿ������ ���α׷� �������� ũ�Ⱑ �����Ǿ�� �Ѵ�
// �迭�� �������� �Ҵ�
// -> ���� �޸� �Ҵ� or ���� �迭 ����

void show(int* arr, int len) {
	printf("[ ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n\n");

}

void main() {
	int N;
	printf("�����Է�: ");
	scanf("%d", &N);

	int* arr = (int*)malloc(N * sizeof(int));
	//N�� ��ŭ�� intũ�� ������ ����� int* ���·� ����ȯ(type casting)�Ͽ� int*�� �ִ´�

	for (int i = 0; i < N; i++) {
		printf("%d��° �����Է�: ", i + 1);
		scanf("%d", &arr[i]);
	}

	show(arr, N);

	free(arr); // �����޸� �ݳ�(����)
}
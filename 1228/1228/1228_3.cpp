// ���� 1�� �Է� : 10
// 1~10���� �Է� / 0: ������ϻ�����(==�������)
// 5 6 1 0 10 2 0 0 0 7
// [5 7] -> 12��

// ���� 1�� �Է�: 6
// 10 9 0 1 2 0
// [10 1] -> 11��
#include<stdio.h>
#include<stdlib.h>
void main() {
	int N, num;
	printf("���� 1�� �Է�: ");
	scanf("%d", &N);
	int* data = (int*)malloc(N * sizeof(N)); // ����
	int index = 0; // level
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num) {
			// push();
			data[index++] = num;
		}
		else {
			// pop();
			index--;
		}
	}
	int sum = 0;
	for (int i = 0; i < index; i++) {
		sum += data[i];
	}
	printf("%d��\n\n", sum);
}
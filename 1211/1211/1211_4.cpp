#include<stdio.h>
#define MAX 5 // ��ȣ���== ����� ���� ���
void show(int* arr) {
	//�迭 ���� ����ϴ� �Լ�
	for (int i = 0; i < MAX; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

void main() {
	/*
	int MAX;

	printf("�迭 ũ�� �Է�: ");
	scanf("%d", &MAX);
	*/
	int arr[MAX];
	//�迭�� ũ��� ���α׷��� ����Ǳ� ���� �����Ǿ���Ѵ�

	for (int i = 0; i < MAX; i++) {
		printf("%d��° �迭�� �Է�: ", i+1);
		scanf("%d", &arr[i]);
	}
	show(arr);

}
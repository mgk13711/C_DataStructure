#include<stdio.h>
#include<stdlib.h>
void push(int* stack, int index, int data) { // call by value
	stack[index] = data;
}
int isFull(int index, int MAX) {
	if (index == MAX) { // �ڵ����ǥ �׸���!
		return 1;
	}
	return 0;
}
int isEmpty(int index) {
	if (index == 0) {
		return 1;
	}
	return 0;
}
int pop(int* stack, int index) {
	return stack[index];
}
int size(int index) {
	return index;
}
void main() {

	int N;
	printf("������ ũ�⸦ �Է��ϼ���.  ");
	scanf("%d", &N);
	int* stack = (int*)malloc(N * sizeof(int));
	int index = 0; // ��

	printf("===���� ���α׷�===\n");
	int act;
	while (1) {
		printf("1.push() 2.pop() 3.peek() 4.size() 5.����\n");
		printf("�Է�: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull(index, N)) {
				printf("���ÿ� �����Ͱ� �������� �ԷºҰ���!\n");
				continue;
			}
			int data;
			printf("�������Է�: ");
			scanf("%d", &data);
			push(stack, index++, data);
		}
		else if (act == 2) {
			if (isEmpty(index)) {
				printf("���ÿ� �����Ͱ� ��� ��ºҰ���!\n");
				continue;
			}
			printf("pop(): %d\n", pop(stack, --index));
		}
		else if (act == 3) {
			if (isEmpty(index)) {
				printf("���ÿ� �����Ͱ� ��� ��ºҰ���!\n");
				continue;
			}
			printf("peek(): %d\n", pop(stack, index - 1));
		}
		else if (act == 4) {
			printf("���� ���ÿ� %d���� ����������!\n", size(index));
		}
		else if (act == 5) {
			printf("���α׷� ����...\n");
			break;
		}
		else {
			printf("�߸��� �Է��Դϴ�!\n");
			printf("�ٽ� �Է��غ�����!~~\n\n");
		}
	}

	free(stack);
}
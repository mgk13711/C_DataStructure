// [����] vs [ť]
// stack: �Ա��� 1������ ��������. ���ʳ������� ������ ����°���. ���Լ���==LIFO==FILO
// '�迭'�� ����! -> ũ�� ����
// EX) �������, �ֱ� �湮�� ��������

// queue: �Ա��� �ⱸ�� ������ ��������. ���Լ���==FIFO==LILO
// '�迭' -> '����Ʈ'
// EX) �ð� ���� ó��, ��⿭, ������û, Ƽ����, ���μ��� ����
#include<stdio.h>
#define MAX 3
// push(),pop(),isFull(),isEmpty()
int stack[MAX]; // ���α׷� ����~������� ����̿�. �Լ����� ���ڷ� �̿� -> ���������� ����
int index = -1; // level�� ��Ÿ�� ����
void push(int data) {
	// data�� stack[]�迭�� ����
	stack[++index] = data;
}
int isFull() {
	if (index == MAX - 1) { // "���ÿ� �����Ͱ� ����á�ٸ�,". �ڵ����ǥ �׸���!
		return 1; // T
	}
	return 0; // F
}
int isEmpty() {
	if (index == -1) {
		return 1;
	}
	return 0;
}
int pop() {
	return stack[index--];
}
int peek() {
	return stack[index];
}
int size() {
	return index + 1;
}
void main() {

	printf("===���� ���α׷�===\n");
	int act;
	while (1) {
		printf("1.push() 2.pop() 3.peek() 4.size() 5.����\n");
		// pop(): ������ ������ ���
		// peek()==top(): ������ �����ʴ� ���
		printf("�Է�: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull()) {
				printf("���ÿ� �����Ͱ� �������� �ԷºҰ���!\n");
				continue; // ���� �� ����
			}
			int data;
			printf("�������Է�: ");
			scanf("%d", &data);
			push(data);
		}
		else if (act == 2) {
			if (isEmpty()) {
				printf("���ÿ� �����Ͱ� ��� ��ºҰ���!\n");
				continue;
			}
			printf("pop(): %d\n", pop());
		}
		else if (act == 3) {
			if (isEmpty()) {
				printf("���ÿ� �����Ͱ� ��� ��ºҰ���!\n");
				continue;
			}
			printf("peek(): %d\n", peek());
		}
		else if (act == 4) {
			printf("���� ���ÿ� %d���� ����������!\n", size());
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



}
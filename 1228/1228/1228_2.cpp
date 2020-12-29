#include<stdio.h>
#include<stdlib.h>
void push(int* stack, int index, int data) { // call by value
	stack[index] = data;
}
int isFull(int index, int MAX) {
	if (index == MAX) { // ★디버깅표 그리기!
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
	printf("스택의 크기를 입력하세요.  ");
	scanf("%d", &N);
	int* stack = (int*)malloc(N * sizeof(int));
	int index = 0; // ☆

	printf("===스택 프로그램===\n");
	int act;
	while (1) {
		printf("1.push() 2.pop() 3.peek() 4.size() 5.종료\n");
		printf("입력: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull(index, N)) {
				printf("스택에 데이터가 가득차서 입력불가능!\n");
				continue;
			}
			int data;
			printf("데이터입력: ");
			scanf("%d", &data);
			push(stack, index++, data);
		}
		else if (act == 2) {
			if (isEmpty(index)) {
				printf("스택에 데이터가 없어서 출력불가능!\n");
				continue;
			}
			printf("pop(): %d\n", pop(stack, --index));
		}
		else if (act == 3) {
			if (isEmpty(index)) {
				printf("스택에 데이터가 없어서 출력불가능!\n");
				continue;
			}
			printf("peek(): %d\n", pop(stack, index - 1));
		}
		else if (act == 4) {
			printf("현재 스택에 %d개의 데이터존재!\n", size(index));
		}
		else if (act == 5) {
			printf("프로그램 종료...\n");
			break;
		}
		else {
			printf("잘못된 입력입니다!\n");
			printf("다시 입력해보세요!~~\n\n");
		}
	}

	free(stack);
}
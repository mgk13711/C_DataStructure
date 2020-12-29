// [스택] vs [큐]
// stack: 입구가 1개뿐인 선형구조. 한쪽끝에서만 데이터 입출력가능. 후입선출==LIFO==FILO
// '배열'로 구현! -> 크기 제한
// EX) 실행취소, 최근 방문한 웹페이지

// queue: 입구와 출구가 정해진 선형구조. 선입선출==FIFO==LILO
// '배열' -> '리스트'
// EX) 시간 순서 처리, 대기열, 수강신청, 티켓팅, 프로세스 관리
#include<stdio.h>
#define MAX 3
// push(),pop(),isFull(),isEmpty()
int stack[MAX]; // 프로그램 생성~종료까지 계속이용. 함수에서 인자로 이용 -> 전역변수로 선언
int index = -1; // level를 나타낼 변수
void push(int data) {
	// data를 stack[]배열에 저장
	stack[++index] = data;
}
int isFull() {
	if (index == MAX - 1) { // "스택에 데이터가 가득찼다면,". ★디버깅표 그리기!
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

	printf("===스택 프로그램===\n");
	int act;
	while (1) {
		printf("1.push() 2.pop() 3.peek() 4.size() 5.종료\n");
		// pop(): 삭제를 동반한 출력
		// peek()==top(): 삭제를 하지않는 출력
		printf("입력: ");
		scanf("%d", &act);
		if (act == 1) {
			if (isFull()) {
				printf("스택에 데이터가 가득차서 입력불가능!\n");
				continue; // 유지 및 보수
			}
			int data;
			printf("데이터입력: ");
			scanf("%d", &data);
			push(data);
		}
		else if (act == 2) {
			if (isEmpty()) {
				printf("스택에 데이터가 없어서 출력불가능!\n");
				continue;
			}
			printf("pop(): %d\n", pop());
		}
		else if (act == 3) {
			if (isEmpty()) {
				printf("스택에 데이터가 없어서 출력불가능!\n");
				continue;
			}
			printf("peek(): %d\n", peek());
		}
		else if (act == 4) {
			printf("현재 스택에 %d개의 데이터존재!\n", size());
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



}
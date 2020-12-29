// 정수 1개 입력 : 10
// 1~10까지 입력 / 0: 이전기록삭제☆(==실행취소)
// 5 6 1 0 10 2 0 0 0 7
// [5 7] -> 12점

// 정수 1개 입력: 6
// 10 9 0 1 2 0
// [10 1] -> 11점
#include<stdio.h>
#include<stdlib.h>
void main() {
	int N, num;
	printf("정수 1개 입력: ");
	scanf("%d", &N);
	int* data = (int*)malloc(N * sizeof(N)); // 스택
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
	printf("%d점\n\n", sum);
}
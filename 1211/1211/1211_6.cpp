#include<stdio.h>
#include<stdlib.h>

//배열은 정적인 타입으로 프로그램 실행전에 크기가 결정되어야 한다
// 배열을 동적으로 할당
// -> 동적 메모리 할당 or 동적 배열 생성

void show(int* arr, int len) {
	printf("[ ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n\n");

}

void main() {
	int N;
	printf("정수입력: ");
	scanf("%d", &N);

	int* arr = (int*)malloc(N * sizeof(int));
	//N개 만큼의 int크기 공간을 만들어 int* 형태로 형변환(type casting)하여 int*에 넣는다

	for (int i = 0; i < N; i++) {
		printf("%d번째 정수입력: ", i + 1);
		scanf("%d", &arr[i]);
	}

	show(arr, N);

	free(arr); // 동적메모리 반납(해제)
}
#include<stdio.h>
#define MAX 5 // 기호상수== 사용자 정의 상수
void show(int* arr) {
	//배열 값을 출력하는 함수
	for (int i = 0; i < MAX; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

void main() {
	/*
	int MAX;

	printf("배열 크기 입력: ");
	scanf("%d", &MAX);
	*/
	int arr[MAX];
	//배열의 크기는 프로그램이 실행되기 전에 결정되어야한다

	for (int i = 0; i < MAX; i++) {
		printf("%d번째 배열값 입력: ", i+1);
		scanf("%d", &arr[i]);
	}
	show(arr);

}
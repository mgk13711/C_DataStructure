/*
main()에서 정수 1개 입력: 5
5개의 실수 데이터를 저장할 공간 생성
실수 데이터 입력

ch()함수 구현
>>배열을 1개 입력받아, 데이터들을 절대값으로 바꿔주는 함수

*/

#include<stdio.h>
#include<stdlib.h>

void ch(double* arr, int n) {
	
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 0);
		else 
			arr[i] = -arr[i];
	}
}

void main() {
	int n;
	
	printf("정수를 입력:");
	scanf("%d", &n);

	double* arr = (double*)malloc(n * sizeof(double));

	for (int i = 0; i < n; i++) {
		printf("%d번째 입력:", i + 1);
		scanf("%lf", &arr[i]);
	}

	printf("ch()호출 전 [ ");
	for (int i = 0; i < n; i++) {
		printf("%.1lf ", arr[i]);
	}
	printf(" ]\n");

	ch(arr, n);

	printf("ch()호출 후[ ");
	for (int i = 0; i < n; i++) {
		printf("%.1lf ", arr[i]);
	}
	printf(" ]\n");

}
//1. 정수를 한개 입력받아
//2. main()에 1에서 입력한 정수(int)만큼의 배열공간이 생성
//3. 2번의 배열에 정수 값을 입력(scanf)
//4. 해당 배열 출력, 총합, 평균(소수점 둘째자리) 출력

#include<stdio.h>
#include<stdlib.h>

void show(int* arr, int N) {
	printf("[ ");
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

int show_sum(int* arr, int N) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}
	return sum;
}

void show_avg(int* arr, int N) {
	double avg = 0;
	int sum = show_sum(arr, N);

	avg = (double)sum / N;
	printf("평균: %.2lf\n", avg);
}

void main() {
	int N;
	printf("배열의 크기 정수입력: ");
	scanf("%d", &N);

	int* arr = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++) {
		printf("%d번째 값 입력: ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("\n\n");

	show(arr, N);
	printf("합계: %d\n", show_sum(arr, N));
	show_avg(arr, N);

	free(arr);
}
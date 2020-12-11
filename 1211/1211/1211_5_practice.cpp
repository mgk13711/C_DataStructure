// main()에서 10개의 정수를 저장하고 있는 배열을 1개 생성
// 배열의 값들은 모두 랜덤 대입
// search()함수 만들어서 main()의 배열 안에서 큰 값을 출력해준다.

#include<stdio.h>
#include<stdlib.h> //rand()를 사용하기 위해 추가
#include<time.h>

int search(int* arr, int len) {
	int max=arr[0];
	for (int i = 1; i < len; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

void main() {
	int arr[10];
	int len = 10;
	//printf("%d", arr[2]);

	srand(time(NULL)); // rand()가 매번 다르게 나오도록 하기위한 함수 부분

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 10 + 1; // 1~10 랜덤 값 생성
	}

	printf("max value in arr array is %d\n", search(arr, sizeof(arr)/sizeof(arr[0])));

}
//퀵 정렬 sorting: 분할(divide) -> 정복(conquer)
/*
* [pivot 피벗] : 기준
* 
*/
/*
   [3] 5 7 9 1 10 6 2 8 4
   L            R
   L: 피벗보다 작은 데이터들만 존재가능
   R: 피벗보다 큰 데이터들만 존재가능
   L,R을 swap()
   -> cross발생할때까지 계속 진행
   => 피벗과 R을 swap()

   퀵(피벗의 왼쪽 데이터들)
   퀵(피벗의 오른쪽 데이터들)
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int* arr, int R, int L) {
	int tmp = arr[R];
	arr[R] = arr[L];
	arr[L] = tmp;
}
void quick_sort(int* data, int start, int end) {
	int pivot = data[start];
	int L = start + 1;
	int R = end;
	while (L <= R) {
		while (data[L] < pivot) {
			L++;
		}
		while (data[R] > pivot) {
			R--;
		}
		if (L <= R) {
			swap(data, L, R);
		}
		
	}
	if (start < end) {
		swap(data, start, R); // cross발생하면 피벗<->R 교환
		quick_sort(data, start, R - 1);
		quick_sort(data, R + 1, end);
	}

}

void main() {
	//1) 버블정렬
	//2) 삽입정렬
	//3) 선택정렬
	//4) 퀵 정렬

	int arr[10] = {3, 5, 7, 9, 1, 10, 6, 2, 8, 4};
	int len = 10;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 100 + 1;
	}

	printf("정렬 전: ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	quick_sort(arr, 0, 9);

	printf("정렬 후: ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
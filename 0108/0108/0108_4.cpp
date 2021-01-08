//�� ���� sorting: ����(divide) -> ����(conquer)
/*
* [pivot �ǹ�] : ����
* 
*/
/*
   [3] 5 7 9 1 10 6 2 8 4
   L            R
   L: �ǹ����� ���� �����͵鸸 ���簡��
   R: �ǹ����� ū �����͵鸸 ���簡��
   L,R�� swap()
   -> cross�߻��Ҷ����� ��� ����
   => �ǹ��� R�� swap()

   ��(�ǹ��� ���� �����͵�)
   ��(�ǹ��� ������ �����͵�)
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
		swap(data, start, R); // cross�߻��ϸ� �ǹ�<->R ��ȯ
		quick_sort(data, start, R - 1);
		quick_sort(data, R + 1, end);
	}

}

void main() {
	//1) ��������
	//2) ��������
	//3) ��������
	//4) �� ����

	int arr[10] = {3, 5, 7, 9, 1, 10, 6, 2, 8, 4};
	int len = 10;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 100 + 1;
	}

	printf("���� ��: ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	quick_sort(arr, 0, 9);

	printf("���� ��: ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
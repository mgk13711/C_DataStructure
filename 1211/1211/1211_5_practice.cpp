// main()���� 10���� ������ �����ϰ� �ִ� �迭�� 1�� ����
// �迭�� ������ ��� ���� ����
// search()�Լ� ���� main()�� �迭 �ȿ��� ū ���� ������ش�.

#include<stdio.h>
#include<stdlib.h> //rand()�� ����ϱ� ���� �߰�
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

	srand(time(NULL)); // rand()�� �Ź� �ٸ��� �������� �ϱ����� �Լ� �κ�

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 10 + 1; // 1~10 ���� �� ����
	}

	printf("max value in arr array is %d\n", search(arr, sizeof(arr)/sizeof(arr[0])));

}
/*
main()���� ���� 1�� �Է�: 5
5���� �Ǽ� �����͸� ������ ���� ����
�Ǽ� ������ �Է�

ch()�Լ� ����
>>�迭�� 1�� �Է¹޾�, �����͵��� ���밪���� �ٲ��ִ� �Լ�

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
	
	printf("������ �Է�:");
	scanf("%d", &n);

	double* arr = (double*)malloc(n * sizeof(double));

	for (int i = 0; i < n; i++) {
		printf("%d��° �Է�:", i + 1);
		scanf("%lf", &arr[i]);
	}

	printf("ch()ȣ�� �� [ ");
	for (int i = 0; i < n; i++) {
		printf("%.1lf ", arr[i]);
	}
	printf(" ]\n");

	ch(arr, n);

	printf("ch()ȣ�� ��[ ");
	for (int i = 0; i < n; i++) {
		printf("%.1lf ", arr[i]);
	}
	printf(" ]\n");

}
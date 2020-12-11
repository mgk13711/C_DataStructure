#define _CRT_SECURE_NO_WARNINGS
// 전처리기에 넣음 _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

int f1() {
	int num;
	printf("정수입력");
	scanf("%d", &num);
	return num;
}

int f2(int a, int b) {
	return a + b;
}


int main() {

	int a = f1();
	int b = f1();

	printf("%d + %d = %d\n", a, b, f2(a, b));

}
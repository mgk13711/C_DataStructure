#include<stdio.h>
int func(int x) {
	x += 10;
	return x;
}
void main() {
	int x = 100;
	printf("�Լ� ȣ���� x�� %d\n", x);
	func(x);
	printf("�Լ� ȣ���� x�� %d\n", x);

}
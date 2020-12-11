#include<stdio.h>
int func(int x) {
	x += 10;
	return x;
}
void main() {
	int x = 100;
	printf("함수 호출전 x는 %d\n", x);
	func(x);
	printf("함수 호출후 x는 %d\n", x);

}
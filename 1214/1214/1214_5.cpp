// ����ü
#include<stdio.h>
struct st {
	int i;
	char c; // 'A'->65->2����
};
union un { // ����ü : ������� �޸��ּҸ� ����
	int i;
	char c;
	double d;
};
void main() {

	struct st s;
	s.i = 65;
	s.c = 'a';
	printf("%d %c\n", s.i, s.c);
	s.c = 'z';
	printf("%d %c\n", s.i, s.c);

	union un u;
	u.i = 65;
	printf("%d %c\n", u.i, u.c);
	u.c = 'a';
	printf("%d %c\n", u.i, u.c);

	printf("%d %d\n", sizeof(s), sizeof(u));
}
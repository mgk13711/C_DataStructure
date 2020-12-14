//��ǥ���
#include<stdio.h>
#include<stdlib.h>
typedef struct point {
	char color;
	int x, y;
}P;
void show(P* p) { // ����ü�� �Լ��� ���ڷμ� ��� �����ϴ�
	printf("�����Ͻ� ���� ��ġ��\n");
	printf("%c(%2d,%2d)\n", (*p).color, (*p).x, (*p).y);
}
void move1(P* p, int i) {
	//(*p).x += i;
	//(*p).y += i; // �̰͵� ���� ǥ���̱� ��
	p->x += i;
	p->y += i;  // . ->: ��� ���� ������

}
P move2(P p, int x, int y) {
	p.x += x;
	p.y += y;
	return p;
}
void mid(P p1, P p2) {
	printf("%c ���� %c���� �߰� ��ǥ�� (%.2lf,%.2lf)�Դϴ�.\n\n", p1.color, p2.color, (p1.x + p2.x) / 2.0, (p1.y + p2, y) / 2.0);
}
void main() {
	//��� ���� �������
	// P[] �迭
	// ���

	int N;
	printf("���� ����: ");
	scanf("%d", &N);

	P* p = (P*)malloc(N * sizeof(P));
	for (int i = 0; i < N; i++) {
		printf("%d��° ��... \n", i + 1);
		printf("�� �Է�: ");
		scanf(" %c", &p[i].color);
		printf("x��ǥ: ");
		scanf("%d", &p[i].x);
		printf("y��ǥ: ");
		scanf("%d", &p[i].y);
	}

	//�� ����Լ�
	//����ǥ �̵��Լ�
	printf("\n==�����===\n");
	for (int i = 0; i < N; i++) {
		printf("%d. %c(%2d,%2d)\n", i + 1, p[i].color, p[i].x, p[i].y);
	}	
	printf("\n");

	int num;
	do {
		printf("����ϰ� ���� ���� ��ȣ�� �Է�: \n");
		scanf("%d", &num);
	} while (num <= 0 || num > N); // �ּ� ����Ƚ���� 1ȸ �̻��϶� �ַ� �̿�
	// [��ȿ�� �˻�]: ����ڰ� �Է��� ���� �ùٸ��� Ȯ�� -> ����

	show(&p[num - 1]);

	int i;
	printf("�̵� ĭ�� �Է�: ");
	scanf("%d", &i);

	move1(&p[num - 1], i);
	show(&p[num - 1]);

	int x;
	int y;
	printf("x������ �̵��� ĭ�� �Է�: ");
	scanf("%d", &x);
	printf("y������ �̵��� ĭ�� �Է�: ");
	scanf("%d", &y);

	p[num - 1] = move2(p[num - 1], x, y);
	show(&p[num - 1]);

	int a, b;
	printf("�� 2���� ��ȣ �Է�");
	scanf("%d%d", &a, &b);
	mid(p[a - 1], p[b - 2]);

	free(p);
}
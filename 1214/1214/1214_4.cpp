//좌표평면
#include<stdio.h>
#include<stdlib.h>
typedef struct point {
	char color;
	int x, y;
}P;
void show(P* p) { // 구조체가 함수의 인자로서 사용 가능하다
	printf("선택하신 점의 위치는\n");
	printf("%c(%2d,%2d)\n", (*p).color, (*p).x, (*p).y);
}
void move1(P* p, int i) {
	//(*p).x += i;
	//(*p).y += i; // 이것도 같은 표현이긴 함
	p->x += i;
	p->y += i;  // . ->: 멤버 접근 연산자

}
P move2(P p, int x, int y) {
	p.x += x;
	p.y += y;
	return p;
}
void mid(P p1, P p2) {
	printf("%c 점과 %c점의 중간 좌표는 (%.2lf,%.2lf)입니다.\n\n", p1.color, p2.color, (p1.x + p2.x) / 2.0, (p1.y + p2, y) / 2.0);
}
void main() {
	//몇개의 점을 사용할지
	// P[] 배열
	// 출력

	int N;
	printf("점의 개수: ");
	scanf("%d", &N);

	P* p = (P*)malloc(N * sizeof(P));
	for (int i = 0; i < N; i++) {
		printf("%d번째 점... \n", i + 1);
		printf("색 입력: ");
		scanf(" %c", &p[i].color);
		printf("x좌표: ");
		scanf("%d", &p[i].x);
		printf("y좌표: ");
		scanf("%d", &p[i].y);
	}

	//점 출력함수
	//점좌표 이동함수
	printf("\n==점목록===\n");
	for (int i = 0; i < N; i++) {
		printf("%d. %c(%2d,%2d)\n", i + 1, p[i].color, p[i].x, p[i].y);
	}	
	printf("\n");

	int num;
	do {
		printf("출력하고 싶은 점의 번호를 입력: \n");
		scanf("%d", &num);
	} while (num <= 0 || num > N); // 최소 수행횟수가 1회 이상일때 주로 이용
	// [유효성 검사]: 사용자가 입력한 값이 올바른지 확인 -> 예방

	show(&p[num - 1]);

	int i;
	printf("이동 칸수 입력: ");
	scanf("%d", &i);

	move1(&p[num - 1], i);
	show(&p[num - 1]);

	int x;
	int y;
	printf("x축으로 이동할 칸수 입력: ");
	scanf("%d", &x);
	printf("y축으로 이동할 칸수 입력: ");
	scanf("%d", &y);

	p[num - 1] = move2(p[num - 1], x, y);
	show(&p[num - 1]);

	int a, b;
	printf("점 2개의 번호 입력");
	scanf("%d%d", &a, &b);
	mid(p[a - 1], p[b - 2]);

	free(p);
}
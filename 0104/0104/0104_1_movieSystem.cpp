#include<stdio.h>
#include<stdlib.h>
#include<string>
char title[5][20] = { "도굴", "콜", "스위트홈" }; //영화 수는 최대 5개 -> [5]
int cnt = 3; //영화 수
char cinema[][10] = { "MEGA", "LOTTE", "CGV" }; //영화관수는 3개로 고정 -> []
typedef struct MOVIE {
	char title[20];
	int time;
	char cinema[10];
	int num;	
}M;
typedef struct NODE {
	char name[10];
	M data;
	struct NODE* next;
}N;
typedef struct Queue {
	N* front;
	N* rear;
	int size;
}Q;
void managerMode() {
	printf("☆★관리자 모드★☆\n");
	if (cnt == 5) {
		printf("더이상 영화를 추가할 수 없습니다.\n");
		return;
	}
	printf("추가하실 영화제목을 입력하세요: ");
	scanf("%s", title[cnt++]);
	printf("영화 추가완료!\n");
}
void Enqueue(Q* q) {
	// 1. 이름입력
	// 2. 영화 제목선택
	// 3. 시간입력
	// 4. 영화관 선택
	// 5. 예약번호 생성
	N* node = (N*)malloc(sizeof(N));
	node->next = NULL;

	printf("이름입력: ");
	scanf("%s", node->name);
	
	int num;
	do {
		printf("영화 제목선택: [ ");
		for (int i = 0; i < cnt; i++) {
			printf("%d.%s  ", i + 1, title[i]);
		}
		printf(" ]\n");
		scanf("%d", &num);
	} while (num<1 || num>cnt);
	strcpy(node->data.title, title[num-1]);

	printf("시간입력: ");
	scanf("%d", &node->data.time);

	printf("영화관 선택: ");
	do {
		printf("[ ");
		for (int i = 0; i < 3; i++) {
			printf("%d.%s  ", i + 1, cinema[i]);
		}
		printf(" ]\n");
		scanf("%d", &num);
	} while (num<1 || num>3);
	strcpy(node->data.cinema, cinema[num - 1]);

	node->data.num = num * 1000 + rand() % 998 + 1;
	printf("%s님, 예약번호는 [%d]입니다.\n\n", node->name, node->data.num);

	if (q->size == 0) {
		q->front = node;
	}
	else {
		q->rear->next = node;  //여기 복습해
	}
	q->rear = node;  //여기 복습해
	q->size++;
}
int Dequeue(Q* q) {
	int num;
	for (int i = 0; i < 2; i++) {
		printf("%s님, 예약번호는? ", q->front->name);
		scanf("%d", &num);
		if (num == q->front->data.num) {
			printf("%d시 [%s]영화 %s에서 즐거운관람되세요~^^\n", q->front->data.time, q->front->data.title, q->front->data.cinema);

			q->front = q->front->next;
			q->size--;
			return 0; // 입장성공
		}
		printf("%d회오류! 2회오류시 다시 입장하셔야합니다!\n", i + 1);
	}
	return 1; // 다시대기
}
void roll(Q* q) {
	q->rear->next = q->front;
	q->rear = q->rear->next;
	q->front = q->front->next;

	q->rear->next = NULL;
	printf("%s님 줄의 제일 뒤로 이동됨\n", q->rear->name);
}
void main() {
	int act;
	Q q;
	q.front = NULL;
	q.rear = NULL;
	q.size = 0;

	while (1) {
		printf("== 영화 예매 시스템==\n");
		printf("1. 예매 2.입장 3.대기인원 4.종료\n");
		printf("입력: ");
		scanf("%d", &act);
		if (act == 0) { //0. 관리자 모드
			managerMode();
		}
		else if (act == 1) { //1. 예매
			Enqueue(&q);
		}
		else if (act == 2) { 
			// 1. 몇명입장? 다시입력
			// 2. kim님, 예약번호는? 2회이상틀리면 roll() / Dequeue()+
			int num;
			while (1) {
				printf("몇명입장하시겠습니까? ");
				scanf("%d", &num);
				if (num <= 0) {
					printf("유효한 입력이 아닙니다!\n");
				}
				else if (num > q.size) {
					printf("대기인원을 다시 확인해주세요!\n");
				}
				else {
					break;
				}
			}
			for (int i = 0; i < num; i++) {
				if (Dequeue(&q)) {
					// Dequeue()결과 1이 return되면,
					// roll()수행
					roll(&q);
				}
			}
		}
		else if (act == 3) { // 3.대기인원
			printf("현재 대기인원은 [%d]명 입니다.\n\n", q.size);
		}
		else if (act == 4) {
			printf("프로그램 종료...\n");
			break;
		}
		else {
			printf("잘못된 입력입니다!!\n\n");
		}
	}
}
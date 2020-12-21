#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
	int data; // 데이터 부
	struct NODE* next; // 주소부
}N;
int check(N* head, int data) {
	N* p = head->next;
	while (p != NULL) {
		if (p->data == data)
			return 1; // found
		p = p->next;
	}
	return 0; //not found
}
void remove(N* head, int data) {
	N* p = head;
	while (p->next != NULL) {
		if (p->next->data == data) {
			p->next = p->next->next;
			//free(p->next);
			return;
		}
		p = p->next;
	}
	printf("해당 데이터는 없습니다!");
}
void add(N* head, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL; //노드 생성
	N* p = head;

	while(p->next != NULL){ // 조건: 검색포인터의 다음값이 NULL인지?
		if (p->next->data == data) {
			printf("이미 존재하는 데이터입니다.!\n");
			return;
		}
		else if ((p->next->data > data) && (p->data < data )) { // 오름차순 정렬하여 입력
			node->next = p->next;
			break; //다음 노드 연결은 while문 밖에서 해줌
		}
		p = p->next; //노드연결-> 리스트 생성
	}
	p->next = node;
}
void show(N* head) {
	printf("show(): ");
	N* p=head->next;
	while (p != NULL) {
		printf("%d", p->data);
		if (p->next != NULL)
			printf("->", p->data);
		p = p->next;
	}
	printf("\n");
}
void main() {

	N* head = (N*)malloc(sizeof(N));
	head->next = NULL; //initialize
	
	printf("[리스트 프로그램]\n");
	int act;
	while (1) {
		printf("--------\n");
		printf("1.추가 2.삭제 3.출력 4.종료\n");
		printf("입력: ");
		scanf("%d", &act);
		if (act == 1) {
			int data;
			printf("데이터 입력: ");
			scanf("%d", &data);
			add(head, data);
		}
		else if (act == 2) { // 삭제
			int data;
			printf("삭제할 데이터 입력: ");
			scanf("%d", &data);
			remove(head, data);
		}
		else if (act == 3) { // 출력
			show(head);
		}
		else if (act == 4) {
			printf("프로그램 종료...\n");
			break;
		}
		else {
			printf("잘못된 입력입니다!\n");
		}
	}

}
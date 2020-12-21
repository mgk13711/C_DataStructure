#include<stdio.h>
#include<stdlib.h>
typedef struct NODE N;
typedef struct NODE {
	int data;
	struct NODE * next;  //다음노드(다음데이터xxx)의 주소-> 자기참조구조체 == 노드
}N;
void main() {
	//배열: 크기가 제한적, 데이터 삽입, 삭제가 불리
	//index방식의 접근 -> 검색(탐색)에 유리

	//[리스트] - Linked list(연결 리스트)
	//하나의 요소(노드, node): 데이터부(정보부)+ 주소부(연결부, 링크부)
	// --> 노드 구현을 위해 구조체를 이용
	// 삽입, 삭제가 유리. 공간효율이 좋다/ A다음B, B다음C, ... -> 탐색에 불리함
	
	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;

	N* node1 = (N*)malloc(sizeof(N));
	node1->data = 10;
	node1->next = NULL;
	head->next = node1;

	N* node2 = (N*)malloc(sizeof(N));
	node2->data = 20;
	node2->next = NULL;
	node1->next = node2;

	// 리스트 출력 == 순회; 순회용 포인터 == 출력용 포인터 == 방문용 포인터
	N* p = head->next; // <--------- 이부분 익숙치 않아
	
	while (p != NULL) { // <-------- 순회용 포인터 반복문
		printf("%d ", p->data);
		p = p->next;
	}

	free(node2);
	free(node1);
	free(head);
	
}
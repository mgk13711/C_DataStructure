#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
	int data;
	struct NODE* next = (struct NODE*)malloc(sizeof(struct NODE));
}N;
void add(N* head, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL;
	
	N* p = head; //��ȯ ������
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}
void add2(N* head, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = head->next;

	N* p = head; //��ȯ ������
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;	
}
void show(N* head) {
	N* p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}
void show2(N* head,int a, int b) {
	N* p = head;
	N* pp = NULL;
	for (int j = 0; j < a; j++) {
		for (int i = 0; i < b; i++) {
			pp = p;
			p = p->next;
		}
		printf("%d ", p->data);
		pp->next = pp->next->next;
	}

	/*
	N* p = head;
	N* pp = NULL;
	for(int j = 0; j<a; j++){
		for (int i = 0; i < b; i++) {
			p = p->next;
			if (p->data == 0)
				return;
		}
		pp->next = pp->next->next;

		printf("%d is deleted\n", p->data);
		//p->data = 0;
	}*/



}
void main() {
	int a, b;
	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;

	printf("���� 2�� �Է�: ");
	scanf(" %d %d", &a, &b);
	printf("a: %d, b: %d\n\n", a, b);
	
	for (int i = 0; i < a-1; i++) {
		add(head, i + 1);
	}
	add2(head, a);

	show2(head,a, b);

	//show(head);	
}
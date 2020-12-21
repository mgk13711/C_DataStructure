#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
	int data; // ������ ��
	struct NODE* next; // �ּҺ�
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
	printf("�ش� �����ʹ� �����ϴ�!");
}
void add(N* head, int data) {
	N* node = (N*)malloc(sizeof(N));
	node->data = data;
	node->next = NULL; //��� ����
	N* p = head;

	while(p->next != NULL){ // ����: �˻��������� �������� NULL����?
		if (p->next->data == data) {
			printf("�̹� �����ϴ� �������Դϴ�.!\n");
			return;
		}
		else if ((p->next->data > data) && (p->data < data )) { // �������� �����Ͽ� �Է�
			node->next = p->next;
			break; //���� ��� ������ while�� �ۿ��� ����
		}
		p = p->next; //��忬��-> ����Ʈ ����
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
	
	printf("[����Ʈ ���α׷�]\n");
	int act;
	while (1) {
		printf("--------\n");
		printf("1.�߰� 2.���� 3.��� 4.����\n");
		printf("�Է�: ");
		scanf("%d", &act);
		if (act == 1) {
			int data;
			printf("������ �Է�: ");
			scanf("%d", &data);
			add(head, data);
		}
		else if (act == 2) { // ����
			int data;
			printf("������ ������ �Է�: ");
			scanf("%d", &data);
			remove(head, data);
		}
		else if (act == 3) { // ���
			show(head);
		}
		else if (act == 4) {
			printf("���α׷� ����...\n");
			break;
		}
		else {
			printf("�߸��� �Է��Դϴ�!\n");
		}
	}

}
//TODO: �̿ϼ��̹Ƿ� �ϼ� �ؾ���
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
	int data;
	struct NODE* next;
}N;
void add(N* head, int data) {
	N* p = NULL;
	N* node = (N*)malloc(sizeof(N));
	node->next = NULL;
	node->data = data;
	p->next = head->next;
	while (p->next != NULL) {
		p->next = p;
	}
	p->next = node;
}
void show(N* head) {
	N* p=head->next;
	while (p->next != NULL) {
		printf("%d ", p->data);
		p->next = p;
	}
}

void main() {
	N* head = (N*)malloc(sizeof(N));
	head->next = NULL;

	int cmd;
	int data;
	printf("��� ����> 1.�����߰� 2.���ڻ��� 3.��Ͽ� �ִ°� ��� 4.����\n");
	scanf("%d", &cmd);
	while (1) {
		if (cmd == 1) {
			printf("�߰��� �����Է�: ");
			scanf("%d", &data);
			add(head, data);
		}
		else if (cmd == 3) {
			show(head);
		}
		else if (cmd == 4) {
			break;
		}
	}


}
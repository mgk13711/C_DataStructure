#include<stdio.h>
#include<stdlib.h>
typedef struct NODE N;
typedef struct NODE {
	int data;
	struct NODE * next;  //�������(����������xxx)�� �ּ�-> �ڱ���������ü == ���
}N;
void main() {
	//�迭: ũ�Ⱑ ������, ������ ����, ������ �Ҹ�
	//index����� ���� -> �˻�(Ž��)�� ����

	//[����Ʈ] - Linked list(���� ����Ʈ)
	//�ϳ��� ���(���, node): �����ͺ�(������)+ �ּҺ�(�����, ��ũ��)
	// --> ��� ������ ���� ����ü�� �̿�
	// ����, ������ ����. ����ȿ���� ����/ A����B, B����C, ... -> Ž���� �Ҹ���
	
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

	// ����Ʈ ��� == ��ȸ; ��ȸ�� ������ == ��¿� ������ == �湮�� ������
	N* p = head->next; // <--------- �̺κ� �ͼ�ġ �ʾ�
	
	while (p != NULL) { // <-------- ��ȸ�� ������ �ݺ���
		printf("%d ", p->data);
		p = p->next;
	}

	free(node2);
	free(node1);
	free(head);
	
}
// Ʈ��: ������ ����
// ����Ʈ��: binary tree. �����ڽ�/�������ڽ� ���
// root: �θ��尡 ���� �ֻ��� ���
// leaf: �ڽĳ�尡 ���� ������ ���. �ܸ����

#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
	// binary tree node
	int data;
	struct NODE* left;
	struct NODE* right;
}N;
void main() {
	N* root = (N*)malloc(sizeof(N));
	root->data = 50;
	root->left = NULL;
	root->right = NULL;
	
	N* node1 = (N*)malloc(sizeof(N));
	node1->left = NULL;
	node1->right = NULL;
	printf("data input: ");
	scanf("%d", &node1->data);
	if (node1->data < root->data)
		root->left = node1;
	else
		root->right = node1;
}
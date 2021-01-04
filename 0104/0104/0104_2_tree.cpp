// 트리: 노드들의 집합
// 이진트리: binary tree. 왼쪽자식/오른쪽자식 노드
// root: 부모노드가 없는 최상위 노드
// leaf: 자식노드가 없는 최하위 노드. 단말노드

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
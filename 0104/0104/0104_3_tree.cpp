#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
    int data;
    struct NODE* left;
    struct NODE* right;
}N;
N* create(N* root, int data) {
    if (root == NULL) {
        root = (N*)malloc(sizeof(N));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else {
        if (root->data > data) {
            // �����ڽ�
            root->left = create(root->left, data); // ����Լ�
        }
        else {
            // �������ڽ�
            root->right = create(root->right, data);
        }
    }
    return root;
}
void main() {

    N* root = NULL;
    int act;
    printf("===Ʈ�� ���α׷�===\n");
    while (1) {
        printf("1.������ 2.Ʈ����ȸ 3.������ 4.����\n");
        printf("�Է�: ");
        scanf("%d", &act);
        if (act == 1) {
            int data;
            printf("�������Է�: ");
            scanf("%d", &data);
            root = create(root, data);
        }
        else if (act == 2) {

        }
        else if (act == 3) {

        }
        else if (act == 4) {
            printf("���α׷�����...\n");
            break;
        }
        else {
            printf("�߸����Է�!\n");
        }
    }





}
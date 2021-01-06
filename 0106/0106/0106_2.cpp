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
// "����Ʈ��"
void preorder(N* root) {
    /*
     1
    2 3
    */
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(N* root) {
    /*
     2
    1 3
    */
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(N* root) {
    /*
     3
    1 2
    */
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void del(N* root, int data) {
    // 1) ������ �����Ͱ� Ʈ���� ���������ʴ� ���
    // 2) ������ �����Ͱ� �ܸ������ ���
    // 3) ������ ������(���)�� �ϳ��� ����Ʈ���� ���� ���
    // 4) ������ ������(���)�� �ΰ��� ����Ʈ���� ���� ���
    N* c = root;  //���� ã�� ������
    N* p = root;  //c�������� ���� ���� ����
    while (c != NULL && c->data != data) {
        // ������ �����͸� �߰��Ҷ����� or ��ȸ�� ������ c�� NULL�� �ɶ�����(==���1) ����
        p = c;
        c = data < p->data ? p->left : p->right;
    }
    // 1) ������ �����͸� �߰��� ���
    // 2) ������ �����͸� �߰��������ؼ� ��ȸ�� ������ c�� NULL�� �� ���
    if (c == NULL) {
        printf("�ش� ������ ����!\n\n");
        return;
    }
    if (c->left == NULL && c->right == NULL) {
        // ���2
        if (p->left == c) {
            p->left = NULL;
        }
        else {
            p->right = NULL;
        }
    }
    else if (c->left == NULL || c->right == NULL) {
        // ���3
        if (p->left == c) {
            c = c->left != NULL ? c->left : c->right;
            p->left = c;
        }
        else {
            c = c->left != NULL ? c->left : c->right;
            p->right = c;
        }
    }
    else {
        // ���4
      // 1)������ ������(���)�� ������ ����Ʈ������ ������������ ã�´�.
      // 2)������ ������(���)�� ���� ����Ʈ������ ����ū���� ã�´�.
      /*
      ������ ����Ʈ������ ������������ ã������,
      ���� ���ʿ� ��ġ�� ��带 ã�´�.

      ã�� ����� ����, ������ ��忡 ����

      ã�� ����� �θ��尡 �����
      �׷���!
      ã�� ��忡�� �������ڽĳ�尡 ���� ���ɼ��� �ִ�!
      => ã�� ��忡�� �������ڽ��� �ִ�����,
      ã�� ����� �θ��尡 ã�� ����� �������ڽ��� ����Ű�� �ڵ�!!!
      */
        N* subp = c;
        N* subc = c->right;
        while (subc->left != NULL) { // subc�� ���ʳ�尡 ������ ����
            subp = subc;
            subc = subc->left;
        }
        // 1.while���� ������ ���(1ȸ�̻�): ã�� ����� �θ���(���� �����)
        // 2.while���� ���ѹ��� ������������ ���: ã�� ����� �θ���(������ �����)
    }
    printf("%d �����Ϸ�!\n\n", data);
}
void main() {

    N* root = NULL;
    int act;
    printf("===Ʈ�� ���α׷�===\n");
    while (1) {
        printf("1.������ 2.������ȸ 3.������ȸ 4.������ȸ 5.������ 6.����\n");
        printf("�Է�: ");
        scanf("%d", &act);
        if (act == 1) {
            int data;
            printf("�������Է�: ");
            scanf("%d", &data);
            root = create(root, data);
            printf("%d �Է¿Ϸ�!\n\n", data);
        }
        else if (act == 2) {
            printf("������ȸ ����!\n");
            /*
             1
            2 3
            */
            preorder(root);
            printf("\n\n");
        }
        else if (act == 3) {
            printf("������ȸ ����!\n");
            /*
             2
            1 3
            */
            inorder(root);
            printf("\n\n");
        }
        else if (act == 4) {
            printf("������ȸ ����!\n");
            /*
              3
             1 2
            */
            postorder(root);
            printf("\n\n");
        }
        else if (act == 5) { //�����
            int data;
            printf("����� ���� ������: ");
            scanf("%d", &data);
            del(root, data);
        }
        else if (act == 6) {
            printf("���α׷�����...\n");
            break;
        }
        else {
            printf("�߸����Է�!\n");
        }
    }





}
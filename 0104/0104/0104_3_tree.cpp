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
            // 왼쪽자식
            root->left = create(root->left, data); // 재귀함수
        }
        else {
            // 오른쪽자식
            root->right = create(root->right, data);
        }
    }
    return root;
}
void main() {

    N* root = NULL;
    int act;
    printf("===트리 프로그램===\n");
    while (1) {
        printf("1.노드생성 2.트리순회 3.노드삭제 4.종료\n");
        printf("입력: ");
        scanf("%d", &act);
        if (act == 1) {
            int data;
            printf("데이터입력: ");
            scanf("%d", &data);
            root = create(root, data);
        }
        else if (act == 2) {

        }
        else if (act == 3) {

        }
        else if (act == 4) {
            printf("프로그램종료...\n");
            break;
        }
        else {
            printf("잘못된입력!\n");
        }
    }





}
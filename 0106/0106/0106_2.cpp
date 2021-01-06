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
// "서브트리"
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
    // 1) 삭제할 데이터가 트리에 존재하지않는 경우
    // 2) 삭제할 데이터가 단말노드인 경우
    // 3) 삭제할 데이터(노드)가 하나의 서브트리를 가진 경우
    // 4) 삭제할 데이터(노드)가 두개의 서브트리를 가진 경우
    N* c = root;  //값을 찾는 포인터
    N* p = root;  //c포인터의 이전 값을 저장
    while (c != NULL && c->data != data) {
        // 삭제할 데이터를 발견할때까지 or 순회용 포인터 c가 NULL이 될때까지(==경우1) 수행
        p = c;
        c = data < p->data ? p->left : p->right;
    }
    // 1) 삭제할 데이터를 발견한 경우
    // 2) 삭제할 데이터를 발견하지못해서 순회용 포인터 c가 NULL이 된 경우
    if (c == NULL) {
        printf("해당 데이터 없음!\n\n");
        return;
    }
    if (c->left == NULL && c->right == NULL) {
        // 경우2
        if (p->left == c) {
            p->left = NULL;
        }
        else {
            p->right = NULL;
        }
    }
    else if (c->left == NULL || c->right == NULL) {
        // 경우3
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
        // 경우4
      // 1)삭제할 데이터(노드)의 오른쪽 서브트리에서 가장작은값을 찾는다.
      // 2)삭제할 데이터(노드)의 왼쪽 서브트리에서 가장큰값을 찾는다.
      /*
      오른쪽 서브트리에서 가장작은값을 찾기위해,
      가장 왼쪽에 위치한 노드를 찾는다.

      찾은 노드의 값을, 삭제할 노드에 대입

      찾은 노드의 부모노드가 변경됨
      그런데!
      찾은 노드에게 오른쪽자식노드가 있을 가능성이 있다!
      => 찾은 노드에게 오른쪽자식이 있던없던,
      찾은 노드의 부모노드가 찾은 노드의 오른쪽자식을 가리키게 코딩!!!
      */
        N* subp = c;
        N* subc = c->right;
        while (subc->left != NULL) { // subc의 왼쪽노드가 있으면 진행
            subp = subc;
            subc = subc->left;
        }
        // 1.while문을 수행한 경우(1회이상): 찾은 노드의 부모노드(왼쪽 연결부)
        // 2.while문을 단한번도 수행하지않은 경우: 찾은 노드의 부모노드(오른쪽 연결부)
    }
    printf("%d 삭제완료!\n\n", data);
}
void main() {

    N* root = NULL;
    int act;
    printf("===트리 프로그램===\n");
    while (1) {
        printf("1.노드생성 2.전위순회 3.중위순회 4.후위순회 5.노드삭제 6.종료\n");
        printf("입력: ");
        scanf("%d", &act);
        if (act == 1) {
            int data;
            printf("데이터입력: ");
            scanf("%d", &data);
            root = create(root, data);
            printf("%d 입력완료!\n\n", data);
        }
        else if (act == 2) {
            printf("전위순회 시작!\n");
            /*
             1
            2 3
            */
            preorder(root);
            printf("\n\n");
        }
        else if (act == 3) {
            printf("중위순회 시작!\n");
            /*
             2
            1 3
            */
            inorder(root);
            printf("\n\n");
        }
        else if (act == 4) {
            printf("후위순회 시작!\n");
            /*
              3
             1 2
            */
            postorder(root);
            printf("\n\n");
        }
        else if (act == 5) { //지우기
            int data;
            printf("지우고 싶은 데이터: ");
            scanf("%d", &data);
            del(root, data);
        }
        else if (act == 6) {
            printf("프로그램종료...\n");
            break;
        }
        else {
            printf("잘못된입력!\n");
        }
    }





}
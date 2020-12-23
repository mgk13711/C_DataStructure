#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define TEST 2
typedef struct student {
    char name[10];
    int num;
    int score[TEST];
    double avg;
    char grade;
}STU;
typedef struct NODE {
    STU data;
    struct NODE* next;
}N;
/* //이 부분을 함수로 빼서 호출하는것으로 사용하자
node->data.avg = 0.0;
for (int i = 0; i < TEST; i++) {
node->data.score[i] = rand() % 101;
node->data.avg += node->data.score[i];
}
node->data.avg /= TEST;
if (node->data.avg >= 50.0) {
node->data.grade = 'P';
}
else {
node->data.grade = 'F';
}
*/ // coding_helper@naver.com 질문 보내면 답변 가능
void add(N* head, int num) {
    srand(time(NULL));
    N* node = (N*)malloc(sizeof(N));
    printf("학생이름입력: ");
    scanf("%s", node->data.name);
    node->data.num = num;
    node->data.avg = 0.0;
    for (int i = 0; i < TEST; i++) {
        node->data.score[i] = rand() % 101;
        node->data.avg += node->data.score[i];
    }
    node->data.avg /= TEST;
    if (node->data.avg >= 50.0) {
        node->data.grade = 'P';
    }
    else {
        node->data.grade = 'F';
    }
    node->next = NULL;
    N* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = node;
    printf("%s학생정보 추가완료!\n", node->data.name);
}
void remove(N* head, int n) {
    N* p = head;
    N* pp = NULL; // free()를 위한 포인터
    while (p->next != NULL) {
        if (p->next->data.num == n) {
            pp = p->next;
            p->next = p->next->next;
            free(pp);
            printf("%d번학생 삭제완료!\n", n);
            return;
        }
        p = p->next;
    }
    printf("%d번학생은 존재하지않습니다!\n", n);
}
void show(N* head) {
    printf("===학생목록===\n");
    N* p = head->next;
    while (p != NULL) {
        printf("%d.%s ", p->data.num, p->data.name);
        for (int i = 0; i < TEST; i++) {
            printf("%d ", p->data.score[i]);
        }
        printf("[%.2lf점 / %c]\n", p->data.avg, p->data.grade);
        p = p->next;
    }
    printf("\n\n");
}
void ch(N* head, int n) {
    N* p = head->next;
    while (p != NULL) {
        if (n == p->data.num) {
            printf("%d번학생의 현재정보: %s [%c]\n", n, p->data.name, p->data.grade);
            int act;
            do {
                printf("1.이름변경 2.재시험  ");
                scanf("%d", &act);
            } while (act < 1 || act>2);
            if (act == 1) {
                printf("%d번학생 이름재입력: ", p->data.num);
                scanf("%s", p->data.name);
            }
            else {
                p->data.avg = 0.0;
                for (int i = 0; i < TEST; i++) {
                    p->data.score[i] = rand() % 101;
                    p->data.avg += p->data.score[i];
                }
                p->data.avg /= TEST;
                if (p->data.avg >= 50.0) {
                    p->data.grade = 'P';
                }
                else {
                    p->data.grade = 'F';
                }
            }
            printf("%s학생 정보변경완료!\n", p->data.name);
            return;
        }
        p = p->next;
    }
    printf("%d번학생은 존재하지않습니다!\n", n);
}
void freee(N* head) {
    printf("프로그램 종료중..");
    for (int i = 0; i < 5; i++) {
        printf(".");
        Sleep(500); // 1000==1초
    }
    N* p = head->next;
    N* pp = NULL;
    while (p != NULL) {
        pp = p;
        p = p->next;
        free(pp);
    }
    printf("\n프로그램종료!\n");
}
void main() {

    // 리스트==학생부
    N* head = (N*)malloc(sizeof(N));
    head->next = NULL;

    int num = 1001; // 학생번호

    int act;
    while (1) {
        printf("===============\n");
        printf("1.입력 2.삭제 3.출력 4.수정 5.종료\n");
        printf("번호입력: ");
        scanf("%d", &act);
        if (act == 1) {
            // 크기제한xxx
            add(head, num++);
        }
        else if (act == 2) {
            // 원하는 데이터 삭제가능
            int n;
            do {
                printf("수정할 학생의 번호입력: ");
                scanf("%d", &n);
            } while (n <= 1000 || 2000 <= n);
            remove(head, n);
        }
        else if (act == 3) {
            show(head);
        }
        else if (act == 4) {
            int n;
            do {
                printf("수정할 학생의 번호입력: ");
                scanf("%d", &n);
            } while (n <= 1000 || 2000 <= n);
            ch(head, n);
        }
        else if (act == 5) {
            break;
        }
        else {
            printf("잘못입력!\n");
        }

    }
    // 전체리스트(학생부)에 저장되어있는 노드들을 전부 free()시켜보자!
    freee(head);
	free(head);
}
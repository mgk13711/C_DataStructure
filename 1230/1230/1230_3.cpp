//Linked list Queue
//리스트 큐
//프론트 노드 + 리어 노드 -> 구성
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE {
    int data;
    struct NODE* next;
}N;
typedef struct Queue {
    N* front;
    N* rear;
    int size;
}Q;
void Enqueue(Q* q, int data) {
    N* node = (N*)malloc(sizeof(N));
    node->data = data;
    node->next = NULL;
    // 노드생성

    if (q->size == 0) { // 큐가 비어있다면,
       // 현재 만들어진 노드를 맨 앞으로 설정!
        q->front = node;
    }
    else {
        q->rear->next = node;
    }
    q->rear = node;
    q->size++;
}
int Dequeue(Q* q) {
    int data = q->front->data;
    N* p = q->front;
    q->front = q->front->next;
    free(p);
    q->size--;
    return data;
}
void show(Q q) {
    N* p = q.front;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
void roll(Q* q) {
    q->rear->next = q->front;
    // 1. 사이클 생성

    q->rear = q->rear->next;
    q->front = q->front->next;
    // 2. F,R 이동

    q->rear->next = NULL;
    // 3. 사이클 제거

    printf("roll() 수행완료..\n");
}
void main() {

    Q q;
    q.front = NULL;
    q.rear = NULL;
    q.size = 0;
    printf("===리스트 큐 프로그램===\n\n");

    int act;
    while (1) {
        printf("1.삽입 2.삭제 3.크기 4.출력 5.회전 6.종료\n");
        printf("입력: ");
        scanf("%d", &act);
        if (act == 1) {
            int data;
            printf("데이터입력: ");
            scanf("%d", &data);
            Enqueue(&q, data);
        }
        else if (act == 2) {
            if (q.size == 0) { // -> isEmpty()를 구현한 코드
                printf("큐에 삭제할 데이터가 없습니다!\n");
                continue;
            }
            printf("Dequeue(): %d\n", Dequeue(&q));
        }
        else if (act == 3) {
            printf("현재 큐의 데이터갯수는 %d개입니다.\n", q.size);
        }
        else if (act == 4) {
            if (q.size != 0) {
                printf("show(): ");
                show(q);
            }
            else {
                printf("큐에 데이터없음!");
            }
            printf("\n");
        }
        else if (act == 5) {
            roll(&q);
        }
        else if (act == 6) {
            printf("프로그램종료...\n");
            break;
        }
        else {
            printf("잘못입력하셨습니다!\n");
        }
    }




}
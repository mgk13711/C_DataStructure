//Linked list Queue
//����Ʈ ť
//����Ʈ ��� + ���� ��� -> ����
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
    // ������

    if (q->size == 0) { // ť�� ����ִٸ�,
       // ���� ������� ��带 �� ������ ����!
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
    // 1. ����Ŭ ����

    q->rear = q->rear->next;
    q->front = q->front->next;
    // 2. F,R �̵�

    q->rear->next = NULL;
    // 3. ����Ŭ ����

    printf("roll() ����Ϸ�..\n");
}
void main() {

    Q q;
    q.front = NULL;
    q.rear = NULL;
    q.size = 0;
    printf("===����Ʈ ť ���α׷�===\n\n");

    int act;
    while (1) {
        printf("1.���� 2.���� 3.ũ�� 4.��� 5.ȸ�� 6.����\n");
        printf("�Է�: ");
        scanf("%d", &act);
        if (act == 1) {
            int data;
            printf("�������Է�: ");
            scanf("%d", &data);
            Enqueue(&q, data);
        }
        else if (act == 2) {
            if (q.size == 0) { // -> isEmpty()�� ������ �ڵ�
                printf("ť�� ������ �����Ͱ� �����ϴ�!\n");
                continue;
            }
            printf("Dequeue(): %d\n", Dequeue(&q));
        }
        else if (act == 3) {
            printf("���� ť�� �����Ͱ����� %d���Դϴ�.\n", q.size);
        }
        else if (act == 4) {
            if (q.size != 0) {
                printf("show(): ");
                show(q);
            }
            else {
                printf("ť�� �����;���!");
            }
            printf("\n");
        }
        else if (act == 5) {
            roll(&q);
        }
        else if (act == 6) {
            printf("���α׷�����...\n");
            break;
        }
        else {
            printf("�߸��Է��ϼ̽��ϴ�!\n");
        }
    }




}
// [ť]
// : �迭�� ������ ť
#include<stdio.h>
#define MAX 5
int queue[MAX];
int s = 0;
int e = 0;
int isFull() {
    if (s == e && queue[s] != 0) {
        return 1;
    }
    return 0;
}
int isEmpty() {
    if (s == e && queue[s] == 0) {
        return 1;
    }
    return 0;
}
void Enqueue(int data) {
    queue[e++] = data;
    if (e == MAX) {
        // �迭�� ������ ���->[0]���� ���ƿ�
        e = 0;
    }
}
int Dequeue() {
    int data = queue[s];
    queue[s++] = 0;
    if (s == MAX) {
        s = 0;
    }
    return data;
}
int size() {
    if (isEmpty()) {
        return 0;
    }
    else if (isFull()) {
        return MAX;
    }
    else {
        if (s < e) {
            return e - s;
        }
        else {
            return e - s + MAX;
        }
    }
}
void main() {
    printf("===ť ���α׷�===\n");
    int act;
    while (1) {
        printf("1.Enqueue() 2.Dequeue() 3.size() 4.����\n");
        printf("�Է�: ");
        scanf("%d", &act);
        if (act == 1) {
            if (isFull()) {
                printf("ť�� �����Ͱ� ������!\n");
                continue;
            }
            int data;
            printf("�������Է�: ");
            scanf("%d", &data);
            Enqueue(data);
        }
        else if (act == 2) {
            if (isEmpty()) {
                printf("ť�� �����Ͱ� ��������!\n");
                continue;
            }
            printf("Dequeue(): %d\n", Dequeue());
        }
        else if (act == 3) {
            printf("���� �迭 ť���� %d���� �����Ͱ� ����Ǿ��ֽ��ϴ�!\n", size());
        }
        else if (act == 4) {
            printf("���α׷�����.....\n");
            break;
        }
        else {
            printf("�߸��Է��ϼ̽��ϴ�!\n");
        }
    }
}
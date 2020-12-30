// [큐]
// : 배열로 구현한 큐
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
        // 배열의 범위를 벗어남->[0]으로 돌아옴
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
    printf("===큐 프로그램===\n");
    int act;
    while (1) {
        printf("1.Enqueue() 2.Dequeue() 3.size() 4.종료\n");
        printf("입력: ");
        scanf("%d", &act);
        if (act == 1) {
            if (isFull()) {
                printf("큐에 데이터가 가득참!\n");
                continue;
            }
            int data;
            printf("데이터입력: ");
            scanf("%d", &data);
            Enqueue(data);
        }
        else if (act == 2) {
            if (isEmpty()) {
                printf("큐에 데이터가 전혀없음!\n");
                continue;
            }
            printf("Dequeue(): %d\n", Dequeue());
        }
        else if (act == 3) {
            printf("현재 배열 큐에는 %d개의 데이터가 저장되어있습니다!\n", size());
        }
        else if (act == 4) {
            printf("프로그램종료.....\n");
            break;
        }
        else {
            printf("잘못입력하셨습니다!\n");
        }
    }
}
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
/* //�� �κ��� �Լ��� ���� ȣ���ϴ°����� �������
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
*/ // coding_helper@naver.com ���� ������ �亯 ����
void add(N* head, int num) {
    srand(time(NULL));
    N* node = (N*)malloc(sizeof(N));
    printf("�л��̸��Է�: ");
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
    printf("%s�л����� �߰��Ϸ�!\n", node->data.name);
}
void remove(N* head, int n) {
    N* p = head;
    N* pp = NULL; // free()�� ���� ������
    while (p->next != NULL) {
        if (p->next->data.num == n) {
            pp = p->next;
            p->next = p->next->next;
            free(pp);
            printf("%d���л� �����Ϸ�!\n", n);
            return;
        }
        p = p->next;
    }
    printf("%d���л��� ���������ʽ��ϴ�!\n", n);
}
void show(N* head) {
    printf("===�л����===\n");
    N* p = head->next;
    while (p != NULL) {
        printf("%d.%s ", p->data.num, p->data.name);
        for (int i = 0; i < TEST; i++) {
            printf("%d ", p->data.score[i]);
        }
        printf("[%.2lf�� / %c]\n", p->data.avg, p->data.grade);
        p = p->next;
    }
    printf("\n\n");
}
void ch(N* head, int n) {
    N* p = head->next;
    while (p != NULL) {
        if (n == p->data.num) {
            printf("%d���л��� ��������: %s [%c]\n", n, p->data.name, p->data.grade);
            int act;
            do {
                printf("1.�̸����� 2.�����  ");
                scanf("%d", &act);
            } while (act < 1 || act>2);
            if (act == 1) {
                printf("%d���л� �̸����Է�: ", p->data.num);
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
            printf("%s�л� ��������Ϸ�!\n", p->data.name);
            return;
        }
        p = p->next;
    }
    printf("%d���л��� ���������ʽ��ϴ�!\n", n);
}
void freee(N* head) {
    printf("���α׷� ������..");
    for (int i = 0; i < 5; i++) {
        printf(".");
        Sleep(500); // 1000==1��
    }
    N* p = head->next;
    N* pp = NULL;
    while (p != NULL) {
        pp = p;
        p = p->next;
        free(pp);
    }
    printf("\n���α׷�����!\n");
}
void main() {

    // ����Ʈ==�л���
    N* head = (N*)malloc(sizeof(N));
    head->next = NULL;

    int num = 1001; // �л���ȣ

    int act;
    while (1) {
        printf("===============\n");
        printf("1.�Է� 2.���� 3.��� 4.���� 5.����\n");
        printf("��ȣ�Է�: ");
        scanf("%d", &act);
        if (act == 1) {
            // ũ������xxx
            add(head, num++);
        }
        else if (act == 2) {
            // ���ϴ� ������ ��������
            int n;
            do {
                printf("������ �л��� ��ȣ�Է�: ");
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
                printf("������ �л��� ��ȣ�Է�: ");
                scanf("%d", &n);
            } while (n <= 1000 || 2000 <= n);
            ch(head, n);
        }
        else if (act == 5) {
            break;
        }
        else {
            printf("�߸��Է�!\n");
        }

    }
    // ��ü����Ʈ(�л���)�� ����Ǿ��ִ� ������ ���� free()���Ѻ���!
    freee(head);
	free(head);
}
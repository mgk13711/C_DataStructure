#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
typedef struct action {
    char word[15];
    int code;
}ACT;
void main() {

    ACT stack[MAX];
    int index = 0;
    while (1) {
        char word[15];
        printf("��ɾ��Է�: ");
        scanf("%s", word);
        if (strcmp(word, "����") == 0) {
            break;
        }
        else if (strcmp(word, "�������") == 0) {
            // ������� -> pop()
            if (index == 0) {
                printf("���� ����� �׼��� �����ϴ�.\n");
                continue;
            }
            index--;
            printf("[%d]: %s �������\n", stack[index].code, stack[index].word);
        }
        else {
            // ���ÿ� �׼��� ���� -> push()
            if (index == MAX) {
                printf("���ÿ� ��������� �����ϴ�.!\n");
                continue;
            }
            strcpy(stack[index].word, word);
            stack[index].code = rand() % 8999 + 1001; // 1001~9999
            printf("[%d]: %s ����Ϸ�\n", stack[index].code, stack[index].word);
            index++;
        }
    }

}
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
        printf("명령어입력: ");
        scanf("%s", word);
        if (strcmp(word, "종료") == 0) {
            break;
        }
        else if (strcmp(word, "실행취소") == 0) {
            // 실행취소 -> pop()
            if (index == 0) {
                printf("실행 취소할 액션이 없습니다.\n");
                continue;
            }
            index--;
            printf("[%d]: %s 실행취소\n", stack[index].code, stack[index].word);
        }
        else {
            // 스택에 액션을 저장 -> push()
            if (index == MAX) {
                printf("스택에 저장공간이 없습니다.!\n");
                continue;
            }
            strcpy(stack[index].word, word);
            stack[index].code = rand() % 8999 + 1001; // 1001~9999
            printf("[%d]: %s 수행완료\n", stack[index].code, stack[index].word);
            index++;
        }
    }

}
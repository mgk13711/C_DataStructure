
#include<stdio.h>
#include<string.h>
#define MAX 5
// 정답단어: apple
// 보기단어: _____
// 생명: ♡x3
typedef struct WORD {
	char ans[10];
	char show[10];
	int score;
}W;
void main() {

	char ans;
	W w;

	while (1) {
		printf("문제를 출제하세요.  ");
		scanf("%s", w.ans);
		for (int i = 0; i < strlen(w.ans); i++) {
			w.show[i] = '_';
		}
		w.show[strlen(w.ans)] = '\0'; // _____ + '\0'
		w.score = MAX;
		/*
		// 문자배열 + '\0' == 문자열
		char str1[] = "apple"; // 문자열
		char str2[] = { 'a','p','p','l','e','\0' }; // 문자열
		char arr[] = { 'a','p','p','l','e' }; // 문자배열
		printf("%s  %s\n", w.ans, w.show);
		*/
		while (1) {
			char c;
			printf("%s : ", w.show);
			scanf(" %c", &c);
			int check = 0; // 0:F , 1:T
			for (int i = 0; i < strlen(w.ans); i++) {
				if (w.ans[i] == c) {
					w.show[i] = c;
					check = 1; // 사용자가 입력한 문자를 찾으면, check변수가 1로 바뀜!
				}
			}
			if (check == 0) {
				printf("%c는 없습니다!\n", c);
				w.score--;
			}
			if (w.score == 0) { // 1) 생명이 없으면,
				printf("GameOver...\n");
				break;
			}
			else if (strcmp(w.ans, w.show) == 0) { // 2) 정답을 맞추면,
				printf("%s! 정답입니다!!\n", w.ans);
				if (w.score == MAX) {
					printf("상품을 드리겠습니다!~~\n");
				}
				break;
			}
		}
		do {
			printf("게임 계속하시겠습니까?  ");
			scanf(" %c", &ans);
		} while (!(ans == 'Y' || ans == 'y' || ans == 'N' || ans == 'n'));
		if (ans == 'N' || ans == 'n') {
			break;
		}
	}

}
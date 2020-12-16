
#include<stdio.h>
#include<string.h>
//정답단어: apple
//보기단어: _____
//생명: ♡x3
typedef struct WORD {
	char ans[10];
	char show[10];
	int score;
}W;
void init(W* w) {
	for (int i = 0; i < strlen(w->ans); i++) {
		w->show[i] = '_';
	}
	w->show[strlen(w->ans)] = '\0';
	w->score = 10;
}

void main() {
	while (1) {
		W w;
		printf("문제를 출제하세요. ");
		scanf("%s", w.ans);
		
		init(&w);

		printf("%s\n", w.ans);
		printf("%s\n", w.show);

		printf("********\n");

		char ch;
		while (1) {  //문제 풀기 시작
			
			printf("♡x%d", w.score);
			printf("%s: ", w.show);
			scanf(" %c", &ch);

			int check = 0; // 0:F, 1~:T
			for (int i = 0; i < strlen(w.ans); i++) {
				if (w.ans[i] == ch) {
					w.show[i] = ch; //찾았다
					check++;
				}
			}
			if (check == 0) {
				printf("%c는 없습니다!\n", ch);
				w.score--;
			}

			if (w.score == 0) { // 1) 생명이 다하면
				printf("game over...\n");
				break;
			}
			else if (strcmp(w.ans, w.show) == 0) { // 2) 정답을 맞추면
				printf("%s! 정답입니다.\n", w.ans);
				if (w.score == 10) {
					printf("만점이므로 상품을 드리겠습니다!~~\n");
				}
				break;
			}
		} //문제 풀기 끝
		
		do {
			printf("게임을 계속 하시겠습니가????? Y/N");
			scanf(" %c", &ch);
		} while (!(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n'));
		
		if (ch == 'N' || ch == 'n') {
			break;
		}
	}
}


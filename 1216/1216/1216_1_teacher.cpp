
#include<stdio.h>
#include<string.h>
#define MAX 5
// ����ܾ�: apple
// ����ܾ�: _____
// ����: ��x3
typedef struct WORD {
	char ans[10];
	char show[10];
	int score;
}W;
void main() {

	char ans;
	W w;

	while (1) {
		printf("������ �����ϼ���.  ");
		scanf("%s", w.ans);
		for (int i = 0; i < strlen(w.ans); i++) {
			w.show[i] = '_';
		}
		w.show[strlen(w.ans)] = '\0'; // _____ + '\0'
		w.score = MAX;
		/*
		// ���ڹ迭 + '\0' == ���ڿ�
		char str1[] = "apple"; // ���ڿ�
		char str2[] = { 'a','p','p','l','e','\0' }; // ���ڿ�
		char arr[] = { 'a','p','p','l','e' }; // ���ڹ迭
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
					check = 1; // ����ڰ� �Է��� ���ڸ� ã����, check������ 1�� �ٲ�!
				}
			}
			if (check == 0) {
				printf("%c�� �����ϴ�!\n", c);
				w.score--;
			}
			if (w.score == 0) { // 1) ������ ������,
				printf("GameOver...\n");
				break;
			}
			else if (strcmp(w.ans, w.show) == 0) { // 2) ������ ���߸�,
				printf("%s! �����Դϴ�!!\n", w.ans);
				if (w.score == MAX) {
					printf("��ǰ�� �帮�ڽ��ϴ�!~~\n");
				}
				break;
			}
		}
		do {
			printf("���� ����Ͻðڽ��ϱ�?  ");
			scanf(" %c", &ans);
		} while (!(ans == 'Y' || ans == 'y' || ans == 'N' || ans == 'n'));
		if (ans == 'N' || ans == 'n') {
			break;
		}
	}

}
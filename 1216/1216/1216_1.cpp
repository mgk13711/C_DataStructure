
#include<stdio.h>
#include<string.h>
//����ܾ�: apple
//����ܾ�: _____
//����: ��x3
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
		printf("������ �����ϼ���. ");
		scanf("%s", w.ans);
		
		init(&w);

		printf("%s\n", w.ans);
		printf("%s\n", w.show);

		printf("********\n");

		char ch;
		while (1) {  //���� Ǯ�� ����
			
			printf("��x%d", w.score);
			printf("%s: ", w.show);
			scanf(" %c", &ch);

			int check = 0; // 0:F, 1~:T
			for (int i = 0; i < strlen(w.ans); i++) {
				if (w.ans[i] == ch) {
					w.show[i] = ch; //ã�Ҵ�
					check++;
				}
			}
			if (check == 0) {
				printf("%c�� �����ϴ�!\n", ch);
				w.score--;
			}

			if (w.score == 0) { // 1) ������ ���ϸ�
				printf("game over...\n");
				break;
			}
			else if (strcmp(w.ans, w.show) == 0) { // 2) ������ ���߸�
				printf("%s! �����Դϴ�.\n", w.ans);
				if (w.score == 10) {
					printf("�����̹Ƿ� ��ǰ�� �帮�ڽ��ϴ�!~~\n");
				}
				break;
			}
		} //���� Ǯ�� ��
		
		do {
			printf("������ ��� �Ͻðڽ��ϰ�????? Y/N");
			scanf(" %c", &ch);
		} while (!(ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n'));
		
		if (ch == 'N' || ch == 'n') {
			break;
		}
	}
}


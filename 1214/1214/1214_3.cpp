#include<stdio.h>
#include<stdlib.h>
#define TEST 2 // ��ȣ���
typedef struct student {
	//�̸� ����1 ����2 ���
	char name[10];
	int score[2];
	double avg;
}STU;
void main() {
	
	int N;
	printf("�л� �� �Է�: ");
	scanf("%d", &N);

	STU* s = (STU*)malloc(N*sizeof(STU));

	//���� ������ ���� �л��� �̸� ���

	for (int i = 0; i < N; i++) {
		printf("%d��° �л����� �Է���...\n", i + 1);
		printf("�̸�: ");
		scanf("%s", s[i].name);
		s[i].avg = 0.0;
		for (int j = 0; j < TEST; j++) {
			printf("%d��° ����: ", j + 1);
			scanf("%d", &s[i].score[j]);
			s[i].avg += s[i].score[j];
		}
		s[i].avg /= TEST*1.0;
	}

	double max = s[0].avg;
	int maxIndex = 0;
	for (int i = 1; i < N; i++) {
		if (max < s[i].avg) {
			max = s[i].avg;
			maxIndex = i;
		}
	}
	printf("1�� �л��� �̸���: %s\n", s[maxIndex].name);

	free(s);
}
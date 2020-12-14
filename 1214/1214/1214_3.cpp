#include<stdio.h>
#include<stdlib.h>
#define TEST 2 // 기호상수
typedef struct student {
	//이름 성적1 성적2 평균
	char name[10];
	int score[2];
	double avg;
}STU;
void main() {
	
	int N;
	printf("학생 수 입력: ");
	scanf("%d", &N);

	STU* s = (STU*)malloc(N*sizeof(STU));

	//가장 성적이 좋은 학생의 이름 출력

	for (int i = 0; i < N; i++) {
		printf("%d번째 학생정보 입력중...\n", i + 1);
		printf("이름: ");
		scanf("%s", s[i].name);
		s[i].avg = 0.0;
		for (int j = 0; j < TEST; j++) {
			printf("%d번째 시험: ", j + 1);
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
	printf("1등 학생의 이름은: %s\n", s[maxIndex].name);

	free(s);
}
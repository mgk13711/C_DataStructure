//학생부 프로그램 - 구조체 활용
#include<stdio.h>
#define SU 5
// 이름, 성적(정수), 번호(정수)
typedef struct student {
	char name[20]; //overflow나지 않도록 크게 여유있게 선언
	//한글은 ascii code가 아닌 unicode라서 글자마다 바이트수가 다르다 그래서 좀 여유있게함
	int num;
	int score;
}STU;

void f1(STU* book, int index, int num) {
	printf("학생이름 입력: ");
	scanf("%s", book[index].name);
	printf("성적입력: ");
	scanf("%d", &book[index].score);
	book[index].num = num++;
	printf("%s학생 등록완료!\n", book[index++].name);
}

void f3(STU* book, int index) {
	for (int i = 0; i < index; i++) {
		printf("%d번 학생 이름: %s", book[i].num, book[i].name);
		printf("성적: %d\n", book[i].score);
	}
}

void f4(STU* book, int index) {
	int n, m;	
	do {
		printf("수정할 학생의 번호를 입력: ");
		scanf("%d", &n);
	} while (n <= 1000 || 2000 <= n);

	for (int i = 0; i < index; i++) { // 해당 학생이 있는지 검색
		if (n == book[i].num) {
			n = i;
			break;
		}
	}
	if (n > 1000) { // 이부분 잘 모르겠어
		printf("해당 학생은 존재하지 않습니다.!!\n");
		return;
	}

	do {
		printf("1) 이름수정, 2) 성적수정 : ");
		scanf("%d", &m);
	} while (m < 1 || 2 < m);

	if (m == 1) {
		printf("이름 재입력: ");
		scanf("%s", book[n].name);
	}
	else {
		printf("성적 재입력: ");
		scanf("%d", &book[n].score);
	}
	printf("학생 수정 완료!\n");
}

void main() {
	STU book[SU]; // 학생부 == 구조체 배열 => 배열(제한적인 크기를 갖기에 항상 크기를 넘어서는지 확인필요)
	int index = 0; // 학생부의 현재 index
	int num = 1001; // 학생번호 지정
	//int N;
	//STU* book = (STU*)malloc(N * scanf("%d", &N));

	int act;
	while (1) { // 무한루프 --> 종료조건 먼저 구현
		printf("\n=========================\n");
		printf("1.입력 2.삭제 3.출력 4.수정 5.종료\n");
		printf("번호입력: ");
		scanf("%d", &act);

		if (act == 1) { // 입력
			if (index == SU) { //학생부에 학생이 가득찬다면,
				printf("더이상 입력하실 수 없습니다.!\n");
				continue;//가장 가까운 반복문으로 돌아감
			}
			f1(book, index++, num++);
		}
		else if (act == 2) { // 최근 데이터 삭제
			if (index == 0) {
				printf("삭제할 학생 없음!\n");
				continue;
			}
			index--;
			printf("학생삭제 완료!\n");
		}
		else if (act == 3) { // 출력
			if (index == 0) {
				printf("아직은 학생이 없습니다!\n");
				continue;
			}
			f3(book, index);
		}
		else if (act == 4) { // 수정
			// 누구
			// 이름? 성적?

			// 잘못된 번호 처리
			if (index == 0) {
				printf("수정할 학생이 없습니다!\n");
				continue;
			}
			f4(book, index);
		}
		else if (act == 5) {
			printf("프로그램 종료...\n");
			break;
		}
		else { // [유효성 검증]
			printf("잘못된 입력!!");
		}
	}
}

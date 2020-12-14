//학생부 프로그램 - 구조체 활용
#include<stdio.h>
// 이름, 성적(정수), 번호(정수)
typedef struct student {

}STU;
void main() {

	int act;
	while (1) { // 무한루프 --> 종료조건 먼저 구현
		printf("=========================\n");
		printf("1.입력 2.삭제 3.출력 4.수정 5.종료\n");
		printf("번호입력: ");
		scanf("%d", &act);

		if (act == 1) {

		}
		else if (act == 2) {

		}
		else if (act == 3) {

		}
		else if (act == 4) {

		}
		else if (act == 5) {
			printf("프로그램 종료...\n");
			break;
		}
		else { // [유효성 검증]
			printf("잘못된 입력!!")
		}

	}
}

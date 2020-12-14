#include<stdio.h>
#include<string.h>

typedef struct student { // 구조체 선언, 생성
	char name[10]; // 멤버 == 멤버변수 == 필드 == 속성 == attribute
	int age;
	double score;
	char grade;
}STU; // 자료형으로 생성해버림

void main() {
	struct student s1 = { "kim", 20, 3.14, 'c' }; // 구조체 instancing
	int i = 10;
	int arr[3] = { 1, 2, 3 }; // 배열
	struct student s2;

	strcpy(s2.name, "lee"); // string.h

	s2.age = 10;  // . : 멤버 접근 연산자
	s2.grade = 'B';

	struct student s3;

	printf("이름 입력: ");
	scanf("%s", s3.name); // s3.name은 배열의 이름이기에 &를 넣지 않아도 됨
	printf("성적 입력: ");
	scanf("%lf", &s3.score);
	printf("나이 입력: ");
	scanf("%d", &s3.age);
	printf("학점 입력: ");
	scanf(" %c", &s3.grade);

	printf("%s %d살 %.2lf점 %c학점\n", s3.name, s3.age, s3.score, s3.grade);
}
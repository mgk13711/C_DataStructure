#include<stdio.h>
#include<string.h>

typedef struct student { // ����ü ����, ����
	char name[10]; // ��� == ������� == �ʵ� == �Ӽ� == attribute
	int age;
	double score;
	char grade;
}STU; // �ڷ������� �����ع���

void main() {
	struct student s1 = { "kim", 20, 3.14, 'c' }; // ����ü instancing
	int i = 10;
	int arr[3] = { 1, 2, 3 }; // �迭
	struct student s2;

	strcpy(s2.name, "lee"); // string.h

	s2.age = 10;  // . : ��� ���� ������
	s2.grade = 'B';

	struct student s3;

	printf("�̸� �Է�: ");
	scanf("%s", s3.name); // s3.name�� �迭�� �̸��̱⿡ &�� ���� �ʾƵ� ��
	printf("���� �Է�: ");
	scanf("%lf", &s3.score);
	printf("���� �Է�: ");
	scanf("%d", &s3.age);
	printf("���� �Է�: ");
	scanf(" %c", &s3.grade);

	printf("%s %d�� %.2lf�� %c����\n", s3.name, s3.age, s3.score, s3.grade);
}
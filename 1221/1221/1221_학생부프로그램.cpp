//�л��� ���α׷� - ����ü Ȱ��
#include<stdio.h>
#define SU 5
// �̸�, ����(����), ��ȣ(����)
typedef struct student {
	char name[20]; //overflow���� �ʵ��� ũ�� �����ְ� ����
	//�ѱ��� ascii code�� �ƴ� unicode�� ���ڸ��� ����Ʈ���� �ٸ��� �׷��� �� �����ְ���
	int num;
	int score;
}STU;

void f1(STU* book, int index, int num) {
	printf("�л��̸� �Է�: ");
	scanf("%s", book[index].name);
	printf("�����Է�: ");
	scanf("%d", &book[index].score);
	book[index].num = num++;
	printf("%s�л� ��ϿϷ�!\n", book[index++].name);
}

void f3(STU* book, int index) {
	for (int i = 0; i < index; i++) {
		printf("%d�� �л� �̸�: %s", book[i].num, book[i].name);
		printf("����: %d\n", book[i].score);
	}
}

void f4(STU* book, int index) {
	int n, m;	
	do {
		printf("������ �л��� ��ȣ�� �Է�: ");
		scanf("%d", &n);
	} while (n <= 1000 || 2000 <= n);

	for (int i = 0; i < index; i++) { // �ش� �л��� �ִ��� �˻�
		if (n == book[i].num) {
			n = i;
			break;
		}
	}
	if (n > 1000) { // �̺κ� �� �𸣰ھ�
		printf("�ش� �л��� �������� �ʽ��ϴ�.!!\n");
		return;
	}

	do {
		printf("1) �̸�����, 2) �������� : ");
		scanf("%d", &m);
	} while (m < 1 || 2 < m);

	if (m == 1) {
		printf("�̸� ���Է�: ");
		scanf("%s", book[n].name);
	}
	else {
		printf("���� ���Է�: ");
		scanf("%d", &book[n].score);
	}
	printf("�л� ���� �Ϸ�!\n");
}

void main() {
	STU book[SU]; // �л��� == ����ü �迭 => �迭(�������� ũ�⸦ ���⿡ �׻� ũ�⸦ �Ѿ���� Ȯ���ʿ�)
	int index = 0; // �л����� ���� index
	int num = 1001; // �л���ȣ ����
	//int N;
	//STU* book = (STU*)malloc(N * scanf("%d", &N));

	int act;
	while (1) { // ���ѷ��� --> �������� ���� ����
		printf("\n=========================\n");
		printf("1.�Է� 2.���� 3.��� 4.���� 5.����\n");
		printf("��ȣ�Է�: ");
		scanf("%d", &act);

		if (act == 1) { // �Է�
			if (index == SU) { //�л��ο� �л��� �������ٸ�,
				printf("���̻� �Է��Ͻ� �� �����ϴ�.!\n");
				continue;//���� ����� �ݺ������� ���ư�
			}
			f1(book, index++, num++);
		}
		else if (act == 2) { // �ֱ� ������ ����
			if (index == 0) {
				printf("������ �л� ����!\n");
				continue;
			}
			index--;
			printf("�л����� �Ϸ�!\n");
		}
		else if (act == 3) { // ���
			if (index == 0) {
				printf("������ �л��� �����ϴ�!\n");
				continue;
			}
			f3(book, index);
		}
		else if (act == 4) { // ����
			// ����
			// �̸�? ����?

			// �߸��� ��ȣ ó��
			if (index == 0) {
				printf("������ �л��� �����ϴ�!\n");
				continue;
			}
			f4(book, index);
		}
		else if (act == 5) {
			printf("���α׷� ����...\n");
			break;
		}
		else { // [��ȿ�� ����]
			printf("�߸��� �Է�!!");
		}
	}
}

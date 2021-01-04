#include<stdio.h>
#include<stdlib.h>
#include<string>
char title[5][20] = { "����", "��", "����ƮȨ" }; //��ȭ ���� �ִ� 5�� -> [5]
int cnt = 3; //��ȭ ��
char cinema[][10] = { "MEGA", "LOTTE", "CGV" }; //��ȭ������ 3���� ���� -> []
typedef struct MOVIE {
	char title[20];
	int time;
	char cinema[10];
	int num;	
}M;
typedef struct NODE {
	char name[10];
	M data;
	struct NODE* next;
}N;
typedef struct Queue {
	N* front;
	N* rear;
	int size;
}Q;
void managerMode() {
	printf("�١ڰ����� ���ڡ�\n");
	if (cnt == 5) {
		printf("���̻� ��ȭ�� �߰��� �� �����ϴ�.\n");
		return;
	}
	printf("�߰��Ͻ� ��ȭ������ �Է��ϼ���: ");
	scanf("%s", title[cnt++]);
	printf("��ȭ �߰��Ϸ�!\n");
}
void Enqueue(Q* q) {
	// 1. �̸��Է�
	// 2. ��ȭ ������
	// 3. �ð��Է�
	// 4. ��ȭ�� ����
	// 5. �����ȣ ����
	N* node = (N*)malloc(sizeof(N));
	node->next = NULL;

	printf("�̸��Է�: ");
	scanf("%s", node->name);
	
	int num;
	do {
		printf("��ȭ ������: [ ");
		for (int i = 0; i < cnt; i++) {
			printf("%d.%s  ", i + 1, title[i]);
		}
		printf(" ]\n");
		scanf("%d", &num);
	} while (num<1 || num>cnt);
	strcpy(node->data.title, title[num-1]);

	printf("�ð��Է�: ");
	scanf("%d", &node->data.time);

	printf("��ȭ�� ����: ");
	do {
		printf("[ ");
		for (int i = 0; i < 3; i++) {
			printf("%d.%s  ", i + 1, cinema[i]);
		}
		printf(" ]\n");
		scanf("%d", &num);
	} while (num<1 || num>3);
	strcpy(node->data.cinema, cinema[num - 1]);

	node->data.num = num * 1000 + rand() % 998 + 1;
	printf("%s��, �����ȣ�� [%d]�Դϴ�.\n\n", node->name, node->data.num);

	if (q->size == 0) {
		q->front = node;
	}
	else {
		q->rear->next = node;  //���� ������
	}
	q->rear = node;  //���� ������
	q->size++;
}
int Dequeue(Q* q) {
	int num;
	for (int i = 0; i < 2; i++) {
		printf("%s��, �����ȣ��? ", q->front->name);
		scanf("%d", &num);
		if (num == q->front->data.num) {
			printf("%d�� [%s]��ȭ %s���� ��ſ�����Ǽ���~^^\n", q->front->data.time, q->front->data.title, q->front->data.cinema);

			q->front = q->front->next;
			q->size--;
			return 0; // ���强��
		}
		printf("%dȸ����! 2ȸ������ �ٽ� �����ϼž��մϴ�!\n", i + 1);
	}
	return 1; // �ٽô��
}
void roll(Q* q) {
	q->rear->next = q->front;
	q->rear = q->rear->next;
	q->front = q->front->next;

	q->rear->next = NULL;
	printf("%s�� ���� ���� �ڷ� �̵���\n", q->rear->name);
}
void main() {
	int act;
	Q q;
	q.front = NULL;
	q.rear = NULL;
	q.size = 0;

	while (1) {
		printf("== ��ȭ ���� �ý���==\n");
		printf("1. ���� 2.���� 3.����ο� 4.����\n");
		printf("�Է�: ");
		scanf("%d", &act);
		if (act == 0) { //0. ������ ���
			managerMode();
		}
		else if (act == 1) { //1. ����
			Enqueue(&q);
		}
		else if (act == 2) { 
			// 1. �������? �ٽ��Է�
			// 2. kim��, �����ȣ��? 2ȸ�̻�Ʋ���� roll() / Dequeue()+
			int num;
			while (1) {
				printf("��������Ͻðڽ��ϱ�? ");
				scanf("%d", &num);
				if (num <= 0) {
					printf("��ȿ�� �Է��� �ƴմϴ�!\n");
				}
				else if (num > q.size) {
					printf("����ο��� �ٽ� Ȯ�����ּ���!\n");
				}
				else {
					break;
				}
			}
			for (int i = 0; i < num; i++) {
				if (Dequeue(&q)) {
					// Dequeue()��� 1�� return�Ǹ�,
					// roll()����
					roll(&q);
				}
			}
		}
		else if (act == 3) { // 3.����ο�
			printf("���� ����ο��� [%d]�� �Դϴ�.\n\n", q.size);
		}
		else if (act == 4) {
			printf("���α׷� ����...\n");
			break;
		}
		else {
			printf("�߸��� �Է��Դϴ�!!\n\n");
		}
	}
}
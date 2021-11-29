#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//_crt_secure_no_warnings;
#define MAX 100001
//211130����
//scanf_ & scanf ����
//scanf("%d\n",&item); ���� \n����

typedef struct stackNode {
	int data;
	struct stackNode* link;
}stackNode;

stackNode* top;

void push(int item) {
	stackNode* k = (stackNode*)malloc(sizeof(stackNode));
	k->data = item;
	k->link = top;
	top = k;
}

int pop() {
	int item;
	stackNode* k = top;
	if (top == NULL) exit(1);	
	item = k->data;
	top = k->link;
	free(k);
	return item;
}
//1.÷������ 2.��ȣ 3.1���� ��������迭
char sort(int* seq , int how) {
	char sign[100000]; //��ȣ
	int num = 1;//��ȣ�������,1���� �����ҿ���,push�� �����������
	push(num);
	for (int i = 0; i < how; i++) {//���°�� �´�������
		printf("%d��° �Դϴ�.\n", i);
		while(1) {//1���� �����ҿ���
			if (num == seq[i]) {
				printf("������\n");
				if (pop() != i) { printf("NO"); return 0; }
				sign[num] = "-";
				break;
			}
			else if (num < seq[i]) {
				printf("������\n");
				num++;
				push(num);
				sign[num] = "+";
			}
			else if (num > seq[i]) {
				printf("Ŭ��\n");
				if (pop() != i) { printf("NO"); return 0; }
				num++;
				sign[num] = "-";
				break;
			}
			
		}

	}
	for (int k = 1; k <= how; k++) {
		printf("%d\n", sign[k]);
	}
	
}
int main() {
	int how = 0;
	int seq[MAX];
	scanf("%d", &how);	
	for (int i = 0; i < how; i++) {
		scanf_s("%d", &seq[i]);	
	}
	sort(seq, how);
}



//8
//
//43687521
//
//1.seq[1]�� ���ö����� push �� 4������pop�� - ���
//2.if seq[1] > seq[2] ��pop�� - ���
//3.seq[2] > seq[3]�� pop �� - ���
//�ƴ϶�� seq[3]���ö����� push
//4.seq[4] > seq[5]�� pop �ƴ϶�� seq[5]���ö����� push ������ pop�� - ���
//5.seq[5] > seq[6]�̴� pop�� - ���
//6.seq[6] > seq[7]�̴� pop�� - ���
//7.seq[7] > seq[8]�̴� pop�� - ���
//
//1.seq[i] > seq[i + 1]�Ͻ� pop�� - ���
//2.seq[i] < seq[i + 1]�Ͻ� seq[i + 1]���ö����� push�� + ����� pop�� - ���
//
//
//	12534
//	1.seq[1]���ö����� push�� + ����� == seq[1]�� �̰��� ������ ���غ��� pop�� �迭�� - ���� ==
//	2.seq[1] < seq[2]�̹Ƿ� ���ô���� push�� + ����� pop���
//	3.seq[2]<seq[3]�̹Ƿ� ���ö����� push�� + ����� pop�� - ���
//	4.seq[3]>seq[4]�̹Ƿ� == seq[4]�� �̰��� ������ ���غ��� pop�� - ��� == ���� ���������� NO���
//
//	���������� �迭�� ����� + �� - ��ȣ�� ������� ���\n�ʼ�
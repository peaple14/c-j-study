#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//_crt_secure_no_warnings;
#define MAX 100000
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
//1243
//2314
//12
char sort(int* seq, int how) {
	char sign[MAX * 2]; //��ȣ������
	//int num = 1;//��ȣ�������,1���� �����ҿ���,push�� �����������
	//push(num);
	//for (int i = 0; i < how; i++) {//���°�� �´�������
	//	//printf("%d��°�� �Դϴ�. ����num�� %d�Դϴ�.\n", i + 1, num);
	//	while (1) {//1���� �����ҿ���
	//		if (num == seq[i]) {
	//			int save = num;//���������� ������츦 ����
	//			while (1) {
	//				int backup = pop();//Ȯ�ο�
	//				if (save  == (backup = pop())) {
	//					seq[i] = "-";
	//					i++;
	//					continue;
	//				}
	//				else(push(backup));
	//				if (num > how) i += how;
	//				break;
	//			}
	//			num++;
	//			sign[num] = "-";
	//			if (num > how) i += how;
	//			break;
	//		}
	//		else if (num < seq[i]) {
	//			num++;
	//			push(num);
	//			sign[num] = "+";
	//			if (num > how) i += how;
	//		}
	//		else if (num > seq[i]) {
	//			printf("NO"); return 0;
	//		}
	//	}
	//}
	//printf("num�� %d�Դϴ�!!!!���̴�!", num);
	//printf("%s", sign[1]);
	//for (int k = 1; k < num; k++) {
	//	
	//	/*printf("%s\n", sign[k]);*/
	//}'
	int num = 1;//�����ϴ¼���
	push(num);
	int point = 0; // sign�� ������� ��ǥ
	for (int i = 0; i < how; i++) {
		if (seq[i] == num) {
			pop();
			sign[point] = "-";
			num++;
			point++;
			printf("�̰žȺ��̳�\n");
		}
		else if (seq[i] < num) {
			push(num);
			num++;
			sign[point] = "+";
			point++;
		}
	}
	printf("�ݺ��̴�\n");
	printf("%s", sign[0]);
	for (int k = 0; k < num; k++) {
		printf("%s\n", sign[k]);
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



//43687521
//1.seq[1]�� ���ö����� push �� 4������pop�� - ����
//2.if seq[1] > seq[2] ��pop�� - ����
//3.seq[2] > seq[3]�� pop �� - ����
//�ƴ϶�� seq[3]���ö����� push�� + ����
//4.seq[4] > seq[5]�� pop �ƴ϶�� seq[5]���ö����� push ������ pop�� - ����
//5.seq[5] > seq[6]�̴� pop�� - ����
//6.seq[6] > seq[7]�̴� pop�� - ����
//7.seq[7] > seq[8]�̴� pop�� - ����
//======
//34
//12534
//1.seq[1]���ö����� push�� + ����� == seq[1]�� �̰��� ������ ���غ��� pop�� �迭�� - ���� ==
//2.seq[1] < seq[2]�̹Ƿ� ���ô���� push�� + ������ pop�� - ����
//	3.seq[2]<seq[3]�̹Ƿ� ���ö����� push�� + ������ pop�� - ����
//	4.seq[3]>seq[4]�̹Ƿ� == seq[4]�� �̰��� ������ ���غ��� pop�� - ���� == ���� ���������� NO���
//
//	���������� �迭�� ����� + �� - ��ȣ�� ������� ���\n�ʼ�
//	//////////////////////////////////////////////////////////////////////////////////////////////////////
//	123
//	4 3 6 8 7 5 2 1
//	0.//num = 1
//	1.num < seq[1]�̹Ƿ� num++�� push�� + ���� //num = 2
//	2.num < seq[1]�̹Ƿ� num++�� push�� + ���� //num = 3
//	3.num < seq[1]�̹Ƿ� num++�� push�� + ���� //num = 4
//	4.num = seq[1]�̹Ƿ� pop�� - ���� // num = 4
//	5.num = seq[2]�̹Ƿ� pop�� - ���� // num = 4(�� ���ǰ� ������ Ȯ���� �ٽ� ����ֱ�)
//	6. num<seq[3]�̹Ƿ� num++�� push�� + ���� //num = 5
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	0.�ϴ� �������� num ���� 1�� ��Ӵþ.�迭�� 2���� 1.ó�����������(seq) 2.��ȣ(���� ũ�Ը����)
//	������ ������.1���� ��� �����ϴ½���(push�� pop�� �Ҽ��ִ� ����)
//
//
//	1.seq[i]>seq[i + 1]�Ͻ� pop�� - �迭�� ������ i++
//	2.seq[i] < seq[i + 1]�Ͻ� seq[i + 1]���ö����� push�� + �迭�� ������ pop���� seq[i + 1]�� pop�� ���ϰ� ������ - ����
//	Ʋ���� return 1 �ϰ� NO���.
//
//
//	1.������ ó��������
//	2.f or ��� ����(how�� ������ �����ؾ���)
//	3.��ȣ�־��ִ� �������� k(���° �迭�� ���������� ������++)(while ���Ͻ� break ��)
//
//	12
//	321
//	0.//num = 1
//	1.�����Ƿ� pop�� - ���� // num = 1
//	2.num < seq[2]�̹Ƿ� num++ �� push �ϰ� + ����
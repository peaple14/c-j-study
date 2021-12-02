#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define ���� �Ҷ� ����ġ�� ū���� �迭������ �����ɸ��Ƿ� ���������� �����ϱ�.
//��ū��
//����:�ڽ��� �����ʿ� �����鼭 �ڱ� �ڽź��� ū �� �߿��� ���� ���ʿ� �ִ� ���� ���Ѵ�.
//������ �׼����,���ٸ� -1���

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

int topp() {
	stackNode* k = top;
	return k->data;
}

int isEmpty() {
	return (top == -1) ? 1 : 0;
}

int how = 0;//Ƚ��
int a[1000000];//����
int bkup[1000000]; // ���Ұ� �����ϴ°�

int main() {
	scanf_s("%d", &how);
	for (int i = 0; i < how; i++) {
		scanf_s("%d", &a[i]);
		bkup[i] = -1;
	}
	push(0);
	for (int i = 0; i < how; i++) {

		while (!isEmpty() && a[topp()] < a[i]) {
			bkup[pop()] = a[i];
		}
		push(i);

	}

	for (int p = 0; p < how; p++) {
		printf("gd");
		printf("%d ", bkup[p]);
	}
}
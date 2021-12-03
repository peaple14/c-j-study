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
	top = -1;
	scanf_s("%d", &how);
	for (int i = 0; i < how; i++) {
		scanf_s("%d", &a[i]);
	}
	push(0);
	for (int i = 1; i < how; i++) {
		if (isEmpty()) {
			push(i);
		}
		while (!isEmpty() && a[topp()] < a[i]) {
			bkup[topp()] = a[i];
			pop();
		}
		push(i);
	}
	while (!isEmpty()) {
		bkup[topp()] = -1;
		pop();
	}

	for (int p = 0; p < how; p++) {
		printf("%d ", bkup[p]);
	}
}


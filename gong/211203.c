#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define 으로 할때 지나치게 큰수로 배열생성시 오류걸리므로 전역변수로 생성하기.
//오큰수
//정의:자신의 오른쪽에 있으면서 자기 자신보다 큰 수 중에서 가장 왼쪽에 있는 수를 말한다.
//있으면 그수출력,없다면 -1출력

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

int how = 0;//횟수
int a[1000000];//갯수
int bkup[1000000]; // 비교할것 저장하는것

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


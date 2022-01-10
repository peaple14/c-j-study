#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100

//�����ڷᱸ���̿�

//typedef int element; //���ÿ���
//
//element stack[STACK_SIZE]; //�迭 ����
//int top = -1; //top �ʱ�ȭ
//
////����������� Ȯ��
//int isEmpty() {
//	if (top == -1) return 1; //����ִٸ�
//	else return 0; //���� �ʾҴٸ�
//}
//
////��á����(��ȭ����)�ƴ���
//int isFull() {
//	if (top == STACK_SIZE - 1) return 1; //��á�ٸ�
//	else return 0; //������ �ʾҴٸ�
//}
//
////���ҳֱ�
//void push(element item) {
//	if (isFull()) { //��á�ٸ�
//		printf("\n\n Stack is FULL! \n");
//		return;
//	}
//	else stack[++top] = item; //top�� 1���ϰ�(������Ű��) ���һ���
//}
//
////���һ���
//element pop() {
//	if (isEmpty()) { //����ִٸ�
//		printf("\n\n Stack is Empty!!\n");
//		return 0;
//	}
//	else return stack[top--]; //���һ����� top���ҽ�Ŵ
//}
//
//element peek() {
//	if (isEmpty()) {
//		printf("\n\n Stack is Empty!!\n");
//		exit(1);
//	}
//	else return stack[top]; //ã�Ҵٸ� ����top���� Ȯ��
//}
//
////���
//void printStack() {
//	int i;
//	printf("\n STACK{ ");
//	for (i = 0; i <= top; i++)//top�� 0�϶����� ������ ���
//		printf("%d", stack[i]);
//	printf("]");
//}
//
////test��
//void main(void) {
//	element item;
//	printf("\n** ���� ���� ���� **\n");
//	printStack();
//	push(1); printStack();
//	push(2); printStack();
//	push(3); printStack();
//
//	item = peek(); printStack();
//	printf("peek => %d ", item);
//
//	item = pop(); printStack();
//	printf("\t pop   => %d ", item);
//
//	item = pop(); printStack();
//	printf("\t pop   => %d ", item);
//
//	item = pop(); printStack();
//	printf("\t pop   => %d ", item);
//
//	getchar();
//}

typedef int element;

//���ó�� ����ü
typedef struct stackNode {
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;

//�������� Ȯ��
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

//top����
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode)); 
	temp->data = item;
	temp->link = top;
	top = temp; //top��ġ �̵�
}

element pop() { //void �� ���� ���Ѵ� @@@@@@@@@@@@@@@@@
	element item;
	stackNode *temp = top;

	if (top == NULL) { //���������
		printf("\n\n Stack is empty!\n");
		return 0;
	}
	else {
		item = temp->data; //�����ֱ�� ������
		top = temp->link; //top ��ĭ ������
		free(temp); //temp�� �����ְ�
		return item; //�����ֱ�� item ����
	}
}

//����ã���
element peek() {
	if (top == NULL) {//��ã����
		printf("\n\n Stack is Empty");
		return 0;
	}
	else {//ã����
		return(top->data);
	}
}

//���ÿ� ���ִ��� �����ֱ��
void printStack() {
	stackNode* p = top; //top���� ����
	printf("\n STACK [");
	while (p) { //�ٴڱ��� ��������
		printf("%d ", p->data);
		p = p->link; //��ĭ ������
	}
	printf("] ");
}
//�׽�Ʈ��
void main(void) {
	element item;
	top = NULL;
	printf("\n** ���� ���� ���� **\n");
	printStack();
	push(1);   printStack();
	push(2);   printStack();
	push(3);   printStack();

	item = peek(); printStack();
	printf("peek =>%d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	getchar();
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int element;

//���ó�� ����ü
typedef struct stackNode {
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;

//�������� Ȯ��
int isEmpty() {
	return (top < 0);
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
	stackNode* temp = top;

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
////�ְ�ȣ �˻�
//int testPair(char* exp) {
//	char symbol, open_pair;
//
//	int i, length = strlen(exp); //�������
//	top = NULL;
//
//	for (i = 0; i < length; i++) { //������ ���� �ɶ�����
//		symbol = exp[i]; //symbol�� �������
//		switch (symbol) { //���°��� �̰��Ͻ�
//		case'(':
//		case'[':
//		case'{':
//			push(symbol); break;
//		case')':
//		case']':
//		case'}':
//			if (top == NULL) return 0; //������
//			else {
//				open_pair = pop(); //���ٸ� pop�Ѵ�
//
//				if((open_pair == '(' && symbol != ')')|| //���� �����ʴٸ�
//				   (open_pair =='[' && symbol != ']') ||
//				   (open_pair == '}' && symbol != '}'))
//					return 0;
//					
//				else break;
//			}
//		}
//	}
//	if (top == NULL) return 1;
//	else return 0;
//}
////Ȯ�ο�
//void main(void) {
//	char* express = "{(A+B)-3}*5+[{cos(s+y)+z}-1]*4";
//	printf("%s", express);
//
//	if (testPair(express) == 1)
//		printf("\n\n������ ��ȣ�� �°� ���Ǿ����ϴ�!");
//	else
//		printf("\n\n������ ��ȣ�� Ʋ�Ƚ��ϴ�!");
//
//	getchar();
//}


////����ǥ���
//element evalPostfix(char* exp) {
//	int opr1, opr2, value, i = 0;
//	int length = strlen(exp);
//	char symbol; 
//	top = NULL;
//
//	for (i = 0; i < length; i++) {
//		symbol = exp[i];
//		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') { //���� ������(��ȣ)�϶�
//			value = symbol - '0'; //���� �ǿ�����(����) �϶�
//			push(value);
//		}
//		else {
//			opr2 = pop();
//			opr1 = pop();
//
//			switch (symbol) {
//			case'+': push(opr1 + opr2); break;
//			case'-': push(opr1 - opr2); break;
//			case'*': push(opr1 * opr2); break;
//			case'/': push(opr1 / opr2); break;
//			}
//		}
//	}
//	return pop();
//}
//
////������
//void main(void) {
//	int result;
//	char* express = "35*62/-";
//	printf("���� ǥ���: %s", express);
//
//	result = evalPostfix(express);
//	printf("\n\n���� ��� => %d", result);
//
//	getchar();
//}
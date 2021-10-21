#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int element;

//스택노드 구조체
typedef struct stackNode {
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;

//공백인지 확인
int isEmpty() {
	return (top < 0);
}

//top삽입
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp; //top위치 이동
}

element pop() { //void 는 리턴 못한다 @@@@@@@@@@@@@@@@@
	element item;
	stackNode* temp = top;

	if (top == NULL) { //비어있을때
		printf("\n\n Stack is empty!\n");
		return 0;
	}
	else {
		item = temp->data; //보여주기용 아이템
		top = temp->link; //top 한칸 내리고
		free(temp); //temp값 없애주고
		return item; //보여주기용 item 리턴
	}
}
////쌍괄호 검사
//int testPair(char* exp) {
//	char symbol, open_pair;
//
//	int i, length = strlen(exp); //길이재긱
//	top = NULL;
//
//	for (i = 0; i < length; i++) { //길이의 끝이 될때까지
//		symbol = exp[i]; //symbol에 집어넣음
//		switch (symbol) { //들어온것이 이것일시
//		case'(':
//		case'[':
//		case'{':
//			push(symbol); break;
//		case')':
//		case']':
//		case'}':
//			if (top == NULL) return 0; //끝날시
//			else {
//				open_pair = pop(); //같다면 pop한다
//
//				if((open_pair == '(' && symbol != ')')|| //만약 맞지않다면
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
////확인용
//void main(void) {
//	char* express = "{(A+B)-3}*5+[{cos(s+y)+z}-1]*4";
//	printf("%s", express);
//
//	if (testPair(express) == 1)
//		printf("\n\n수식의 괄호가 맞게 사용되었습니다!");
//	else
//		printf("\n\n수식의 괄호가 틀렸습니다!");
//
//	getchar();
//}


////후위표기식
//element evalPostfix(char* exp) {
//	int opr1, opr2, value, i = 0;
//	int length = strlen(exp);
//	char symbol; 
//	top = NULL;
//
//	for (i = 0; i < length; i++) {
//		symbol = exp[i];
//		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') { //만약 연산자(기호)일때
//			value = symbol - '0'; //만약 피연산자(숫자) 일때
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
////연습용
//void main(void) {
//	int result;
//	char* express = "35*62/-";
//	printf("후위 표기식: %s", express);
//
//	result = evalPostfix(express);
//	printf("\n\n연산 결과 => %d", result);
//
//	getchar();
//}
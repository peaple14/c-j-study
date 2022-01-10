#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100

//순차자료구조이용

//typedef int element; //스택원소
//
//element stack[STACK_SIZE]; //배열 선언
//int top = -1; //top 초기화
//
////공백상태인지 확인
//int isEmpty() {
//	if (top == -1) return 1; //비어있다면
//	else return 0; //비지 않았다면
//}
//
////꽉찼는지(포화상태)아닌지
//int isFull() {
//	if (top == STACK_SIZE - 1) return 1; //꽉찼다면
//	else return 0; //꽉차지 않았다면
//}
//
////원소넣기
//void push(element item) {
//	if (isFull()) { //꽉찼다면
//		printf("\n\n Stack is FULL! \n");
//		return;
//	}
//	else stack[++top] = item; //top를 1더하고(증가시키고) 원소삽입
//}
//
////원소삭제
//element pop() {
//	if (isEmpty()) { //비어있다면
//		printf("\n\n Stack is Empty!!\n");
//		return 0;
//	}
//	else return stack[top--]; //원소삭제후 top감소시킴
//}
//
//element peek() {
//	if (isEmpty()) {
//		printf("\n\n Stack is Empty!!\n");
//		exit(1);
//	}
//	else return stack[top]; //찾았다면 현재top원소 확인
//}
//
////출력
//void printStack() {
//	int i;
//	printf("\n STACK{ ");
//	for (i = 0; i <= top; i++)//top가 0일때부터 끝까지 출력
//		printf("%d", stack[i]);
//	printf("]");
//}
//
////test용
//void main(void) {
//	element item;
//	printf("\n** 순차 스택 연산 **\n");
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

//스택노드 구조체
typedef struct stackNode {
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;

//공백인지 확인
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
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
	stackNode *temp = top;

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

//원소찾기용
element peek() {
	if (top == NULL) {//못찾으면
		printf("\n\n Stack is Empty");
		return 0;
	}
	else {//찾으면
		return(top->data);
	}
}

//스택에 뭐있는지 보여주기용
void printStack() {
	stackNode* p = top; //top에서 시작
	printf("\n STACK [");
	while (p) { //바닥까지 갈때까지
		printf("%d ", p->data);
		p = p->link; //한칸 내려감
	}
	printf("] ");
}
//테스트용
void main(void) {
	element item;
	top = NULL;
	printf("\n** 연결 스택 연산 **\n");
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



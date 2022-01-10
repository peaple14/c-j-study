#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS

//노드 구조값
typedef struct ListNode {
	char data[4]; //데이터넣을곳
	struct ListNode* link;  //링크넣을곳
}listNode;

//리스트 시작지점
typedef struct {
	listNode* head; //주소값
} linkedList_h;

//연결 리스트 생성
linkedList_h* createLinkedList_h(void) { //공백연결리스트 만들기
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h)); 
	CL->head = NULL;
	return CL;
}


//순서대로 출력하기
void printList(linkedList_h* CL) {
	listNode* p;
	printf("CL = (");
	p = CL->head; //p는 대충 좌표찾기용
	do {
		printf("%s", p->data); //출력후
		p = p->link; //이동
		if (p != CL->head) printf(", "); //이동시 출력
	} while (p != CL->head);  //마지막 될때까지
	printf(") \n");
}

//첫번째노드 삽입
void insertFirstNode(linkedList_h* CL, char* x) {
	listNode* newNode, * temp; //노드와 temp값 만들고
	newNode = (listNode*)malloc(sizeof(listNode)); //메모리 할당후
	strcpy(newNode->data, x); //뉴노드에 데이터 집어넣고
	if (CL->head == NULL) { //만약 NULL값 일때
		CL->head = newNode; 
	}
	else {
		temp = CL->head; //temp 값 만들어서 가장 처음에 넣고
		while (temp->link != CL->head) //마지막 도달시
			temp = temp->link; //temp에 마지막이 가리키는 링크값넣기
		newNode->link = temp->link; //뉴노드링크에 temp링크값넣고
		temp->link = newNode; //뉴노드전 마지막노드 링크값이 뉴노드로 향하도록하고
		CL->head=newNode; //cl헤드 즉,시작값이 뉴노드 보게 이어줌
	}
}

//중간삽입
void insertMiddleNode(linkedList_h *CL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL== NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link; //새로넣을노드의 링크에는 전에있던노드의 링크넣고
		pre->link = newNode; //전에있던노드의 링크엔 새로들오는노드를 향하게
	}
}

//삭제
void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre; //좌표찾기용
	if (CL->head == NULL) return; //공백이면 리턴
	if (CL->head->link == CL->head) { //자기 혼자일시
		free(CL->head); 
		CL->head = NULL;
		return;
	}
	else if (old == NULL) return; //노드없을시 리턴
	else {
		pre = CL->head; //삭제 전 노드를 찾기위한 pre설정 시작지점부터
		while (pre->link != old) { //pre의 링크값이 삭제할값이 될때까지 가서
			pre = pre->link; //삭제 전에 링크값 넣기
		}
		pre->link = old->link; //삭제전 노드링크에 삭제링크넣기
		if (old == CL->head) //삭제노드가 마지막일시
			CL->head = old->link; //시작지점에 삭제노드링크 넣키
		free(old); //메모리 해제
	}
}

//탐색용
listNode* searchNode(linkedList_h* CL, char x) {
	listNode* temp;
	temp = CL->head;
	if (temp == NULL) return NULL; //아무것도 없을시
	do {
		if (strcmp(temp->data, x) == 0) return temp; //찾았을시
		else temp = temp->link; //아니라면 계속 이동
	} while (temp != CL->head); //다시 처음으로 돌아올때까지
	return NULL;
}

int main() {
	linkedList_h* CL;
	listNode* p;
	CL = createLinkedList_h();
	printf("(1) 원형 연결 리스트 생성하기! \n");
	getchar();

	printf("(2) 원형 연결 리스트에 [월] 노드 삽입하기!\n");
	insertFirstNode(CL, "월");
	printList(CL); getchar();

	printf("(3) 원형 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기! \n");
	p = searchNode(CL, "월"); insertMiddleNode(CL, p, "수");
	printList(CL); getchar();

	printf("(4) 원형 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기!\n");
	p = searchNode(CL, "수"); insertMiddleNode(CL, p, "금");
	printList(CL); getchar();

	printf("(5) 원형 연결 리스트에서 [수] 노드 삭제하기! \n");
	p = searchNode(CL, "수"); deleteNode(CL, p);
	printList(CL); getchar();

	return 0;
}

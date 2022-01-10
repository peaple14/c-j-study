#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS

typedef struct ListNode { //노드구조 만들기
	char data[4];
	struct ListNode* link;
} listNode;

typedef struct { //가장 첫번째 노드구조 만들기
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void) { //공백연결리스트 만들기
	linkedList_h *L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h)); //메모리할당
	L->head = NULL; //헤드값을 null값을 가리키게 만듦
		return L;
}

void freeLinkedList_h(linkedList_h* L) { //연결리스트 메모리 해제
	listNode* p;  //p값은 삭제당할 노드 주소
	while (L->head != NULL) { //헤드값이 가리키는것이 NULL값이 될때까지
		p = L->head; //헤드값을향해 간다
		L->head = L->head->link; //자신이 가리키는 노드값의 링크를 가리키게함
		free(p); //메모리 해제
		p = NULL; //가리키는값이 null값이 되게한다
	}
}

void printList(linkedList_h* L) { //연결리스트 순서대로 표시함
	listNode* p;
	printf(" L=("); 
	p = L->head; //p에다 첫번째값을 넣어줌
	while (p != NULL) { //p값이 null값 즉,마지막값이 될때까지
		printf("%s", p->data); //값을 표시한후
		p = p->link; //그값이 가리키는곳으로 감
		if (p != NULL) printf(", "); //마지막일시 이것 표시
	}
	printf(") \n");
}

//첫번째노드로 삽입하는것
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode; //뉴노드 만들고
		newNode = (listNode*)malloc(sizeof(listNode)); //새로만든곳에 메모리할당해주고
	strcpy(newNode->data, x); //뉴노드에 데이터값과  주소값x 넣어주고
	newNode->link = L->head; //새로만들 노드가 가리키는값을 L값 즉,가장 첫번째 노드를 가리키게 해주고
	L->head = newNode; //L의헤드값이 뉴노드(가장 첫번째값)를(을) 가리키게 한다.
}

//노드를 pre뒤에 삽입하는것
void insertMiddleNode(linkedList_h* L, listNode* pre, char *x) { //구조체,어디뒤에넣을것인가,넣을것
	listNode *newNode; //새로운 노드 만들고
	newNode = (listNode*)malloc(sizeof(listNode)); //메모리할당
	strcpy(newNode->data, x); //데이터,주소값넣기
	if (L == NULL) { //삽입할때 가장 첫번째값이면
		newNode->link = NULL; //NULL값 가리키게함
		L->head = newNode; //L이 뉴노드 가리키게함
	}
	else if (pre == NULL) { //자기뒤쪽이 빈곳이라면
		L->head = newNode; //첫번째 노드로 지정
	}
	else {
		newNode->link = pre->link; //노드가 가리키는값이 자기이전노드가 가리키는값으로 넣기
		pre->link = newNode; //자기이전값은 새로만들값을 가리키게함
	}
}

//마지막 노드로 삽입하는것
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode; 
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL; //노드값이 NULL값을 가리키게함
		if (L->head == NULL) {  //리스트가 공백이면
			L->head = newNode; //새노드를 시작노드로 함
			return;
		}
	temp = L->head; //대충 좌표측정기
	while (temp->link != NULL) temp = temp->link; //temp 값이 마지막될때까지 계속 link타고감
	temp->link = newNode; //마지막값이 뉴노드값을 가리키게함
}
//실험용
//int main() {
//	linkedList_h* L;
//	L = createLinkedList_h();
//	printf("(1) 공백 리스트 생성하기! \n");
//	printList(L); getchar();
//
//	printf("(2) 리스트에 [수] 노드 삽입하기! \n");
//	insertFirstNode(L, "수");
//	printList(L); getchar();
//
//	printf("(3) 리스트 마지막에 [금] 노드 삽입하기! \n");
//	insertLastNode(L, "금");
//	printList(L); getchar();
//
//	printf("(4) 리스트 첫번째에 [월] 노드 삽입하기! \n");
//	insertFirstNode(L, "월");
//	printList(L); getchar();
//
//	printf("(5) 리스트 공간을 해제하여 공백 리스트로 만들기! \n");
//	freeLinkedList_h(L);
//	printList(L);
//
//
//	getchar();
//
//	return 0;
//}

//노드 삭제
void deleteNode(linkedList_h* L, listNode *p) { //p값 삭제할것
	listNode* pre;
	if (L->head == NULL)return; //공백리시트일시
	if (L->head->link == NULL) { //한개만있을시
		free(L->head);
		return;
	}
	else if (p == NULL)return; //그냥 리스가 없을시
	else {
		pre = L->head; // 가장 처음헤드값 가리키게함
		while (pre->link != p) { //pre가 가리키는게 p(삭제할값)이 아닐때동안
			pre = pre->link; //링크값 계속이동
		}
		pre->link = p->link; //삭제할값의 전값이 삭제값이 가리키는걸 가리키게함
		free(p); //삭제값 메모리 해제
	}
}

//노드 검색
listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp; //좌표검색기
	temp = L->head; //가장처음으로
	while (temp != NULL) {//NULL값이 아닐때동안
		if (strcmp(temp->data, x) == 0) return temp; //두개 비교해서 같을시 0나옴 0나올시 temp리턴
		else temp = temp->link; //템프가나올시 링크값으로 이동
	}
return temp; //최종 리턴
}

//노드순서 역순으로
void reverse(linkedList_h* L) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = L->head; //첫번째를 p로설정
	q = NULL;
	r = NULL;

	while (p != NULL) { //첫번째가 NULL값이 될때까지
		r = q; //이동하면서 바꿔넣음 밑에4줄
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q; //마지막 정리
}

//실험용
int main() {
	linkedList_h* L;
	listNode* p;
	L = createLinkedList_h();
	printf("(1) 리스트에 [월],[수],[일] 노드 삽입하기! \n");
	insertLastNode(L, "월"); insertLastNode(L, "수"); insertLastNode(L, "일");
	printList(L); getchar();

	printf("(2) 리스트에서 [수] 노드 탐색하기! \n");
	p = searchNode(L, "수");
	if (p == NULL)printf("찾는 데이터가 없습니다.\n");
	else printf("[%s]를 찾았습니다. \n", p->data);
	getchar();

	printf("(3) 리스트에서 [수] 뒤에 [금] 노드 삽입하기! \n");
	insertMiddleNode(L, p, "금");
	printList(L); getchar();

	printf("(4) 리스트에서 [일] 노드 삭제하기!\n");
	p = searchNode(L, "일");
	deleteNode(L, p);
	printList(L); getchar();

	printf("(5) 리스트 순서를 역순으로 바꾸기!\n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L);
	getchar();

	return 0;
}
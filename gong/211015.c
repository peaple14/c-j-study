#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS

typedef struct ListNode { //��屸�� �����
	char data[4];
	struct ListNode* link;
} listNode;

typedef struct { //���� ù��° ��屸�� �����
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void) { //���鿬�Ḯ��Ʈ �����
	linkedList_h *L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h)); //�޸��Ҵ�
	L->head = NULL; //��尪�� null���� ����Ű�� ����
		return L;
}

void freeLinkedList_h(linkedList_h* L) { //���Ḯ��Ʈ �޸� ����
	listNode* p;  //p���� �������� ��� �ּ�
	while (L->head != NULL) { //��尪�� ����Ű�°��� NULL���� �ɶ�����
		p = L->head; //��尪������ ����
		L->head = L->head->link; //�ڽ��� ����Ű�� ��尪�� ��ũ�� ����Ű����
		free(p); //�޸� ����
		p = NULL; //����Ű�°��� null���� �ǰ��Ѵ�
	}
}

void printList(linkedList_h* L) { //���Ḯ��Ʈ ������� ǥ����
	listNode* p;
	printf(" L=("); 
	p = L->head; //p���� ù��°���� �־���
	while (p != NULL) { //p���� null�� ��,���������� �ɶ�����
		printf("%s", p->data); //���� ǥ������
		p = p->link; //�װ��� ����Ű�°����� ��
		if (p != NULL) printf(", "); //�������Ͻ� �̰� ǥ��
	}
	printf(") \n");
}

//ù��°���� �����ϴ°�
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode; //����� �����
		newNode = (listNode*)malloc(sizeof(listNode)); //���θ������ �޸��Ҵ����ְ�
	strcpy(newNode->data, x); //����忡 �����Ͱ���  �ּҰ�x �־��ְ�
	newNode->link = L->head; //���θ��� ��尡 ����Ű�°��� L�� ��,���� ù��° ��带 ����Ű�� ���ְ�
	L->head = newNode; //L����尪�� �����(���� ù��°��)��(��) ����Ű�� �Ѵ�.
}

//��带 pre�ڿ� �����ϴ°�
void insertMiddleNode(linkedList_h* L, listNode* pre, char *x) { //����ü,���ڿ��������ΰ�,������
	listNode *newNode; //���ο� ��� �����
	newNode = (listNode*)malloc(sizeof(listNode)); //�޸��Ҵ�
	strcpy(newNode->data, x); //������,�ּҰ��ֱ�
	if (L == NULL) { //�����Ҷ� ���� ù��°���̸�
		newNode->link = NULL; //NULL�� ����Ű����
		L->head = newNode; //L�� ����� ����Ű����
	}
	else if (pre == NULL) { //�ڱ������ ����̶��
		L->head = newNode; //ù��° ���� ����
	}
	else {
		newNode->link = pre->link; //��尡 ����Ű�°��� �ڱ�������尡 ����Ű�°����� �ֱ�
		pre->link = newNode; //�ڱ��������� ���θ��鰪�� ����Ű����
	}
}

//������ ���� �����ϴ°�
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode; 
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL; //��尪�� NULL���� ����Ű����
		if (L->head == NULL) {  //����Ʈ�� �����̸�
			L->head = newNode; //����带 ���۳��� ��
			return;
		}
	temp = L->head; //���� ��ǥ������
	while (temp->link != NULL) temp = temp->link; //temp ���� �������ɶ����� ��� linkŸ��
	temp->link = newNode; //���������� ����尪�� ����Ű����
}
//�����
//int main() {
//	linkedList_h* L;
//	L = createLinkedList_h();
//	printf("(1) ���� ����Ʈ �����ϱ�! \n");
//	printList(L); getchar();
//
//	printf("(2) ����Ʈ�� [��] ��� �����ϱ�! \n");
//	insertFirstNode(L, "��");
//	printList(L); getchar();
//
//	printf("(3) ����Ʈ �������� [��] ��� �����ϱ�! \n");
//	insertLastNode(L, "��");
//	printList(L); getchar();
//
//	printf("(4) ����Ʈ ù��°�� [��] ��� �����ϱ�! \n");
//	insertFirstNode(L, "��");
//	printList(L); getchar();
//
//	printf("(5) ����Ʈ ������ �����Ͽ� ���� ����Ʈ�� �����! \n");
//	freeLinkedList_h(L);
//	printList(L);
//
//
//	getchar();
//
//	return 0;
//}

//��� ����
void deleteNode(linkedList_h* L, listNode *p) { //p�� �����Ұ�
	listNode* pre;
	if (L->head == NULL)return; //���鸮��Ʈ�Ͻ�
	if (L->head->link == NULL) { //�Ѱ���������
		free(L->head);
		return;
	}
	else if (p == NULL)return; //�׳� ������ ������
	else {
		pre = L->head; // ���� ó����尪 ����Ű����
		while (pre->link != p) { //pre�� ����Ű�°� p(�����Ұ�)�� �ƴҶ�����
			pre = pre->link; //��ũ�� ����̵�
		}
		pre->link = p->link; //�����Ұ��� ������ �������� ����Ű�°� ����Ű����
		free(p); //������ �޸� ����
	}
}

//��� �˻�
listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp; //��ǥ�˻���
	temp = L->head; //����ó������
	while (temp != NULL) {//NULL���� �ƴҶ�����
		if (strcmp(temp->data, x) == 0) return temp; //�ΰ� ���ؼ� ������ 0���� 0���ý� temp����
		else temp = temp->link; //���������ý� ��ũ������ �̵�
	}
return temp; //���� ����
}

//������ ��������
void reverse(linkedList_h* L) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = L->head; //ù��°�� p�μ���
	q = NULL;
	r = NULL;

	while (p != NULL) { //ù��°�� NULL���� �ɶ�����
		r = q; //�̵��ϸ鼭 �ٲ���� �ؿ�4��
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q; //������ ����
}

//�����
int main() {
	linkedList_h* L;
	listNode* p;
	L = createLinkedList_h();
	printf("(1) ����Ʈ�� [��],[��],[��] ��� �����ϱ�! \n");
	insertLastNode(L, "��"); insertLastNode(L, "��"); insertLastNode(L, "��");
	printList(L); getchar();

	printf("(2) ����Ʈ���� [��] ��� Ž���ϱ�! \n");
	p = searchNode(L, "��");
	if (p == NULL)printf("ã�� �����Ͱ� �����ϴ�.\n");
	else printf("[%s]�� ã�ҽ��ϴ�. \n", p->data);
	getchar();

	printf("(3) ����Ʈ���� [��] �ڿ� [��] ��� �����ϱ�! \n");
	insertMiddleNode(L, p, "��");
	printList(L); getchar();

	printf("(4) ����Ʈ���� [��] ��� �����ϱ�!\n");
	p = searchNode(L, "��");
	deleteNode(L, p);
	printList(L); getchar();

	printf("(5) ����Ʈ ������ �������� �ٲٱ�!\n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L);
	getchar();

	return 0;
}
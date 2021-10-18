#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS

//��� ������
typedef struct ListNode {
	char data[4]; //�����ͳ�����
	struct ListNode* link;  //��ũ������
}listNode;

//����Ʈ ��������
typedef struct {
	listNode* head; //�ּҰ�
} linkedList_h;

//���� ����Ʈ ����
linkedList_h* createLinkedList_h(void) { //���鿬�Ḯ��Ʈ �����
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h)); 
	CL->head = NULL;
	return CL;
}


//������� ����ϱ�
void printList(linkedList_h* CL) {
	listNode* p;
	printf("CL = (");
	p = CL->head; //p�� ���� ��ǥã���
	do {
		printf("%s", p->data); //�����
		p = p->link; //�̵�
		if (p != CL->head) printf(", "); //�̵��� ���
	} while (p != CL->head);  //������ �ɶ�����
	printf(") \n");
}

//ù��°��� ����
void insertFirstNode(linkedList_h* CL, char* x) {
	listNode* newNode, * temp; //���� temp�� �����
	newNode = (listNode*)malloc(sizeof(listNode)); //�޸� �Ҵ���
	strcpy(newNode->data, x); //����忡 ������ ����ְ�
	if (CL->head == NULL) { //���� NULL�� �϶�
		CL->head = newNode; 
	}
	else {
		temp = CL->head; //temp �� ���� ���� ó���� �ְ�
		while (temp->link != CL->head) //������ ���޽�
			temp = temp->link; //temp�� �������� ����Ű�� ��ũ���ֱ�
		newNode->link = temp->link; //����帵ũ�� temp��ũ���ְ�
		temp->link = newNode; //������� ��������� ��ũ���� ������ ���ϵ����ϰ�
		CL->head=newNode; //cl��� ��,���۰��� ����� ���� �̾���
	}
}

//�߰�����
void insertMiddleNode(linkedList_h *CL, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL== NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link; //���γ�������� ��ũ���� �����ִ������ ��ũ�ְ�
		pre->link = newNode; //�����ִ������ ��ũ�� ���ε���³�带 ���ϰ�
	}
}

//����
void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre; //��ǥã���
	if (CL->head == NULL) return; //�����̸� ����
	if (CL->head->link == CL->head) { //�ڱ� ȥ���Ͻ�
		free(CL->head); 
		CL->head = NULL;
		return;
	}
	else if (old == NULL) return; //�������� ����
	else {
		pre = CL->head; //���� �� ��带 ã������ pre���� ������������
		while (pre->link != old) { //pre�� ��ũ���� �����Ұ��� �ɶ����� ����
			pre = pre->link; //���� ���� ��ũ�� �ֱ�
		}
		pre->link = old->link; //������ ��帵ũ�� ������ũ�ֱ�
		if (old == CL->head) //������尡 �������Ͻ�
			CL->head = old->link; //���������� ������帵ũ ��Ű
		free(old); //�޸� ����
	}
}

//Ž����
listNode* searchNode(linkedList_h* CL, char x) {
	listNode* temp;
	temp = CL->head;
	if (temp == NULL) return NULL; //�ƹ��͵� ������
	do {
		if (strcmp(temp->data, x) == 0) return temp; //ã������
		else temp = temp->link; //�ƴ϶�� ��� �̵�
	} while (temp != CL->head); //�ٽ� ó������ ���ƿö�����
	return NULL;
}

int main() {
	linkedList_h* CL;
	listNode* p;
	CL = createLinkedList_h();
	printf("(1) ���� ���� ����Ʈ �����ϱ�! \n");
	getchar();

	printf("(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�!\n");
	insertFirstNode(CL, "��");
	printList(CL); getchar();

	printf("(3) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = searchNode(CL, "��"); insertMiddleNode(CL, p, "��");
	printList(CL); getchar();

	printf("(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�!\n");
	p = searchNode(CL, "��"); insertMiddleNode(CL, p, "��");
	printList(CL); getchar();

	printf("(5) ���� ���� ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = searchNode(CL, "��"); deleteNode(CL, p);
	printList(CL); getchar();

	return 0;
}

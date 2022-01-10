#include <stdio.h>
#include<stdlib.h>
#define RADIX 10 //10����
#define DIGIT 2 //���ڸ�


//////�������
//typedef int element; 
//
//typedef struct QNode { //�ذ͵� �� �𸣰����� 211025���� ����
//	element data;
//	struct QNode* link;
//}QNode;
//
//typedef struct {
//	QNode* front, * rear;
//}LQueueType;
//
//LQueueType* createLinkedQueue() { 
//	LQueueType* LQ;
//	LQ = (LQueueType *)malloc(sizeof(LQueueType));
//	LQ->front = NULL;
//	LQ->rear = NULL;
//	return LQ;
//}
//
//int isEmpty(LQueueType* LQ) {
//	if (LQ->front == NULL) return 1;
//	else return 0;
//}
//
//void enQueue(LQueueType* LQ, element item) {
//	QNode* newNode = (QNode*)malloc(sizeof(QNode));
//	newNode->data = item;
//	newNode->link = NULL;
//	if (LQ->front == NULL) {
//		LQ->front = newNode;
//		LQ->rear = newNode;
//	}
//	else {
//		LQ->rear->link = newNode;
//		LQ->rear = newNode;
//
//	}
//}
//
//element deQueue(LQueueType *LQ){
//	QNode* old = LQ->front;
//	element item;
//	if (isEmpty(LQ)) return 0;
//	else{
//		item = old->data;
//		LQ->front = LQ->front->link;
//		if (LQ->front == NULL)
//			LQ->rear = NULL;
//		free(old);
//		return item;
//	}
//}
////������� ť
//
////�������
//void radixSort(element a[], int n) {
//	int i, bucket, d, factor = 1;
//
//	LQueueType* Q[RADIX];//���� ������ ����� ����
//	for (bucket = 0; bucket < RADIX; bucket++) 
//		Q[bucket] = createLinkedQueue(); //�ֳ��� RADIX������ŭ ���� �����
//
//		for (d = 0; d < DIGIT; d++) {
//			for (i = 0; i < n; i++)
//				enQueue(Q[(a[i] / factor) % 10], a[i]);//1���� �ڽſ��� �´¼���â ���� �ֱ�
//			for (bucket = 0, i = 0; bucket < RADIX; bucket++) //�ٽ� ������ a[]�� ����
//				while (!isEmpty(Q[bucket])) a[i++] = deQueue(Q[bucket]);
//				printf("\n\n %d �ܰ� : ", d + 1);//���� �ܰ� �����ֱ��
//				for (i = 0; i < n; i++) printf("%d ", a[i]);
//				factor = factor * 10; //10������ ������� �ݺ��ϱ�����  facotr ����
//		}
//}
//
////�����
//void main() {
//	element list[8] = { 69,10,30,2,16,8,31,22 };
//	int size = 8;
//	printf("\n <<<<< ��� ���� ���� >>>>>");
//	radixSort(list, size);
//
//	getchar();
//}

////Ʈ������

typedef int element; //Ʈ�� �𸣸� 211028��
typedef struct treeNode{
	element key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* insertNode(treeNode* p, element x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key)p->left = insertNode(p->left, x);
	else if (x > p->key) p->right = insertNode(p->right, x);
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ�!");
	return p;
}

void displayInorder(treeNode* root) {//������ȸ
	if (root) {
		displayInorder(root->left);
		printf("%d ", root->key);
		displayInorder(root->right);
	}
}

//Ʈ�����Ŀ���
void treeSort(element a[], int n) {
	treeNode* root = NULL; //����Ʈ������
	root = insertNode(root, a[0]);//a[0]�� ��Ʈ�� ����

	for (int i = 0; i < n; i++)
		insertNode(root, a[i]);//�����ϸ鼭 ����Ž��Ʈ�� ����
	displayInorder(root);//������ȸ�Ѱ� ������
}

//�����
int main() {
	element list[8] = { 69,10,30,2,16,8,31,22 };
	int size = 8;
	printf("\n <<<<Ʈ�� ���� ����>>>>>");
	treeSort(list, size);

	getchar();
}
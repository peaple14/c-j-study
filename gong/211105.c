#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_VERTEX 10//�迭 �ִ�ũ��
#define FALSE 0
#define TRUE 1

////�׷��� �ʺ�켱 Ž��


//��������Ʈ ����ü
typedef struct graphNode {
	int vertex;//�迭
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int n; //��������
	graphNode* adjList_H[MAX_VERTEX];//��������Ʈ �����迭
	int visited[MAX_VERTEX]; //�湮ǥ��(True,False)
}graphType;

typedef int element;

typedef struct QNode {//ť��� ����ü
	int data;
	struct QNode* link;
}QNode;

//ť ����ü
typedef struct { 
	QNode* front, * rear;
}LQueueType;

//ť���� �̾��ִ°�
LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;//�ʱ�ȭ�ʼ�
	LQ->rear = NULL;//�ʱ�ȭ
	return LQ;
}
//�����������
int isEmpty(LQueueType* LQ) {
	if (LQ->front == NULL) {
		printf("\n Linked Queue is empty");
		return 1;
	}
	else return 0;
}

//ť��� ����ִ°�
void enQueue(LQueueType* LQ, int item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front = NULL) {
		LQ->front = NULL;
		LQ->rear = NULL;
	}
	else {
		LQ->rear->link = newNode;//LQ�� rear�� ����Ű���ִ� ��ũ
		LQ->rear = newNode; 
	}
}

//ť��� ���°�
int deQueue(LQueueType* LQ) {
	QNode* old = LQ->front; //front �� old������
	int item;
	if (isEmpty(LQ)) return 0; //���������
	else {
		item = old->data; //�����ֱ��
		LQ->front = LQ->front->link; //front�� ��ĭ����(��ũ���󰣰�����) ����
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);//�޸� ����
		return item;
	}
}

//�ʱ����׷���
void createGraph(graphType* g) {
	int v;
	g->n = 0;//�������� 0
	for (v = 0; v < MAX_VERTEX; v++) {
		g->visited[v] = FALSE; //�ʱ�ȭ(�湮�ߴ������ߴ���)
		g->adjList_H[v] = NULL; //�ʱ�ȭ(��尪)
	}
}

//�׷���g�� ����v����
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n �׷��� ������ ������ �ʰ��߽��ϴ�");
		return;
	}
	g->n++;//�������� �߰�
}

//�׷���g�� u,v�����߰�
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n �׷����� ���� �����Դϴ� \n");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;//����
	node->link = g->adjList_H[u];//u�� �̾��̵��� ��ũ����
	g->adjList_H[u] = node;//���� ��������Ϳ� node ����
}

//�迭�� ������� ���
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {//�������� ����������
		printf("\n\t\t���� %c�� ���� ����Ʈ", i + 65);
		p = g->adjList_H[i];//������� ������ �ο�
		while (p) {
			printf(" -> %c", p->vertex + 65);
			p = p->link;//��ũŸ�� ��������
		}
	}
}

//�׷��� g���� ���� v������ �ʺ�켱Ž��
void BFS_adjList(graphType* g, int v) {
	graphNode* w;
	LQueueType* Q;
	Q = createLinkedQueue();
	g->visited[v] = TRUE;
	printf(" %c", v + 65);//A~G�� �ٲپ� ���
	enQueue(Q, v);

	while (!isEmpty(Q)) {//ť�� ������ �ƴѵ���
		v = deQueue(Q);
		//�湮���Ѱ��
		for (w = g->adjList_H[v]; w; w = w->link)
			if (!g->visited[w->vertex]) {//�湮���� �������̶��
				g->visited[w->vertex] = TRUE; //�湮ǥ��
				printf(" %c", w->vertex + 65);//���
				enQueue(Q, w->vertex);//����ֱ�
			}

	}
}

//�����
void main() {
	int i;
	graphType* G9;
	G9 = (graphType*)malloc(sizeof(graphType));//�޸��Ҵ�
	createGraph(G9);//G9��� �׷��� ���� �����
	for (i = 0; i < 7; i++)//
		insertVertex(G9, i);
	insertEdge(G9, 0, 2);
	insertEdge(G9, 0, 1);
	insertEdge(G9, 1, 4);
	insertEdge(G9, 1, 3);
	insertEdge(G9, 1, 0);
	insertEdge(G9, 2, 4);
	insertEdge(G9, 2, 0);
	insertEdge(G9, 3, 6);
	insertEdge(G9, 3, 1);
	insertEdge(G9, 4, 6);
	insertEdge(G9, 4, 2);
	insertEdge(G9, 4, 1);
	insertEdge(G9, 5, 6);
	insertEdge(G9, 6, 5);
	insertEdge(G9, 6, 4);
	insertEdge(G9, 6, 3);
	printf("\n G9�� ��������Ʈ");
	print_adjList(G9);

	printf("\n\n////////////\n\n�ʺ� �켱 Ž�� >>");
	BFS_adjList(G9, 0);

	getchar();
}
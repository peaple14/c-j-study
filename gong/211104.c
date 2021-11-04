#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_VERTEX 10//�迭 �ִ�ũ��
#define FALSE 0
#define TRUE 1



////�׷��� ���̿켱 Ž��
//extern�ᵵ ������ ���������Ῡ �Ⱦ�

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

//��� ����ü
typedef struct stackNode {
	int data;
	struct stackNode* link;
}stackNode;

stackNode* top;

//��������
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

//����ִ°�
void push(int item) {//���ñ���(Ǫ��,�˱���)
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode)); // �޸𸮺ο�
	temp->data = item;//�˲��� �����ϰ� �н�
	temp->link = top;
	top = temp;
}

//���°�
int pop() {
	int item;
	stackNode* temp = top;

	if (isEmpty()) {//���������
		printf("\n\n Stack is empty \n");
		return 0;
	}
	else{
		item = temp->data;//������������ �����ֱ��
		top = temp->link;//��ũ ���󰡼� �ο�
		free(temp);//����
		return item;//�����ֱ�
	}
}

//�ʱ����׷��� ����
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

//�׷���g���� ����v������ ���̿켱Ž��
void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL; //top����
	push(v);//Ž����� Ǫ��
	g->visited[v] = TRUE; //�湮�ߴ��� True�� ����
	printf(" %c", v + 65);//���

	//������� �ƴҶ����� ���
	while (!isEmpty()) {
		w = g->adjList_H[v];
		while (w) {//�������� �ִµ��ȹݺ�
			if (!g->visited[w->vertex]){
			if (isEmpty()) push(v);//�����Ͻ� �ٷ� Ǫ��
			push(w->vertex);//����Ǫ��
			g->visited[w->vertex] = TRUE;//�湮�ߴٰ�ǥ��
			printf(" %c", w->vertex + 65);//�湮�Ѱ� ���
			v = w->vertex;//�̵������ϱ� �������� ����
			w = g->adjList_H[v];//ù��°���� ������ �������� �ִµ��� �ݺ�
			}
			else w = w->link;
		}
		v = pop();
	}
}

//�����
void main() {
	int i;
	graphType* G9;
	G9 = (graphType*)malloc(sizeof(graphType));
	createGraph(G9);
	for (i = 0; i < 7; i++)
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

	printf("\n\n////////////\n\n���� �켱 Ž�� >>");
	DFS_adjList(G9, 0);

	getchar();
}
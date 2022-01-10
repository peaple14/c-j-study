#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30 //�迭 �ִ�ũ��

//////�׷��� ������� �����
//
////�׷��� ����ü
//typedef struct graphType {
//	int n; //��������
//	int adjmatrix[MAX_VERTEX][MAX_VERTEX];//�׷����� 2�����迭
//}graphType;
//
////����׷�������
//void createGraph(graphType* g) {
//	int i, j;
//	g->n = 0; //������ 0������
//	for (i = 0; i < MAX_VERTEX; i++) {
//		for (j = 0; j < MAX_VERTEX; j++)
//			g->adjmatrix[i][j] = 0;//0���� �ʱ�
//	}
//}
//
////�׷���g�� ����v����
//void insertVertex(graphType* g, int v) {
//	if (((g->n) + 1) > MAX_VERTEX) { //����������
//		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");//���
//		return;
//	}
//	g->n++;//��������+1
//}
//
////�׷���g�� ����(u,v)����
//void insertEdge(graphType* g, int u, int v) {
//	if (u >= g->n || v >= g->n) { //u��v������ �����ϴ��� Ȯ��
//		printf("\n �׷����� ���� �����Դϴ�");
//		return;
//	}
//	g->adjmatrix[u][v] = 1; //�̾����� Ȯ���ϴ� �迭�� 1�μ���
//}
//
////�迭�� ������� ���
//void print_adjMatrix(graphType* g) {
//	int i, j;
//	for (i = 0; i < (g->n); i++) {
//		printf("\n\t\t");
//		for (j = 0; j < (g->n); j++)
//			printf("%2d", g->adjmatrix[i][j]);//0����1���� �� ���
//	}
//}
//
////�����
//void main() {
//	int i;
//	graphType* G1, * G2, * G3, * G4;
//	G1 = (graphType*)malloc(sizeof(graphType));
//	G2 = (graphType*)malloc(sizeof(graphType));
//	G3 = (graphType*)malloc(sizeof(graphType));
//	G4 = (graphType*)malloc(sizeof(graphType));
//	createGraph(G1); createGraph(G2); createGraph(G3); createGraph(G4);
//
//	//�׷���G1
//	for (i = 0; i < 4; i++)
//		insertVertex(G1, i);
//	insertEdge(G1, 0, 1);
//	insertEdge(G1, 0, 3);
//	insertEdge(G1, 1, 0);
//	insertEdge(G1, 1, 2);
//	insertEdge(G1, 1, 3);
//	insertEdge(G1, 2, 1);
//	insertEdge(G1, 2, 3);
//	insertEdge(G1, 3, 0);
//	insertEdge(G1, 3, 1);
//	insertEdge(G1, 3, 2);
//	printf("\n\n G1�� ���� ���");
//	print_adjMatrix(G1);
//
//	//�׷��� G2
//	for (i = 0; i < 3; i++)
//		insertVertex(G2, i);
//	insertEdge(G2, 0, 1);
//	insertEdge(G2, 0, 2);
//	insertEdge(G2, 1, 0);
//	insertEdge(G2, 1, 2);
//	insertEdge(G2, 2, 0);
//	insertEdge(G2, 2, 1);
//	printf("\n\n G2�� ���� ���");
//	print_adjMatrix(G2);
//	
//	//�׷��� G3
//	for (i = 0; i < 4; i++)
//		insertVertex(G3, i);
//	insertEdge(G3, 0, 1);
//	insertEdge(G3, 0, 3);
//	insertEdge(G3, 1, 2);
//	insertEdge(G3, 1, 3);
//	insertEdge(G3, 2, 3);
//	printf("\n\n G3�� ���� ���");
//	print_adjMatrix(G3);
//
//	//�׷��� G4
//	for (i = 00; i < 3; i++)
//		insertVertex(G4, i);
//	insertEdge(G4, 0, 1);
//	insertEdge(G4, 0, 2);
//	insertEdge(G4, 1, 0);
//	insertEdge(G4, 1, 2);
//	printf("\n\n G4�� ���� ���");
//	print_adjMatrix(G4);
//
//	getchar();
//}

////�׷����� ���� ����Ʈ�� ǥ��

//��������Ʈ ����ü
typedef struct graphNode {
	int vertex; //����
	struct graphNode* link; //�������� ��ũ
} graphNode;

//��������Ʈ ǥ�� ����ü
typedef struct graphType {
	int n; //��������
	graphNode* adjList_H[MAX_VERTEX];//���� ��� ������ �迭
}graphType;

//����׷��� ����
void createGraph(graphType* g) {
	int v;
	g->n = 0;//���� ���� 0���� �ʱ�ȭ
	for (v = 0; v < MAX_VERTEX; v++)
		g->adjList_H[v] = NULL;//��������� NULL�� �ʱ�ȭ
}

//�׷���g�� ����v����
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) { //����������
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");//���
		return;
	}
	g->n++;//��������+1
}

//�׷���g�� ����(u,v)����
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;
	if (u >= g->n || v >= g->n) { //u��v������ �����ϴ��� Ȯ��
		printf("\n �׷����� ���� �����Դϴ�");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));//�޸��Ҵ�
	node->vertex = v; //����
	node->link = g->adjList_H[u];//u�� �̾��̵��� ��ũ����
	g->adjList_H[u] = node;//���� ��������Ϳ� node ����
}

//�迭�� ������� ���
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for(i=0; i<g->n; i++){//�������� ����������
		printf("\n\t\t���� %c�� ���� ����Ʈ", i + 65);
		p = g->adjList_H[i];//������� ������ �ο�
		while (p) {
			printf(" -> %c", p->vertex + 65);
			p = p->link;//��ũŸ�� ��������
		}
	}
}

//�����
void main() {
	int i;
	graphType* G1, * G2, * G3, * G4;
	G1 = (graphType*)malloc(sizeof(graphType));
	G2 = (graphType*)malloc(sizeof(graphType));
	G3 = (graphType*)malloc(sizeof(graphType));
	G4 = (graphType*)malloc(sizeof(graphType));
	createGraph(G1); createGraph(G2); createGraph(G3); createGraph(G4);

	//�׷���G1
	for (i = 0; i < 4; i++)
		insertVertex(G1, i);
	insertEdge(G1, 0, 3);
	insertEdge(G1, 0, 1);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 2, 3);
	insertEdge(G1, 2, 1);
	insertEdge(G1, 3, 2);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 3, 0);
	printf("\n\n G1�� ���� ����Ʈ");
	print_adjList(G1);

	//�׷��� G2
	for (i = 0; i < 3; i++)
		insertVertex(G2, i);
	insertEdge(G2, 0, 2);
	insertEdge(G2, 0, 1);
	insertEdge(G2, 1, 2);
	insertEdge(G2, 1, 0);
	insertEdge(G2, 2, 1);
	insertEdge(G2, 2, 0);
	printf("\n\n G2�� ���� ����Ʈ");
	print_adjList(G2);
	
	//�׷��� G3
	for (i = 0; i < 4; i++)
		insertVertex(G3, i);
	insertEdge(G3, 0, 3);
	insertEdge(G3, 0, 1);
	insertEdge(G3, 1, 3);
	insertEdge(G3, 1, 2);
	insertEdge(G3, 2, 3);
	printf("\n\n G3�� ���� ����Ʈ");
	print_adjList(G3);

	//�׷��� G4
	for (i = 00; i < 3; i++)
		insertVertex(G4, i);
	insertEdge(G4, 0, 2);
	insertEdge(G4, 0, 1);
	insertEdge(G4, 1, 2);
	insertEdge(G4, 1, 0);
	printf("\n\n G4�� ���� ����Ʈ");
	print_adjList(G4);

	getchar();
}
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30 //배열 최대크기

//////그래프 인접행렬 만들기
//
////그래프 구조체
//typedef struct graphType {
//	int n; //정점개수
//	int adjmatrix[MAX_VERTEX][MAX_VERTEX];//그래프의 2차원배열
//}graphType;
//
////공백그래프생성
//void createGraph(graphType* g) {
//	int i, j;
//	g->n = 0; //개수는 0개부터
//	for (i = 0; i < MAX_VERTEX; i++) {
//		for (j = 0; j < MAX_VERTEX; j++)
//			g->adjmatrix[i][j] = 0;//0으로 초기
//	}
//}
//
////그래프g에 정점v삽입
//void insertVertex(graphType* g, int v) {
//	if (((g->n) + 1) > MAX_VERTEX) { //꽉차있을시
//		printf("\n 그래프 정점의 개수를 초과하였습니다!");//출력
//		return;
//	}
//	g->n++;//정점개수+1
//}
//
////그래프g에 간선(u,v)삽입
//void insertEdge(graphType* g, int u, int v) {
//	if (u >= g->n || v >= g->n) { //u와v정점이 존재하는지 확인
//		printf("\n 그래프에 없는 정점입니다");
//		return;
//	}
//	g->adjmatrix[u][v] = 1; //이어짐을 확인하는 배열에 1로설정
//}
//
////배열값 순서대로 출력
//void print_adjMatrix(graphType* g) {
//	int i, j;
//	for (i = 0; i < (g->n); i++) {
//		printf("\n\t\t");
//		for (j = 0; j < (g->n); j++)
//			printf("%2d", g->adjmatrix[i][j]);//0인지1인지 쭉 출력
//	}
//}
//
////실험용
//void main() {
//	int i;
//	graphType* G1, * G2, * G3, * G4;
//	G1 = (graphType*)malloc(sizeof(graphType));
//	G2 = (graphType*)malloc(sizeof(graphType));
//	G3 = (graphType*)malloc(sizeof(graphType));
//	G4 = (graphType*)malloc(sizeof(graphType));
//	createGraph(G1); createGraph(G2); createGraph(G3); createGraph(G4);
//
//	//그래프G1
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
//	printf("\n\n G1의 인접 행렬");
//	print_adjMatrix(G1);
//
//	//그래프 G2
//	for (i = 0; i < 3; i++)
//		insertVertex(G2, i);
//	insertEdge(G2, 0, 1);
//	insertEdge(G2, 0, 2);
//	insertEdge(G2, 1, 0);
//	insertEdge(G2, 1, 2);
//	insertEdge(G2, 2, 0);
//	insertEdge(G2, 2, 1);
//	printf("\n\n G2의 인접 행렬");
//	print_adjMatrix(G2);
//	
//	//그래프 G3
//	for (i = 0; i < 4; i++)
//		insertVertex(G3, i);
//	insertEdge(G3, 0, 1);
//	insertEdge(G3, 0, 3);
//	insertEdge(G3, 1, 2);
//	insertEdge(G3, 1, 3);
//	insertEdge(G3, 2, 3);
//	printf("\n\n G3의 인접 행렬");
//	print_adjMatrix(G3);
//
//	//그래프 G4
//	for (i = 00; i < 3; i++)
//		insertVertex(G4, i);
//	insertEdge(G4, 0, 1);
//	insertEdge(G4, 0, 2);
//	insertEdge(G4, 1, 0);
//	insertEdge(G4, 1, 2);
//	printf("\n\n G4의 인접 행렬");
//	print_adjMatrix(G4);
//
//	getchar();
//}

////그래프를 인접 리스트로 표현

//인접리스트 구조체
typedef struct graphNode {
	int vertex; //정점
	struct graphNode* link; //인접정점 링크
} graphNode;

//인접리스트 표현 구조체
typedef struct graphType {
	int n; //정점개수
	graphNode* adjList_H[MAX_VERTEX];//정점 헤드 포인터 배열
}graphType;

//공백그래프 생성
void createGraph(graphType* g) {
	int v;
	g->n = 0;//정점 개수 0으로 초기화
	for (v = 0; v < MAX_VERTEX; v++)
		g->adjList_H[v] = NULL;//헤드포인터 NULL로 초기화
}

//그래프g에 정점v삽입
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) { //꽉차있을시
		printf("\n 그래프 정점의 개수를 초과하였습니다!");//출력
		return;
	}
	g->n++;//정점개수+1
}

//그래프g에 간선(u,v)삽입
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;
	if (u >= g->n || v >= g->n) { //u와v정점이 존재하는지 확인
		printf("\n 그래프에 없는 정점입니다");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));//메모리할당
	node->vertex = v; //정점
	node->link = g->adjList_H[u];//u와 이어이도록 링크연결
	g->adjList_H[u] = node;//정점 헤드포인터에 node 넣음
}

//배열값 순서대로 출력
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for(i=0; i<g->n; i++){//정점보다 적을때동안
		printf("\n\t\t정점 %c의 인접 리스트", i + 65);
		p = g->adjList_H[i];//정점헤드 포인터 부여
		while (p) {
			printf(" -> %c", p->vertex + 65);
			p = p->link;//링크타고 다음으로
		}
	}
}

//실험용
void main() {
	int i;
	graphType* G1, * G2, * G3, * G4;
	G1 = (graphType*)malloc(sizeof(graphType));
	G2 = (graphType*)malloc(sizeof(graphType));
	G3 = (graphType*)malloc(sizeof(graphType));
	G4 = (graphType*)malloc(sizeof(graphType));
	createGraph(G1); createGraph(G2); createGraph(G3); createGraph(G4);

	//그래프G1
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
	printf("\n\n G1의 인접 리스트");
	print_adjList(G1);

	//그래프 G2
	for (i = 0; i < 3; i++)
		insertVertex(G2, i);
	insertEdge(G2, 0, 2);
	insertEdge(G2, 0, 1);
	insertEdge(G2, 1, 2);
	insertEdge(G2, 1, 0);
	insertEdge(G2, 2, 1);
	insertEdge(G2, 2, 0);
	printf("\n\n G2의 인접 리스트");
	print_adjList(G2);
	
	//그래프 G3
	for (i = 0; i < 4; i++)
		insertVertex(G3, i);
	insertEdge(G3, 0, 3);
	insertEdge(G3, 0, 1);
	insertEdge(G3, 1, 3);
	insertEdge(G3, 1, 2);
	insertEdge(G3, 2, 3);
	printf("\n\n G3의 인접 리스트");
	print_adjList(G3);

	//그래프 G4
	for (i = 00; i < 3; i++)
		insertVertex(G4, i);
	insertEdge(G4, 0, 2);
	insertEdge(G4, 0, 1);
	insertEdge(G4, 1, 2);
	insertEdge(G4, 1, 0);
	printf("\n\n G4의 인접 리스트");
	print_adjList(G4);

	getchar();
}
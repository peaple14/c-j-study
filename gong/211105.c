#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_VERTEX 10//배열 최대크기
#define FALSE 0
#define TRUE 1

////그래프 너비우선 탐색


//인접리스트 구조체
typedef struct graphNode {
	int vertex;//배열
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int n; //정점개수
	graphNode* adjList_H[MAX_VERTEX];//인접리스트 헤드노드배열
	int visited[MAX_VERTEX]; //방문표시(True,False)
}graphType;

typedef int element;

typedef struct QNode {//큐노드 구조체
	int data;
	struct QNode* link;
}QNode;

//큐 구조체
typedef struct { 
	QNode* front, * rear;
}LQueueType;

//큐끼리 이어주는것
LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;//초기화필수
	LQ->rear = NULL;//초기화
	return LQ;
}
//공백상태인지
int isEmpty(LQueueType* LQ) {
	if (LQ->front == NULL) {
		printf("\n Linked Queue is empty");
		return 1;
	}
	else return 0;
}

//큐노드 집어넣는것
void enQueue(LQueueType* LQ, int item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front = NULL) {
		LQ->front = NULL;
		LQ->rear = NULL;
	}
	else {
		LQ->rear->link = newNode;//LQ의 rear가 가리키고있는 링크
		LQ->rear = newNode; 
	}
}

//큐노드 빼는것
int deQueue(LQueueType* LQ) {
	QNode* old = LQ->front; //front 를 old로지정
	int item;
	if (isEmpty(LQ)) return 0; //비어있을시
	else {
		item = old->data; //보여주기용
		LQ->front = LQ->front->link; //front를 한칸위로(링크따라간것으로) 지정
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);//메모리 해제
		return item;
	}
}

//초기공백그래프
void createGraph(graphType* g) {
	int v;
	g->n = 0;//정점개수 0
	for (v = 0; v < MAX_VERTEX; v++) {
		g->visited[v] = FALSE; //초기화(방문했는지안했는지)
		g->adjList_H[v] = NULL; //초기화(헤드값)
	}
}

//그래프g에 정점v삽입
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n 그래프 정점의 개수를 초과했습니다");
		return;
	}
	g->n++;//정점개수 추가
}

//그래프g에 u,v간선추가
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다 \n");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;//정점
	node->link = g->adjList_H[u];//u와 이어이도록 링크연결
	g->adjList_H[u] = node;//정점 헤드포인터에 node 넣음
}

//배열값 순서대로 출력
void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {//정점보다 적을때동안
		printf("\n\t\t정점 %c의 인접 리스트", i + 65);
		p = g->adjList_H[i];//정점헤드 포인터 부여
		while (p) {
			printf(" -> %c", p->vertex + 65);
			p = p->link;//링크타고 다음으로
		}
	}
}

//그래프 g에서 정점 v에대한 너비우선탐색
void BFS_adjList(graphType* g, int v) {
	graphNode* w;
	LQueueType* Q;
	Q = createLinkedQueue();
	g->visited[v] = TRUE;
	printf(" %c", v + 65);//A~G로 바꾸어 출력
	enQueue(Q, v);

	while (!isEmpty(Q)) {//큐가 공백이 아닌동안
		v = deQueue(Q);
		//방문안한경우
		for (w = g->adjList_H[v]; w; w = w->link)
			if (!g->visited[w->vertex]) {//방문하지 않은것이라면
				g->visited[w->vertex] = TRUE; //방문표시
				printf(" %c", w->vertex + 65);//출력
				enQueue(Q, w->vertex);//집어넣기
			}

	}
}

//실험용
void main() {
	int i;
	graphType* G9;
	G9 = (graphType*)malloc(sizeof(graphType));//메모리할당
	createGraph(G9);//G9라는 그래프 새로 만들기
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
	printf("\n G9의 인접리스트");
	print_adjList(G9);

	printf("\n\n////////////\n\n너비 우선 탐색 >>");
	BFS_adjList(G9, 0);

	getchar();
}
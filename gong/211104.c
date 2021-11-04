#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_VERTEX 10//배열 최대크기
#define FALSE 0
#define TRUE 1



////그래프 깊이우선 탐색
//extern써도 되지만 모양새를위햐여 안씀

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

//노드 구조체
typedef struct stackNode {
	int data;
	struct stackNode* link;
}stackNode;

stackNode* top;

//공백인지
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

//집어넣는거
void push(int item) {//스택구조(푸쉬,팝구조)
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode)); // 메모리부여
	temp->data = item;//알꺼라 생각하고 패스
	temp->link = top;
	top = temp;
}

//빼는거
int pop() {
	int item;
	stackNode* temp = top;

	if (isEmpty()) {//비어있을시
		printf("\n\n Stack is empty \n");
		return 0;
	}
	else{
		item = temp->data;//뭐가빠지는지 보여주기용
		top = temp->link;//링크 따라가서 부여
		free(temp);//해제
		return item;//보여주기
	}
}

//초기공백그래프 생성
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

//그래프g에서 정점v에대한 깊이우선탐색
void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL; //top설정
	push(v);//탐색장소 푸쉬
	g->visited[v] = TRUE; //방문했던곳 True로 설정
	printf(" %c", v + 65);//출력

	//공백상태 아닐때동안 계속
	while (!isEmpty()) {
		w = g->adjList_H[v];
		while (w) {//인접정점 있는동안반복
			if (!g->visited[w->vertex]){
			if (isEmpty()) push(v);//공백일시 바로 푸쉬
			push(w->vertex);//정점푸쉬
			g->visited[w->vertex] = TRUE;//방문했다고표기
			printf(" %c", w->vertex + 65);//방문한곳 출력
			v = w->vertex;//이동했으니까 정점으로 설정
			w = g->adjList_H[v];//첫번째노드로 설정후 인접정점 있는동안 반복
			}
			else w = w->link;
		}
		v = pop();
	}
}

//실험용
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
	printf("\n G9의 인접리스트");
	print_adjList(G9);

	printf("\n\n////////////\n\n깊이 우선 탐색 >>");
	DFS_adjList(G9, 0);

	getchar();
}
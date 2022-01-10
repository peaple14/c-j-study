#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct {
	int heap[MAX_ELEMENT]; //히프 최대개수
	int heap_size; //히프 개수
}heapType;

//공백히프 생성
heapType* createHeap() {
	heapType* h= (heapType*)malloc(sizeof(heapType));//메모리 부여
	h->heap_size = 0;//히프개수 0부터
	return h;
}
//히프에 삽입
void insertHeap(heapType* h, int item) {
	int i;//히프번호
	h->heap_size = h->heap_size + 1;//개수 하나 추가
	i = h->heap_size; //히프번호에 최대개수 부여
	while ((i != 1) && (item > h->heap[i / 2])) {//처음이 아니고,삽입할것이 부모노드보다 작거나같을때까지
		h->heap[i] = h->heap[i / 2];//히프번호를 2로 나눔(테스트느낌)	
		i /= 2;// 대충 i=i/2라는뜻(적용느낌)
	}
	h->heap[i] = item;//알맞은 장소에 삽입
}

//히프 루트 삭제후 반환
int deleteHeap(heapType* h) {
	int parent, child;//부모,자식
	int item, temp;//삭제할것,마지막원소 저장통
	item = h->heap[1];//시작위치1부터
	temp = h->heap[h->heap_size];//히프개수저장
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {//자식노드가 현 최대사이즈 전까지
		if ((child < h->heap_size) && (h->heap[child]) < h->heap[child + 1])//자식노드가 아직 히프개수전이고,왼쪽자식이 오른쪽자식보다 작을동안 (왼쪽과 오른쪽중 더큰 자식노드 찾기)
			child++;//자식노드 +1
		if (temp >= h->heap[child])break;//만약 위에서찾은temp값이 자식노드보다 크거나 같다면 중지
		else {//temp가 더 작다면
			h->heap[parent] = h->heap[child];//자식노드와 부모노드 자리바꿈
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;//가장 작은곳 찾았으면 그곳에 temp값 저장
	return item;//삭제된것반환
}

//히프내용 출력
void printHeap(heapType* h) {
	int i;
	printf("Heap : ");
	for (i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
}

//실험용
void main() {
	int i, n, item;
	heapType* heap = createHeap();
	insertHeap(heap, 10);
	insertHeap(heap, 45);
	insertHeap(heap, 19);
	insertHeap(heap, 11);
	insertHeap(heap, 96);

	printHeap(heap);

	n = heap->heap_size;//전부삭제 
	for (i = 1; i <= n; i++) {
		item = deleteHeap(heap);
		printf("\n delete : [%d]", item);//하나씩 삭제한것 보여줌
	}
	getchar();
}
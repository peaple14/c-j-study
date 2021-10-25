#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 4
#define cQ_SIZE 4

////순차큐
//typedef char element; //큐원소
//typedef struct { //큐배열
//	element queue[Q_SIZE];
//	int front, rear; //front는 가장앞원소 앞칸에 있는것임.
//} QueueType;
//
////공백 순차큐 생성
//QueueType* createQueue() {
//	QueueType* Q;
//	Q = (QueueType*)malloc(sizeof(QueueType)); //메모리 할당
//	Q->front = -1; //front는 -1부터시작
//	Q->rear = -1; //rear도 -1부터 시작
//	return Q;
//}
//
////공백상태검사
//int isEmpty(QueueType* Q) {
//	if (Q->front == Q->rear) { //둘다 같으면 빈것
//		printf("Queue is empty!");
//		return 1;
//	}
//	else return 0;
//}
//
////다찼는지 검사
//int isFull(QueueType* Q) {
//	if (Q->rear == Q_SIZE - 1) { //가장처음 define 한값-1
//		printf("Queue is full! ");
//		return 1;
//	}
//	else return 0;
//}
//
////순차큐에 원소삽입
//void enQueue(QueueType* Q, element item) {
//	if (isFull(Q)) return; //꽉차있을시
//	else {
//		Q->rear++; //시작부분 한번씩 뒤로밀어주고
//		Q->queue[Q->rear] = item; //그곳에 원소삽입
//	}
//}
//
////순차큐에서 원소삭제
//element deQueue(QueueType* Q) {
//	if (isEmpty(Q)) return; //공백일시
//	else {
//		Q->front++; //가장처음부분 뒤로밀어주고
//		return Q->queue[Q->front]; //삭제된값 리턴해줌
//	}
//}
//
////가장앞원소검색
//element peek(QueueType* Q) {
//	if (isEmpty(Q)) exit(1); //공백일시
//	else return Q->queue[Q->front + 1]; //가장 앞의값 돌려줌
//}
//
////큐값들 출력
//void printQ(QueueType* Q) {
//	int i;
//	printf("Queue : [");
//	for (i = Q->front + 1; i <= Q->rear; i++) //처음부터 끝가지 출력
//		printf("%3c", Q->queue[i]);
//	printf("]");
//}
//
////실험용
//void main() {
//	QueueType* Q1 = createQueue();
//	element data;
//	printf("\n *****순차 큐 연산 *****\n");
//	printf("\n 삽입 A>>"); enQueue(Q1, 'A'); printQ(Q1);
//	printf("\n 삽입 B>>"); enQueue(Q1, 'B'); printQ(Q1);
//	printf("\n 삽입 C>>"); enQueue(Q1, 'C'); printQ(Q1);
//	data = peek(Q1); printf("peek item : %c \n", data);
//	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
//	printf("\t삭제 데이터: %c", data);
//	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
//	printf("\t삭제 데이터: %c", data);
//	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
//	printf("\t삭제 데이터: %c", data);
//	printf("\n 삽입 D>>"); enQueue(Q1, 'D'); printQ(Q1);
//	printf("\n 삽입 E>>"); enQueue(Q1, 'E'); printQ(Q1);
//	getchar();
//}

//원형큐
typedef char element; //큐원소
typedef struct { //큐배열
	element queue[Q_SIZE];
	int front, rear; //front는 가장앞원소 앞칸에 있는것임.
} QueueType;

QueueType* createQueue() {
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ -> front = 0;//원형큐는 front,rear 0부터시작
	cQ -> rear = 0;
}

//공백인지
int isEmpty(QueueType* cQ) {
	if (cQ->front == cQ->rear) { //이건 순차큐와 같음
		printf("Circular Queue is empty");
		return 1;
	}
	else return 0;
}

//포화상태인지 검사
int isFull(QueueType* cQ) {
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) {//원형큐 특성상 0이 있기에 mod함
		printf("Circular Queue is Full");
		return 1;
	}
	else return 0;
}

//원소삽입
void enQueue(QueueType* cQ, element item) {
	if (isFull(cQ)) return;
	else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;;
		cQ->queue[cQ->rear] = item;
	}
}

//원형큐 삭제후 반환
element deQueue(QueueType *cQ){
	if (isEmpty(cQ)) exit(1); //공백일시
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;//뒤로 한칸 이동후
		return cQ->queue[cQ->front];//반환
	}
}

//가장 앞값 반환
element peek(QueueType* cQ) {
	if (isEmpty(cQ)) exit(1);
	else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

//원형큐 출력
void printQ(QueueType* cQ) {
	int i, first, last;
	first =(cQ->front + 1) % cQ_SIZE;
	last = (cQ->rear + 1) % cQ_SIZE;
	printf("Circular Queue: [");
	i = first;
	while (i != last) {
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % cQ_SIZE;
	}
	printf("]");
}

//실험용
void main() {
	QueueType* cQ = createQueue();
	element data;
	printf("\n *****원형 큐 연산 *****\n");
	printf("\n 삽입 A>>"); enQueue(cQ, 'A'); printQ(cQ);
	printf("\n 삽입 B>>"); enQueue(cQ, 'B'); printQ(cQ);
	printf("\n 삽입 C>>"); enQueue(cQ, 'C'); printQ(cQ);
	data = peek(cQ); printf("peek item : %c \n", data);
	printf("\n 삭제 >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n 삭제 >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n 삭제 >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t삭제 데이터: %c", data);
	printf("\n 삽입 D>>"); enQueue(cQ, 'D'); printQ(cQ);
	printf("\n 삽입 E>>"); enQueue(cQ, 'E'); printQ(cQ);
	getchar();
}
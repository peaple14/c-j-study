#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 4
#define cQ_SIZE 4

////����ť
//typedef char element; //ť����
//typedef struct { //ť�迭
//	element queue[Q_SIZE];
//	int front, rear; //front�� ����տ��� ��ĭ�� �ִ°���.
//} QueueType;
//
////���� ����ť ����
//QueueType* createQueue() {
//	QueueType* Q;
//	Q = (QueueType*)malloc(sizeof(QueueType)); //�޸� �Ҵ�
//	Q->front = -1; //front�� -1���ͽ���
//	Q->rear = -1; //rear�� -1���� ����
//	return Q;
//}
//
////������°˻�
//int isEmpty(QueueType* Q) {
//	if (Q->front == Q->rear) { //�Ѵ� ������ ���
//		printf("Queue is empty!");
//		return 1;
//	}
//	else return 0;
//}
//
////��á���� �˻�
//int isFull(QueueType* Q) {
//	if (Q->rear == Q_SIZE - 1) { //����ó�� define �Ѱ�-1
//		printf("Queue is full! ");
//		return 1;
//	}
//	else return 0;
//}
//
////����ť�� ���һ���
//void enQueue(QueueType* Q, element item) {
//	if (isFull(Q)) return; //����������
//	else {
//		Q->rear++; //���ۺκ� �ѹ��� �ڷιо��ְ�
//		Q->queue[Q->rear] = item; //�װ��� ���һ���
//	}
//}
//
////����ť���� ���һ���
//element deQueue(QueueType* Q) {
//	if (isEmpty(Q)) return; //�����Ͻ�
//	else {
//		Q->front++; //����ó���κ� �ڷιо��ְ�
//		return Q->queue[Q->front]; //�����Ȱ� ��������
//	}
//}
//
////����տ��Ұ˻�
//element peek(QueueType* Q) {
//	if (isEmpty(Q)) exit(1); //�����Ͻ�
//	else return Q->queue[Q->front + 1]; //���� ���ǰ� ������
//}
//
////ť���� ���
//void printQ(QueueType* Q) {
//	int i;
//	printf("Queue : [");
//	for (i = Q->front + 1; i <= Q->rear; i++) //ó������ ������ ���
//		printf("%3c", Q->queue[i]);
//	printf("]");
//}
//
////�����
//void main() {
//	QueueType* Q1 = createQueue();
//	element data;
//	printf("\n *****���� ť ���� *****\n");
//	printf("\n ���� A>>"); enQueue(Q1, 'A'); printQ(Q1);
//	printf("\n ���� B>>"); enQueue(Q1, 'B'); printQ(Q1);
//	printf("\n ���� C>>"); enQueue(Q1, 'C'); printQ(Q1);
//	data = peek(Q1); printf("peek item : %c \n", data);
//	printf("\n ���� >>"); data = deQueue(Q1); printQ(Q1);
//	printf("\t���� ������: %c", data);
//	printf("\n ���� >>"); data = deQueue(Q1); printQ(Q1);
//	printf("\t���� ������: %c", data);
//	printf("\n ���� >>"); data = deQueue(Q1); printQ(Q1);
//	printf("\t���� ������: %c", data);
//	printf("\n ���� D>>"); enQueue(Q1, 'D'); printQ(Q1);
//	printf("\n ���� E>>"); enQueue(Q1, 'E'); printQ(Q1);
//	getchar();
//}

//����ť
typedef char element; //ť����
typedef struct { //ť�迭
	element queue[Q_SIZE];
	int front, rear; //front�� ����տ��� ��ĭ�� �ִ°���.
} QueueType;

QueueType* createQueue() {
	QueueType* cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ -> front = 0;//����ť�� front,rear 0���ͽ���
	cQ -> rear = 0;
}

//��������
int isEmpty(QueueType* cQ) {
	if (cQ->front == cQ->rear) { //�̰� ����ť�� ����
		printf("Circular Queue is empty");
		return 1;
	}
	else return 0;
}

//��ȭ�������� �˻�
int isFull(QueueType* cQ) {
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) {//����ť Ư���� 0�� �ֱ⿡ mod��
		printf("Circular Queue is Full");
		return 1;
	}
	else return 0;
}

//���һ���
void enQueue(QueueType* cQ, element item) {
	if (isFull(cQ)) return;
	else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;;
		cQ->queue[cQ->rear] = item;
	}
}

//����ť ������ ��ȯ
element deQueue(QueueType *cQ){
	if (isEmpty(cQ)) exit(1); //�����Ͻ�
	else {
		cQ->front = (cQ->front + 1) % cQ_SIZE;//�ڷ� ��ĭ �̵���
		return cQ->queue[cQ->front];//��ȯ
	}
}

//���� �հ� ��ȯ
element peek(QueueType* cQ) {
	if (isEmpty(cQ)) exit(1);
	else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

//����ť ���
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

//�����
void main() {
	QueueType* cQ = createQueue();
	element data;
	printf("\n *****���� ť ���� *****\n");
	printf("\n ���� A>>"); enQueue(cQ, 'A'); printQ(cQ);
	printf("\n ���� B>>"); enQueue(cQ, 'B'); printQ(cQ);
	printf("\n ���� C>>"); enQueue(cQ, 'C'); printQ(cQ);
	data = peek(cQ); printf("peek item : %c \n", data);
	printf("\n ���� >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t���� ������: %c", data);
	printf("\n ���� >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t���� ������: %c", data);
	printf("\n ���� >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t���� ������: %c", data);
	printf("\n ���� D>>"); enQueue(cQ, 'D'); printQ(cQ);
	printf("\n ���� E>>"); enQueue(cQ, 'E'); printQ(cQ);
	getchar();
}
#include <stdio.h>
#include<stdlib.h>
#define RADIX 10 //10진수
#define DIGIT 2 //두자리


//////기수정렬
//typedef int element; 
//
//typedef struct QNode { //밑것들 잘 모르겠으면 211025파일 참고
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
////여기까지 큐
//
////기수정렬
//void radixSort(element a[], int n) {
//	int i, bucket, d, factor = 1;
//
//	LQueueType* Q[RADIX];//대충 수납장 만드는 느낌
//	for (bucket = 0; bucket < RADIX; bucket++) 
//		Q[bucket] = createLinkedQueue(); //주납장 RADIX갯수만큼 층수 만들기
//
//		for (d = 0; d < DIGIT; d++) {
//			for (i = 0; i < n; i++)
//				enQueue(Q[(a[i] / factor) % 10], a[i]);//1단위 자신에게 맞는수납창 층에 넣기
//			for (bucket = 0, i = 0; bucket < RADIX; bucket++) //다시 꺼내서 a[]에 저장
//				while (!isEmpty(Q[bucket])) a[i++] = deQueue(Q[bucket]);
//				printf("\n\n %d 단계 : ", d + 1);//현재 단계 보여주기용
//				for (i = 0; i < n; i++) printf("%d ", a[i]);
//				factor = factor * 10; //10단위로 기수정렬 반복하기위해  facotr 수정
//		}
//}
//
////실험용
//void main() {
//	element list[8] = { 69,10,30,2,16,8,31,22 };
//	int size = 8;
//	printf("\n <<<<< 기수 정렬 수행 >>>>>");
//	radixSort(list, size);
//
//	getchar();
//}

////트리정렬

typedef int element; //트리 모르면 211028로
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
	else printf("\n 이미 같은 키가 있습니다!");
	return p;
}

void displayInorder(treeNode* root) {//중위순회
	if (root) {
		displayInorder(root->left);
		printf("%d ", root->key);
		displayInorder(root->right);
	}
}

//트리정렬연산
void treeSort(element a[], int n) {
	treeNode* root = NULL; //공백트리생성
	root = insertNode(root, a[0]);//a[0]을 루트로 삽입

	for (int i = 0; i < n; i++)
		insertNode(root, a[i]);//삽입하면서 이진탐색트리 구성
	displayInorder(root);//중위순회한것 경로출력
}

//실험용
int main() {
	element list[8] = { 69,10,30,2,16,8,31,22 };
	int size = 8;
	printf("\n <<<<트리 정렬 수행>>>>>");
	treeSort(list, size);

	getchar();
}
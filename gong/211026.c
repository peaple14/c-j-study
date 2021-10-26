#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

////수직이진트리 순회
//typedef struct treeNode { //트리 노드
//	char data;
//	struct treeNode* left;
//	struct treeNode* right;
//} treeNode;
//
////오른쪽,왼쪽 연결
//treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode) { 
//	treeNode* root = (treeNode *)malloc(sizeof(treeNode));
//	root->data = data;
//	root->left = leftNode; //왼쪽연결
//	root->right = rightNode; //오른쪽연결
//	return root;
//}
//
////전위순환
//void preorder(treeNode* root) {
//	if (root) {
//		printf("%c", root->data);
//		preorder(root->left);
//		preorder(root->right);
//	}
//}
//
////중위순환
//void inorder(treeNode* root) {
//	if (root) {
//		preorder(root->left);
//		printf("%c", root->data);
//		preorder(root->right);
//	}
//}
//
////후위순환
//void postorder(treeNode* root) {
//	if (root) {
//		preorder(root->left);		
//		preorder(root->right);
//		printf("%c", root->data);
//	}
//}
//
////실험용
//void main() {
//	treeNode* n7 = makeRootNode('D', NULL, NULL);
//	treeNode* n6 = makeRootNode('C', NULL, NULL);
//	treeNode* n5 = makeRootNode('B', NULL, NULL);
//	treeNode* n4 = makeRootNode('A', NULL, NULL);
//	treeNode* n3 = makeRootNode('/', n6, n7);
//	treeNode* n2 = makeRootNode('*', n4, n5);
//	treeNode* n1 = makeRootNode('-', n2, n3);
//
//	printf("\n preorder : ");
//	preorder(n1);
//	printf("\n inorder : ");
//	inorder(n1);
//	printf("\n postorder : ");
//	postorder(n1);
//
//	getchar();
//}

//typedef struct treeNode {//노드만들기
//	int size; //사이즈 저장
//	struct treeNode* left;
//	struct treeNode* right;
//}treeNode;
//
//int FolderSize = 0;//폴더용량
//
////왼쪽 오//후위순회 폴더용량계산
//른쪽 트리 연결
//treeNode* makeRootNode(int size, treeNode *leftNode, treeNode* rightNode) {
//	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
//	root->size = size;
//	root->left = leftNode;
//	root->right = rightNode;
//	return root;
//}
//
////후위 순환연산
//int postorder_FolderSize(treeNode* root) {
//	if (root) {
//		postorder_FolderSize(root->left);
//		postorder_FolderSize(root->right);
//		FolderSize += root->size;
//	}
//}
//
////실험용
//void main() {
//	treeNode* F11 = makeRootNode(120, NULL, NULL);
//	treeNode* F10 = makeRootNode(55, NULL, NULL);
//	treeNode* F9 = makeRootNode(100, NULL, NULL);
//	treeNode* F8 = makeRootNode(200, NULL, NULL);
//	treeNode* F7 = makeRootNode(68, F10, F11);
//	treeNode* F6 = makeRootNode(40, NULL, NULL);
//	treeNode* F5 = makeRootNode(15, NULL, NULL);
//	treeNode* F4 = makeRootNode(2, F8, F9);
//	treeNode* F3 = makeRootNode(10, F6, F7);
//	treeNode* F2 = makeRootNode(0, F4, F5);
//	treeNode* F1 = makeRootNode(0, F2, F3);
//
//	printf("\n\n C:\\의 용량: %d M \n, postorder_FolderSize(F2)");
//	
//	FolderSize = 0;//다시 초기화
//	printf("\n\n D:\\의 용량: %d M \n, postorder_FolderSize(F3)");
//
//	FolderSize = 0;//다시 초기화
//	printf("\n\n 내 컴퓨터의 전체 용량: %d M \n, postorder_FolderSize(F1)");
//}

//스레드 이진트리
typedef struct treeNode { //노드구현
	char data;
	struct treeNode* left;
	struct treeNode* right;
	int isThreadRight;
}treeNode;


//오른쪽트리와 왼쪽트리 연결
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode, int isThreadRight) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	root->isThreadRight = isThreadRight;
	return root;
}

//후속자 노드 반환
treeNode* findThreadSuccessor(treeNode* p) {
	treeNode* q = p->right; //포인트 설정
	if (q == NULL) return q; //후속자없다면 
	if (p->isThreadRight == 1) return q; //스레드 있을시
	while (q->left != NULL) q = q->left; //왼쪽으로 계속이동
	return q;
}

//중위순회
void threadInorder(treeNode* root) {
	treeNode* q;
	q = root;
	while (q->left) q = q->left;
	do {
		printf("%3c", q->data);
		q = findThreadSuccessor(q);
	} while (q);
}

//실험용
void main() {
	treeNode* n7 = makeRootNode('D', NULL, NULL, 0);
	treeNode* n6 = makeRootNode('C', NULL, NULL, 1);//넣을것,왼쪽,오른쪽,스레드여부
	treeNode* n5 = makeRootNode('B', NULL, NULL, 1);
	treeNode* n4 = makeRootNode('A', NULL, NULL, 1);
	treeNode* n3 = makeRootNode('/', n6, n7, 0);
	treeNode* n2 = makeRootNode('*', n4, n5, 0);
	treeNode* n1 = makeRootNode('-', n2, n3, 0);

	//후속자
	n4->right = n2; 
	n5->right = n1; 
	n6->right = n3;

	printf("\n 스레드 이진 트리의 중위 순회 : ");
	threadInorder(n1);

	getchar();

}
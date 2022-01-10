#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

////��������Ʈ�� ��ȸ
//typedef struct treeNode { //Ʈ�� ���
//	char data;
//	struct treeNode* left;
//	struct treeNode* right;
//} treeNode;
//
////������,���� ����
//treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode) { 
//	treeNode* root = (treeNode *)malloc(sizeof(treeNode));
//	root->data = data;
//	root->left = leftNode; //���ʿ���
//	root->right = rightNode; //�����ʿ���
//	return root;
//}
//
////������ȯ
//void preorder(treeNode* root) {
//	if (root) {
//		printf("%c", root->data);
//		preorder(root->left);
//		preorder(root->right);
//	}
//}
//
////������ȯ
//void inorder(treeNode* root) {
//	if (root) {
//		preorder(root->left);
//		printf("%c", root->data);
//		preorder(root->right);
//	}
//}
//
////������ȯ
//void postorder(treeNode* root) {
//	if (root) {
//		preorder(root->left);		
//		preorder(root->right);
//		printf("%c", root->data);
//	}
//}
//
////�����
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

//typedef struct treeNode {//��常���
//	int size; //������ ����
//	struct treeNode* left;
//	struct treeNode* right;
//}treeNode;
//
//int FolderSize = 0;//�����뷮
//
////���� ��//������ȸ �����뷮���
//���� Ʈ�� ����
//treeNode* makeRootNode(int size, treeNode *leftNode, treeNode* rightNode) {
//	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
//	root->size = size;
//	root->left = leftNode;
//	root->right = rightNode;
//	return root;
//}
//
////���� ��ȯ����
//int postorder_FolderSize(treeNode* root) {
//	if (root) {
//		postorder_FolderSize(root->left);
//		postorder_FolderSize(root->right);
//		FolderSize += root->size;
//	}
//}
//
////�����
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
//	printf("\n\n C:\\�� �뷮: %d M \n, postorder_FolderSize(F2)");
//	
//	FolderSize = 0;//�ٽ� �ʱ�ȭ
//	printf("\n\n D:\\�� �뷮: %d M \n, postorder_FolderSize(F3)");
//
//	FolderSize = 0;//�ٽ� �ʱ�ȭ
//	printf("\n\n �� ��ǻ���� ��ü �뷮: %d M \n, postorder_FolderSize(F1)");
//}

//������ ����Ʈ��
typedef struct treeNode { //��屸��
	char data;
	struct treeNode* left;
	struct treeNode* right;
	int isThreadRight;
}treeNode;


//������Ʈ���� ����Ʈ�� ����
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode, int isThreadRight) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	root->isThreadRight = isThreadRight;
	return root;
}

//�ļ��� ��� ��ȯ
treeNode* findThreadSuccessor(treeNode* p) {
	treeNode* q = p->right; //����Ʈ ����
	if (q == NULL) return q; //�ļ��ھ��ٸ� 
	if (p->isThreadRight == 1) return q; //������ ������
	while (q->left != NULL) q = q->left; //�������� ����̵�
	return q;
}

//������ȸ
void threadInorder(treeNode* root) {
	treeNode* q;
	q = root;
	while (q->left) q = q->left;
	do {
		printf("%3c", q->data);
		q = findThreadSuccessor(q);
	} while (q);
}

//�����
void main() {
	treeNode* n7 = makeRootNode('D', NULL, NULL, 0);
	treeNode* n6 = makeRootNode('C', NULL, NULL, 1);//������,����,������,�����忩��
	treeNode* n5 = makeRootNode('B', NULL, NULL, 1);
	treeNode* n4 = makeRootNode('A', NULL, NULL, 1);
	treeNode* n3 = makeRootNode('/', n6, n7, 0);
	treeNode* n2 = makeRootNode('*', n4, n5, 0);
	treeNode* n1 = makeRootNode('-', n2, n3, 0);

	//�ļ���
	n4->right = n2; 
	n5->right = n1; 
	n6->right = n3;

	printf("\n ������ ���� Ʈ���� ���� ��ȸ : ");
	threadInorder(n1);

	getchar();

}
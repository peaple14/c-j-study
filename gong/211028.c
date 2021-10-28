#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/////////����Ž��Ʈ�� ����

typedef char element;

//Ʈ����� ����ü
typedef struct treeNode {
	char key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

//Ű��ã�°�
treeNode* searchBST(treeNode* root, char x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) p = p->left; //�Ѹ����� Ű������ �۴ٸ� ��������
		else if (x == p->key) return p; // ���ٸ� ����
		else p = p->right; // ũ�ٸ� ����������
	}
	printf("\n ã�� Ű�� �����ϴ�!"); //���ٸ� ���
	return p;
	}

//���ο ���� ����ִ°�
treeNode* insertNode(treeNode* p, char x) {
	treeNode* newNode; // ���ο� ���
	if (p == NULL) { //��������Ͻ�
		newNode == (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x; //�� �����ߴ����� �˱�@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insertNode(p->left, x); // x������ p���� ������ ���ʿ�
	else if (x > p->key) p->left = insertNode(p->right, x);//ũ�ٸ� �����ʿ�
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ� \n"); // ���ٸ� ���

	return p;
}

//�������� �ִٸ� ����
void deleteNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root; //���ʰ�(���� �����ϴ³��)
	while ((p != NULL) && (p->key != key)) { // ���������� key�� ã��������������
		parent = p; //�θ�����(������� �ٷ������)
		if (key < p->key)p = p->left; //ã�°����� �۴ٸ� ����
		else p = p->right;//ũ�ٸ� ������
	}
	//ã�°��� ������
	if (p == NULL) {
		printf("\nã�� Ű�� ���� Ʈ���� �����ϴ�");
		return;
	}

	//������ ��尡 �ܸ��ϰ��(�ڽĳ�� �������)
	if ((p->left == NULL) && p->right == NULL) {
		if (parent != NULL) {//���� �θ��� �������
			if (parent->left == p) parent->left = NULL;//�θ����� ���ʿ� �����ҳ�尡 �������
			else parent->right = NULL;//�θ����� �����ʿ� ������ ��尡 �ִ°��
		}
		else root = NULL;//��尡 �ڽ�ȥ���ϰ��
	}

	//������ ��尡 �ڽĳ�带 �Ѱ� �������
	else if ((p->left == NULL) || (p->right == NULL)) { //�ڽĳ�� �����ϳ��� NULL�ϰ��
		if (p->left != NULL) child = p->left;//���� �����ҳ���� ���ʿ� �ڽĳ�尡������� �ڽĳ�带 child�� ����
		else child = p->right; // �����ʿ� �������

		if (parent != NULL) { //�θ��� NULL���� �ƴ϶��
			if (parent->left == p) parent->left = child;//��������� �θ�����ʿ� �ٿ���
			else parent->right = child;//�����ʿ� ����
		}
		else root = child;//������尪�� root���Ͻ� 
	}

	//�ڽĳ�尡 ������ �ڽĳ�带 �ΰ� �������
	else {
		succ_parent = p; //�����Ұ�
		succ = p->left; //�����ɰ��� �����ڽĳ��
		while (succ->right != NULL) { //�����ڽĳ���� �����ʳ��� �ɵ���(�����ڽĳ�忡�� ����ū���ã��)
			succ_parent = succ;//����ū���� succ������
			succ = succ->right; // succ�� �������� ���δ�
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left;//���� �����ɰ��� ������ ����Ŭ�� �����ɰ��� ���ʳ�忡 �װ��� �ִ´�
		else succ_parent->right = succ->left;  //���� �����ʳ���� �װ��� ���ʳ�忡 �ִ´�
		p->key = succ->key; // p�� Ű���� �������� �ִ´�
		p = succ; //�����ɰ��� �װ����ִ´�
	}
	free(p); // �޸� ����
	}

void displayInorder(treeNode* root) {
	if (root) {//��Ʈ���� �����Ҷ� ��ȸ�ϸ� ������(������ȯ)
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	}

}
//�����1
void menu() {
	printf("\n*--------------------*");
	printf("\nt1 : Ʈ�� ���");
	printf("\nt2 : ���� ����");
	printf("\nt3 : ���� ����");
	printf("\nt4 : ���� �˻�");
	printf("\nt5 : ����");
	printf("\n*--------------------*");
	printf("\n�޴� �Է� >>");
}
//�����2
int main() {
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;
	char choice, key;

	root = insertNode(root,'G');
	insertNode(root,'I');
	insertNode(root,'H');
	insertNode(root,'D');
	insertNode(root,'B');
	insertNode(root,'M');
	insertNode(root,'N');
	insertNode(root,'A');
	insertNode(root,'J');
	insertNode(root,'E');
	insertNode(root,'Q');

	while (1) {
		menu();
		scanf(" %c", &choice);
		
		switch (choice - '0') {
		case 1: printf("\t[���� Ʈ�� ���] ");
			displayInorder(root); printf("\n");
			break;
		case 2: printf("������ ���ڸ� �Է��ϼ��� : ");
			scanf("%c", &key);
			insertNode(root,key);
			break;
		case 3: printf("������ ���ڸ� �Է��ϼ��� : ");
			deleteNode(root,key);
			break;
		case 4: printf("ã�� ���ڸ� �Է��ϼ��� : ");
			foundedNode = searchBST(root, key);
			if (foundedNode != NULL)
				printf("\n %c�� ã�ҽ��ϴ�! \n", foundedNode->key);
			else printf("\n ���ڸ� ã�� ���߽��ϴ�. \n");
			break;

		case 5: return 0;

		default: printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ��� \n");
			break;
		}
	}
}
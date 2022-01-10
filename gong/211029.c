#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX(a,b) ((a>b) ? a:b)

////AVL Ʈ��


typedef int element;

typedef struct treeNode {
	element key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

//�Ʒ� 4������ �׸��׷����� �����ϱ� ����.
//LLȸ��
treeNode* LL_rotate(treeNode* parent) {
	treeNode* child = parent->left;//�θ����� left�� child������
	parent->left = child->right;//�θ����� ���ʿ� �ڽĳ���� �������� ����
	child->right = parent; //�ڽĳ���� ���������� �θ���(���ڽĳ�嵵)�� �ٿ���
}

//RRȸ��
treeNode* RR_rotate(treeNode* parent) {
	treeNode* child = parent->right;//LLȸ���� ���
	parent->right = child->left;
	child->left = parent; 
}

//LRȸ��
treeNode* LR_rotate(treeNode* parent) {
	treeNode* child = parent->left;//child�� �����ϰ�
	parent->left = RR_rotate(child);//�ڽĳ�忡�� rrȸ�� �ѹ����ְ�
	return LL_rotate(parent);//LL�ϰ� ����
}

//RLȸ��
treeNode* RL_rotate(treeNode* parent) {
	treeNode* child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}

//����Ʈ�� ���̱��ϱ�
int getHeight(treeNode* p) {
	int height = 0; //0���ͽ���
	if(p != NULL) height = MAX(getHeight(p->left), getHeight(p->right)) +1; //������ �ƴҶ� ���̿� ����,Ȥ�� ������ �ڱ��ڽ� ȣ��� ���̱��ϰ� 1���ϱ�
	return height;
}

//�����μ� BF ���ϱ�
int getBF(treeNode* p) {
	if (p == NULL)return 0; //�����Ͻ�
	return getHeight(p->left) - getHeight(p->right); //���ʿ��� �����ʻ���
}

//�ұ��� �߻��� ȸ������ȣ��
treeNode* rebalance(treeNode** p) {
	int BF = getBF(*p);

	if (BF>1) {
		if (getBF((*p)->left) > 0)
			*p = LL_rotate(*p);
		else *p = LR_rotate(*p);
	}
	else if (BF < -1) {
		if (getBF((*p)->right) < 0)
			*p = RR_rotate(*p);
		else *p = RL_rotate(*p);
	}
	return *p;
}

//avlƮ���� ������
treeNode* insert_AVL_Node(treeNode** root, element x) {
	if (*root == NULL) { //�����Ͻ�
		*root = (treeNode*)malloc(sizeof(treeNode));
		(*root)->key = x;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (x < (*root)->key) { //�������� Ű������ ������
		(*root)->left = insert_AVL_Node(&((*root)->left), x);//��Ʈ�� ���ʳ��� �̵��ؼ� �ڽ�ȣ��ݺ�
		*root = rebalance(root);
	}
	else if (x > (*root)->key) { //�������� Ű������ Ŭ��
		(*root)->right = insert_AVL_Node(&((*root)->right), x);//��Ʈ�� �����ʳ��� �̵��ؼ� �ڽ�ȣ��ݺ�
		*root = rebalance(root);
	}
	else {
		printf("\n �̹� ���� Ű�� �ֽ��ϴ� \n");
		exit(1);
	}
	return *root;
}

//����Ž��Ʈ�� ������
treeNode* insert_BST_Node(treeNode* p, element x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insert_BST_Node(p->left, x);
	else if (x > p->key) p->right = insert_BST_Node(p->right, x);
	else printf("\n �̹� ����Ű�� �ֽ��ϴ�.");

	return p;
}

//Ű��ã�°�
treeNode* searchTree(treeNode* root, element x) {
	treeNode* p;
	int count = 0;
	p = root;
	while (p != NULL) {
		count++;
		if (x < p->key) p = p->left; //�Ѹ����� Ű������ �۴ٸ� ��������
		else if (x == p->key) {
			printf("%3d��°�� Ž�� ����", count);
			return p;
		}
		else p = p->right;
	}
	count++;
	printf("%3d��°�� Ž�� ����! ã�� Ű�� �����ϴ�", count);
	return p;
}

//����Ʈ�� ������ȸ ���
void displayInorder(treeNode* root) {
	if (root) {//��Ʈ���� �����Ҷ� ��ȸ�ϸ� ������(������ȯ)
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	}
}
//�����
int main() {
	treeNode* root_AVL = NULL;
	treeNode* root_BST = NULL;
	
	//////////////////////////
	root_AVL = insert_AVL_Node(&root_AVL, 50); //AVL�����
	insert_AVL_Node(&root_AVL, 60);
	insert_AVL_Node(&root_AVL, 70);
	insert_AVL_Node(&root_AVL, 90);
	insert_AVL_Node(&root_AVL, 80);
	insert_AVL_Node(&root_AVL, 75);
	insert_AVL_Node(&root_AVL, 73);
	insert_AVL_Node(&root_AVL, 72);
	insert_AVL_Node(&root_AVL, 78);

	printf("\n ******* AVL Ʈ�� ��� ************\n\n");
	displayInorder(root_AVL);

	printf("\n\n AVL Ʈ������ 70 Ž�� :");
	searchTree(root_AVL, 70);

	printf("\n\nAVL Ʈ������  72 Ž�� :");
	searchTree(root_AVL, 72);

	printf("\n\n AVL Ʈ������ 76 Ž�� :");
	searchTree(root_AVL, 76);

	//////////////////////////
	root_BST = insert_BST_Node(&root_BST, 50); //BST�����
	insert_BST_Node(&root_BST, 60);
	insert_BST_Node(&root_BST, 70);
	insert_BST_Node(&root_BST, 90);
	insert_BST_Node(&root_BST, 80);
	insert_BST_Node(&root_BST, 75);
	insert_BST_Node(&root_BST, 73);
	insert_BST_Node(&root_BST, 72);
	insert_BST_Node(&root_BST, 78);

	printf("\n ******* BST Ʈ�� ��� ************\n\n");
	displayInorder(root_BST);

	printf("\n\n BST Ʈ������ 70 Ž�� :");
	searchTree(root_BST, 70);

	printf("\n\nBST Ʈ������  72 Ž�� :");
	searchTree(root_BST, 72);

	printf("\n\nBST Ʈ������ 76 Ž�� :");
	searchTree(root_BST, 76);

	getchar();
} 
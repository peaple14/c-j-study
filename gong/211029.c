#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX(a,b) ((a>b) ? a:b)

////AVL 트리


typedef int element;

typedef struct treeNode {
	element key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

//아래 4가지는 그림그려보면 이해하기 쉬움.
//LL회전
treeNode* LL_rotate(treeNode* parent) {
	treeNode* child = parent->left;//부모노드의 left를 child로지정
	parent->left = child->right;//부모노드의 왼쪽에 자식노드의 오른쪽을 붙임
	child->right = parent; //자식노드의 오른쪽을에 부모노드(의자식노드도)를 붙여줌
}

//RR회전
treeNode* RR_rotate(treeNode* parent) {
	treeNode* child = parent->right;//LL회전과 비슷
	parent->right = child->left;
	child->left = parent; 
}

//LR회전
treeNode* LR_rotate(treeNode* parent) {
	treeNode* child = parent->left;//child로 지정하고
	parent->left = RR_rotate(child);//자식노드에서 rr회전 한번해주고
	return LL_rotate(parent);//LL하고 리턴
}

//RL회전
treeNode* RL_rotate(treeNode* parent) {
	treeNode* child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}

//서브트리 높이구하기
int getHeight(treeNode* p) {
	int height = 0; //0부터시작
	if(p != NULL) height = MAX(getHeight(p->left), getHeight(p->right)) +1; //공백이 아닐때 높이에 왼쪽,혹은 오른쪽 자기자신 호출로 높이구하고 1더하기
	return height;
}

//균형인수 BF 구하기
int getBF(treeNode* p) {
	if (p == NULL)return 0; //공백일시
	return getHeight(p->left) - getHeight(p->right); //왼쪽에서 오른쪽빼기
}

//불균형 발생시 회전연산호출
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

//avl트리에 노드삽입
treeNode* insert_AVL_Node(treeNode** root, element x) {
	if (*root == NULL) { //공백일시
		*root = (treeNode*)malloc(sizeof(treeNode));
		(*root)->key = x;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (x < (*root)->key) { //넣을값이 키값보다 작을시
		(*root)->left = insert_AVL_Node(&((*root)->left), x);//루트의 왼쪽노드로 이동해서 자신호출반복
		*root = rebalance(root);
	}
	else if (x > (*root)->key) { //넣을값이 키값보다 클시
		(*root)->right = insert_AVL_Node(&((*root)->right), x);//루트의 오른쪽노드로 이동해서 자신호출반복
		*root = rebalance(root);
	}
	else {
		printf("\n 이미 같은 키가 있습니다 \n");
		exit(1);
	}
	return *root;
}

//이진탐색트리 노드삽입
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
	else printf("\n 이미 같은키가 있습니다.");

	return p;
}

//키값찾는곳
treeNode* searchTree(treeNode* root, element x) {
	treeNode* p;
	int count = 0;
	p = root;
	while (p != NULL) {
		count++;
		if (x < p->key) p = p->left; //뿌리값이 키값보다 작다면 왼쪽으로
		else if (x == p->key) {
			printf("%3d번째에 탐색 성공", count);
			return p;
		}
		else p = p->right;
	}
	count++;
	printf("%3d번째에 탐색 실패! 찾는 키가 없습니다", count);
	return p;
}

//이진트리 중위순회 출력
void displayInorder(treeNode* root) {
	if (root) {//루트값이 존재할때 순회하며 보여줌(중위순환)
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	}
}
//실험용
int main() {
	treeNode* root_AVL = NULL;
	treeNode* root_BST = NULL;
	
	//////////////////////////
	root_AVL = insert_AVL_Node(&root_AVL, 50); //AVL만들기
	insert_AVL_Node(&root_AVL, 60);
	insert_AVL_Node(&root_AVL, 70);
	insert_AVL_Node(&root_AVL, 90);
	insert_AVL_Node(&root_AVL, 80);
	insert_AVL_Node(&root_AVL, 75);
	insert_AVL_Node(&root_AVL, 73);
	insert_AVL_Node(&root_AVL, 72);
	insert_AVL_Node(&root_AVL, 78);

	printf("\n ******* AVL 트리 출력 ************\n\n");
	displayInorder(root_AVL);

	printf("\n\n AVL 트리에서 70 탐색 :");
	searchTree(root_AVL, 70);

	printf("\n\nAVL 트리에서  72 탐색 :");
	searchTree(root_AVL, 72);

	printf("\n\n AVL 트리에서 76 탐색 :");
	searchTree(root_AVL, 76);

	//////////////////////////
	root_BST = insert_BST_Node(&root_BST, 50); //BST만들기
	insert_BST_Node(&root_BST, 60);
	insert_BST_Node(&root_BST, 70);
	insert_BST_Node(&root_BST, 90);
	insert_BST_Node(&root_BST, 80);
	insert_BST_Node(&root_BST, 75);
	insert_BST_Node(&root_BST, 73);
	insert_BST_Node(&root_BST, 72);
	insert_BST_Node(&root_BST, 78);

	printf("\n ******* BST 트리 출력 ************\n\n");
	displayInorder(root_BST);

	printf("\n\n BST 트리에서 70 탐색 :");
	searchTree(root_BST, 70);

	printf("\n\nBST 트리에서  72 탐색 :");
	searchTree(root_BST, 72);

	printf("\n\nBST 트리에서 76 탐색 :");
	searchTree(root_BST, 76);

	getchar();
} 
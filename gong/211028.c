#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/////////이진탐색트리 연산

typedef char element;

//트리노드 구조체
typedef struct treeNode {
	char key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

//키값찾는곳
treeNode* searchBST(treeNode* root, char x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) p = p->left; //뿌리값이 키값보다 작다면 왼쪽으로
		else if (x == p->key) return p; // 같다면 리턴
		else p = p->right; // 크다면 오른쪽으로
	}
	printf("\n 찾는 키가 없습니다!"); //없다면 출력
	return p;
	}

//새로운값 비교후 집어넣는곳
treeNode* insertNode(treeNode* p, char x) {
	treeNode* newNode; // 새로운 노드
	if (p == NULL) { //공백상태일시
		newNode == (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x; //왜 에러뜨는지좀 알기@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insertNode(p->left, x); // x값보다 p값이 작을시 왼쪽에
	else if (x > p->key) p->left = insertNode(p->right, x);//크다면 오른쪽에
	else printf("\n 이미 같은 키가 있습니다 \n"); // 같다면 출력

	return p;
}

//같은것이 있다면 삭제
void deleteNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root; //최초값(대충 시작하는노드)
	while ((p != NULL) && (p->key != key)) { // 끝까지가고 key값 찾을수없을때까지
		parent = p; //부모값지정(넣을장소 바로윗노드)
		if (key < p->key)p = p->left; //찾는값보다 작다면 왼쪽
		else p = p->right;//크다면 오른쪽
	}
	//찾는값이 없을시
	if (p == NULL) {
		printf("\n찾는 키가 이진 트리에 없습니다");
		return;
	}

	//삭제할 노드가 단말일경우(자식노드 없을경우)
	if ((p->left == NULL) && p->right == NULL) {
		if (parent != NULL) {//또한 부모노드 있을경우
			if (parent->left == p) parent->left = NULL;//부모노드의 왼쪽에 삭제할노드가 있을경우
			else parent->right = NULL;//부모노드의 오른쪽에 삭제할 노드가 있는경우
		}
		else root = NULL;//노드가 자신혼자일경우
	}

	//삭제할 노드가 자식노드를 한개 가진경우
	else if ((p->left == NULL) || (p->right == NULL)) { //자식노드 둘중하나가 NULL일경우
		if (p->left != NULL) child = p->left;//만약 삭제할노드의 왼쪽에 자식노드가있을경우 자식노드를 child로 지정
		else child = p->right; // 오른쪽에 있을경우

		if (parent != NULL) { //부모값이 NULL값이 아니라면
			if (parent->left == p) parent->left = child;//삭제노드의 부모노드왼쪽에 붙여둠
			else parent->right = child;//오른쪽에 붙임
		}
		else root = child;//삭제노드값이 root값일시 
	}

	//자식노드가 삭제할 자식노드를 두개 가진경우
	else {
		succ_parent = p; //삭제할값
		succ = p->left; //삭제될값의 왼쪽자식노드
		while (succ->right != NULL) { //왼쪽자식노드의 오른쪽끝이 될동안(왼쪽자식노드에서 가장큰노드찾기)
			succ_parent = succ;//가장큰값을 succ로지정
			succ = succ->right; // succ의 오른쪽을 붙인다
		}
		if (succ_parent->left == succ) succ_parent->left = succ->left;//만약 삭제될값의 왼쪽이 가장클때 삭제될값의 왼쪽노드에 그값을 넣는다
		else succ_parent->right = succ->left;  //만약 오른쪽노드라면 그값을 왼쪽노드에 넣는다
		p->key = succ->key; // p의 키값에 넣은값을 넣는다
		p = succ; //삭제될값에 그값을넣는다
	}
	free(p); // 메모리 해제
	}

void displayInorder(treeNode* root) {
	if (root) {//루트값이 존재할때 순회하며 보여줌(중위순환)
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	}

}
//실험용1
void menu() {
	printf("\n*--------------------*");
	printf("\nt1 : 트리 출력");
	printf("\nt2 : 문자 삽입");
	printf("\nt3 : 문자 삭제");
	printf("\nt4 : 문자 검색");
	printf("\nt5 : 종료");
	printf("\n*--------------------*");
	printf("\n메뉴 입력 >>");
}
//실험용2
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
		case 1: printf("\t[이진 트리 출력] ");
			displayInorder(root); printf("\n");
			break;
		case 2: printf("삽입할 문자를 입력하세요 : ");
			scanf("%c", &key);
			insertNode(root,key);
			break;
		case 3: printf("삭제할 문자를 입력하세요 : ");
			deleteNode(root,key);
			break;
		case 4: printf("찾을 문자를 입력하세요 : ");
			foundedNode = searchBST(root, key);
			if (foundedNode != NULL)
				printf("\n %c를 찾았습니다! \n", foundedNode->key);
			else printf("\n 문자를 찾지 못했습니다. \n");
			break;

		case 5: return 0;

		default: printf("없는 메뉴입니다. 메뉴를 다시 선택하세요 \n");
			break;
		}
	}
}
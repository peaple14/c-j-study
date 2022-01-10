#include <stdio.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

//void main()
//{
//	int i, sale[4] = { 157,209,251,312 };
//
//	for (i = 0; i < 4; i++) {
//		printf("\n address : %u sale[%d] = %d", &sale[i], i, sale[i]);
//	}
//
//	getchar();
//}

typedef struct  { //����ü����
	int degree; //����
	float coef[MAX_DEGREE]; //������ ���
}polynomial;

polynomial addPoly(polynomial, polynomial);  //���ϱ�
void printPoly(polynomial); //���

void main() {
	polynomial A = { 3,{4,3,5,0 }}; //�ʱ�ȭ
	polynomial B = { 4,{3,1,0,2,1}};//�ʱ�ȭ

	polynomial C;  //����� ������
	C = addPoly(A, B); //����� �����
	
	printf("\n A(x) ="); printPoly(A); //A
	printf("\n B(x) ="); printPoly(B); //B
	printf("\n C(x) ="); printPoly(C); //����� C

	getchar();
}

polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0; //�ִ����� �ʱ�ȭ�ϱ�(�迭����)
	int A_degree = A.degree, B_degree = B.degree; //��� �ּҰ� ����ֱ�
	C.degree = MAX(A.degree, B.degree); //C�� �ְ����� ����ֱ�
	
	while (A_index <= A.degree && B_index <= B.degree) { //�ִ������� 0���ϰ� �ɶ�����
		if (A_degree > B_degree) {	//���� a������ b���� ũ�ٸ�
			C.coef[C_index++] = A.coef[A_index++]; //c�� a ���� ����ֱ�
			A_degree--; //a�� b�� ������ ������������ �� �̾���
		}
		else if (A_degree == B_degree) {	//�Ѱ�� ���ٸ�
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];	//�ְ��� ���ؼ� c�� �ֱ�
			A_degree--; //���� �Ѱ��� ������ ���
			B_degree--;	//���� �Ѱ��� ������ ���
		}
		else {	//���� b������ a���� ũ�ٸ�
			C.coef[C_index++] = B.coef[B_index++]; //c������ b���� ���ؼ� �ֱ�
			B_degree--; //a�� b�� ������ ������������ �� �̾���
		}
	}
	return C;
}

void printPoly(polynomial P) { //����Ʈ�ϴ°�
	int i, degree; //�ʱⰪ�� ���� �ֱ�
	degree = P.degree; //�ְ������ֱ�

	for (i = 0; i <= P.degree; i++) { //�ְ��������� �۾��������� �ݺ�
		printf("%3.0fx^%d", P.coef[i], degree--); //�ϳ��� �����ֱ�
		if (i < P.degree) printf(" +"); //
	}
	printf("\n");
}
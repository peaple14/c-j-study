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

typedef struct  { //구조체정의
	int degree; //차수
	float coef[MAX_DEGREE]; //각항의 계수
}polynomial;

polynomial addPoly(polynomial, polynomial);  //더하기
void printPoly(polynomial); //출력

void main() {
	polynomial A = { 3,{4,3,5,0 }}; //초기화
	polynomial B = { 4,{3,1,0,2,1}};//초기화

	polynomial C;  //결과물 넣을곳
	C = addPoly(A, B); //결과물 만들기
	
	printf("\n A(x) ="); printPoly(A); //A
	printf("\n B(x) ="); printPoly(B); //B
	printf("\n C(x) ="); printPoly(C); //결과물 C

	getchar();
}

polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0; //최대차수 초기화하기(배열순서)
	int A_degree = A.degree, B_degree = B.degree; //계수 주소값 집어넣기
	C.degree = MAX(A.degree, B.degree); //C에 최고계수값 집어넣기
	
	while (A_index <= A.degree && B_index <= B.degree) { //최대차수가 0이하가 될때까지
		if (A_degree > B_degree) {	//만약 a차수가 b보다 크다면
			C.coef[C_index++] = A.coef[A_index++]; //c에 a 차수 집어넣기
			A_degree--; //a와 b의 차수가 같아질때까지 쭉 이어짐
		}
		else if (A_degree == B_degree) {	//둘계수 같다면
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];	//최고계수 더해서 c에 넣기
			A_degree--; //차수 한개씩 내려서 계산
			B_degree--;	//차수 한개씩 내려서 계산
		}
		else {	//만약 b차수가 a보다 크다면
			C.coef[C_index++] = B.coef[B_index++]; //c차수에 b차수 더해서 넣기
			B_degree--; //a와 b의 차수가 같아질때까지 쭉 이어짐
		}
	}
	return C;
}

void printPoly(polynomial P) { //프린트하는곳
	int i, degree; //초기값과 차수 넣기
	degree = P.degree; //최고차수넣기

	for (i = 0; i <= P.degree; i++) { //최고차수보다 작아질때까지 반복
		printf("%3.0fx^%d", P.coef[i], degree--); //하나씩 보여주기
		if (i < P.degree) printf(" +"); //
	}
	printf("\n");
}
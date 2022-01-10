#include<stdio.h>
#include<stdlib.h>

//진짜 기초부터 차근차근 빠르게 넘어가보기(백준알고리즘)
int main()
{
	int a;
	int b;
	int num1 = 0, num2 = 0, num3 = 0;
	scanf("%d", &a);
	scanf("%d", &b);
	num1 = b / 100;
	num2 = (b % 100) / 10;
	num3 = b % 10;
	printf("%d\n", a * num3);
	printf("%d\n", a * num2);
	printf("%d\n", a * num1);
	printf("%d", a * b);
}


//int main() {
//	int A, B, C;
//	scanf("%d %d %d", &A, &B, &C);
//	printf("%d\n%d\n%d\n%d", (A + B) % C, ((A % C) + (B % C)) % C, (A*B) % C, ((A % C) *(B % C)) % C);
//
//}


//int main() {
//	int A, B;
//	scanf("%d %d", &A, &B);
//	printf("%d\n%d\n%d\n%d\n%d", A + B, A - B, A * B, A / B, A % B);
//}


//int main() {
//	double A, B;
//	scanf_s("%lf %lf", &A, &B);
//	printf("%.9lf\n", A / B);
//}


//int main() {
//	printf("\\    /\\\n");
//	printf(" )  ( \')\n");
//	printf("(  /  )\n");
//	printf(" \\(__)|\n");
//}



//int main() {
//	printf("|\\_/|\n");
//	printf("|q p|   /}\n");
//	printf("( 0 )\"\"\"\\\n");
//	printf("|\"^\"`    |\n");
//	printf("||_/=\\\\__|");
//
//}


//void main() {
//	printf("강한친구 대한육군\n강한친구 대한육군");
//}

//int main() {
//	printf("Hello World!");
//}
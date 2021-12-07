#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;
//백트래킹하다 절망. 기초부터 다시

//int main() {
//	int a, b = 0;
//	int row[10001];
//	scanf("%d %d", &a, &b);
//	for (int i = 0; i < a; i++) {
//		scanf("%d", &row[i]);
//	}
//	for (int i = 0; i < a; i++) {
//		if (row[i] < b) {
//			printf("%d ", row[i]);
//		}
//	}
//}


//int main() {
//	int a = 0;
//	scanf("%d", &a);
//	for (int i = 1; i <= a; i++) {
//		for (int j = 1; j <= a-i; j++) {
//			printf(" ");
//		}
//		for (int k = 1; k <= i; k++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//}
//int main() {
//	int a, b, c = 0;
//	scanf("%d", &a);
//	for (int i = 1; i <= a; i++) {
//		scanf(" %d %d", &b, &c);
//		printf("Case #%d: %d + %d = %d\n", i,b,c, b + c);
//	}
//}
//int main() {
//	int a,b,c = 0;
//	scanf("%d", &a);
//	for (int i = 1; i <= a; i++) {
//		scanf(" %d %d", &b, &c);
//		printf("Case #%d: %d\n",i, b + c);
//	}
//}
//int main() {
//	int a = 0;
//	scanf("%d", &a);
//	for (int i = a; i >=1; i--) {
//		printf("%d\n", i);
//	}
//}
//int main() {
//	int a = 0;
//	scanf("%d", &a);
//	for (int i = 1; i <= a; i++) {
//		printf("%d\n", i);
//	}
//}
//int sum(int n)
//{
//    if (n == 1)      // n이 1일 때
//        return 1;    // 1을 반환하고 재귀호출을 끝냄
//
//    return n + sum(n - 1);    // n과 factorial 함수에 n - 1을 넣어서 반환된 값을 곱함
//}
//
//int main()
//{   
//    int a = 0;
//    scanf("%d", &a);
//    printf("%d", sum(a));
//
//    return 0;
//}
//int main() {
//	int a,b,c = 0;
//	scanf("%d", &a);
//	for (int i = 0; i < a; i++) {
//		scanf(" %d %d", &b, &c);
//		printf("%d\n", b + c);
//	}
//}
//int main() {
//	int a = 0;
//	scanf("%d", &a);
//	for (int i = 1; i <= 9; i++) {
//		printf("%d * %d = %d\n", a, i, a * i);
//	}
//}
//int main() {
//	int a, b, c = 0;
//	scanf("%d", &a);
//	scanf("%d", &b);
//	if (a == 0 && b<45) {
//		a = 24;
//	}
//	printf("%d %d", ((a * 60 + b) - 45) / 60, ((a * 60 + b) - 45) % 60);
//	
//}
//int main() {
//	int a, b = 0;
//	scanf("%d", &a);
//	scanf("%d", &b);
//	if (a > 0 && b > 0) printf("1");
//	if (a > 0 && b < 0)printf("4");
//	if (a < 0 && b < 0)printf("3");
//	if (a < 0 && b>0) printf("2");
//}
//int main() {
//	int year = 0;
//	scanf_s("%d", &year);
//	printf("%d\n", (year % 4 == 0 && year % 100 != 0 )||( year % 400 == 0) ? 1 : 0);
//}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;

//백준1193번
int chest[2];//리턴대신 쓸곳
int main() {
	long int num = 0;
	scanf("%d", &num);
	long int result;
	find(num);//chest에다 저장
	long int a = 0;//오른쪽
	long int b = 0;//왼쪽
	int king = num - chest[1]+1;//몇번째 수인가 정해주는것
	if (num == 1)printf("1/1");
	else if (chest[0] % 2 == 0) {//번호가 짝수면 작은수/큰수부터 시작위치 chest[1]
		a = king;
		b = chest[0]+1 - a;
		printf("%d/%d", a, b);;
	}
	else {//번호가 홀수면 큰수/작은수부터
		a = king;
		b = chest[0]+1 - a;
		printf("%d/%d", b, a);;
	}
}


void find(int num) {
	long int k = 1;//결과값(몇~몇번할때 더할값)
	long int pp = 2;//어디서부터 어디까지(첨엔 2~3)

	if (num == 1) {  k = 0; }

	while (k) {
		if (pp <= num && pp + k >= num) {
			chest[0] = k + 1;//몇번인가
			chest[1] = pp;//어디서부터 어디쪽의 번호인가
			break;
		}
		k++;
		pp += k;
	}
}

//int main() {
//	long int num = 0;
//	scanf("%d", &num);
//	long int k = 1;//결과값
//	long int a = 2;//어디서부터 어디까지
//
//	if (num == 1) { printf("1"); k = 0; }
//
//	while (k) {
//		if (a <= num && a + k*6-1 >= num) {
//			printf("%d", k+1);
//			break;
//		}
//		a += k * 6;
//		k++;
//	}
//}
//int main() {//백준 1712번
//	long int a, b, c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (c - b == 0) { 
//		printf("-1");
//	}
//	else {
//		long int result = a / (c - b);
//		printf("%d", result + 1 < 0 ? -1 : result + 1);
//	}
//}
//int main() {//백준 1316
//	int how = 0;
//	scanf("%d", &how);
//	char text[102];
//	int result = 0;
//	char exp[101];
//	int anum = -1;
//	int exit = -1;
//	for (int k = 0; k < how; k++) {
//		scanf("%s", &text);
//		int len = strlen(text);
//		for (int i = 0; i < len; i++) {
//			while (text[i] == text[i + 1]) {
//				i++;
//			}
//			anum++;
//			exp[anum] = text[i];
//			for (int j = 0; j < anum; j++) {
//				if (exp[j] == exp[anum] && j!=anum) {
//					exit = 0;
//				}
//			}
//		}
//
//		anum = -1;
//		if (exit == 0) {
//			exit = -1;
//			continue;
//		}
//		result++;
//	}
//	printf("%d", result);
//}
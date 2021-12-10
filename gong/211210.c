#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;
//백트래킹하다 절망. 기초부터 다시

int main() {
	int a = 0;//한수인지 아닌지검증
	int count = 99;//100이상수 카운트용
	scanf("%d", &a);
	if (a < 100) {
		printf("%d", a); return 0;
	}
	for (int i = 100; i <= a; i++) {
		int hun = i / 100;
		int ten = (i % 100) / 10;
		int one = (i % 100) % 10;
		if ((hun - ten) == (ten - one)) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}



//long long sum(int* a, int n) {
//	long long ans = 0;
//	for (int i = 0; i < n; i++) ans += a[i];
//	return ans;
//}
//int main() {
//	int c = 0;//테스트 케이스 갯수
//	int n = 0;//학생수
//	int score[1002];//점수들
//	int sums = 0;//평균을 내기위한 더하기
//	int high = 0;//평균보다 높은학생수
//	scanf("%d", &c);
//	for (int i = 0; i < c; i++) {
//		scanf("%d", &n);
//			for (int j = 0; j < n; j++) {
//				scanf("%d", &score[j]);
//				sums += score[j];
//		}
//			for (int k = 0; k < n; k++) {
//				if (score[k] > (double)sums / (double)n) {
//					high++;
//				}
//			}
//			printf("%.3f%%\n", (double)high / (double)n * 100.0);
//			high = 0;
//			sums = 0;
//	}
//
//}
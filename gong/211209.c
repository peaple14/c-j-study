#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;
//백트래킹하다 절망. 기초부터 다시

int main() {
	int how = -1;
	int point = 0;
	int sum = 0;
	char arr[81];
	scanf("%d", &how);
	for (int i = 0; i < how; i++) {
		sum = 0;
		point = 1;
		scanf("%s", arr);
		for (int j=0; j <strlen(arr); j++) {
			if (arr[j] == 'O') {
				sum += point;
				point++;
			}
			if (arr[j] == 'X') point = 1;
		}
		printf("%d\n", sum);
	}
}



//int main() {
//	int how = -1;
//	double high = -1;
//	double arr[1001] = { 0, };
//	double sum = 0;
//	scanf("%d", &how);
//	for (int i = 0; i < how; i++) {
//		scanf("%d", &arr[i]);
//		if (arr[i] > high) { high = arr[i]; }
//	}
//	for (int j = 0; j < how; j++) {
//		arr[j] = arr[j] / high * 100;
//	}
//	for (int k = 0; k < how; k++) {
//		sum += arr[k];
//	}
//	printf("%.4f", sum / how);
//}
//int main() {
//	int a[43]={0,};
//	int j = 0;
//	int k = 0;
//	for (int i = 0; i < 10; i++) {
//		scanf("%d", &j);
//		a[j % 42]++;
//	}
//	for (int j = 0; j < 43; j++) {
//		if (a[j] != 0) {
//			k++;
//		}
//	}
//	printf("%d", k);
//}
//int main() {
//    int a, b, c;
//    int arr[10];
//    scanf("%d %d %d", &a, &b, &c);
//    int result = a * b * c;
//
//    int num;
//    while (result > 0) {
//        num = result % 10;
//        arr[num]++;
//        result /= 10;
//    }
//
//    for (int i = 0; i < 10; i++) {
//        printf("%d\n", arr[i]);
//    }
//
//    return 0;
//}
// //int main() {
//	int num[10];
//	int result = -1;
//	int rnum = -1;
//	for (int i = 0; i < 9; i++) {
//		scanf("%d", &num[i]);
//	}
//	for (int j = 0; j < 9; j++) {
//		if (result < num[j]) {
//			result = num[j];
//			rnum = j;
//		}
//	}
//	printf("%d\n%d", result, rnum+1);
//}
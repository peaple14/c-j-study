#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;






//int main() {//10250
//	int how = 0;
//	scanf("%d", &how);
//	int h = 0;//호텔의 층수
//	int w = 0;//각층의 방수
//	int n = 0;//몇번째 손님
//	int a = 0;//방 백의자리
//	int b = 0;//방 일과십의자리
//	for (int i = 0; i < how; i++) {
//		scanf("%d %d %d", &h, &w, &n);
//
//		a = n % h;
//		if (n <= h)a = n;
//		if (n % h == 0)a = h;
//		b = n / h + 1;
//		if (n % h == 0)b = n/h;
//		if (n <= h)b = 1;
//		if (h == 1)b = n / h;
//		printf("%d\n", a * 100 + b);
//	}
//}

//int main() {//백준 2869
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    scanf("%d %d %d", &a, &b, &c);
//    int day;
//
//    if ((c - a) % (a- b) == 0)//(정확히 도착 전날의위치)%(올라가고내려가고) 정확히맞게
//        day = (c - a) / (a - b);
//    else
//        day = (c - a) / (a - b) + 1;//아니라면 나누고 하루추가
//    printf("%d\n", day + 1);
//
//}
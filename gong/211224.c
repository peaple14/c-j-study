#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;






//int main() {//10250
//	int how = 0;
//	scanf("%d", &how);
//	int h = 0;//ȣ���� ����
//	int w = 0;//������ ���
//	int n = 0;//���° �մ�
//	int a = 0;//�� �����ڸ�
//	int b = 0;//�� �ϰ������ڸ�
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

//int main() {//���� 2869
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    scanf("%d %d %d", &a, &b, &c);
//    int day;
//
//    if ((c - a) % (a- b) == 0)//(��Ȯ�� ���� ��������ġ)%(�ö󰡰�������) ��Ȯ���°�
//        day = (c - a) / (a - b);
//    else
//        day = (c - a) / (a - b) + 1;//�ƴ϶�� ������ �Ϸ��߰�
//    printf("%d\n", day + 1);
//
//}
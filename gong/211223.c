#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;

//����1193��
int chest[2];//���ϴ�� ����
int main() {
	long int num = 0;
	scanf("%d", &num);
	long int result;
	find(num);//chest���� ����
	long int a = 0;//������
	long int b = 0;//����
	int king = num - chest[1]+1;//���° ���ΰ� �����ִ°�
	if (num == 1)printf("1/1");
	else if (chest[0] % 2 == 0) {//��ȣ�� ¦���� ������/ū������ ������ġ chest[1]
		a = king;
		b = chest[0]+1 - a;
		printf("%d/%d", a, b);;
	}
	else {//��ȣ�� Ȧ���� ū��/����������
		a = king;
		b = chest[0]+1 - a;
		printf("%d/%d", b, a);;
	}
}


void find(int num) {
	long int k = 1;//�����(��~����Ҷ� ���Ұ�)
	long int pp = 2;//��𼭺��� ������(÷�� 2~3)

	if (num == 1) {  k = 0; }

	while (k) {
		if (pp <= num && pp + k >= num) {
			chest[0] = k + 1;//����ΰ�
			chest[1] = pp;//��𼭺��� ������� ��ȣ�ΰ�
			break;
		}
		k++;
		pp += k;
	}
}

//int main() {
//	long int num = 0;
//	scanf("%d", &num);
//	long int k = 1;//�����
//	long int a = 2;//��𼭺��� ������
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
//int main() {//���� 1712��
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
//int main() {//���� 1316
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;



int main() {//2839
	int a = 0;//ó���־����°�
	int result = 0;//�����
	scanf("%d", &a);
	while (a>=0) {
		if (a % 5 == 0) { result += a / 5; a = 0; break; }
		a -= 3;
		result++;
	}
	
	printf("%d", a == 0 ? result : -1);
}

/*trash
* 
* for (int i = len; i > 0; i--) {//���ϱ�
		r[i + 1] = (a[i + 1] - '0') + (b[i + 1] - '0');
		if (r[i + 1] - '0' >= 10) {
			r[i + 1] = (r[i + 1] - '0') - 10;
			r[i] = (r[i] - '0') + 1;
		}
	}
* 
if (a % 5 == 0) { result = a / 5; a = 0; }
if (a % 3 == 0) { result = a / 3; a = 0; }
for (int i = 0; i < a; i++) {
	a -= 15;
	result++;
	printf("@15:����a��:%d�̰� result��:%d�̴�.\n", a, result);

}
if (a < 0) { result--; a += 15; }
while (a) {
	a -= 3; result++;
	if (a % 5 == 0) { result += result / 3; a = 0; }
	a -=5; result++;
	if (a % 3 == 0) { result += result / 5; a = 0; }
}
//if (a < 0) {
//	a += 15;
//	result--;
//	if (a == 3) { a = 0; result++; }
//	for (int i = 0; i < a; i++) {
//		a -= 5;
//		result++;
//		printf("@5:����a��:%d�̰� result��:%d�̴�.\n", a, result);
//	}
//}
//if (a < 0) {
//	a += 5;
//	result--;
//	for (int i = 0; i < a; i++) {
//		a -= 3;
//		result++;
//		printf("@3:����a��:%d�̰� result��:%d�̴�.\n", a, result);
//	}
//}
*///trash

//int main() {//2775
//	int how = 0;//�
//	int f = 0;//����(��� �̵��Ұ��ΰ�)
//	int h = 0;//��ȣ(������ �̵��Ұ��ΰ�)
//	int a[18][18];//���߹迭 �� ����(��,ȣ��)
//	scanf("%d", &how);
//	for (int i = 0; i < 17; i++) {
//		a[i][0] = 0;
//	}
//	for (int i = 0; i < 17; i++) {
//		a[0][i] = i;
//	}
//	while (how) {
//		scanf("%d", &f);
//		scanf("%d", &h);
//		for (int i = 1; i < f + 1; i++) {
//			if (f == 0)break;
//			for (int j = 1; j < h + 1; j++) {
//				a[i][j] = a[i][j - 1] + a[i - 1][j];
//			}
//		}
//		printf("%d\n", a[f][h]);
//		how--;
//	}
//
//}
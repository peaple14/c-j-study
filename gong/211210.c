#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;
//��Ʈ��ŷ�ϴ� ����. ���ʺ��� �ٽ�

int main() {
	int a = 0;//�Ѽ����� �ƴ�������
	int count = 99;//100�̻�� ī��Ʈ��
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
//	int c = 0;//�׽�Ʈ ���̽� ����
//	int n = 0;//�л���
//	int score[1002];//������
//	int sums = 0;//����� �������� ���ϱ�
//	int high = 0;//��պ��� �����л���
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
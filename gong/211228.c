#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;



int main() {//a>b�� ���� �Է��Ҷ� ������ ��ġ��.
	char a[10004];
	char b[10004];
	int r[10005];
	scanf("%s %s", &a, &b);
	int len = strlen(a) > strlen(b) ? strlen(a) : strlen(b);//�� ������ ����
	int alen = strlen(a);
	int blen = strlen(b);
	if (strlen(a) < strlen(b)) {//�ٸ��߱�� �̵�
		int more = blen - alen;
		for (int i = alen; i > -1; i--) {
			a[i + more + 1] = a[i];
		}
		for (int i = blen; i > -1; i--) {
			b[i + 1] = b[i];
		}
	}
	else if (strlen(a) > strlen(b)) {
		int more = alen - blen;
		for (int i = alen; i > -1; i--) {
			a[i + more + 1] = a[i];
		}
		for (int i = blen; i > -1; i--) {
			b[i + 1] = b[i];
		}
	}
	else {
		for (int i = blen; i > -1; i--) {
			a[i + 1] = a[i];
			b[i + 1] = b[i];
		}

	}//�ٸ��߱�� ��

	for (int i = len - alen; i > -1; i--) {//����� 0���� �ʱ�ȭ -> ��
		a[i] = '0';
	}
	for (int i = len - blen; i > -1; i--) {
		b[i] = '0';
	}
	r[0] = '0';
	int ten = 0;//10�ڸ��� �ȴٸ� 1�̵ȴ�.
	for (int i = len + 1; i > -1; i--) {
		r[i] = a[i] - '0' + b[i] - '0' + ten;
		ten = 0;

		if (r[i] >= 10) {
			r[i] = r[i] - 10;
			ten = 1;
		}
	}


	for (int i = r[0] == 0 ? 1 : 0; i < len + 1; i++) {
		printf("%d", r[i]);
	}
}
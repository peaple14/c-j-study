#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define ���� �Ҷ� ����ġ�� ū���� �迭������ �����ɸ��Ƿ� ���������� �����ϱ�.
//��ū��
//����:�ڽ��� �����ʿ� �����鼭 �ڱ� �ڽź��� ū �� �߿��� ���� ���ʿ� �ִ� ���� ���Ѵ�.
//������ �׼����,���ٸ� -1���


//�ð��ʰ�
int how = 0;//Ƚ��
int a[1000000];//����
int bkup[1000000]; // ���Ұ� �����ϴ°�
int main() {
	scanf_s("%d", &how);
	for (int i = 0; i < how; i++) {
		scanf_s("%d", &a[i]);
	}


	for (int j = 0; j < how; j++) {//���°���� ����
		for (int k = j + 1; k < how; k++) {//�� ���ϴ���
			if (a[j] < a[k]) {
				bkup[j] = a[k];
				break;
			}
			else if (k == how - 1) {
				bkup[j] = -1;
				break;
			}
		}
	}
	for (int p = 0; p < how; p++) {
		if (bkup[p] == 0) {
			printf("-1");
		}
		else{
			printf("%d ", bkup[p]);
		}
	}
}


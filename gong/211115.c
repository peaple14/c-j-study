#include <stdio.h>
#define MAX 30
typedef int element;
int size;
element sorted[MAX];

//////������
//
////�κ����� ������
//void intervalSort(element a[], int begin, int end, int interval) {
//	int i, j;
//	element item;
//	for (i = begin + interval; i <= end; i = i + interval) {//���ݸ�ŭ �����������
//		item = a[i];//�����ۿ� ����ְ�
//		for (j = i - interval; j >= begin && item < a[j]; j = j - interval)
//			a[j + interval] = a[j];
//		a[j + interval] = item;
//	}
//}
//
////�����ĺκ�
//void shellSort(int a[], int size) {
//	int i, t, interval;
//	printf("\n������ ���� : ");
//	for (t = 0; t < size; t++) printf("%d", a[t]); //������� �����ֱ�
//	printf("\n\n <<<<<�� ���� ����>>>>>\n");
//	interval = size / 2;//���� ���ϱ�
//	while (interval >= 1) {//������ 1���ϰ� �ɶ�����
//		for (i = 0; i < interval; i++) intervalSort(a, i, size - 1, interval);//�κ����� ������ ��
//		printf("\n interval = %d >>", interval);
//		for (t = 0; t < size; t++) printf("%d ", a[t]);//�� �ܰ� ��Ȳ �����ֱ�
//		printf("\n");
//		interval = interval / 2; // ����/2 �ؼ� 1���ϱ��� �� while�� �ݺ�
//	}
//}

////��������


void merge(element a[], int m, int middle, int n) {
	int i, j, k, t;
	i = m;
	j = middle + 1;
	k = m;

	while (i <= middle && j <= n) {//�� ĭ�� ���� ����ֱ�
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle)for (t = j; t <= n; t++, k++)sorted[k] = a[t]; //�����ι�° �κ����� sorted�� ����
	else for (t = i; t < middle; t++, k++)sorted[k] = a[t];//���� ù��° �κ����� sorted�� ����

	for (t = m; t <= n; t++)a[t] = sorted[t];//���� �Ϸ�Ȱ� a[t]�� ����
	printf("\n���� ���� >>");
	for (t = 0; t < size; t++)printf("%3d ", a[t]);;
}

void mergeSort(element a[], int m, int n) {
	int middle;
	if (m < n) {
		middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

void main() {
	int t;
	element list[8] = { 69,10,30,2,16,8,31,22 };
	size = 8;
	printf("\n ������ ���� >> ");
	for (t = 0; t < size; t++) printf("%4d", list[t]);
	printf("\n\n<<<<<���� ���� ����>>>>>\n");
	mergeSort(list, 0, size - 1);
	getchar();
}
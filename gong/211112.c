#include <stdio.h>
typedef int element;
int size, i = 0;

//////������
//
////�Ǻ���ġȮ������
//int partition(element a[], int begin, int end) {
//	int pivot, L, R, t;
//	element temp;
//	L = begin;//�� ��ĭ
//	R = end;//�� ��ĭ
//	pivot = (int)((begin + end) / 2.0); //�߰���ġ �Ǻ�����
//
//	printf("\n[%d�ܰ� : pivot = %d ] \n", ++i, a[pivot]);
//	while (L < R) {//����ĭ�� ��ĭ�� ����ġ�� �ʴµ���
//		while ((a[L] < a[pivot]) && (L < R)) L++;//����ĭ�� �ǹ����� �۰� R�� ����ġġ �ʴµ��� L++
//		while ((a[R] >= a[pivot]) && (L < R)) R--;//�����ٰ� ���
//		if (L < R) {//���� R��L���� �� �۴ٸ�
//			temp = a[L];//�� 2ĭ���� �ڸ��ٲٱ�
//			a[L] = a[R];
//			a[R] = temp;
//
//			if (L == pivot)//L�� �ǹ��Ͻ�
//				pivot = R;//R�� �Ǻ���ġ�� ����
//		}
//	}
//	//L=R�� �Ǿ��ٸ� R�� �Ǻ��� �ڸ��� ��ȯ�� ��
//	temp = a[pivot];//�� 2������ ��ġ�ٲٱ�
//	a[pivot] = a[R];
//	a[R] = temp;
//	for (t = 0; t < size; t++) printf(" %d", a[t]);//�������� �����ֱ�
//	printf("\n");
//	return R; //�Ǻ���ġ ����
//}
//
//void quickSort(element a[], int begin, int end) {
//	int p;
//	if (begin < end) {
//		p = partition(a, begin, end);//������ġ����
//		quickSort(a, begin, p - 1);//������ ���� ����,������ ���ȣ��
//		quickSort(a, p + 1, end);
//	}
//}
////�����
//void main() {
//	element list[8] = { 69,10,30,2,16,8,31,22 };
//	size = 8;
//	printf("\n [�ʱ� ����]\n");
//	for (int i = 0; i <= size - 1; i++) printf(" %d", list[i]);
//	printf("\n");
//
//	quickSort(list, 0, size - 1);
//
//	getchar();
//}

////��������

void insertionSort(int a[], int size) {
	int i, j, t, temp;
	for (t = 0; t < size; t++) pirntf("%d ", a[t]);//�����Ȳ �����ֱ�
	printf("\n\n<<<<<<<���� ���� ����>>>>>>>>\n");
	for (i = 1; i < size; i++) {
		temp = a[i]; j = i;
		while ((j > 0) && (a[j - 1] > temp)){//�������� ���ã��
		a[j] = a[j - 1];
		j = j - 1;
}
a[j] = temp;//a[j]�� temp ��ġ ����
printf("\n %d�ܰ� : ", i);
for (t = 0; t < size; t++) printf("%3d", a[t]);//�����Ȳ �����ֱ�
	}
}

void main() {
	int list[8] = { 69,10,30,2,16,8,31,22 };
	size = 8;

	insertionSort(list, size);

	getchar();
}
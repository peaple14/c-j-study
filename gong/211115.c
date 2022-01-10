#include <stdio.h>
#define MAX 30
typedef int element;
int size;
element sorted[MAX];

//////셀정렬
//
////부분집합 셀정렬
//void intervalSort(element a[], int begin, int end, int interval) {
//	int i, j;
//	element item;
//	for (i = begin + interval; i <= end; i = i + interval) {//간격만큼 띄워질때마다
//		item = a[i];//아이템에 집어넣고
//		for (j = i - interval; j >= begin && item < a[j]; j = j - interval)
//			a[j + interval] = a[j];
//		a[j + interval] = item;
//	}
//}
//
////쉘정렬부분
//void shellSort(int a[], int size) {
//	int i, t, interval;
//	printf("\n정렬할 원소 : ");
//	for (t = 0; t < size; t++) printf("%d", a[t]); //현재상태 보여주기
//	printf("\n\n <<<<<셀 정렬 수행>>>>>\n");
//	interval = size / 2;//간격 정하기
//	while (interval >= 1) {//간격이 1이하가 될때까지
//		for (i = 0; i < interval; i++) intervalSort(a, i, size - 1, interval);//부분집합 셀정렬 함
//		printf("\n interval = %d >>", interval);
//		for (t = 0; t < size; t++) printf("%d ", a[t]);//현 단계 상황 보여주기
//		printf("\n");
//		interval = interval / 2; // 간격/2 해서 1이하까지 위 while문 반복
//	}
//}

////병합정렬


void merge(element a[], int m, int middle, int n) {
	int i, j, k, t;
	i = m;
	j = middle + 1;
	k = m;

	while (i <= middle && j <= n) {//각 칸을 비교후 집어넣기
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
	if (i > middle)for (t = j; t <= n; t++, k++)sorted[k] = a[t]; //남은두번째 부분집합 sorted에 저장
	else for (t = i; t < middle; t++, k++)sorted[k] = a[t];//남은 첫번째 부분집합 sorted에 저장

	for (t = m; t <= n; t++)a[t] = sorted[t];//정렬 완료된것 a[t]로 복사
	printf("\n병합 정렬 >>");
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
	printf("\n 정렬할 원소 >> ");
	for (t = 0; t < size; t++) printf("%4d", list[t]);
	printf("\n\n<<<<<병합 정렬 수행>>>>>\n");
	mergeSort(list, 0, size - 1);
	getchar();
}
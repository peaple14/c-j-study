#include <stdio.h>
typedef int element;
int size, i = 0;

//////퀵정렬
//
////피봇위치확정연산
//int partition(element a[], int begin, int end) {
//	int pivot, L, R, t;
//	element temp;
//	L = begin;//맨 앞칸
//	R = end;//맨 뒷칸
//	pivot = (int)((begin + end) / 2.0); //중간위치 피봇설정
//
//	printf("\n[%d단계 : pivot = %d ] \n", ++i, a[pivot]);
//	while (L < R) {//젤앞칸과 뒷칸이 지나치지 않는동안
//		while ((a[L] < a[pivot]) && (L < R)) L++;//젤앞칸이 피벗동안 작고 R을 지나치치 않는동안 L++
//		while ((a[R] >= a[pivot]) && (L < R)) R--;//위의줄과 비슷
//		if (L < R) {//만약 R이L보다 더 작다면
//			temp = a[L];//밑 2칸포함 자리바꾸기
//			a[L] = a[R];
//			a[R] = temp;
//
//			if (L == pivot)//L이 피벗일시
//				pivot = R;//R을 피봇위치로 지정
//		}
//	}
//	//L=R이 되었다면 R과 피봇의 자리를 교환후 끝
//	temp = a[pivot];//밑 2개포함 위치바꾸기
//	a[pivot] = a[R];
//	a[R] = temp;
//	for (t = 0; t < size; t++) printf(" %d", a[t]);//현재정렬 보여주기
//	printf("\n");
//	return R; //피봇위치 리턴
//}
//
//void quickSort(element a[], int begin, int end) {
//	int p;
//	if (begin < end) {
//		p = partition(a, begin, end);//분할위치결정
//		quickSort(a, begin, p - 1);//밑포함 각각 왼쪽,오른쪽 재귀호출
//		quickSort(a, p + 1, end);
//	}
//}
////실험용
//void main() {
//	element list[8] = { 69,10,30,2,16,8,31,22 };
//	size = 8;
//	printf("\n [초기 상태]\n");
//	for (int i = 0; i <= size - 1; i++) printf(" %d", list[i]);
//	printf("\n");
//
//	quickSort(list, 0, size - 1);
//
//	getchar();
//}

////삽입정렬

void insertionSort(int a[], int size) {
	int i, j, t, temp;
	for (t = 0; t < size; t++) pirntf("%d ", a[t]);//현재상황 보여주기
	printf("\n\n<<<<<<<삽입 정렬 수행>>>>>>>>\n");
	for (i = 1; i < size; i++) {
		temp = a[i]; j = i;
		while ((j > 0) && (a[j - 1] > temp)){//끼워넣을 장소찾기
		a[j] = a[j - 1];
		j = j - 1;
}
a[j] = temp;//a[j]에 temp 위치 설정
printf("\n %d단계 : ", i);
for (t = 0; t < size; t++) printf("%3d", a[t]);//현재상황 보여주기
	}
}

void main() {
	int list[8] = { 69,10,30,2,16,8,31,22 };
	size = 8;

	insertionSort(list, size);

	getchar();
}
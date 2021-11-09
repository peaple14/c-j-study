#include <stdio.h>
typedef int element;
int size;

//////선택정렬
//
//void SelectionSort(int a[], int size) {//배열과 사이즈를 집어넣을시
//	int i, j, t, min;
//	element temp;//자리 교체용 보관장소
//	printf("\n 정렬할 원소: ");
//	for (t = 0; t < size; t++) printf(" %d", a[t]);
//	printf("\n\n<<<<<<<선택 정렬 수행 >>>>>>> \n");
//	for (i = 0; i < size - 1; i++) {//배열의 마지막까지
//		min = i;//가장 작은값 저장해두는곳
//		for (j = i + 1; j < size; j++) {
//			if (a[j] < a[min]) min = j;//계속해서 min값이 바뀜을 반복
//		}
//		temp = a[i];//밑2개포함 자리바꾸기
//		a[i] = a[min];
//		a[min] = temp;
//		printf("\n%d단계 : ", i + 1);
//		for (t = 0; t < size; t++) printf("%3d", a[t]);
//	}
//}
//
//
//void main(){
//	element list[8] = { 69,10,30,2,16,8,31,22 };
//size = 8;
//SelectionSort(list, size);
//
//getchar();
//}

////버블정렬

void bubbleSort(element a[], int size) {
	int i, j, t;
	element temp;
	printf("\n정렬할 원소 : ");
	for (t = 0; t < size; t++) printf("%d ", a[t]);
	printf("\n <<<버블 정렬 수행>>>");
	for (i = size - 1; i>0; i--) {
		printf("\n %d단계>>", size - i);
		for (j = 0; j < i;j++){
			if (a[j] > a[j + 1]) {
				temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
			}
			printf("\n\t");
			for (t = 0; t < size; t++)printf("%3d ", a[t]);
		}
	}
}

void main(){
	element list[8] = { 69,10,30,2,16,8,31,22 };
size = 8;
bubbleSort(list, size);

getchar();
}
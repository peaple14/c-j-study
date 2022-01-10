#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct {
	int heap[MAX_ELEMENT]; //���� �ִ밳��
	int heap_size; //���� ����
}heapType;

//�������� ����
heapType* createHeap() {
	heapType* h= (heapType*)malloc(sizeof(heapType));//�޸� �ο�
	h->heap_size = 0;//�������� 0����
	return h;
}
//������ ����
void insertHeap(heapType* h, int item) {
	int i;//������ȣ
	h->heap_size = h->heap_size + 1;//���� �ϳ� �߰�
	i = h->heap_size; //������ȣ�� �ִ밳�� �ο�
	while ((i != 1) && (item > h->heap[i / 2])) {//ó���� �ƴϰ�,�����Ұ��� �θ��庸�� �۰ų�����������
		h->heap[i] = h->heap[i / 2];//������ȣ�� 2�� ����(�׽�Ʈ����)	
		i /= 2;// ���� i=i/2��¶�(�������)
	}
	h->heap[i] = item;//�˸��� ��ҿ� ����
}

//���� ��Ʈ ������ ��ȯ
int deleteHeap(heapType* h) {
	int parent, child;//�θ�,�ڽ�
	int item, temp;//�����Ұ�,���������� ������
	item = h->heap[1];//������ġ1����
	temp = h->heap[h->heap_size];//������������
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {//�ڽĳ�尡 �� �ִ������ ������
		if ((child < h->heap_size) && (h->heap[child]) < h->heap[child + 1])//�ڽĳ�尡 ���� �����������̰�,�����ڽ��� �������ڽĺ��� �������� (���ʰ� �������� ��ū �ڽĳ�� ã��)
			child++;//�ڽĳ�� +1
		if (temp >= h->heap[child])break;//���� ������ã��temp���� �ڽĳ�庸�� ũ�ų� ���ٸ� ����
		else {//temp�� �� �۴ٸ�
			h->heap[parent] = h->heap[child];//�ڽĳ��� �θ��� �ڸ��ٲ�
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;//���� ������ ã������ �װ��� temp�� ����
	return item;//�����Ȱ͹�ȯ
}

//�������� ���
void printHeap(heapType* h) {
	int i;
	printf("Heap : ");
	for (i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
}

//�����
void main() {
	int i, n, item;
	heapType* heap = createHeap();
	insertHeap(heap, 10);
	insertHeap(heap, 45);
	insertHeap(heap, 19);
	insertHeap(heap, 11);
	insertHeap(heap, 96);

	printHeap(heap);

	n = heap->heap_size;//���λ��� 
	for (i = 1; i <= n; i++) {
		item = deleteHeap(heap);
		printf("\n delete : [%d]", item);//�ϳ��� �����Ѱ� ������
	}
	getchar();
}
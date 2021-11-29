#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//_crt_secure_no_warnings;
#define MAX 100001
//211130포함
//scanf_ & scanf 주의
//scanf("%d\n",&item); 에서 \n주의

typedef struct stackNode {
	int data;
	struct stackNode* link;
}stackNode;

stackNode* top;

void push(int item) {
	stackNode* k = (stackNode*)malloc(sizeof(stackNode));
	k->data = item;
	k->link = top;
	top = k;
}

int pop() {
	int item;
	stackNode* k = top;
	if (top == NULL) exit(1);	
	item = k->data;
	top = k->link;
	free(k);
	return item;
}
//1.첨받은것 2.기호 3.1부터 계속증가배열
char sort(int* seq , int how) {
	char sign[100000]; //기호
	int num = 1;//기호넣을장소,1부터 증가할예정,push로 집어넣을예정
	push(num);
	for (int i = 0; i < how; i++) {//몇번째랑 맞는지구분
		printf("%d번째 입니다.\n", i);
		while(1) {//1부터 증가할예정
			if (num == seq[i]) {
				printf("같을때\n");
				if (pop() != i) { printf("NO"); return 0; }
				sign[num] = "-";
				break;
			}
			else if (num < seq[i]) {
				printf("적을때\n");
				num++;
				push(num);
				sign[num] = "+";
			}
			else if (num > seq[i]) {
				printf("클때\n");
				if (pop() != i) { printf("NO"); return 0; }
				num++;
				sign[num] = "-";
				break;
			}
			
		}

	}
	for (int k = 1; k <= how; k++) {
		printf("%d\n", sign[k]);
	}
	
}
int main() {
	int how = 0;
	int seq[MAX];
	scanf("%d", &how);	
	for (int i = 0; i < how; i++) {
		scanf_s("%d", &seq[i]);	
	}
	sort(seq, how);
}



//8
//
//43687521
//
//1.seq[1]가 나올때까지 push 후 4나오면pop과 - 출력
//2.if seq[1] > seq[2] 면pop후 - 출력
//3.seq[2] > seq[3]면 pop 후 - 출력
//아니라면 seq[3]나올때까지 push
//4.seq[4] > seq[5]면 pop 아니라면 seq[5]나올때까지 push 나오면 pop후 - 출력
//5.seq[5] > seq[6]이니 pop후 - 출력
//6.seq[6] > seq[7]이니 pop후 - 출력
//7.seq[7] > seq[8]이니 pop후 - 출력
//
//1.seq[i] > seq[i + 1]일시 pop후 - 출력
//2.seq[i] < seq[i + 1]일시 seq[i + 1]나올때까지 push와 + 출력후 pop과 - 출력
//
//
//	12534
//	1.seq[1]나올때까지 push과 + 출력후 == seq[1]과 이것이 같은지 비교해보고 pop과 배열에 - 저장 ==
//	2.seq[1] < seq[2]이므로 나올대까지 push과 + 출력후 pop출력
//	3.seq[2]<seq[3]이므로 나올때까지 push과 + 출력후 pop과 - 출력
//	4.seq[3]>seq[4]이므로 == seq[4]와 이것이 같은지 비교해보고 pop과 - 출력 == 만약 맞지않을시 NO출력
//
//	마지막으로 배열에 저장된 + 와 - 기호들 순서대로 출력\n필수
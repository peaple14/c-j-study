#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//_crt_secure_no_warnings;
#define MAX 100000
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
//1243
//2314
//12
char sort(int* seq, int how) {
	char sign[MAX * 2]; //기호넣을곳
	//int num = 1;//기호넣을장소,1부터 증가할예정,push로 집어넣을예정
	//push(num);
	//for (int i = 0; i < how; i++) {//몇번째랑 맞는지구분
	//	//printf("%d번째수 입니다. 현재num은 %d입니다.\n", i + 1, num);
	//	while (1) {//1부터 증가할예정
	//		if (num == seq[i]) {
	//			int save = num;//연속적으로 같을경우를 생각
	//			while (1) {
	//				int backup = pop();//확인용
	//				if (save  == (backup = pop())) {
	//					seq[i] = "-";
	//					i++;
	//					continue;
	//				}
	//				else(push(backup));
	//				if (num > how) i += how;
	//				break;
	//			}
	//			num++;
	//			sign[num] = "-";
	//			if (num > how) i += how;
	//			break;
	//		}
	//		else if (num < seq[i]) {
	//			num++;
	//			push(num);
	//			sign[num] = "+";
	//			if (num > how) i += how;
	//		}
	//		else if (num > seq[i]) {
	//			printf("NO"); return 0;
	//		}
	//	}
	//}
	//printf("num은 %d입니다!!!!끝이다!", num);
	//printf("%s", sign[1]);
	//for (int k = 1; k < num; k++) {
	//	
	//	/*printf("%s\n", sign[k]);*/
	//}'
	int num = 1;//증가하는숫자
	push(num);
	int point = 0; // sign에 집어넣을 좌표
	for (int i = 0; i < how; i++) {
		if (seq[i] == num) {
			pop();
			sign[point] = "-";
			num++;
			point++;
			printf("이거안보이나\n");
		}
		else if (seq[i] < num) {
			push(num);
			num++;
			sign[point] = "+";
			point++;
		}
	}
	printf("반복이다\n");
	printf("%s", sign[0]);
	for (int k = 0; k < num; k++) {
		printf("%s\n", sign[k]);
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



//43687521
//1.seq[1]가 나올때까지 push 후 4나오면pop과 - 저장
//2.if seq[1] > seq[2] 면pop후 - 저장
//3.seq[2] > seq[3]면 pop 후 - 저장
//아니라면 seq[3]나올때까지 push와 + 저장
//4.seq[4] > seq[5]면 pop 아니라면 seq[5]나올때까지 push 나오면 pop후 - 저장
//5.seq[5] > seq[6]이니 pop후 - 저장
//6.seq[6] > seq[7]이니 pop후 - 저장
//7.seq[7] > seq[8]이니 pop후 - 저장
//======
//34
//12534
//1.seq[1]나올때까지 push과 + 출력후 == seq[1]과 이것이 같은지 비교해보고 pop과 배열에 - 저장 ==
//2.seq[1] < seq[2]이므로 나올대까지 push과 + 저장후 pop과 - 저장
//	3.seq[2]<seq[3]이므로 나올때까지 push과 + 저장후 pop과 - 저장
//	4.seq[3]>seq[4]이므로 == seq[4]와 이것이 같은지 비교해보고 pop과 - 저장 == 만약 맞지않을시 NO출력
//
//	마지막으로 배열에 저장된 + 와 - 기호들 순서대로 출력\n필수
//	//////////////////////////////////////////////////////////////////////////////////////////////////////
//	123
//	4 3 6 8 7 5 2 1
//	0.//num = 1
//	1.num < seq[1]이므로 num++후 push후 + 저장 //num = 2
//	2.num < seq[1]이므로 num++후 push후 + 저장 //num = 3
//	3.num < seq[1]이므로 num++후 push후 + 저장 //num = 4
//	4.num = seq[1]이므로 pop후 - 저장 // num = 4
//	5.num = seq[2]이므로 pop후 - 저장 // num = 4(그 전의것 꺼내서 확인후 다시 집어넣기)
//	6. num<seq[3]이므로 num++후 push후 + 저장 //num = 5
//	///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	0.일단 지역변수 num 으로 1씩 계속늘어남.배열은 2종류 1.처음저장받은것(seq) 2.기호(정적 크게만들기)
//	스택은 한종류.1부터 계속 증가하는스택(push와 pop을 할수있는 스택)
//
//
//	1.seq[i]>seq[i + 1]일시 pop후 - 배열에 저장후 i++
//	2.seq[i] < seq[i + 1]일시 seq[i + 1]나올때까지 push와 + 배열에 저장후 pop한후 seq[i + 1]과 pop를 비교하고 맞으면 - 저장
//	틀릴시 return 1 하고 NO출력.
//
//
//	1.맨위에 처음받은것
//	2.f or 계속 증가(how값 까지만 증가해야함)
//	3.기호넣어주는 지역변수 k(몇번째 배열에 넣을것인지 저장후++)(while 문일시 break 끝)
//
//	12
//	321
//	0.//num = 1
//	1.같으므로 pop후 - 저장 // num = 1
//	2.num < seq[2]이므로 num++ 후 push 하고 + 저장
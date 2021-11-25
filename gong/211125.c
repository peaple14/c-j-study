#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//_crt_secure_no_warnings;
//4949번 Yes->yes 오타
//공백포함 읽기 scanf("%[^\n]s", exp);

typedef struct stackNode {
	int data;
	struct stackNode* link;

}stackNode;

stackNode* top;

void push(int item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

char pop() {
	char show;
	stackNode* k = top;
	if (top == NULL) exit(1);
	show = k->data;
	top = k->link;
	free(k);
	return show;
}

int isempty() {
	return(top == NULL);
}

int scanrow(char* item) {
	char test1, test2;
	top = NULL;
		for (int i = 0; i <= strlen(item); i++) {
			test1 = item[i];
			switch (test1) {
			case '(':
			case '[':
				push(test1); break;
			case ')':
			case ']':
				if (top == NULL) return 0;
				else {
					test2 = pop();
					if ((test1 == ')' && test2 != '(') ||
						(test1 == ']' && test2 != '['))
						return 0;
					else break;
				}

			}
		
		}
	
	if (top == NULL) return 1;
	else return 0;
}

int main() {
	char exp[101];
	while(1){
		scanf("%[^\n]s", exp);
		if (exp[0] == '.') break;
		printf("%s\n", scanrow(exp) == 1 ? "yes" : "no");
		getchar();
	}
	return 0;
}


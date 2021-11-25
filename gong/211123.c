#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//_crt_secure_no_warnings;
typedef struct stack{
	int sign;
	struct stack* link;
}stack;

stack* top;

int isempty() {
	return (top==NULL);
}

void push(int item) {
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->sign = item;
	temp->link = top;
	top = temp;
}

char pop() {
	stack* topp = top;
	char item;
	if (top == NULL) exit(1);
	else {
		item = topp->sign;
		top = topp->link;
		free(topp);
		return item;
	}
}

int eval(char* exp) {
	char test;
	char test2;
	top = NULL;
	for (int i = 0; i <= strlen(exp); i++) {
		
		test = exp[i];
		switch (test) 
		{
		case '(':
			push(test);
			break;
		case ')':
			if (top == NULL) return 0;
			else
			{
			test2 = pop();
			if ((test2 == '(' && test != ')')) return 0;
			else break;
			}
		}
	}
	if (top == NULL) return 1;
	else return 0;
}



void main() {
	int result;
	int a;
	char express[51];
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%s", &express);
		result = eval(express);
		if (result == 1)  printf("YES\n");
		else printf("NO\n");
	}
}




#include<stdio.h>
#include<stdlib.h>
//_CRT_SECURE_NO_WARNINGS;
int stack[100001];
int topp = -1;
int curs = 0;


void push(int how) {
	while (how) {
		scanf("%d", &stack[++topp]);
		if (stack[topp] == 0) {
		topp--;
		topp--;
		}
		how--;
	}
}
void sum() {
	int k = 0;
	for(int i = 0; i <= topp; i++){
		k += stack[curs++];
	}
	printf("%d",k);
}

int main() {
	int how;
	scanf("%d", &how);
	push(how);
	sum();
}


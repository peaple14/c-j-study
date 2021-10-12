#include <stdio.h>
#define CRT_SECURE_NO_WARNING

int j, i, a, b;

int prm(int a, int b)
{
	for (int i;  i < b;  b++) {		
		for (int j; j < a; a++) {
			printf("*");
		}
		printf("\n");

	}
}

int main() {
	int a, b;
	printf("길이는");
	scanf_s("%d" ,& a);
	printf("높이는");
	scanf_s("%d", &b);

	prm(a, b);

	return 0;
}

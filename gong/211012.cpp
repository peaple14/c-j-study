#include <stdio.h>
#define CRT_SECURE_NO_WARNING

int j, i, a, b;

int prm(int a, int b)
{
	for (int i=0;  i < b;  b++) {		
		for (int j=0; j < a; a++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

int main() {
	int a, b;
	printf("길이는");
	scanf_s("%d" ,& a);
	printf("높이는");
	scanf_s("%d", &b);
	a = 10;
	b = 5;
	prm(a, b);

	return 0;
}

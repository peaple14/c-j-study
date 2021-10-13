#include <stdio.h>
#define CRT_SECURE_NO_WARNING



int prm(int a, int b)
{
	for (int i=0;  i < b;  i++) {		
		for (int j=0; j < a; j++) {
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
	
	prm(a, b);

	return 0;
}

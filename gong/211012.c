#include <stdio.h>
#define CRT_SECURE_NO_WARNING

// 빗금표시는 영역선택후 컨트롤K누른다음 컨트롤U하면 사라짐
// 반대로 빗금 치는것은 컨트롤K누른다음 컨트롤c하면 생김


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

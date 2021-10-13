#include <stdio.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS
//void main()
//{
//	int a = 4;
//	int b = 6;
//	int p = 0;
//	int sta[4][6];
//	for (int i = 0; i <= 4; i++)
//	{
//		for (int j = 0; j <= 6; j++) {
//			sta[i][j] = p;
//			p += 1;
//			printf("sta[%d][%d]=%d \n", i, j, sta[i][j]);
//		}
//	}
//	
//}
//==========
//void main()
//{
//	int a = 0;
//	int* b = &a;
//	*b = 10;
//	printf("%d\n",&a);
//	printf("%d\n",b);
//	printf("%d",&b);
//	
//}
//=========
struct employee {
	char name[10];
	int age;
	int pay;

};
void main() {
	struct employee Aee;
	struct employee * a = &Aee;
	strcpy(a->name, "길동");
	a->age = 30;
	a->pay = 2021;

	printf("%s은 %d살이고 %d의 월급을받는다.", a->name, a->age, a->pay);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;
//백트래킹하다 절망. 기초부터 다시

//int main() {
//	char word[101];
//	scanf("%s", &word);
//	int wlen = strlen(word);
//	char exp[27] = { "abcdefghijklmnopqrstuvwxyz" };
//	int elen = strlen(exp);
//	for (int i = 0; i < elen; i++) {//a,b,c,d,e순서
//		for (int j = 0; j < wlen; j++) {//집어넣은거 순서 대충 a=몇번째,b=몇번째로 할 예정
//			if (exp[i]==word[j]) {
//				printf("%d ", j);
//				break;
//			}
//			else if(j==wlen-1) {
//				printf("-1 ");
//			}
//			
//		}
//	}
//}


//int main(void) {
//    int count, sum = 0;
//    scanf("%d", &count);
//    char num[101];
//    scanf("%s", num);
//    for (int i = 0; i < count; i++) {
//        sum += num[i] - '0';
//    }
//    printf("%d", sum);
//}
//int main() {
//	char a;
//	int b = 0;
//	scanf("%c", &a);
//	b = a;
//	printf("%d", b);
//}
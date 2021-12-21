#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//;_CRT_SECURE_NO_WARNINGS;

int main() {
	char text[101];
	scanf("%s", &text);
	int count = 0;
	for (int i = 0; i<strlen(text); i++) {
		if (text[i] == 'c' && text[i + 1] == '=')
		{
			count++;
			i++;
		}
		else if (text[i] == 'c' && text[i + 1] == '-')
		{
			count++;
			i++;
		}
		else if (text[i] == 'd' && text[i + 1] == 'z' && text[i + 2] == '=')
		{
			count++;
			i++;
			i++;
		}
		else if (text[i] == 'd' && text[i + 1] == '-')
		{
			count++;
			i++;
		}
		else if (text[i] == 'l' && text[i + 1] == 'j')
		{
			count++;
			i++;
		}
		else if (text[i] == 'n' && text[i + 1] == 'j')
		{
			count++;
			i++;
		}
		else if (text[i] == 's' && text[i + 1] == '=')
		{
			count++;
			i++;
		}
		else if (text[i] == 'z' && text[i + 1] == '=')
		{
			count++;
			i++;
		}
		else if (text[i] != ' ')
			count++;
	}
	printf("%d", count);
}


//int main() {
//	char a[15] = { 0, };
//	int num = 0;
//	int cnt = 0;
//	scanf("%s", &a);
//	for (int i = 0; i < 16; i++) {
//		if (a[i] == 0) {
//			break;
//		}
//		if (a[i] == 'A' || a[i] == 'B' || a[i] == 'C') {
//			cnt += 3;
//		}
//		else if (a[i] == 'D' || a[i] == 'E' || a[i] == 'F') {
//			cnt += 4;
//		}
//		else if (a[i] == 'G' || a[i] == 'H' || a[i] == 'I') {
//			cnt += 5;
//		}
//		else if (a[i] == 'J' || a[i] == 'K' || a[i] == 'L') {
//			cnt += 6;
//		}
//		else if (a[i] == 'M' || a[i] == 'N' || a[i] == 'O') {
//			cnt += 7;
//		}
//		else if (a[i] == 'P' || a[i] == 'Q' || a[i] == 'R' || a[i] == 'S') {
//			cnt += 8;
//		}
//		else if (a[i] == 'T' || a[i] == 'U' || a[i] == 'V') {
//			cnt += 9;
//		}
//		else if (a[i] == 'W' || a[i] == 'X' || a[i] == 'Y' || a[i] == 'Z') {
//			cnt += 10;
//		}
//	}
//	printf("%d", cnt);
//}
//
//
//int main() {
//	char text[8];
//	scanf("%[^\n]", &text);
//	int rtext[8];
//	for (int i = 0; i < strlen(text); i++) {
//		rtext[i] = text[i] - 48;
//	}
//	int a = rtext[2] * 100 + rtext[1] * 10+ rtext[0];
//	int b= rtext[6] * 100 + rtext[5] * 10 + rtext[4];
//	printf("%d", a > b ? a : b);
//}
	//char text[1000001];
	//int main() {
	//	scanf("%[^\n]", &text);
	//	int count = 0;
	//	int tlen = strlen(text);
	//	if (text[0] == ' ')
	//		count--;
	//	if (text[tlen-1] == ' ')
	//		count--;
	//	for (int i = 0; i < tlen; i++) {
	//		if (text[i] == ' ')
	//			count++;
	//	}
	//	if (count < 0) {
	//		printf("0");
	//	}
	//	else {
	//	printf("%d", count + 1);
	//	}
	//}
//char text[10000005];
//int main() {
//	char exp[27] = { "ABCDEFGHIJKLNMOPQRSTUVWXYZ" };
//	int result[27];
//	int high = -1;//마지막 조사용
//	int code = 0;//마지막 좌표용
//	scanf("%s", &text);
//	int tlen = strlen(text);
//	int elen = strlen(exp);
//	for (int i = 0; i < tlen; i++)	//대문자로			
//	{
//		if (text[i] >= 97)
//			text[i] -= 32;
//	}
//	for (int o = 0; o < elen; o++) {
//		result[o] = 0;
//	}
//	for (int i = 0; i < tlen; i++) {
//		for (int j = 0; j < elen; j++) {
//			if (text[i] == exp[j]) {
//				result[j]++;
//				break;
//			}
//		}
//	}
//	for (int k = 0; k < elen; k++) {
//		if (high < result[k]) {
//			high = result[k];
//			code = k;
//		}	
//	}
//	for (int p = 0; p < elen; p++) {
//		if (high == result[p] && p!=code)
//			code = -10;
//	}
//
//	if (code == -10) {
//		printf("?");
//	}
//	else {
//		printf("%c", exp[code]);
//	}
//}
//int main() {
//	int how = 0;//첫번째 횟수
//	int how2 = 0;//2번째줄부터 그것의횟수
//	char text[21];//문자 넣을곳
//	scanf("%d", &how);
//	for (int i = 0; i < how; i++) {
//		scanf("%d", &how2);
//		scanf("%s", &text);
//		int tlen = strlen(text);
//		for (int j = 0; j < tlen; j++) {
//			for (int k = 0; k < how2; k++) {
//				printf("%c", text[j]);
//			}	
//		}
//		printf("\n");
//	}
//}
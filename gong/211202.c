#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define 으로 할때 지나치게 큰수로 배열생성시 오류걸리므로 전역변수로 생성하기.
//오큰수
//정의:자신의 오른쪽에 있으면서 자기 자신보다 큰 수 중에서 가장 왼쪽에 있는 수를 말한다.
//있으면 그수출력,없다면 -1출력


//시간초과
int how = 0;//횟수
int a[1000000];//갯수
int bkup[1000000]; // 비교할것 저장하는것
int main() {
	scanf_s("%d", &how);
	for (int i = 0; i < how; i++) {
		scanf_s("%d", &a[i]);
	}


	for (int j = 0; j < how; j++) {//몇번째수와 비교중
		for (int k = j + 1; k < how; k++) {//비교 당하는중
			if (a[j] < a[k]) {
				bkup[j] = a[k];
				break;
			}
			else if (k == how - 1) {
				bkup[j] = -1;
				break;
			}
		}
	}
	for (int p = 0; p < how; p++) {
		if (bkup[p] == 0) {
			printf("-1");
		}
		else{
			printf("%d ", bkup[p]);
		}
	}
}


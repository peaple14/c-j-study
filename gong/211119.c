#include<stdio.h>
#include<stdlib.h>

int stack[10001];
int topp = -1;

void empty() {
	if (topp < 0) 
		printf("1\n");
	else
		printf("0\n");
	}

void pop()
{
	if (topp < 0)
		return printf("-1\n");
	int a = stack[topp--];
	printf("%d\n", a);
	
}
void size() {
	int k = topp + 1;
	printf("%d\n", k );
}

void top() {
	if (topp == -1) {
		printf("-1\n");
	}
	else{
		printf("%d\n", stack[topp]);
	}
}

void push(k) {
	stack[++topp] = k;	
}

int main(void)
{
	int many, i;
	scanf("%d", &many);
	char what[10];
	while(many)
	{
		scanf("%s", what);
		if (!strcmp(what, "push"))
		{
			int x;
			scanf("%d", &x);
			push(x);
		}
		else if (!strcmp(what, "top"))
			top();
		else if (!strcmp(what, "size"))
			size();
		else if (!strcmp(what, "empty"))
			empty();
		else if (!strcmp(what, "pop"))
			pop();
		many--;
	}
	return 0;
}

//int main() {
//	int a=0;
//	int max = -1000000;
//	int min = 1000000;
//
//	scanf("%d", &a);
//	int b[1000000];
//	for (int i = 0; i < a; i++) {
//		scanf("%d ", &b[i]);
//	}
//	for (int j = 0; j < a; j++) {
//		if (max < b[j]) 
//			max = b[j];	
//		if (min > b[j]) 
//			min = b[j];
//	}
//	printf("%d %d", min, max);
//}


//int main() {
//	int a;
//	scanf("%d", &a);
//	if (a >= 90 && a<=100) {
//		printf("A");
//	}
//	else if (a >= 80 && a < 90) {
//		printf("B");
//	}
//	else if (a >= 70 && a < 80) {
//		printf("C");
//	}
//	else if (a >= 60 && a < 70) {
//		printf("D");
//	}
//	else
//		printf("F");
//
//}


//int main() {
//	int a, b;
//	scanf(" %d %d", &a, &b);
//	if (a > b) {
//		printf(">");
//	}
//	else if (a < b) {
//		printf("<");
//	}
//	else {
//		printf("==");
//	}
//}




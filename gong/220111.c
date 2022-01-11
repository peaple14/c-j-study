#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//_CRT_SECURE_NO_WARNINGS;
int card[1000005];
int main() {
	int count = 0;
	int front = 1;
	int last = 1;
	scanf("%d", &count);
	last = count;
	for (int n = 1; n <= count; n++) {
		card[n] = n;
	}
	while (count>1) {
		front++;
		if (front == last) break;
		last++;
		card[last] = card[front];
		front++;
		count --;
	}
	printf("%d", card[last]);
	return 0;
}

//int queue[2000002]; //18258
//int first = 0;
//int last = 0;
//void push(int n) {
//	queue[last] = n;
//	last++;
//}
//
//void pop() {
//	if (first == last)
//		printf("-1\n");
//	else {
//	printf("%d\n", queue[first]);
//	first++;
//	}
//}
//
//void size() {
//	printf("%d\n", last - first);
//}
//void empty() {
//	printf("%d\n", first == last ? 1 : 0);
//}
//void front() {
//	printf("%d\n", first == last? -1: queue[first]);
//}
//void back() {
//	printf("%d\n", first == last? -1: queue[last-1]);
//}
//
//int main(void)
//{
//	int many, i;
//	scanf("%d", &many);
//	char what[10];
//	while (many)
//	{
//		scanf("%s", what);
//		if (!strcmp(what, "push"))
//		{
//			int x;
//			scanf("%d", &x);
//			push(x);
//		}
//		else if (!strcmp(what, "pop"))
//			pop();
//		else if (!strcmp(what, "size"))
//			size();
//		else if (!strcmp(what, "empty"))
//			empty();
//		else if (!strcmp(what, "front"))
//			front();
//		else if (!strcmp(what, "back"))
//			back();
//		many--;
//	}
//}

//int fact(int n) { //10872
//	if (n > 1)
//		return n * fact(n);
//	else
//		return 1;
//
//}
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fact(n));
//	return 0;
//}




#include <stdio.h>
#include <stdbool.h>

#define MAXN 1000010

int maxS[MAXN], maxs, maxe;
int minS[MAXN], mins, mine;
int a[MAXN];

int N, M, C;

void push(int x){
	for (; maxs < maxe && maxS[maxe-1] < x; maxe--);
	maxS[maxe++] = x;
	for (; mins < mine && minS[mine-1] > x; mine--);
	minS[mine++] = x;
}

void pop(int x){
	if (maxS[maxs] == x) maxs++;
	if (minS[mins] == x) mins++;
}

int main(void){
	bool didSomething = false;
	int i;

	scanf("%d %d %d", &N, &M, &C);

	if (M > N) goto ded;

	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < M-1; i++)
		push(a[i]);

	for (; i < N; i++){
		push(a[i]);
		if (i-M >= 0)
			pop(a[i-M]);
		if (maxS[maxs] - minS[mins] <= C){
			printf("%d\n", i-M+2);
			didSomething = true;
		}
	}

ded:
	if (!didSomething)
		printf("NONE\n");

	return 0;
}

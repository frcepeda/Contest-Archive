#include <stdio.h>

#define MAXN 1010

int N;
int nodes[MAXN];

void inRange(int a, int b){
	int i;
	for (i = 0; i < N; i++){
		if (a <= nodes[i] && nodes[i] <= b){
			printf(" %d", nodes[i]);
			inRange(a, nodes[i] - 1);
			inRange(nodes[i] + 1, b);
			return;
		}
	}
}

int main(void) {
	int i;
	scanf("%d", &N);
	
	for (i = N-1; i >= 0; i--)
		scanf("%d", &nodes[i]);
	
	printf("%d", nodes[0]);
	inRange(1, nodes[0]-1);
	inRange(nodes[0]+1, N);
	putchar('\n');
	
	return 0;
}

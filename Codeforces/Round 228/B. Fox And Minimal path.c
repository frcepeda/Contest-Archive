#include <stdio.h>
#include <stdbool.h>

#define MAXN 1010

int N = 40, K;
bool adj[MAXN][MAXN];

void join(int a, int b){
	adj[a][b] = adj[b][a] = true;
}

void constructGraph(){
	int i, j, a, b;

	join(3, ++N);

	for (j = 0; j < 30; j++, N++)
		join(N, N+1);

	join(N, 2);
	a = b = 2;

	for (i = 1; i < 30; i++){
		join(3+i, ++N);

		for (j = i; j < 30; j++, N++)
			join(N, N+1);

		join(N, N+1);
		join(N, N+2);

		join(N+1, a);
		join(N+1, b);
		join(N+2, a);
		join(N+2, b);

		a = N+1;
		b = N+2;
		N += 2;
	}
}

int main(void){
	int i, j;

	scanf("%d", &K);

	constructGraph();

	for (i = 0; i < 30; i++)
		if (K & (1<<i))
			join(1, i+3);

	printf("%d\n", N);
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			printf("%c%s", adj[i][j] ? 'Y' : 'N', j < N ? "" : "\n");

	return 0;
}

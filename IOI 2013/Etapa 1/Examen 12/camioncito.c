#include <stdio.h>
#include <stdbool.h>

#define MAXE 1010
#define MAXN 15
#define INFINITY (1<<30)

unsigned int path[MAXE][MAXE];
int N, C, E, I, F;

unsigned int answer = INFINITY;

int required[MAXN];
int willGo[MAXN];
bool used[MAXN];

unsigned int min(unsigned int a, unsigned int b){
	return a < b ? a : b;
}

void tryPaths(int idx){
	if (idx > N){
		unsigned int this = 0;
		int i;

		for (i = 1; i <= N+1; i++)
			this += path[willGo[i-1]][willGo[i]];

		if (this < answer)
			answer = this;
	} else {
		int i;
		for (i = 1; i <= N; i++){
			if (!used[i]){
				used[i] = true;
				willGo[i] = required[idx];
				tryPaths(idx+1);
				used[i] = false;
			}
		}
	}
}

int main(void){
	int i, j, k;
	
	scanf("%d %d %d %d %d", &N, &C, &E, &I, &F);

	for (i = 1; i <= E; i++)
		for (j = 1; j <= E; j++)
			if (i != j)
				path[i][j] = INFINITY;

	for (i = 0; i < C; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (c < path[a][b])
			path[a][b] = path[b][a] = c;
	}

	for (i = 1; i <= N; i++)
		scanf("%d", &required[i]);

	for (k = 1; k <= E; k++)
		for (i = 1; i <= E; i++)
			for (j = 1; j <= E; j++)
				path[i][j] = min(path[i][j], path[i][k] + path[k][j]);

	willGo[0] = I; willGo[N+1] = F;
	tryPaths(1);

	printf("%d\n", answer);

	return 0;
}

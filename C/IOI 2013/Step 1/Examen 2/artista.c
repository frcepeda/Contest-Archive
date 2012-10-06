#include <stdio.h>

#define MAXN 205
#define MAXK 1010

short next[MAXN][MAXN];
short remaining[MAXN][MAXN];
char stack[MAXN][MAXN][MAXK];

int N, M, K, G, C;

int main(void){
	int i, j;

	scanf("%d %d", &M, &N);
	scanf("%d %d", &G, &C);

	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			remaining[i][j] = G;
		}
	}

	scanf("%d", &K);

	while (K--){
		int width, height, starti, startj, color;
		scanf("%d %d %d %d %d", &color, &width, &height, &startj, &starti);

		for (i = starti; i < starti + height && i <= N; i++){
			for (j = startj; j < startj + width && j <= M; j++){
				if (color != -1){
					stack[i][j][next[i][j]++] = color;
				} else {
					if (next[i][j])
						next[i][j]--;
					else if (remaining[i][j])
						remaining[i][j]--;
				}
			}
		}
	}

	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			printf("%d ", next[i][j] ? (int)stack[i][j][next[i][j]-1] : remaining[i][j] ? C : -1);
		}
		printf("\n");
	}

	return 0;
}


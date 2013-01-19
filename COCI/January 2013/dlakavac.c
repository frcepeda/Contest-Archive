#include <stdio.h>
#include <stdbool.h>

#define MAXN 1500

bool infected[2][MAXN];
int start[MAXN];

int N, M, K;

int main(void){
	int i, j, k;

	scanf("%d %d %d", &K, &M, &N);

	for (i = 0; i < N; i++){
		scanf("%d", &start[i]);
		infected[1][start[i]] = infected[0][start[i]] = true;
	}

	for (k = 1; k < K; k++){
		for (i = 0; i < M; i++)
			infected[(k+1)%2][i] = false;

		for (i = 0; i < N; i++){
			for (j = 0; j < M; j++){
				if (infected[k%2][j]){
					infected[(k+1)%2][(start[i]*j)%M] = true;
				}
			}
		}
	}

	for (i = 0; i < M; i++)
		if (infected[K%2][i])
			printf("%d ", i);
	printf("\n");

	return 0;
}

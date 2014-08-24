#include <stdio.h>
#include <stdbool.h>

#define MAXN 20

int N, M, K, kM, kN;
int map[MAXN][MAXN], key[MAXN][MAXN];

bool check(int a, int b){
	int i, j;
	for (i = 0; i < kN; i++)
		for (j = 0; j < kM; j++)
			if (map[a+i][b+j] != key[i][j])
				return false;
	return true;
}

int main(void){
	int i, j, k;
	scanf("%d %d %d", &N, &M, &K);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	for (k = 0; k < K; k++){
		scanf("%d %d", &kN, &kM);
		for (i = 0; i < kN; i++)
			for (j = 0; j < kM; j++)
				scanf("%d", &key[i][j]);

		for (i = 0; i < N - kN + 1; i++)
			for (j = 0; j < M - kM + 1; j++)
				if (check(i,j))
					goto ok;

	}

ok:
	if (k < K)
		printf("%d\n%d %d\n", k+1, i+1, j+1);
	else
		printf("-1\n");

	return 0;
}

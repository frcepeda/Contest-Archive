#include <stdio.h>
#include <stdbool.h>

#define MAXN 100

int garden[MAXN][MAXN];
int N, M, T;
int maxRow[MAXN], maxCol[MAXN];

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int t;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int i, j;
		bool possible = true;

		scanf("%d %d", &N, &M);

		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				scanf("%d", &garden[i][j]);

		for (i = 0; i < N; i++)
			for (maxRow[i] = 0, j = 0; j < M; j++)
				maxRow[i] = max(maxRow[i], garden[i][j]);

		for (j = 0; j < M; j++)
			for (maxCol[j] = 0, i = 0; i < N; i++)
				maxCol[j] = max(maxCol[j], garden[i][j]);

		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				if (garden[i][j] < min(maxRow[i], maxCol[j]))
					possible = false;

		printf("Case #%d: %s\n", t, possible ? "YES" : "NO");
	}

	return 0;
}

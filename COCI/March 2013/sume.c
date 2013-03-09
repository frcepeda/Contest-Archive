#include <stdio.h>

#define MAXN 1010

int S[MAXN][MAXN];
int A[MAXN];
int N;

int main(void){
	int i, j;

	scanf("%d", &N);

	if (N == 2){
		printf("1 1\n");
		return 0;
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &S[i][j]);

	A[0] = (S[0][1] - S[1][2] + S[0][2]) / 2;

	for (i = 1; i < N; i++)
		A[i] = S[i-1][i] - A[i-1];

	for (i = 0; i < N; i++)
		printf("%d%c", A[i], i < N-1 ? ' ' : '\n');

	return 0;
}

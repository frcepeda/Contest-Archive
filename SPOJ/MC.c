#include <stdio.h>
#include <strings.h>

#define MAXN 1010

int dp[MAXN][MAXN];
char S[MAXN], T[MAXN];
int N, M;

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int i, j;

	for (i = 1; i < MAXN; i++){
		dp[i][0] = i * 15;
		dp[0][i] = i * 30;
	}

	while (scanf("%s %s", S+1, T+1) == 2){
		N = strlen(S+1);
		M = strlen(T+1);

		for (i = 1; i <= N; i++){
			for (j = 1; j <= M; j++){
				if (S[i] == T[j])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min(dp[i-1][j] + 15, dp[i][j-1] + 30);
			}
		}

		printf("%d\n", dp[N][M]);
	}

	return 0;
}

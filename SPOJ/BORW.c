#include <stdio.h>

#define MAXN 210

int dp[MAXN][MAXN][MAXN];
int sequence[MAXN];

int N;

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int i, lastUp, lastDown;

	while (scanf("%d", &N), N != -1){
		for (i = 1; i <= N; i++)
			scanf("%d", &sequence[i]);

		for (i = 1; i <= N; i++){
			for (lastUp = i+1; lastUp <= N+1; lastUp++){
				for (lastDown = i+1; lastDown <= N+1; lastDown++){
					dp[i][lastUp][lastDown] = dp[i-1][lastUp][lastDown] + 1;

					if (lastDown > N || sequence[i] < sequence[lastDown])
						dp[i][lastUp][lastDown] = min(dp[i][lastUp][lastDown], dp[i-1][lastUp][i]);

					if (lastUp > N || sequence[i] > sequence[lastUp])
						dp[i][lastUp][lastDown] = min(dp[i][lastUp][lastDown], dp[i-1][i][lastDown]);
				}
			}
		}

		printf("%d\n", dp[N][N+1][N+1]);
	}

	return 0;
}

#include <stdio.h>

#define MAXN 11
#define MAXCOUNT 51

int chooseHalf[] = {1, 0, 2, 0, 6, 0, 20, 0, 70, 0, 252};
int chooseThree[] = {1, 0, 0, 6, 0, 0, 90, 0, 0, 1680, 0};

unsigned long long int dp[MAXN][MAXCOUNT][MAXCOUNT][MAXCOUNT];
int N, R, V, A;

int main(void){
	int i, r, v, a;

	scanf("%d %d %d %d", &N, &R, &V, &A);

	for (r = 0; r <= R; r++)
		for (v = 0; v <= V; v++)
			for (a = 0; a <= A; a++)
				dp[0][r][v][a] = 1;

	for (i = 1; i <= N; i++){
		for (r = 0; r <= R; r++){
			for (v = 0; v <= V; v++){
				for (a = 0; a <= A; a++){
					if (r >= i)
						dp[i][r][v][a] += dp[i-1][r-i][v][a];
					if (v >= i)
						dp[i][r][v][a] += dp[i-1][r][v-i][a];
					if (a >= i)
						dp[i][r][v][a] += dp[i-1][r][v][a-i];

					if (i % 2 == 0){
						if (r >= i/2 && v >= i/2)
							dp[i][r][v][a] += dp[i-1][r-i/2][v-i/2][a] * chooseHalf[i];
						if (v >= i/2 && a >= i/2)
							dp[i][r][v][a] += dp[i-1][r][v-i/2][a-i/2] * chooseHalf[i];
						if (r >= i/2 && a >= i/2)
							dp[i][r][v][a] += dp[i-1][r-i/2][v][a-i/2] * chooseHalf[i];
					}

					if (i % 3 == 0 && r >= i/3 && v >= i/3 && a >= i/3)
						dp[i][r][v][a] += dp[i-1][r-i/3][v-i/3][a-i/3] * chooseThree[i];
				}
			}
		}
	}

	printf("%llu\n", dp[N][R][V][A]);

	return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define MAXN 500
#define MAXVAL 500000

int sequence[MAXN];
bool dp[2][MAXVAL*2+1];
int N, M;

bool _dp(int i, int j){
	if (j < MAXVAL*2+1 && j >= 0)
		return dp[i][j];
	return false;
}

int main(void){
	int i, j;

	scanf("%d %d", &N, &M);

	if (N == 1){
		scanf("%d", &sequence[0]);
		printf("%d\n", sequence[0] == M);
		return 0;
	} else if (N == 2){
		scanf("%d %d", &sequence[0], &sequence[1]);
		printf("%d\n", sequence[0] - sequence[1] == M);
		return 0;
	}

	scanf("%d %d", &sequence[0], &sequence[1]);
	N -= 2;
	M -= sequence[0] - sequence[1];

	for (i = 0; i < N; i++)
		scanf("%d", &sequence[i]);

	dp[N%2][M + MAXVAL] = true;
	for (i = N-1; i >= 0; i--)
		for (j = -MAXVAL; j <= MAXVAL; j++)
			dp[i%2][j + MAXVAL] = _dp((i+1)%2, j + MAXVAL + sequence[i]) | _dp((i+1)%2, j + MAXVAL - sequence[i]);

	printf("%d\n", dp[0][MAXVAL]);

	return 0;
}

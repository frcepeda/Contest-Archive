#include <stdio.h>
#include <math.h>

#define MAXN 5010

int N, K;
int heights[MAXN];
int dp[MAXN];

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	int i, j;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
		scanf("%d", &heights[i]);

	dp[N-1] = 1;

	for (i = N-2; i >= 0; i--){
		double angle = -M_PI/2;
		dp[i] = 100000000;
		for (j = 1; j <= K && i+j < N; j++){
			double new = atan2(heights[i+j] - heights[i], j);
			if (new >= angle){
				angle = new;
				dp[i] = min(dp[i], dp[i+j] + 1);
			}
		}
	}

	printf("%d\n", dp[0]);

	return 0;
}

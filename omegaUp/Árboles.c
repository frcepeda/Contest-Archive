#include <stdio.h>

#define MAXN 55

int N;
int H[MAXN], dp[MAXN];

int max(int a, int b){ return a > b ? a : b; }

int try(int K){
	int i;
	for (i = 1; i <= N; i++){
		if (dp[i-1] < H[i]){
			dp[i] = max(dp[i-1] + 1, H[i] - K);
		} else {
			if (H[i] + K <= dp[i-1]) return 0;
			dp[i] = dp[i-1] + 1;
		}
	}
	return 1;
}

int main(void){
	int i;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &H[i]);

	int lo = 0, hi = 1<<30, mid;
	while (lo < hi){
		mid = lo + (hi - lo)/2;
		if (try(mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%d\n", hi);

	return 0;
}

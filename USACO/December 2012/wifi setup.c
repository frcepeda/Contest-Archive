#include <stdio.h>

#define MAXN 2010
#define INFINITY 1e80

double dp[MAXN];
int N, A, B;
int positions[MAXN];

double min(double a, double b){
	return a < b ? a : b;
}

int intCmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(void){
	int i, j;

	freopen("wifi.in", "r", stdin);
	freopen("wifi.out", "w", stdout);

	scanf("%d %d %d", &N, &A, &B);

	for (i = 1; i <= N; i++)
		scanf("%d", &positions[i]);

	qsort(positions+1, N, sizeof(int), intCmp);

	for (i = 1; i <= N; i++){
		dp[i] = INFINITY;
		for (j = 0; j < i; j++)
			dp[i] = min(dp[i], dp[j] + A + B*(((double)positions[i]-positions[j+1])/2));
	}

	if ((unsigned long long int)dp[N] <= dp[N] && (unsigned long long int)(dp[N] + .9) <= dp[N])
		printf("%llu\n", (unsigned long long int)dp[N]);
	else
		printf("%llu.5\n", (unsigned long long int)dp[N]);
	
	return 0;
}

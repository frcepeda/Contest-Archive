/*
    ID: frceped1
    LANG: C
    TASK: subset
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("subset.in", "r", stdin); freopen("subset.out", "w", stdout)
#else
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

#define MAXN 40
#define MAXSUM 900

bool visited[MAXN][MAXSUM];
long long int dp[MAXN][MAXSUM];

long long int f(int i, int k){
	if (visited[i][k])
		return dp[i][k];
	if ((i == 1 && k == 1) || k == 0)
		return 1;
	if (i <= 1 || k < 0)
		return 0;
	visited[i][k] = true;
	return dp[i][k] = f(i-1, k) + f(i-1, k-i);
}

int main(void){
	openFiles();

	int N;
	long long int answer = 0;

	scanf("%d", &N);

	int sum = N*(N+1)/2;

	if (sum % 2 == 0){
		answer = f(N, sum/2)/2;
	} else if (N == 1){
		answer = 1;
	}

	printf("%lld\n", answer);
	return 0;
}

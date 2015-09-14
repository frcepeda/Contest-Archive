#include <cstdio>
#include <algorithm>

#define MAXF 10
#define MAXN 100100

using namespace std;

int N, F[MAXF];
int dp[MAXN];

int main(){
	int i, j;

	F[0] = 1;
	for (i = 1; i < MAXF; i++)
		F[i] = i * F[i-1];

	for (i = 1; i < MAXN; i++){
		dp[i] = 1000;
		for (j = 0; F[j] <= i; j++)
			dp[i] = min(dp[i], dp[i-F[j]] + 1);
	}

	while (scanf("%d", &N) == 1)
		printf("%d\n", dp[N]);
}

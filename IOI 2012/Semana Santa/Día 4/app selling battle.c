New file: C/IOI 2012/Semana Santa/Día 4/app selling battle.c
#include <stdio.h>

#define MAXDP 10005
#define MOD 1000000007

long long int dp[2][MAXDP];

int main(void){
	int i,j;
	int a,b;

	scanf("%d %d", &a, &b);

	a++;
	b++;

	dp[0][2] = 3;
	dp[0][1] = 1;
	dp[1][2] = 1;
	dp[1][1] = 1;

	for (i = 3; i <= b; i++)
		dp[1][i] = (dp[1][i-1] * 2) % MOD;

	for (i = 2; i <= a; i++){
		for (j = 1; j <= b; j++){
			if (i > 2 || j > 2){
				dp[i%2][j] = 2 * (dp[(i-1)%2][j] + dp[i%2][j-1] - dp[(i-1)%2][j-1]);
				dp[i%2][j] += MOD;
				dp[i%2][j] %= MOD;
			}
		}
	}

	printf("%lld\n", dp[a%2][b]);

	return 0;
}


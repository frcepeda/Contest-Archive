#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1010

int N;
int A[MAXN][MAXN], dp[MAXN][MAXN];

int main(){
	while (scanf("%d", &N), N){
		int i, j;

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				scanf("%d", &A[i][j]);

		for (i = 0; i <= N; i++)
			dp[N][i] = dp[i][N] = 0;

		for (i = N-1; i >= 0; i--)
			for (j = N-1; j >= 0; j--)
				dp[i][j] = A[i][j] + max(dp[i+1][j], dp[i][j+1]);

		printf("%d\n", dp[0][0]);
	}
}

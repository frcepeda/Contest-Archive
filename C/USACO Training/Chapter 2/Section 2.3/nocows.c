/*
    ID: frceped1
    LANG: C
    TASK: nocows
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("nocows.in", "r", stdin); freopen("nocows.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MOD 9901
#define MAXN 201
#define MAXH 101

int dp[MAXN][MAXH];
bool visited[MAXN][MAXH];

int f(int nodes, int height){
	if (visited[nodes][height])
		return dp[nodes][height];
	
	visited[nodes][height] = true;
	int answer = 0;

	if (nodes == 1){
		answer = 1;
	} else if (nodes <= 0 || height <= 1){
		answer = 0;
	} else {
		int i;

		for (i = 0; i < nodes; i++){
			answer += f(i, height-1) * f(nodes-i-1, height-1);
			answer %= MOD;
		}
	}

	return dp[nodes][height] = answer;
}

int main(void){
	openFiles();
	
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d\n", (f(N, K) - f(N, K-1) + MOD) % MOD);

	return 0;
}

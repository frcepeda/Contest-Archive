#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 155
#define INF (1<<27)

int N;
int dp[MAXN][MAXN][MAXN][2];
bool v[MAXN][MAXN][MAXN][2];
int a[MAXN];
char str[MAXN];

int f(int s, int e, int l, bool d){
	if (e < s) return a[l] != -1 ? a[l] : -INF;

	if (v[s][e][l][d]) return dp[s][e][l][d];

	v[s][e][l][d] = true;
	dp[s][e][l][d] = d ? -INF : 0;

	if (l && a[l] != -1)
		dp[s][e][l][d] = max(dp[s][e][l][d], f(s,e,0,d) + a[l]);

	for (int i = s; i < e; i++){
		dp[s][e][l][d] = max(dp[s][e][l][d], f(s,i,l,l || d) + f(i+1,e,0,l || d));
		dp[s][e][l][d] = max(dp[s][e][l][d], f(s,i,0,l || d) + f(i+1,e,l,l || d));
	}

	if (str[s] == str[e])
		dp[s][e][l][d] = max(dp[s][e][l][d], f(s+1,e-1,l+2 - (s == e),1));

	/*
	for (int i = 0; s+i <= e-i; i++){
		if (str[s+i] != str[e-i]) break;

		int l = 2 * (i+1) - (s+i == e-i);

		if (a[l] == -1) continue;

		dp[s][e][d] = max(dp[s][e][d],
		                  f(s+i+1, e-i-1, true) + a[l]);
	}
	*/

	return dp[s][e][l][d];
}

int main(void){
	int i;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	scanf("%s", str);

	printf("%d\n", f(0, N-1, 0, 0));
}

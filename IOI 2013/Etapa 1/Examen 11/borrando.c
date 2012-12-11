#include <stdio.h>
#include <stdbool.h>

#define MAXN 155
#define INFINITY 100000000

int dp[MAXN][MAXN][MAXN][2];
bool erasedCompletely[MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN][2];

char string[MAXN];
int points[MAXN];
int best[MAXN];

int N;

int max(int a, int b){
	return a > b ? a : b;
}

bool isPalindrome(int a, int b){
	while (a <= b)
		if (string[a++] != string[b--])
			return false;
	return true;
}

int f(int a, int b, int c, bool mustObliterate){
	if (visited[a][b][c][mustObliterate])
		return dp[a][b][c][mustObliterate];
	visited[a][b][c][mustObliterate] = true;

	int i, k, t;

	if (a > b){
		erasedCompletely[a][b] = true;

		return dp[a][b][c][mustObliterate] = best[c];
	}

	for (i = a; i < b; i++){
		for (k = 0; k <= c; k++){
			t = f(a, i, k, mustObliterate) + f(i+1, b, c-k, mustObliterate);
			erasedCompletely[a][b] |= erasedCompletely[a][i] && erasedCompletely[i+1][b];
			if (!(mustObliterate && !(erasedCompletely[a][i] && erasedCompletely[i+1][b])))
				dp[a][b][c][mustObliterate] = max(dp[a][b][c][mustObliterate], t);
		}
	}

	if (string[a] == string[b]){
		t = f(a+1, b-1, c + (a == b ? 1 : 2), true);

		erasedCompletely[a][b] |= erasedCompletely[a+1][b-1];
		if (!(mustObliterate && !erasedCompletely[a+1][b-1]))
			dp[a][b][c][mustObliterate] = max(dp[a][b][c][mustObliterate], t);
	}

	if (!mustObliterate){
		t = max(f(a+1, b, c, mustObliterate), f(a, b-1, c, mustObliterate));
		dp[a][b][c][mustObliterate] = max(dp[a][b][c][mustObliterate], t);
	}

	return dp[a][b][c][mustObliterate];
}

int main(void){
	int i, j;
	char c;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d", &points[i]);

	for (i = 1; i <= N; i++)
		for (j = 0; j <= i; j++)
			if (points[j] != -1 && points[i-j] != -1)
				best[i] = max(best[i], points[j] + points[i-j]);

	while ((c = getchar()), !isalpha(c));
	ungetc(c, stdin);

	scanf("%s", string+1);

	printf("%d\n", f(1, N, 0, false));

	return 0;
}

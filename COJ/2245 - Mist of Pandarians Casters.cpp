#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 22

int N, M;
char g[MAXN][MAXN];

int dp[MAXN][MAXN][MAXN][MAXN];
bool v[MAXN][MAXN][MAXN][MAXN];

#define arr(w) w[a][b][c][d]

int SG(int a, int b, int c, int d){
	if (a >= c || b >= d) return 0;

	if (arr(v)) return arr(dp);
	arr(v) = true;

	bool z[MAXN*MAXN] = {false};
	for (int i = a; i < c; i++)
		for (int j = b; j < d; j++){
			int x;

			if (g[i][j] == '-') {
				x = SG(a, b, i, d) ^ SG(i+1, b, c, d);
			} else if (g[i][j] == '|') {
				x = SG(a, b, c, j) ^ SG(a, j+1, c, d);
			} else {
				x = SG(a, b, i, j) ^ SG(i+1, b, c, j) ^ SG(a, j+1, i, d) ^ SG(i+1, j+1, c, d);
			}

			z[x] = true;
		}

	for (int i = 0;; i++)
		if (!z[i]){
			arr(dp) = i;
			break;
		}

	return arr(dp);
}

int main(){
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%s", g[i]);

	printf("%s\n", SG(0,0,N,M) ? "WIN" : "LOSE");
}

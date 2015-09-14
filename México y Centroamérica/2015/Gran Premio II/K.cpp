#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXS 2010
#define fst first
#define snd second

using namespace std;

typedef pair<int,int> pii;

int S;
char str[MAXS];
bool x[MAXS];
pii dp[MAXS][MAXS];

pii f(int i, int j){
	if (i > j) return {0,0};
	if (i == j) return {x[i], 1};
	if (dp[i][j].snd != 0) return dp[i][j];

	dp[i][j] = {-1, -1};

	if (str[i] == str[j]){
		dp[i][j] = f(i+1, j-1);
		dp[i][j].fst += x[i] + x[j];
		dp[i][j].snd += 2;
	}

	dp[i][j] = max(dp[i][j], max(f(i+1, j), f(i, j-1)));

	return dp[i][j];
}

int main(){
	while (scanf("%s", str) == 1){
		int i, j;

		S = strlen(str);

		fill(x, x + S, false);

		scanf("%d", &i);
		while (i--){
			scanf("%d", &j);
			x[j-1] = true;
		}

		for (i = 0; i < S; i++)
			for (j = 0; j < S; j++)
				dp[i][j] = {0,0};

		printf("%d\n", f(0, S-1).snd);
	}
}

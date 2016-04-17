#include <cstdio>
#include <algorithm>

#define MAXN 202

using namespace std;

int N;
char S[MAXN];
char dp[MAXN][MAXN][MAXN];

char f(int r, int g, int b){
	if (dp[r][g][b])
		return dp[r][g][b];

	if (r && g)
		dp[r][g][b] |= f(r-1,g-1,b+1);
	if (r && b)
		dp[r][g][b] |= f(r-1,g+1,b-1);
	if (g && b)
		dp[r][g][b] |= f(r+1,g-1,b-1);
	if (r >= 2)
		dp[r][g][b] |= f(r-1,g,b);
	if (g >= 2)
		dp[r][g][b] |= f(r,g-1,b);
	if (b >= 2)
		dp[r][g][b] |= f(r,g,b-1);
	
	return dp[r][g][b];
}

int main(){
	int r = 0, g = 0, b = 0;

	scanf("%d %s", &N, S);

	for (int i = 0; i < N; i++){
		if (S[i] == 'R')
			r++;
		else if (S[i] == 'G')
			g++;
		else
			b++;
	}

	dp[0][0][1] = 1<<0;
	dp[0][1][0] = 1<<1;
	dp[1][0][0] = 1<<2;

	char ans = f(r, g, b);

	if (ans & (1<<0))
		putchar('B');
	if (ans & (1<<1))
		putchar('G');
	if (ans & (1<<2))
		putchar('R');
	putchar('\n');
}

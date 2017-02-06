#include <cstdio>
#include <algorithm>

using namespace std;

int T, H, S, X, Y, Z;

typedef long double ld;

void readSpell(){
	scanf(" %dd%d", &X, &Y);

	char c = getchar();
	ungetc(c, stdin);

	if (c == '+' || c == '-')
		scanf("%d", &Z);
	else
		Z = 0;
}

const int maxx = 21, maxy = 21, maxv = 401;
ld dp[maxy][maxx][maxv];

ld winP(){
	ld ret = 0;

	for (int i = 0; i < maxv; i++)
		if (i + Z >= H)
			ret += dp[Y][X][i];

	return ret;
}

int main(){
	scanf("%d", &T);

	for (int y = 1; y < maxy; y++){
		dp[y][0][0] = 1;

		for (int x = 1; x < maxx; x++)
			for (int v = 1; v < maxv; v++){
				dp[y][x][v] = 0;
				for (int k = 1; k <= y; k++)
					if (v - k >= 0)
						dp[y][x][v] += dp[y][x-1][v-k];
				dp[y][x][v] /= y;
			}
	}

	for (int t = 1; t <= T; t++){
		scanf("%d %d", &H, &S);

		ld ans = 0;

		while (S--){
			readSpell();
			ans = max(ans, winP());
		}

		printf("Case #%d: %.10Lf\n", t, ans);
	}
}

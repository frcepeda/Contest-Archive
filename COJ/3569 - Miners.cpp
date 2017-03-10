#include <cstdio>
#include <cassert>
#include <set>
#include <algorithm>

using namespace std;

#define MAXN 100100

int N;
char s[MAXN];
int dp[MAXN][4][4][4][4];

inline int g(int a, int b, int c){
	if (b == 0 && c == 0)
		return 1;

	if (c == 0){
		if (a == b) return 1;
		return 2;
	}
	
	if (a == b && b == c) return 1;
	if (a != b && b != c && a != c) return 3;
	return 2;
}

int z(char c){
	return c == 'M' ? 0 : c == 'F' ? 1 : 2;
}

int main(){
	scanf("%d", &N);
	scanf("%s", s);

	for (int i = N-1; i >= 0; i--){
		int nn = z(s[i]) + 1;

		for (int x0 = 0; x0 < 4; x0++)
		for (int y0 = 0; y0 < 4; y0++)
		for (int x1 = 0; x1 < 4; x1++)
		for (int y1 = 0; y1 < 4; y1++)
			dp[i][x0][x1][y0][y1] = max(
				g(nn, x0, x1) + dp[i+1][nn][x0][y0][y1],
				g(nn, y0, y1) + dp[i+1][x0][x1][nn][y0]
			);
	}

	printf("%d\n", dp[0][0][0][0][0]);
}

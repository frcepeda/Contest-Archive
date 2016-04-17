#include <cstdio>
#include <algorithm>

using namespace std;

int r, c;
int g[110][110];

int main(){
	int i, j, ans = 0;

	freopen("lucky.in", "r", stdin);
	freopen("lucky.out", "w", stdout);

	scanf("%d %d", &r, &c);
	
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
			scanf("%d", &g[i][j]);

	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++){
			int k;
			for (k = i-1; k > 0; k--)
				if (g[k][j] >= g[i][j])
					break;
			ans += k == 0;
			for (k = i+1; k <= r; k++)
				if (g[k][j] >= g[i][j])
					break;
			ans += k > r;
			for (k = j-1; k > 0; k--)
				if (g[i][k] >= g[i][j])
					break;
			ans += k == 0;
			for (k = j+1; k <= c; k++)
				if (g[i][k] >= g[i][j])
					break;
			ans += k > c;
			//printf("%d ", ans);
		}

	printf("%d\n", ans);
}

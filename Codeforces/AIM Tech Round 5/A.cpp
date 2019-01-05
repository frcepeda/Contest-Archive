#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200;
int n, m;
char g[maxn][maxn];

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%s", g[i]);

	int lr = maxn, lc = maxn;
	int hr = 0, hc = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == 'B'){
				lr = min(lr, i);
				hr = max(hr, i);
				lc = min(lc, j);
				hc = max(hc, j);
			}

	printf("%d %d\n", (lr + hr + 2)/2, (lc + hc + 2)/2);
}

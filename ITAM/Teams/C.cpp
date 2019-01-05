#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 105;
int a[maxn][maxn];

int main(){
	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < k; i++){
		int r, c, v;
		scanf("%d %d %d", &r, &c, &v);
		a[r-1][c-1] = v;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			int acc = 0;

			for (int k = 0; k < n; k++)
				acc += a[i][k] * a[k][j];

			if (acc == 0) ans++;
		}

	printf("%d\n", ans);
}

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;
int n, k;
int d[maxn][maxn];

int main(){
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			d[i][j] = i == j ? 0 : 1<<29;

	while (k--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		d[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	long long ans = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j && d[i][j] < (1<<29)){
				ans += d[i][j];
				cnt++;
			}

	printf("%.8lf\n", double(ans)/cnt);
}

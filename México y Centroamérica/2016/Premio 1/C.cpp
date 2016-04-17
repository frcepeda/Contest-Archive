#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100100

int n, q;
int cnt[MAXN][10];

int main(){
	while (scanf("%d", &n) == 1){
		for (int i = 1; i <= n; i++){
			int x;
			for (int j = 0; j < 10; j++)
				cnt[i][j] = cnt[i-1][j];
			scanf("%d", &x);
			cnt[i][x]++;
		}

		scanf("%d", &q);

		while (q--){
			int l, r, ans = 0;
			scanf("%d %d", &l, &r);
			for (int i = 0; i < 10; i++)
				ans += cnt[r][i] != cnt[l-1][i];
			printf("%d\n", ans);
		}
	}
}

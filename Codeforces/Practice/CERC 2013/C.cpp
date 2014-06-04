// Accepted
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100100
#define MAXLG 19

typedef long long ll;

int T, N;
ll ST[MAXLG][MAXN];
ll best[MAXN];

int lg2(int x){
	int r = -1;
	for (; x; r++, x >>= 1);
	return r;
}

ll gcd(int i, int j){
	int l = lg2(j-i+1);
	return __gcd(ST[l][i], ST[l][j-(1<<l)+1]);
}

int main(){
	scanf("%d", &T);

	while (T--){
		int i, j;
		ll ans = 0;

		scanf("%d", &N);

		for (i = 0; i <= N; i++)
			best[i] = 0;

		for (i = 0; i < N; i++){
			scanf("%lld", &ST[0][i]);
			best[1] = max(best[1], ST[0][i]);
		}

		for (j = 1; j < MAXLG; j++)
			for (i = 0; i < N; i++)
				ST[j][i] = __gcd(ST[j-1][i], ST[j-1][min(N-1, i + (1<<(j-1)))]);

		for (i = 0; i < N; i++){
			int l = N - i;
			while (l > 1){
				// printf("%d %d %lld\n", i, i+l-1, gcd(i,i+l-1));

				ll g = gcd(i, i+l-1);
				best[l] = max(best[l], g);

				int lo = i, hi = i + l, mid;
				while (lo < hi){
					mid = (lo + hi)/2;
					if (gcd(i, mid) <= g)
						hi = mid;
					else
						lo = mid + 1;
				}

				l = hi - i;
			}
		}

		for (i = N-1; i > 0; i--)
			best[i] = max(best[i], best[i+1]);

		for (i = 1; i <= N; i++)
			ans = max(ans, best[i] * i);

		printf("%lld\n", ans);
	}
}

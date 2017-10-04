// Accepted
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define mp make_pair

const int maxn = 100100;
int n, m, k, sq;
int a[maxn], l[maxn], r[maxn], q[maxn], cnt[1<<22];
long long out[maxn];

int main(){
	scanf("%d %d %d", &n, &m, &k);

	sq = round(sqrt(n));

	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[i] ^= a[i-1];
	}

	for (int i = 0; i < m; i++){
		scanf("%d %d", &l[i], &r[i]);
		q[i] = i;
	}

	sort(q, q+m, [=](const int &x, const int &y){
				return mp(l[x]/sq,r[x]) < mp(l[y]/sq,r[y]);
			});

	long long ans = 0;
	int L = 1, R = 0;
	cnt[0] = 1;
	for (int i = 0; i < m; i++){
		while (R < r[q[i]]){
			R++;
			ans += cnt[a[R] ^ k];
			cnt[a[R]]++;
		}
		while (R > r[q[i]]){
			cnt[a[R]]--;
			ans -= cnt[a[R] ^ k];
			R--;
		}
		while (L > l[q[i]]){
			L--;
			ans += cnt[a[L-1] ^ k];
			cnt[a[L-1]]++;
		}
		while (L < l[q[i]]){
			cnt[a[L-1]]--;
			ans -= cnt[a[L-1] ^ k];
			L++;
		}

		out[q[i]] = ans;
	}

	for (int i = 0; i < m; i++)
		printf("%lld\n", out[i]);
}

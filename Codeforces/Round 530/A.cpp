#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 100010;
int n, p[maxn], s[maxn], a[maxn];
vector<int> adj[maxn];

void fill(int x, int pp, int acc){
	a[x] = s[x] - acc;

	for (auto y: adj[x])
		fill(y, x, s[x]);
}

int main(){
	scanf("%d", &n);

	for (int i = 2; i <= n; i++){
		scanf("%d", &p[i]);
		adj[p[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		scanf("%d", &s[i]);

	for (int i = 1; i <= n; i++){
		if (s[i] >= 0) continue;

		ll mm = INT_MAX;
		for (auto x: adj[i])
			mm = min(mm, (ll)s[x] - s[p[i]]);

		if (mm < 0){
			printf("-1\n");
			return 0;
		}

		if (mm == INT_MAX)
			s[i] = s[p[i]];
		else
			s[i] = s[p[i]] + mm;
	}

	fill(1, 1, 0);

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += a[i];

	printf("%lld\n", ans);
}

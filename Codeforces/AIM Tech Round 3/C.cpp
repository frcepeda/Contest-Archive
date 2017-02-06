#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 400100;

int n;
vector<int> adj[MAXN];
bool ans[MAXN];
int s[MAXN], l[MAXN];

void pre(int x, int p = 0){
	s[x] = 1;

	if (adj[x].size() == 1 && p){
		l[x] = min(n/2, 1);
		return;
	}

	for (auto c : adj[x]){
		if (c == p) continue;
		pre(c, x);
		s[x] += s[c];
		l[x] = max(l[x], l[c]);
		if (s[c] <= n/2)
			l[x] = max(l[x], s[c]);
	}

	if (s[x] <= n/2)
		l[x] = s[x];
}

void dfs(int x, int p = 0, int um = 0){
	int u = n - s[x];
	bool one = true;

	if (u <= n/2)
		ans[x] = true;
	else {
		one = false;
		ans[x] = u - um <= n/2;
	}

	int a = 0, b = 0;

	for (auto c : adj[x]){
		if (c == p) continue;

		if (a < l[c]) {
			b = a;
			a = l[c];
		} else if (b < l[c])
			b = l[c];

		if (s[c] <= n/2) continue;

		if (!one) ans[x] = false;
		one = false;

		if (s[c] - l[c] > n/2)
			ans[x] = false;
	}

	for (auto c : adj[x]){
		if (c == p) continue;
		int z = l[c] == a ? b : a;
		if (n - s[c] <= n/2)
			z = max(z, n - s[c]);
		dfs(c, x, max(z, um));
	}
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	pre(1);
	dfs(1);

	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i], i < n ? ' ' : '\n');
}

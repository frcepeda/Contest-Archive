// Accepted
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct flight {
	int to, ts, te, id;

	flight() {}
	flight(int to, int ts, int te, int id) :
		to(to), ts(ts), te(te), id(id) {}

	bool operator < (const flight &f) const {
		return ts < f.ts;
	}
};

bool operator < (const flight &f, const int &t) {
	return f.ts < t;
}

const int maxn = 100100;
int n, m, s, target, targett;
vector<flight> adj[maxn];
vector<int> ans;

bool v[maxn];

void dfs(int x, int t){
	if (x == target && t <= targett){
		printf("%lu\n", ans.size());

		for (int i = 0; i < ans.size(); i++)
			printf("%d%c", ans[i], i+1 < ans.size() ? ' ' : '\n');
		exit(0);
	}

	auto e = lower_bound(adj[x].begin(), adj[x].end(), t);

	for (; e != adj[x].end(); e++){
		if (v[e->id]) return;
		v[e->id] = true;
		ans.push_back(e->id);
		dfs(e->to, e->te);
		ans.pop_back();
	}
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++){
		flight f; int x;
		scanf("%d %d %d %d", &x, &f.to, &f.ts, &f.te);
		f.id = i+1;
		adj[x].push_back(f);
	}

	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());

	int start, startt;
	scanf("%d %d %d %d", &start, &target, &startt, &targett);

	dfs(start, startt);

	printf("Impossible\n");
}

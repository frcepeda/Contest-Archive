#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1010

int T, N, F[MAXN], v[MAXN];
vector<int> adj[MAXN];

int dfs(int x){
	if (v[x] == 2){
		int i = 1, j;
		for (j = F[x]; j != x; j = F[j])
			i++;
		return i;
	}

	if (v[x]) return 0;

	v[x] = 2;
	int w = dfs(F[x]);
	v[x] = 1;
	return w;
}

int dfs2(int x, int p){
	int r = 1;

	for (auto w: adj[x])
		if (w != p)
			r = max(r, 1 + dfs2(w, x));

	return r;
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		int ans = 0;

		scanf("%d", &N);

		for (int i = 1; i <= N; i++){
			adj[i].clear();
			v[i] = 0;
		}

		for (int i = 1; i <= N; i++){
			scanf("%d", &F[i]);
			adj[F[i]].push_back(i);
		}

		for (int i = 1; i <= N; i++)
			if (!v[i])
				ans = max(ans, dfs(i));

		int w = 0;
		for (int i = 1; i <= N; i++)
			if (F[i] > i && F[F[i]] == i)
				w += dfs2(i, F[i]) + dfs2(F[i], i);

		ans = max(ans, w);

		printf("Case #%d: %d\n", t, ans);
	}
}

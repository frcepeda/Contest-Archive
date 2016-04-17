#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 50100
#define MAXK 17

int N, A[MAXN], q;
int tree[4*MAXN], v[MAXN];

int query(int i, int j, int n = 0, int l = 0, int r = N-1){
	if (j < l || r < i) return 0;
	if (i <= l && r <= j) return tree[n];
	return __gcd(query(i, j, 2*n+1, l, (l+r)/2),
	             query(i, j, 2*n+2, (l+r)/2+1, r));
}

void update(int i, int x, int n = 0, int l = 0, int r = N-1){
	if (i < l || i > r) return;
	if (l == r){
		tree[n] = x;
		return;
	}
	update(i, x, 2*n+1, l, (l+r)/2);
	update(i, x, 2*n+2, (l+r)/2+1, r);
	tree[n] = __gcd(tree[2*n+1], tree[2*n+2]);
}

void build(int n = 0, int l = 0, int r = N-1){
	if (l == r){
		tree[n] = v[l];
		return;
	}
	build(2*n+1, l, (l+r)/2);
	build(2*n+2, (l+r)/2+1, r);
	tree[n] = __gcd(tree[2*n+1], tree[2*n+2]);
}

int g[MAXN], p[MAXN][MAXK], d[MAXN], ix[MAXN], sz[MAXN], nIx; 
vector<int> adj[MAXN];

int LCA(int u, int v){
	if (d[u] < d[v])
		swap(u,v);

	for (int i = MAXK-1; i >= 0; i--)
		if (d[p[u][i]] >= d[v])
			u = p[u][i];

	if (u == v) return u;

	for (int i = MAXK-1; i >= 0; i--)
		if (p[u][i] != p[v][i]){
			u = p[u][i];
			v = p[v][i];
		}

	return p[u][0];
}

int size(int n, int pr){
	sz[n] = 1;
	for (auto z: adj[n]){
		if (z == pr) continue;
		sz[n] += size(z, n);
	}
	return sz[n];
}

void hl(int n, int pr, int grp){
	int best = -1;

	d[n] = (n ? d[pr] : 0) + 1;
	p[n][0] = pr;
	g[n] = grp;

	ix[n] = nIx;
	v[nIx] = A[n];
	nIx++;

	for (auto z: adj[n]){
		if (z == pr) continue;
		if (best == -1 || sz[best] < sz[z])
			best = z;
	}

	if (best != -1)
		hl(best, n, grp);

	for (auto z: adj[n]){
		if (z == pr || z == best) continue;
		hl(z, n, z);
	}
}

int lineQ(int u, int v){
	int ans = 0;

	for (; g[u] != g[v]; u = p[g[u]][0])
		ans = __gcd(ans, query(ix[g[u]], ix[u]));

	ans = __gcd(ans, query(ix[v], ix[u]));

	return ans;
}

int treeQ(int u, int v){
	int l = LCA(u, v);
	return __gcd(lineQ(u, l), lineQ(v, l));
}

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < N-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	size(0, 0);
	hl(0, 0, 0);
	build();

	for (int k = 1; k < MAXK; k++)
		for (int i = 0; i < N; i++)
			p[i][k] = p[p[i][k-1]][k-1];

	scanf("%d", &q);

	while (q--){
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		if (t == 1){
			printf("%d\n", treeQ(u,v));
		} else {
			update(ix[u], v);
		}
	}
}

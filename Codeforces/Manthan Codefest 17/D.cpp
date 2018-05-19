#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;
const int maxl = 18;
const int maxx = 11;
int n;
int p[2][maxn][maxl], d[maxn], t[maxn];

int LCA(int u, int v, int a, int b){
	for (int k = maxl-1; k >= 0; k--)
		if (d[p[a][u][k]] >= d[v])
			u = p[a][u][k];

	for (int k = maxl-1; k >= 0; k--)
		if (d[p[b][v][k]] >= d[u])
			v = p[b][v][k];

	if (u == v) return u;

	for (int k = maxl-1; k >= 0; k--)
		if (p[a][u][k] != p[b][v][k]){
			u = p[a][u][k];
			v = p[b][v][k];
		}

	u = p[a][u][0];
	v = p[b][v][0];

	return u == v ? u : -1;
}

bool query(int t, int u, int v){
	if (u == v) return false;

	int L = LCA(u, v, 0, t);

	return t == 0 ? L == u : L > 0 && L != v;
}

int depth(int i){
	if (d[i]) return d[i];
	return d[i] = 1 + (t[i] >= 0 ? depth(p[t[i]][i][0]) : 0);
}

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		int tmp;
		scanf("%d %d", &tmp, &t[i]);
		p[0][i][0] = p[1][i][0] = i;
		if (t[i] >= 0) p[t[i]][i][0] = tmp;
	}

	for (int i = 1; i <= n; i++)
		if (!d[i])
			d[i] = depth(i);

	for (int k = 0; k < 2; k++)
		for (int j = 1; j < maxl; j++)
			for (int i = 1; i <= n; i++)
				p[k][i][j] = p[k][p[k][i][j-1]][j-1];

	int q;
	scanf("%d", &q);

	while (q--){
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		printf("%s\n", query(t-1, u, v) ? "YES" : "NO");
	}
}

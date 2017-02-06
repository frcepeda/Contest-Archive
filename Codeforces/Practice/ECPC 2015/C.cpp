#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100100, maxl = 18;
int T, n, m, q[maxn], p[maxn][maxl], M[maxn][maxl];

int id(int x){
	if (q[x] == x) return x;
	return q[x] = id(q[x]);
}

int d(int x){
	int xx = p[x][maxl-1], ret = 0;

	if (xx == x) return 0;

	for (int i = maxl-1; i >= 0; i--){
		if (p[x][i] != xx){
			x = p[x][i];
			ret += 1<<i;
		}
	}

	return ret + 1;
}

void join(int a, int b, int t){
	int ta = id(a);
	int tb = id(b);

	if (ta == tb) return;

	q[ta] = tb;
	p[ta][0] = tb;
	M[ta][0] = t;
}

int query(int u, int v){
	int du = d(u);
	int dv = d(v);
	
	if (du < dv){
		swap(u, v);
		swap(du, dv);
	}

	int ret = 0;

	for (int i = maxl-1; i >= 0; i--)
		if (du - (1<<i) >= dv){
			ret = max(ret, M[u][i]);
			u = p[u][i];
			du -= 1<<i;
		}

	if (u == v) return ret;

	for (int i = maxl-1; i >= 0; i--)
		if (p[u][i] != p[v][i]){
			ret = max(ret, max(M[u][i], M[v][i]));
			u = p[u][i]; v = p[v][i];
		}

	ret = max(ret, max(M[u][0], M[v][0]));

	return p[u][0] == p[v][0] ? ret : -1;
}

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++){
			q[i] = i;
			p[i][0] = i;
			M[i][0] = 0;
		}

		vector<pair<int, pair<int,int>>> q;

		for (int t = 1; t <= m; t++){
			int w, u, v;
			scanf("%d %d %d", &w, &u, &v);
			if (w == 1){
				join(u, v, t);
			} else {
				q.push_back(make_pair(t, make_pair(u, v)));
			}
		}

		for (int l = 1; l < maxl; l++){
			for (int i = 1; i <= n; i++){
				p[i][l] = p[p[i][l-1]][l-1];
				M[i][l] = max(M[i][l-1], M[p[i][l-1]][l-1]);
			}
		}

		for (auto z: q){
			int t = query(z.second.first, z.second.second);
			printf("%d\n", t <= z.first ? t : -1);
		}
	}
}

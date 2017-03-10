#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define MAXN 105
#define MAXV (2 + MAXN + MAXN + 50)
#define MAXE (MAXN + MAXN*MAXN + MAXN + 50)

struct edge {
	int node, next, cap, flow;
};

edge g[MAXE*2];
int start[MAXV], nextEdge;
int V;

void addEdge(int a, int b, int c){
	g[nextEdge] = {b, start[a], c, 0};
	start[a] = nextEdge++;
	g[nextEdge] = {a, start[b], 0, 0};
	start[b] = nextEdge++;
}

#define INF 10101010

int maxFlow(int s, int t){
	int tot = 0;
	static int q[MAXV], z[MAXV], d[MAXV], p[MAXV], qs, qe, curr;

	while (true){
		fill(d, d + V, MAXV);
		d[s] = qs = qe = 0;
		q[qe++] = s;

		while (qs < qe){
			curr = q[qs++];
			z[curr] = start[curr];
			if (d[curr] == d[t]) continue;
			for (int i = start[curr]; i; i = g[i].next){
				if (g[i].cap - g[i].flow > 0 &&
				    d[g[i].node] > d[curr] + 1){
					d[g[i].node] = d[curr] + 1;
					q[qe++] = g[i].node;
				}
			}
		}

		if (d[t] == MAXV) return tot;

		curr = s;
		while (true){
			while (z[curr] && (g[z[curr]].cap - g[z[curr]].flow <= 0 ||
			                   d[g[z[curr]].node] != d[curr] + 1))
				z[curr] = g[z[curr]].next;

			if (!z[curr]){
				if (curr == s) break;
				curr = g[p[d[curr]-1]^1].node;
				d[g[p[d[curr]]].node] = -INF;
				continue;
			}

			p[d[curr]] = z[curr];
			curr = g[z[curr]].node;

			if (curr == t){
				int m = INF;
				for (int i = 0; i < d[t]; i++)
					m = min(m, g[p[i]].cap - g[p[i]].flow);
				for (int i = 0; i < d[t]; i++){
					g[p[i]].flow += m;
					g[p[i]^1].flow -= m;
				}
				tot += m;
				curr = s;
			}
		}
	}
}

int T, N;
int a[MAXN];
char adj[MAXN][MAXN];

bool works(int x){
	V = 2 + 2*N;
	nextEdge = 2;
	fill(start, start + V, 0);

	int k = 0;
	for (int i = 0; i < N; i++){
		if (a[i]){
			addEdge(0, i+2, a[i]);
			addEdge(i+2, i+2+N, 200);

			bool ded = false;
			for (int j = 0; j < N; j++){
				if (adj[i][j] == 'Y'){
					if (a[j] == 0){
						ded = true;
					} else {
						addEdge(i+2, j+2+N, 200);
					}
				}
			}

			if (ded){
				k += x;
				addEdge(i+2+N, 1, x);
			} else {
				k++;
				addEdge(i+2+N, 1, 1);
			}
		}
	}

	int w = maxFlow(0, 1);
	return w == k;
}

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);

		int sum = 0;
		for (int i = 0; i < N; i++){
			scanf("%d", &a[i]);
			sum += a[i];
		}

		for (int i = 0; i < N; i++)
			scanf("%s", adj[i]);

		int lo = 1, hi = sum, mid;
		
		while (lo <= hi){
			mid = (lo + hi)/2;

			if (works(mid))
				lo = mid + 1;
			else
				hi = mid - 1;
		}

		printf("%d\n", lo-1);
	}
}

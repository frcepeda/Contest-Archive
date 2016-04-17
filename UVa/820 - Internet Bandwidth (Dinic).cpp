#include <cstdio>
#include <algorithm>

#define MAXV 110
#define MAXE (MAXV*MAXV)
#define INF 1000000

using namespace std;

struct edge {
	int node, next, cap, flow;
};

edge g[MAXE*2];
int start[MAXV], nextEdge; // init start to 0s and nextEdge to 2

int addEdge(int a, int b, int c){
	g[nextEdge] = {b, start[a], c, 0};
	start[a] = nextEdge++;
	g[nextEdge] = {a, start[b], c, 0}; // set to 0
	start[b] = nextEdge++;
}

int n, s, t, c;

int maxFlow(){
	int tot = 0;
	int q[MAXV], z[MAXV], d[MAXV], p[MAXV], qs, qe, curr;

	while (true){
		fill(d, d + n, MAXV);
		d[s] = qs = qe = 0;
		q[qe++] = s;

		while (qs < qe){
			curr = q[qs++];
			z[curr] = start[curr];
			if (d[curr] == d[t]) continue;
			for (int i = start[curr]; i; i = g[i].next)
				if (g[i].cap - g[i].flow > 0 &&
				    d[g[i].node] > d[curr] + 1){
					d[g[i].node] = d[curr] + 1;
					q[qe++] = g[i].node;
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

int cap[MAXV][MAXV];

int main(){
	for (int T = 1; scanf("%d", &n), n; T++){
		scanf("%d %d %d", &s, &t, &c);
		s--, t--;

		fill(start, start + n, 0);
		nextEdge = 2;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cap[i][j] = 0;

		while (c--){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			cap[a-1][b-1] += c; cap[b-1][a-1] += c;
		}

		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				if (cap[i][j])
					addEdge(i, j, cap[i][j]);

		printf("Network %d\nThe bandwidth is %d.\n\n", T, maxFlow());
	}
}

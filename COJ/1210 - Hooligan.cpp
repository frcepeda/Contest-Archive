#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define MAXN 41
#define MAXV (840 + 44 + 2)
#define MAXE (840 * (1 + 2) + 44 + 100)

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

int N, M, G, R;
int P[MAXN], Q[MAXN][MAXN];

bool solve(){
	nextEdge = 2;
	fill(start, start + 2 + (N-1), 0);
	
	for (int i = 1; i < N; i++){
		if (P[i] >= P[0]) return false;
		addEdge(1+i, 1, P[0] - P[i] - 1);
	}

	int R = 0;
	V = 2 + (N-1);
	for (int i = 1; i < N; i++)
		for (int j = i+1; j < N; j++)
			if (Q[i][j] < M){
				int z = M - Q[i][j];
				R += z;

				start[V] = 0;
				addEdge(0, V, 2*z);
				addEdge(V, i+1, 2*z);
				addEdge(V, j+1, 2*z);

				V++;
			}

	return maxFlow(0, 1) == 2*R;
}

int main(){
	while (scanf("%d %d %d", &N, &M, &G), (N || M || G)){
		fill(P, P + N, 0);
		for (int i = 0; i < N; i++)
			fill(Q[i], Q[i] + N, 0);

		for (int i = 0; i < G; i++){
			int a, b; char tmp[10];

			scanf("%d %s %d", &a, tmp, &b);

			if (tmp[0] == '<'){
				P[b] += 2;
			} else if (tmp[0] == '='){
				P[a]++;
				P[b]++;
			} else {
				P[a] += 2;
			}

			Q[a][b]++;
			Q[b][a]++;
		}

		for (int i = 1; i < N; i++){
			int z = M - Q[0][i];
			G += z;
			P[0] += 2 * z;
			Q[0][i] += z;
			Q[i][0] += z;
		}

		printf("%c\n", solve() ? 'Y' : 'N');
	}
}

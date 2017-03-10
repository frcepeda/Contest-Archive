#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define MAXV 60
#define MAXE (MAXV*MAXV)

struct edge {
	int node, next, cap, flow;
};

edge g[MAXE*2];
int start[MAXV], nextEdge;

int addEdge(int a, int b, int c){
	g[nextEdge] = {b, start[a], c, 0};
	start[a] = nextEdge++;
	g[nextEdge] = {a, start[b], c, 0};
	start[b] = nextEdge++;
}

#define INF 10101010
int N;

int maxFlow(int s, int t){
	int tot = 0;
	static int q[MAXV], z[MAXV], d[MAXV], p[MAXV], qs, qe, curr;

	for (int i = 0; i < nextEdge; i++)
		g[i].flow = 0;

	while (true){
		fill(d, d + N, MAXV);
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

void parse(int x, string &v){
	for (int i = 0; i < N; i++)
		if (x < i)
			addEdge(x, i, v[i] - '0');
}

int main(){
	string tmp;

	while (cin >> tmp){
		N = tmp.length();

		fill(start, start + N, 0);
		nextEdge = 2;

		parse(0, tmp);
		for (int i = 1; i < N; i++){
			cin >> tmp;
			parse(i, tmp);
		}

		int ans = 1<<29;
		for (int i = 1; i < N; i++)
			ans = min(ans, maxFlow(0, i));

		cout << ans << endl;
	}
}

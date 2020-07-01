/*
    ID: frceped1
    LANG: C++
    TASK: milk6
 */

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#ifdef DBG
	#define openFiles()
#else
	#define openFiles() freopen("milk6.in", "r", stdin); freopen("milk6.out", "w", stdout)
#endif

#define fst first
#define snd second
#define mp make_pair

typedef long long ll;

const int MAXE = 1010;
const int MAXV = 40;
const ll INF = 1LL<<62;

struct edge {
	int node, next;
	ll cap, flow;
	int idx;
};

edge g[MAXE*2];
int start[MAXV], nextEdge = 2; // init start to 0s and nextEdge to 2

int N, M;
int s, t;

void addEdge(int a, int b, ll c, int i){
	g[nextEdge] = {b, start[a], c, 0, i};
	start[a] = nextEdge++;
	g[nextEdge] = {a, start[b], 0, 0, i};
	start[b] = nextEdge++;
}

ll maxFlow(){
	ll tot = 0;
	static int q[MAXV], z[MAXV], p[MAXV], qs, qe, curr;
	static ll d[MAXV];

	while (true){
		fill(d, d + N, MAXV);
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
				ll m = INF;
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

bool visited[MAXV];

void dfs(int x, int p){
	if (visited[x]) return;
	visited[x] = true;
	for (int j = start[x]; j; j = g[j].next){
		if (g[j].flow < g[j].cap)
			dfs(g[j].node, x);
	}
}

int main(){
	openFiles();

	scanf("%d %d", &N, &M);
	s = 1;
	t = N;
	N++;

	for (int i = 1; i <= M; i++){
		ll s, e, c;
		scanf("%lld %lld %lld", &s, &e, &c);
		addEdge(s, e, M * c + 1, i);
	}

	ll flow = maxFlow();
	ll totalFlow = flow;
	vector<int> shutdown;

	vector<int> candidates;
	for (int i = 1; i <= M; i++)
		candidates.push_back(i);
	sort(candidates.begin(), candidates.end(), [&](int a, int b){ return make_pair(g[2*a].cap, a) < make_pair(g[2*b].cap, b); });

	for (auto ee: candidates){
		for (int i = 1; i <= N; i++){
			for (int j = start[i]; j; j = g[j].next){
				g[j].flow = 0;
			}
		}

		int eidx = 2*ee;
		ll tmpcap = g[eidx].cap;
		g[eidx].cap = 0;

		ll newflow = maxFlow();

		if (newflow + tmpcap == flow){
			shutdown.push_back(ee);
			flow = newflow;
		} else {
			g[eidx].cap = tmpcap;
		}
	}

	sort(shutdown.begin(), shutdown.end());

	printf("%lld %lu\n", (totalFlow-1) / M, shutdown.size());
	for (auto x: shutdown)
		printf("%d\n", x);
}

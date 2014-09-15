#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

#define MAXS 20100
#define MAXT 40100
#define INF (1<<29)
#define mp make_pair
#define fst first
#define snd second

struct edge {
	int next, node, weight;
};

priority_queue<pii, vector<pii>, greater<pair<int,int> > > q;

int start[MAXS], nextEdge = 1;
edge graph[MAXT];

void addEdge(int a, int b, int c){
	graph[nextEdge].weight = c;
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int p[MAXS];
int id(int x){
	if (p[x] == x) return x;
	return p[x] = id(p[x]);
}

void join(int a, int b){
	p[id(a)] = id(b);
}

int S, T, Q, X, M;

int cycleWeight[MAXS];

int v[MAXS];
int path[MAXS], weight[MAXS], ps;

void findCycles(int x, int p, int w){
	if (v[x] == 1) return;

	if (v[x] == 2){
		int tw = w, i;
		for (i = ps-1; path[i] != x; i--)
			join(path[i], x);
		for (i++; i < ps; i++)
			tw += weight[i];
		cycleWeight[id(x)] = tw;
		return;
	}

	weight[ps] = w;
	path[ps++] = x;
	v[x] = 2;

	for (int i = start[x]; i; i = graph[i].next)
		if (graph[i].node != p)
			findCycles(graph[i].node, x, graph[i].weight);

	v[x] = 1;
	ps--;
}

int best = INF;

void check(int s){
	q.push(mp(0,s));

	while (!q.empty()){
		pii curr = q.top(); q.pop();

		if (v[curr.snd]) continue;
		v[curr.snd] = true;

		if (cycleWeight[id(curr.snd)] >= M)
			best = min(best, 2 * curr.fst + cycleWeight[id(curr.snd)]);

		for (int i = start[curr.snd]; i; i = graph[i].next)
			if (!v[graph[i].node])
				q.push(mp(curr.fst + graph[i].weight, graph[i].node));
	}
}

int main(){
	int i, a, b, c;

	scanf("%d %d", &S, &T);

	for (i = 1; i <= S; i++) p[i] = i;

	while (T--){
		scanf("%d %d %d", &a, &b, &c);
		addEdge(a, b, c);
		addEdge(b, a, c);
	}

	for (i = 1; i <= S; i++)
		if (!v[i])
			findCycles(i, -1, 0);

	scanf("%d", &Q);

	while (Q--){
		scanf("%d %d", &X, &M);

		best = INF;
		for (i = 1; i <= S; i++) v[i] = 0;

		check(X);

		printf("%d\n", best == INF ? -1 : best);
	}
}

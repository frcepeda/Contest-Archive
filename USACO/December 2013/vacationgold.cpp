#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("vacationgold.in", "r", stdin); freopen("vacationgold.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define INF (1<<29)
#define MAXN 20100
#define MAXM 20100
#define MAXK 210
#define fst first
#define snd second
#define mp make_pair

struct edge {
	int node, cost, next;
};

typedef long long ll;
typedef pair<int, int> state;

edge graph[MAXM*2];
int start[MAXN], rStart[MAXN];
int nextEdge = 1;

void addEdge(int a, int b, int c, int s[MAXN]){
	graph[nextEdge].node = b;
	graph[nextEdge].cost = c;
	graph[nextEdge].next = s[a];
	s[a] = nextEdge++;
}

int N, M, K, Q;
int toHub[MAXK][MAXN], fromHub[MAXK][MAXN];

priority_queue< state, vector<state>, greater<state> > p;
void dijkstra(int source, int dist[MAXN], int s[MAXN]){
	int i;

	for (i = 1; i <= N; i++)
		dist[i] = INF;

	p.push(mp(0,source));

	while (!p.empty()){
		state c = p.top();
		p.pop();

		if (dist[c.snd] < c.fst) continue;

		dist[c.snd] = c.fst;

		for (i = s[c.snd]; i; i = graph[i].next)
			if ((dist[graph[i].node] > c.fst + graph[i].cost))
				p.push(mp(c.fst + graph[i].cost, graph[i].node));
	}
}

int main(){
	int i, j;
	openFiles();

	scanf("%d %d %d %d", &N, &M, &K, &Q);

	for (i = 0; i < M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		addEdge(a,b,c,start);
		addEdge(b,a,c,rStart);
	}

	for (i = 1; i <= K; i++){
		scanf("%d", &j);
		dijkstra(j, fromHub[i], start);
		dijkstra(j, toHub[i], rStart);
	}

	int cnt = 0;
	ll ans = 0;
	while (Q--){
		int a, b, c = INF;

		scanf("%d %d", &a, &b);

		for (i = 1; i <= K; i++)
			c = min(c, toHub[i][a] + fromHub[i][b]);

		if (c < INF){
			cnt++;
			ans += c;
		}
	}

	printf("%d\n%lld\n", cnt, ans);
}

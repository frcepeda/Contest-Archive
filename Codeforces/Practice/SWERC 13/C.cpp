#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>

#define fst first
#define snd second
#define mp make_pair
#define MAXN 210
#define MAXM 2010

using namespace std;

typedef double ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> piii;

struct edge {
	int node, next;
	ll w;
};

inline ll sq(ll x){ return x * x; }

int N, M, Q;
pair<int,pii> pts[MAXN];
edge graph[MAXM*2];
int start[MAXN], nextEdge = 1;

void addEdge(int a, int b, ll c){
	graph[nextEdge].node = b;
	graph[nextEdge].w = c;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

priority_queue<piii, vector<piii>, greater<piii>> q;
int parent[MAXN];
bool v[MAXN];

void print(int n){
	if (parent[n] != -1)
		print(parent[n]);
	printf("%s%d", parent[n] == -1 ? "" : " ", n);
}

void search(int s, int e){
	while (!q.empty()) q.pop();
	q.push(mp(0, mp(s,-1)));

	fill(v, v + N, false);

	while (!q.empty()){
		piii curr = q.top(); q.pop();

		if (v[curr.snd.fst]) continue;
		v[curr.snd.fst] = true;

		parent[curr.snd.fst] = curr.snd.snd;

		if (curr.snd.fst == e){
			print(e);
			putchar('\n');
			return;
		}

		for (int i = start[curr.snd.fst]; i; i = graph[i].next)
			if (!v[graph[i].node])
				q.push(mp(curr.fst + graph[i].w, mp(graph[i].node, curr.snd.fst)));
	}
}

int main(){
	int i, j;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		scanf("%I64d %d %d", &pts[i].fst, &pts[i].snd.fst, &pts[i].snd.snd);

	while (M--){
		char str[15];
		scanf("%d %d %s", &i, &j, str);
		ll d = sqrt(25 * sq(pts[i].fst - pts[j].fst) + sq(pts[i].snd.fst - pts[j].snd.fst) + sq(pts[i].snd.snd - pts[j].snd.snd));
		if (strcmp(str, "walking") == 0 || strcmp(str, "stairs") == 0){
			addEdge(i, j, d);
			addEdge(j, i, d);
		} else if (strcmp(str, "lift") == 0){
			addEdge(i, j, 1);
			addEdge(j, i, 1);
		} else {
			addEdge(i, j, 1);
			addEdge(j, i, 3 * d);
		}
	}

	scanf("%d", &Q);

	while (Q--){
		scanf("%d %d", &i, &j);
		search(i, j);
	}
}

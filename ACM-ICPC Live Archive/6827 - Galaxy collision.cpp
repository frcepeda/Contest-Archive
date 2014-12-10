#include <cstdio>
#include <set>
#include <algorithm>

#define mp make_pair
#define fst first
#define snd second
#define sq(a) ((long long)(a) * (long long)(a))

#define MAXN 50100

using namespace std;

struct edge {
	int node, next;
};

edge graph[MAXN*130*2];
int start[MAXN], nextEdge = 1;

typedef pair<int,int> pii;

int N, ans;
pii P[MAXN];
set<pair<pii,int> > in;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int cnt, a;
int color[MAXN];
void bipartite(int n, int c){
	if (color[n]) return;
	color[n] = 1;
	if (c) a++;
	cnt++;
	for (int i = start[n]; i; i = graph[i].next)
		bipartite(graph[i].node, !c);
}

int main(){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d %d", &P[i].fst, &P[i].snd);

	sort(P, P+N);

	for (i = j = 0; i < N; i++){
		for (; j < i && P[j].fst < P[i].fst - 5; j++)
			in.erase(mp(mp(P[j].snd, P[j].fst), j));

		for (set<pair<pii,int> >::iterator it = in.lower_bound(mp(mp(P[i].snd - 5,-1), -1)); it != in.end() && it->fst.fst <= P[i].snd + 5; it++)
			if (sq(P[i].fst - it->fst.snd) + sq(P[i].snd - it->fst.fst) <= 25){
				addEdge(i, it->snd);
				addEdge(it->snd, i);
			}

		in.insert(mp(mp(P[i].snd, P[i].fst), i));
	}

	for (i = 0; i < N; i++)
		if (!color[i]){
			cnt = a = 0;
			bipartite(i, 0);
			ans += min(a, cnt - a);
		}

	printf("%d\n", ans);
}

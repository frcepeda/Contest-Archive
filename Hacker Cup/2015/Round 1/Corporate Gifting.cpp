// Accepted
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
 
using namespace std;
 
#define MAXN 500100
#define mp make_pair
#define fst first
#define snd second
 
struct edge {
	int next, node;
};

edge graph[MAXN*2];
int start[MAXN], nextEdge = 1;
 
void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

int mex(vector<int> v){
	int i;

	sort(v.begin(), v.end());

	if (v.size() == 0 || v[0] != 1) return 1;

	for (i = 0; i < v.size() - 1; i++)
		if (v[i+1] - v[i] > 1)
			break;

	return v[i] + 1;
}

typedef pair<long long, int> pos;
 
int T, N;
vector<int> v;
map<int, long long> m;
pair<pos,pos> g[MAXN];
 
void f(int n){
	if (!start[n]){
		g[n] = mp(mp(1,1),mp(2,2));
		return;
	}
 
	for (int i = start[n]; i; i = graph[i].next)
		f(graph[i].node);

	m.clear();
	v.clear();

	long long r = 0;
 
	for (int i = start[n]; i; i = graph[i].next){
		r += g[graph[i].node].fst.fst;
		v.push_back(g[graph[i].node].fst.snd);
		m[g[graph[i].node].fst.snd] += g[graph[i].node].snd.fst - g[graph[i].node].fst.fst;
	}

	g[n].fst = mp(r, mex(v));
	g[n].fst.fst += g[n].fst.snd;

	v.push_back(g[n].fst.snd);

	g[n].snd = mp(r, mex(v));
	g[n].snd.fst += g[n].snd.snd;

	for (auto it = m.begin(); it != m.end(); it++){
		pos x = mp(r + it->snd + it->fst, it->fst);
		if (x < g[n].fst){
			g[n].snd = g[n].fst;
			g[n].fst = x;
		} else if (x < g[n].snd) {
			g[n].snd = x;
		}
	}
}
 
int main(){
	scanf("%d", &T);
 
	for (int t = 1; t <= T; t++){
		fill(start, start + MAXN, 0);
		nextEdge = 1;
 
		scanf("%d", &N);
 
		for (int i = 1; i <= N; i++){
			int x;
			scanf("%d", &x);
			addEdge(x, i);
		}
 
		f(1);
 
		printf("Case #%d: %lld\n", t, g[1].fst.fst);
	}
}

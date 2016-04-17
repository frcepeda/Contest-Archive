#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

#define MAXN 100010
#define fst first
#define snd second
#define mp make_pair

struct edge {
	int node, next;
};

int n, l;
bool v[MAXN];

edge graph[MAXN*2];
int start[MAXN], nextEdge = 1;
int d[MAXN], ds;

void addEdge(int a, int b){
	graph[nextEdge].node = b;
	graph[nextEdge].next = start[a];
	start[a] = nextEdge++;
}

pair<int,int> furthest(int n, int p){
	auto best = mp(0,n);
	v[n] = true;
	for (int i = start[n]; i; i = graph[i].next){
		if (graph[i].node == p) continue;
		auto z = furthest(graph[i].node, n);
		z.fst += 1;
		best = max(best, z);
	}
	return best;
}

int diameter(int n){
	auto f = furthest(n, -1);
	return furthest(f.snd, -1).fst;
}

int main(){
	int i;

	scanf("%d %d", &n, &l);
	
	for (i = 0; i < l; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		addEdge(a, b);
		addEdge(b, a);
	}

	for (i = 0; i < n; i++)
		if (!v[i])
			d[ds++] = diameter(i);
	
	sort(d, d + ds, greater<int>());

	int ans = d[0];

	if (ds > 1)
		ans = max(ans, (d[0]+1)/2 + (d[1]+1)/2 + 1);

	if (ds > 2)
		ans = max(ans, (d[1]+1)/2 + (d[2]+1)/2 + 2);

	printf("%d\n", ans);
}

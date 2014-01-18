#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAXN 100010
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef pair<ll,ll> pll;

pair<int,int> graph[MAXN*2];
int start[MAXN], nextEdge = 1;
int N, a[MAXN];
ll total;

void addEdge(int a, int b){
	graph[nextEdge].fst = b;
	graph[nextEdge].snd = start[a];
	start[a] = nextEdge++;
}

ll lcm(ll a, ll b){
	return a*(b/__gcd(a,b));
}

pll f(int node, int parent){
	int k = 0;
	
	if (a[node])
		return mp(a[node], 1);
		
	ll minC = 1<<30;
	ll lcmB = 1;
	for (int i = start[node]; i; i = graph[i].snd){
		if (graph[i].fst == parent) continue;
		k++;
		
		pll r = f(graph[i].fst, node);
		minC = min(minC, r.fst);
		lcmB = lcm(lcmB, r.snd);
	}
	
	if (minC == 0){
		printf("%lld\n", total);
		exit(0);
	}
	
	return mp((minC / lcmB) * lcmB * k, lcmB * k);
}

int main() {
	int i, x, y;
	
	scanf("%d", &N);
	
	for (i = 1; i <= N; i++){
		scanf("%d", &a[i]);
		total += a[i];
	}
	
	for (i = 1; i < N; i++){
		scanf("%d %d", &x, &y);
		addEdge(x,y);
		addEdge(y,x);
	}
	
	printf("%lld\n", total - f(1,-1).fst);
}

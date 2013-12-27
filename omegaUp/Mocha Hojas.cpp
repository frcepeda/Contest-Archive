// 100/100 points
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAXN 100010
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;

pair<int,int> graph[MAXN*2];
int start[MAXN], nextEdge = 1;
int N, val[MAXN];
ll total;

void addEdge(int a, int b){
	graph[nextEdge].fst = b;
	graph[nextEdge].snd = start[a];
	start[a] = nextEdge++;
}

ll lcm(ll a, ll b){
	return a*b/__gcd(a,b);
}

pair<ll,ll> f(int n, int p){
	int c = 0;

	if (val[n])
		return mp(val[n], 1);
		
	pair<ll,ll> a = mp(-1,0);
	for (int i = start[n]; i; i = graph[i].snd){
		if (graph[i].fst == p) continue;
		c++;
		
		if (a.fst == -1)
			a = f(graph[i].fst, n);
		else {
			pair<ll,ll> b = f(graph[i].fst, n);
			ll l = lcm(a.snd, b.snd);
			ll m = min(a.fst, b.fst);
			a = mp((m/l)*l, l);
		}
	}
	
	if (a.fst == -1){
		printf("%lld\n", total);
		exit(0);
	}
	
	return mp(a.fst * c, a.snd * c);
}

int main(void) {
	int i, a, b;
	
	scanf("%d", &N);
	
	for (i = 1; i <= N; i++){
		scanf("%d", &val[i]);
		total += val[i];
	}
	
	for (i = 1; i < N; i++){
		scanf("%d %d", &a, &b);
		addEdge(a,b);
		addEdge(b,a);
	}
	
	printf("%lld\n", total - f(1,-1).fst);
}

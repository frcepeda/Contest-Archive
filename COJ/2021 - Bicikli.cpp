#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 10100
#define MOD 1000000000
#define fst first
#define snd second
#define mp make_pair

typedef pair<int, bool> pii;

int N, M;
pii dp[MAXN];
int v[MAXN];
vector<int> adj[MAXN];

pii f(int x){
	if (v[x] == 1) return dp[x];
	if (v[x] == 2) return mp(0, false);
	if (x == 2) return mp(1, false);
	v[x] = 2;

	for (auto y: adj[x]){
		auto r = f(y);
		dp[x].snd |= r.snd || dp[x].fst + r.fst >= MOD;
		dp[x].fst = (dp[x].fst + r.fst) % MOD;
	}

	v[x] = 1;
	return dp[x];
}

int v2[MAXN];
bool l[MAXN], r[MAXN];

bool g(int x){
	l[x] |= v2[x] == 2;
	if (v2[x]) return r[x];

	v2[x] = 2;

	for (auto y: adj[x])
		r[x] |= g(y);

	v2[x] = 1;
	return r[x];
}

int main(){
	scanf("%d %d", &N, &M);

	while (M--){
		int A, B;
		scanf("%d %d", &A, &B);
		adj[A].push_back(B);
	}

	r[2] = true;
	g(1);

	bool noloops = true;
	for (int i = 1; i <= N; i++)
		if (l[i] && r[i]){
			noloops = false;
			break;
		}

	if (noloops){
		auto ans = f(1);
		if (!ans.snd)
			printf("%d\n", ans.fst);
		else
			printf("%09d\n", ans.fst);
	} else printf("inf\n");
}

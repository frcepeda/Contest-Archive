#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 30100

typedef long long ll;

int N, S;
vector<int> adj[MAXN];
ll dp[MAXN], dp2[MAXN];

int main(){
	scanf("%d %d", &N, &S);

	while (S--){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}

	dp[N] = 1;
	for (int i = N-1; i >= 1; i--)
		for (auto x : adj[i])
			dp[i] += dp[x];

	dp2[N] = 1;
	for (int i = N-1; i >= 1; i--){
		dp2[i] = -(1LL<<40);
		for (auto x : adj[i])
			dp2[i] = max(dp2[i], dp2[x] + dp[i]);
	}
	
	printf("%lld\n", dp2[1]);
}

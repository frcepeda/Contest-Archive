#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 200100
#define fst first
#define snd second

int n, k;
typedef long long ll;
typedef pair<ll,ll> pll;
pll players[MAXN];
priority_queue<ll> q;
ll toWin[MAXN];

bool works(ll energy){
	int i, rank = n+1;
	int tWcnt = 0;

	while (!q.empty()) q.pop();

	for (i = 0; i < n && players[i].fst <= energy; i++)
		energy -= players[i].fst;
	const int won = i;

	for (i = 0; i < n; i++){
		if (i < won){
			if (players[i].snd + 1 < won){
				q.push(players[i].fst);
				rank--;
			} else if (players[i].snd <= won)
				rank--;
		} else {
			if (players[i].snd + 1 < won)
				rank--;
			else if (players[i].snd + 1 == won || players[i].snd == won)
				toWin[tWcnt++] = players[i].fst;
		}
	}

	sort(toWin, toWin + tWcnt, greater<ll>());

	while (tWcnt-- && energy >= 0 && !q.empty() && rank > k){
		ll rep = q.top(); q.pop();
		energy -= toWin[tWcnt] - rep;
		rank--;
	}

	return energy >= 0 && rank <= k;
}

int main(){
	int i;
	ll lo = 0, hi = (1LL<<45), mid;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
		scanf("%lld %lld", &players[i].snd, &players[i].fst);

	sort(players, players + n);

	while (lo < hi){
		mid = (lo + hi)/2;
		if (works(mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%lld\n", hi < (1LL<<45) ? hi : -1LL);
}

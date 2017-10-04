#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define MAXN 100100
#define mp make_pair
#define fst first
#define snd second


typedef long long ll;
typedef pair<int, int> pii;

int N, M, K;
pii p[2*MAXN];
ll n[MAXN];
vector<pii> m;
vector<int> adjL[MAXN];
bool uu[MAXN];

void radix_sort(vector<pii> &v){
	static int c[MAXN] = {0};

	vector<pii> w(v.size());

	for (auto x: v)
		c[x.snd]++;

	int t = 0;
	for (int i = 1; i < MAXN; i++){
		int tt = c[i];
		c[i] = c[i-1] + t;
		t = tt;
	}

	for (auto x: v)
		w[c[x.snd]++] = x;

	for (int i = 1; i < MAXN; i++)
		c[i] = 0;

	for (auto x: w)
		c[x.fst]++;

	t = 0;
	for (int i = 1; i < MAXN; i++){
		int tt = c[i];
		c[i] = c[i-1] + t;
		t = tt;
	}

	for (auto x: w)
		v[c[x.fst]++] = x;
}

int main(){
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		n[a]++;
		p[i] = mp(a, b);
		adjL[a].push_back(b);
	}

	ll ans = 0;
	for (ll i = 1; i <= N; i++) {
		
		if ( n[i]*n[i] < K ) continue;
	
//		printf("Node %lld is fat.\n", i);
		for (auto w: adjL[i])
			uu[w] = true;

		for (ll j = 1; j <= N; j++){
			if (j <= i && n[j]*n[j] >= K) continue;

			ll c = 0;

			for (auto w: adjL[j])
				if (uu[w])
					c++;

			ans += c * (c-1) / 2;
		}

		for (auto w: adjL[i])
			uu[w] = false;
	}

	for (ll i = 1; i <= N; i++)
		if (n[i]*n[i] < K)
			for (auto p: adjL[i])
				for (auto q: adjL[i])
					if (p < q)
						m.push_back(mp(p,q));
	
	radix_sort(m);

	ll r = 1;

	for (ll i = 0; i < int(m.size())-1; i++) {
		if (m[i] == m[i+1]) {
			r++;
			continue;
		}
		ans += r*(r-1)/2;
		r = 1;
	}
	ans += r*(r-1)/2;

	printf("%lld\n", ans);
}

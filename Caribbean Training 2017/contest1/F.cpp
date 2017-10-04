#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int inf = 1000000001;
const int maxn = 100100;
struct inp {
	int l, r, p;
} I[maxn];

int n, k, m;
ll dp[maxn];

struct node {
	int v;
	set<pii> s;
};

node tree[4*2*maxn];

void build(int n = 0, int l = 0, int r = m){
	tree[n].v = inf;
	tree[n].s.clear();

	if (l == r) return;

	build(2*n+1, l, (l+r)/2);
	build(2*n+2, (l+r)/2+1, r);
}

void update(int j, int d, int n = 0, int l = 0, int r = m){
	if (j < l || r < j) return;

	if (l == r){
		if (d > 0) tree[n].s.insert(mp(I[d].r, d));
		else tree[n].s.erase(mp(I[-d].r, -d));

		tree[n].v = tree[n].s.empty() ? inf : tree[n].s.begin()->fst;
		return;
	}

	update(j, d, 2*n+1, l, (l+r)/2);
	update(j, d, 2*n+2, (l+r)/2+1, r);
	tree[n].v = min(tree[2*n+1].v, tree[2*n+2].v);
}

int query(int x, int y, int n = 0, int l = 0, int r = m){
	if (y < l || r < x) return inf;

	if (x <= l && r <= y) return tree[n].v;

	return min(query(x, y, 2*n+1, l, (l+r)/2),
	           query(x, y, 2*n+2, (l+r)/2+1, r));
}

bool works(ll x){
	static priority_queue<pii, vector<pii>, greater<pii>> e;
	vector<ll> M;

	M.push_back(0);
	for (int i = 1; i <= n; i++){
		e.push({I[i].r+1, -i});
		M.push_back(I[i].p);
		M.push_back(x - I[i].p);
	}

	sort(M.begin(), M.end());
	M.resize(unique(M.begin(), M.end()) - M.begin());

	build();

	set<int> ends;
	vector<bool> u(n + 1);

	for (int i = 1; i <= n; i++){
		while (!e.empty() && e.top().fst < I[i].l){
			//printf("update (%d): %d\n", i, e.top().snd);
			int k = lower_bound(M.begin(), M.end(), I[abs(e.top().snd)].p) - M.begin();
			int j = e.top().snd;
			if (j > 0 || u[-j]) update(k, e.top().snd);
			u[abs(j)] = true;
			e.pop();
		}

		dp[i] = inf;

		if (I[i].p > x) continue;

		if (I[i].l == 1)
			dp[i] = -inf;
		else {
			int k = lower_bound(M.begin(), M.end(), x - I[i].p) - M.begin();
			dp[i] = query(0, k);
			if (ends.find(I[i].l-1) != ends.end())
				dp[i] = I[i].l;
		}

		if (dp[i] <= I[i].r){
			e.push({dp[i], i});
			ends.insert(I[i].r);
			if (I[i].r == k) return true;
		}
	}

	return false;
}

int main(){
	scanf("%d %d", &n, &k); m = 2 * n;

	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &I[i].l, &I[i].r, &I[i].p);

	sort(I+1, I+1+n, [=](const inp &a, const inp &b){ return a.l < b.l; });

	ll lo = 0, hi = 1LL<<31, mid;
	while (lo < hi){
		mid = (lo + hi) / 2;
		if (works(mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%lld\n", hi != (1LL<<31) ? hi : -1LL);
}

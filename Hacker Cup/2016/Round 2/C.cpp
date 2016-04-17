#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define MAXN 200200
#define mp make_pair
#define fst first
#define snd second
#define MOD 1000000007

using namespace std;

typedef long long ll;

int T, N;
pair<ll,ll> A[MAXN];

int tree[MAXN*4], g[MAXN];
ll H[MAXN], X[MAXN];

inline ll M(ll x){
	return (x % MOD + MOD) % MOD;
}

inline ll sq(ll a){
	return M(a * a);
}

void init(int n, int l, int r){
	if (l == r){
		tree[n] = H[l];
		return;
	}

	init(2*n+1, l, (l+r)/2);
	init(2*n+2, (l+r)/2+1, r);

	tree[n] = max(tree[2*n+1], tree[2*n+2]);
}

ll query(int n, int l, int r, int i, int j){
	if (j < l || i > r)
		return 0;
	else if (i <= l && r <= j)
		return tree[n];
	return max(query(2*n+1, l, (l+r)/2, i, j),
	           query(2*n+2, (l+r)/2+1, r, i, j));
}

map<ll,int> m;
vector<ll> v[MAXN];

ll sum[MAXN], dsum[MAXN], prods[MAXN], lll[MAXN], rr[MAXN];

ll choose2(int n){
	if (n < 2) return 0;
	return M(n*(n-1)/2);
}

ll f(const vector<ll> &v){
	int S = v.size();
	ll ans = 0;

	lll[S] = rr[S] = sum[S] = dsum[S] = prods[S] = 0;

	for (int i = S-1; i >= 0; i--){
		sum[i] = M(sum[i+1] + v[i]);

		if (i == S-1){
			prods[i] = dsum[i] = 0;
		} else {
			dsum[i] = M(dsum[i+1] + M((S-i-1)*(v[i+1]-v[i])));
			prods[i] = M(prods[i+1] + v[i] * sum[i+1]);
		}

		if (i+2 < S){
			lll[i] = M(lll[i+1] + (S-i-2)*v[i+1]);
			rr[i] = rr[i+1] + sum[i+2];
		} else lll[i] = rr[i] = 0;

		ans = M(ans +
		        M(M(M(M(M(sq(dsum[i])) -
			M(2*prods[i+1])) +
			M(2*v[i]*lll[i])) +
			M(2*v[i]*rr[i])) -
			M(2*choose2(S-i-1)*M(sq(v[i]))))
		      );
	}

	return ans;
}

int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		m.clear();

		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> A[i].fst >> A[i].snd;

		sort(A+1, A+1 + N);

		for (int i = 1; i <= N; i++){
			X[i] = A[i].fst;
			H[i] = A[i].snd;
		}

		init(0, 1, N);

		for (int i = 1; i <= N; i++){
			v[i].clear();

			if (m[H[i]] != 0 &&
		            query(0, 1, N, m[H[i]], i) <= H[i]){
				g[i] = g[m[H[i]]];
			} else g[i] = i;

			v[g[i]].push_back(X[i]);

			m[H[i]] = i;
		}

		ll ans = 0;
		for (int i = 1; i <= N; i++)
			if (v[i].size() > 1)
				ans = (ans + f(v[i])) % MOD;

		cout << "Case #" << t << ": " << ans << endl;
	}
}

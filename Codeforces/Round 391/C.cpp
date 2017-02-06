#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1000100;
ll b[maxn][2] = {{1, 1}, {1000003, 1000033}};
int l[maxn], h[maxn][2], cnt[maxn], p[maxn];
pair<ll,ll> e[maxn];
vector<int> s;

const ll mod = 1000000007;
ll f[maxn];

ll inv(ll x){
	ll r = 1, e = mod-2;

	for (; e; e /= 2){
		if (e % 2)
			r = (r * x) % mod;
		x = (x * x) % mod;
	}

	return r;
}

ll choose(int n, int k){
	return f[n] * inv(f[k]) % mod * inv(f[n-k]) % mod;
}

int n, m;

int main(){
	f[0] = f[1] = 1;
	for (int i = 2; i < maxn; i++)
		f[i] = (f[i-1] * i) % mod;

	for (int i = 2; i < maxn; i++)
		for (int j = 0; j < 2; j++)
			b[i][j] = b[i-1][j] * b[1][j];

	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		int g;
		cin >> g;

		for (int j = 0; j < g; j++){
			cin >> p[j];
			cnt[p[j]]++;
		}

		for (int j = 0; j < g; j++){
			if (cnt[p[j]] == 0) continue;

			for (int k = 0; k < 2; k++){
				h[p[j]][k] *= b[i - l[p[j]]][k];
				h[p[j]][k] += cnt[p[j]];
				l[p[j]] = i;
			}

			cnt[p[j]] = 0;
		}
	}

	for (int i = 1; i <= m; i++){
		for (int j = 0; j < 2; j++)
			h[i][j] *= b[n - l[i]][j];
		e[i] = make_pair(h[i][0], h[i][1]);
	}

	sort(e+1, e+1+m);

	int last = 0;
	for (int i = 1; i <= m; i++)
		if (e[i] != e[i-1]){
			s.push_back(i - last);
			last = i;
		}
	if (last != m)
		s.push_back(m+1-last);

	ll ans = 1;
	for (auto w: s){
		ans = (ans * f[w]) % mod;
	}

	cout << ans << endl;
}

#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

class SubtreeSumHash {
	int ans = 0, x;
	const ll MOD = 1000000007;
	vector<int> w, adj[100];

	ll exp(ll b, ll e){
		ll r = 1;

		for (; e; e /= 2){
			if (e % 2)
				r = (r * b) % MOD;
			b = (b * b) % MOD;
		}

		return r;
	}

	ll go(int n){
		ll ret = exp(x, w[n]);

		for (auto w: adj[n])
			ret = (ret * (go(w) + 1)) % MOD;

		ans = (ans + ret) % MOD;

		return ret;
	}

public:
	int count(vector<int> _w, vector<int> _p, int _x){
		w = _w; x = _x;

		for (int i = 0; i < _p.size(); i++)
			adj[_p[i]].push_back(i+1);

		go(0);

		return (ll)ans;
	}
};

#ifdef LOCAL
int main(){
	SubtreeSumHash s;
	printf("%d\n", s.count({1,2,3}, {0,1}, 10));
}
#endif

#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

typedef long long ll;

const int maxc = 1010;

int T;
ll R, B, C;
ll M[maxc], S[maxc], P[maxc];

bool works(ll x){
	static vector<ll> v;

	v.clear();

	for (int i = 0; i < C; i++)
		if (x > P[i])
			v.push_back(min(M[i], (x - P[i])/S[i]));

	sort(v.begin(), v.end(), greater<ll>());

	ll rem = B;

	for (int i = 0; i < min(R, (ll)v.size()) && rem > 0; i++)
		rem -= v[i];

	return rem <= 0;
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%lld %lld %lld", &R, &B, &C);

		for (int i = 0; i < C; i++)
			scanf("%lld %lld %lld", &M[i], &S[i], &P[i]);

		ll lo = 0, hi = 1LL<<50, mid;

		while (lo < hi){
			mid = (lo + hi) / 2;
			if (works(mid))
				hi = mid;
			else
				lo = mid + 1;
		}

		printf("Case #%d: %lld\n", t, hi);
	}
}

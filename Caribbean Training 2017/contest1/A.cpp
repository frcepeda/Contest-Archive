#include <cstdio>
#include <algorithm>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

typedef long long ll;
typedef pair<ll, int> pll;

using namespace __gnu_pbds;
typedef tree<pll, null_type, greater<pll>, rb_tree_tag,
	tree_order_statistics_node_update> ost;

int n;
ll L;

int main(){
	scanf("%d %lld", &n, &L);

	ll ans = 0;

	ost T;

	for (int i = 1; i <= n; i++){
		ll x, t;
		scanf("%lld", &x);
		t = i + L * x;
		pll p = make_pair(t, i);
		ans += T.order_of_key(p);
		T.insert(p);
	}

	printf("%lld\n", ans);
}

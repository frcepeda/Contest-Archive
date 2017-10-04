#include <cstdio>
#include <algorithm>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

typedef long long ll;
typedef pair<int, int> pii;

using namespace __gnu_pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
	tree_order_statistics_node_update> ost;

#define mp make_pair

const int maxn = 100100;
int n, m, a[maxn];
ost t[4*maxn];

void build(int x = 0, int l = 1, int r = n){
	if (l == r){
		t[x] = ost();
		t[x].insert(mp(a[l], l));
		return;
	}

	build(2*x+1, l, (l+r)/2);
	build(2*x+2, (l+r)/2+1, r);

	t[x] = ost(t[2*x+1]);
	for (auto z: t[2*x+2])
		t[x].insert(z);
}

void update(int i, int b, int x = 0, int l = 1, int r = n){
	if (i < l || r < i) return;

	t[x].erase(mp(a[i], i));
	t[x].insert(mp(b, i));

	if (l == r){
		a[i] = b;
		return;
	}

	update(i, b, 2*x+1, l, (l+r)/2);
	update(i, b, 2*x+2, (l+r)/2+1, r);
}

int query(int a, int b, int k, int x = 0, int l = 1, int r = n){
	if (b < l || r < a) return 0;

	if (a <= l && r <= b)
		return t[x].order_of_key(mp(k+1, 0));

	return query(a, b, k, 2*x+1, l, (l+r)/2) +
	       query(a, b, k, 2*x+2, (l+r)/2+1, r);
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	build();

	while (m--){
		char op[5];
		int x, y, k, l;
		scanf("%s", op);

		if (op[0] == 'S'){
			scanf("%d %d", &x, &y);
			update(x, y);
		} else {
			scanf("%d %d %d %d", &x, &y, &k, &l);
			printf("%d\n", query(x, y, l) - query(x, y, k-1));
		}
	}
}

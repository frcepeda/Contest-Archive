#include <cstdio>
#include <algorithm>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

typedef long long ll;
typedef pair<int, int> pii;

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ostg;
typedef tree<int, null_type, greater<int>, rb_tree_tag,
	tree_order_statistics_node_update> ostl;

const int maxn = 1000100;
int n, a[maxn], l[maxn], r[maxn];
ostl tl; ostg tr;

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++){
		l[i] = tl.order_of_key(a[i]);
		tl.insert(a[i]);
	}

	for (int i = n; i >= 1; i--){
		r[i] = tr.order_of_key(a[i]);
		tr.insert(a[i]);
	}

	int a = 0, b = 0;
	for (int i = 1; i <= n; i++)
		if (l[i] >= l[a])
			a = i;
	for (int i = n; i >= 1; i--)
		if (r[i] >= r[b])
			b = i;

	if (l[a] == 0)
		printf("-1 -1\n");
	else
		printf("%d %d\n", b, a);
}

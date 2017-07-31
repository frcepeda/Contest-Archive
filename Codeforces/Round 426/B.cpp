#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 35100;
const int maxk = 52;

int n, k;
int a[maxn], r[maxn], ii[maxn];
int dp[maxk][maxn];
int tree[4*maxn], down[4*maxn];

void push(int x, bool leaf){
	if (down[x]){
		tree[x] += down[x];
		if (!leaf) down[2*x+1] += down[x];
		if (!leaf) down[2*x+2] += down[x];
		down[x] = 0;
	}
}

void build(int x = 0, int l = 0, int r = n){
	if (l == r){
		tree[x] = down[x] = 0;
		return;
	}
	tree[x] = down[x] = 0;
	build(2*x+1, l, (l+r)/2);
	build(2*x+2, (l+r)/2+1, r);
}

int query(int a, int b, int x = 0, int l = 0, int r = n){
	push(x, l == r);

	if (b < l || a > r)
		return -(1<<29);

	if (a <= l && r <= b)
		return tree[x];

	return max(query(a, b, 2*x+1, l, (l+r)/2),
	           query(a, b, 2*x+2, (l+r)/2+1, r));
}

void update(int a, int b, int v, int x = 0, int l = 0, int r = n){
	push(x, l == r);

	if (b < l || a > r) return;

	if (a <= l && r <= b){
		down[x] = v;
		push(x, l == r);
		return;
	}

	update(a, b, v, 2*x+1, l, (l+r)/2);
	update(a, b, v, 2*x+2, (l+r)/2+1, r);

	tree[x] = max(tree[2*x+1], tree[2*x+2]);
}

int main(){
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		ii[i+1] = -1;
	}

	for (int i = n-1; i >= 0; i--){
		r[i] = ii[a[i]] >= 0 ? ii[a[i]] : n;
		ii[a[i]] = i;
		dp[0][i] = -(1<<29);
	}

	for (int j = 1; j <= k; j++){
		build();
		for (int i = n-1; i >= 0; i--){
			update(i+1, r[i], 1);
			dp[j][i] = query(i+1, n);
			update(i, i, dp[j-1][i]);
		}
	}

	printf("%d\n", dp[k][0]);
}

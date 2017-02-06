#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

struct cnt {
	int c[26];
};

const ll inv2 = 500000004;
const ll mod = 1000000007;
const int maxn = 100010;
int N, q;
cnt tree[4 * maxn];
char str[maxn];
ll f[maxn], g[maxn];

void build(int n, int l, int r){
	if (l == r){
		tree[n].c[str[l]-'a']++;
		return;
	}

	build(2*n+1, l, (l+r)/2);
	build(2*n+2, (l+r)/2+1, r);

	for (int i = 0; i < 26; i++)
		tree[n].c[i] = tree[2*n+1].c[i] + tree[2*n+2].c[i];
}

void shift(const int n, const int i, const int j, const int t, const int l = 0, const int r = N-1){
	if (j < l || r < i) return;

	if (i <= l && r <= j){
		int tmp[26];
		for (int i = 0; i < 26; i++)
			tmp[i] = tree[n].c[i];
		for (int i = 0; i < 26; i++)
			tree[n].c[(i+t)%26] = tmp[i];
		return;
	}

	shift(2*n+1, i, j, t, l, (l+r)/2);
	shift(2*n+2, i, j, t, (l+r)/2+1, r);

	for (int i = 0; i < 26; i++)
		tree[n].c[i] = tree[2*n+1].c[i] + tree[2*n+2].c[i];
}

cnt range(const int n, const int i, const int j, const int l = 0, const int r = N-1){
	cnt ret = {.c = {0}};

	if (j < l || r < i) return ret;
	if (i <= l && r <= j) return tree[n];

	cnt a = range(2*n+1, i, j, l, (l+r)/2);
	cnt b = range(2*n+2, i, j, (l+r)/2+1, r);

	for (int i = 0; i < 26; i++)
		ret.c[i] = a.c[i] + b.c[i];

	return ret;
}

ll go(const cnt &c, int k){
	ll ret = 1;

	for (int i = 0; i < 26; i++){
		if (i != k)
			ret = ret * f[c.c[i]] % mod;
		else
			ret = ret * g[c.c[i]] % mod;
	}

	return (ret % mod + mod) % mod;
}

int query(int i, int j){
	cnt c = range(0, i, j);

	ll ans = go(c, 26);

	for (int i = 0; i < 26; i++)
		if (c.c[i])
			ans = (ans + go(c, i)) % mod;

	return (ans - 1 + mod) % mod;
}

int main(){
	scanf("%d %d", &N, &q);
	scanf("%s", str);

	build(0, 0, N-1);

	f[0] = 1;
	f[1] = 1;
	g[0] = 0;
	g[1] = 1;
	for (int i = 2; i < maxn; i++){
		f[i] = (f[i-1] + g[i-1]) % mod;
		g[i] = (f[i-1] + g[i-1]) % mod;
	}

	while (q--){
		int k, t, i, j;

		scanf("%d", &k);

		if (k == 1){
			scanf("%d %d %d", &i, &j, &t);
			shift(0, i, j, t);
		} else {
			scanf("%d %d", &i, &j);
			printf("%d\n", query(i, j));
		}
	}
}

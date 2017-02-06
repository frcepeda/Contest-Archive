#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int p[maxn], m[maxn], M[maxn];
bool v[maxn];
int n, q;

int query(int x){
	if (v[x]) return M[x] - m[x];
	v[x] = true;
	query(p[x]);
	m[x] = min(m[p[x]], m[x]);
	M[x] = max(M[p[x]], M[x]);
	return M[x] - m[x];
}

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		int x, l, r;
		scanf("%d %d %d", &x, &l, &r);
		m[i] = M[i] = x;
		p[l] = p[r] = i;
	}

	v[0] = true;

	scanf("%d", &q);

	while (q--){
		int x;
		scanf("%d", &x);
		printf("%d\n", query(x));
	}
}

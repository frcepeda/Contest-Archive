#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
	int v;
	node *l, *r;
};

typedef node * pnode;

const int maxn = 200100;
int n, m, q, a[maxn];
node sto[30*maxn];
int nextsto;

pnode build(int l, int r){
	if (l == r){
		sto[nextsto].l = sto[nextsto].r = NULL;
		return &sto[nextsto++];
	}

	pnode n = &sto[nextsto++];

	n->l = build(l, (l+r)/2);
	n->r = build((l+r)/2+1, r);
	return n;
}

pnode update(pnode n, int l, int r, int i, int x){
	if (i < l || r < i) return n;

	if (l == r){
		sto[nextsto].v = n->v + x;
		sto[nextsto].l = sto[nextsto].r = NULL;
		return &sto[nextsto++];
	}

	pnode nn = &sto[nextsto++];
	nn->l = update(n->l, l, (l+r)/2, i, x);
	nn->r = update(n->r, (l+r)/2+1, r, i, x);
	nn->v = nn->l->v + nn->r->v;
	return nn;
}

int query(pnode n, int l, int r, int x, int y){
	if (y < l || r < x) return 0;

	if (x <= l && r <= y) return n->v;

	return query(n->l, l, (l+r)/2, x, y) +
	       query(n->r, (l+r)/2+1, r, x, y);
}

pnode t[maxn];
int last[maxn];

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	t[n] = build(0, n);

	for (int i = n-1; i >= 0; i--){
		t[i] = t[i+1];

		if (last[a[i]])
			t[i] = update(t[i], 0, n, last[a[i]], -1);
		t[i] = update(t[i], 0, n, i, 1);

		last[a[i]] = i;
	}

	scanf("%d", &q);

	int p = 0;
	for (int i = 0; i < q; i++){
		int x, y, l, k;
		scanf("%d %d", &x, &y);
		l = (x + p) % n;
		k = ((y + p) % m) + 1;

		int lo = l, hi = n-1, mid;

		while (lo < hi){
			mid = (lo + hi)/2;
			if (query(t[l], 0, n, l, mid) >= k)
				hi = mid;
			else
				lo = mid + 1;
		}

		p = query(t[l], 0, n, l, hi) >= k ? hi+1 : 0;
		printf("%d\n", p);
	}
}

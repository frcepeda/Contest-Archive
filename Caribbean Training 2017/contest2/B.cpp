#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
	int v;
	node *l, *r;
};

typedef node * pnode;

const int maxn = 200100;
int n, m;
node sto[20*maxn];
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
		sto[nextsto].v = x;
		sto[nextsto].l = sto[nextsto].r = NULL;
		return &sto[nextsto++];
	}

	pnode nn = &sto[nextsto++];
	nn->l = update(n->l, l, (l+r)/2, i, x);
	nn->r = update(n->r, (l+r)/2+1, r, i, x);
	return nn;
}

int query(pnode n, int l, int r, int x){
	if (l == r) return n->v;

	if (x <= (l+r)/2)
		return query(n->l, l, (l+r)/2, x);
	return query(n->r, (l+r)/2+1, r, x);
}

pnode t[maxn];
int qs[maxn], qe[maxn];

int main(){
	scanf("%d", &n);

	t[0] = build(0, maxn);

	for (int i = 1; i <= n; i++){
		int o, x, y;

		scanf("%d", &o);

		if (o == 1){
			scanf("%d %d", &x, &y);
			t[i] = update(t[x], 0, maxn, qe[x], y);
			qs[i] = qs[x];
			qe[i] = qe[x] + 1;
		} else {
			scanf("%d", &x);
			printf("%d\n", query(t[x], 0, maxn, qs[x]));
			t[i] = t[x];
			qs[i] = qs[x] + 1;
			qe[i] = qe[x];
		}
	}
}

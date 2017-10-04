#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
	int v;
	node *l, *r;
};

typedef node * pnode;

const int maxn = 100100;
int n, m, a[maxn];
node sto[20*maxn];
int nextsto;

pnode build(int l, int r){
	if (l == r){
		sto[nextsto].v = a[l];
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

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	t[1] = build(1, n);

	scanf("%d", &m);

	int curr = 1;

	while (m--){
		char op[10];
		int i, x, y;
		scanf("%s", op);

		if (op[0] == 'c'){
			scanf("%d %d %d", &i, &x, &y);
			t[++curr] = update(t[i], 1, n, x, y);
		} else {
			scanf("%d %d", &i, &x);
			printf("%d\n", query(t[i], 1, n, x));
		}
	}
}

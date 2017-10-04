#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct node {
	int uniq, diff, sum;
	const node *l, *r;
};

typedef node * pnode;
typedef const node * cpnode;

const int maxn = 300010;
const int maxm = 300010;
int n, m;

cpnode build(int l, int r){
	pnode n = new node;
	n->uniq = n->diff = n->sum = 0;
	n->l = n->r = NULL;

	if (l == r) return n;

	n->l = build(l, (l+r)/2);
	n->r = build((l+r)/2+1, r);

	return n;
}

cpnode update(cpnode n, int l, int r, int i, int x){
	if (i < l || r < i) return n;

	pnode nn = new node;

	if (l == r){
		nn->sum = max(0, n->sum + x);
		nn->uniq = nn->sum == 1;
		nn->diff = nn->sum >= 1;
		nn->l = nn->r = NULL;
		return nn;
	}

	nn->l = update(n->l, l, (l+r)/2, i, x);
	nn->r = update(n->r, (l+r)/2+1, r, i, x);

	nn->sum = nn->l->sum + nn->r->sum;
	nn->uniq = nn->l->uniq + nn->r->uniq;
	nn->diff = nn->l->diff + nn->r->diff;

	return nn;
}

int query(cpnode n, int l, int r, int x){
	if (l == r) return n->sum;

	if (x <= (l+r)/2)
		return query(n->l, l, (l+r)/2, x);
	return query(n->r, (l+r)/2+1, r, x);
}

cpnode t[maxn];

int main(){
	scanf("%d %d", &n, &m);

	assert(n <= maxn && m <= maxm);

	t[0] = build(0, maxm);

	long long s = 0;
	for (int i = 1; i <= n; i++){
		char op[20];
		int y, v, x;
		scanf("%s", op);

		if (op[0] == 'a'){
			scanf("%d", &x);
			t[i] = update(t[i-1], 0, maxm, x, 1);
		} else if (op[0] == 'r'){
			scanf("%d", &x);
			t[i] = update(t[i-1], 0, maxm, x, -1);
		} else if (op[0] == 'd'){
			scanf("%d", &y);
			v = (y + s) % i;
			t[i] = t[i-1];
			s += t[v]->diff;
			printf("%d\n", t[v]->diff);
		} else if (op[0] == 'u'){
			scanf("%d", &y);
			v = (y + s) % i;
			t[i] = t[i-1];
			s += t[v]->uniq;
			printf("%d\n", t[v]->uniq);
		} else { // c
			scanf("%d %d", &x, &y);
			v = (y + s) % i;
			t[i] = t[i-1];
			int ans = query(t[v], 0, maxm, x);
			s += ans;
			printf("%d\n", ans);
		}
	}
}

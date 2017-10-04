#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

#define mp make_pair

const int maxn = 100100;
int n, m;

struct query {
	int l, r, k;
};

query q[maxn];

struct node {
	int v, p;
	bool pending;
};

node t[4*maxn];

void push(int x){
	if (t[x].pending){
		if (2*x+1 < 4*maxn){
			t[2*x+1].p = max(t[x].p, t[2*x+1].p);
			t[2*x+1].pending = true;
		}

		if (2*x+2 < 4*maxn){
			t[2*x+2].p = max(t[x].p, t[2*x+2].p);
			t[2*x+2].pending = true;
		}

		t[x].v = max(t[x].p, t[x].v);
		t[x].p = INT_MIN;
		t[x].pending = false;
	}
}

void build(int x = 0, int l = 1, int r = n){
	t[x].p = t[x].v = INT_MIN;

	if (l == r) return;

	build(2*x+1, l, (l+r)/2);
	build(2*x+2, (l+r)/2+1, r);
}

void update(int i, int j, int b, int x = 0, int l = 1, int r = n){
	push(x);

	if (j < l || r < i) return;

	if (i <= l && r <= j){
		t[x].pending = true;
		t[x].p = b;
		push(x);
		return;
	}

	update(i, j, b, 2*x+1, l, (l+r)/2);
	update(i, j, b, 2*x+2, (l+r)/2+1, r);
	t[x].v = min(t[2*x+1].v, t[2*x+2].v);
}

int query(int a, int b, int x = 0, int l = 1, int r = n){
	push(x);

	if (b < l || r < a) return INT_MAX;

	if (a <= l && r <= b)
		return t[x].v;

	return min(query(a, b, 2*x+1, l, (l+r)/2),
	           query(a, b, 2*x+2, (l+r)/2+1, r));
}

int main(){
	scanf("%d %d", &n, &m);

	build();

	for (int i = 0; i < m; i++){
		scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].k);
		update(q[i].l, q[i].r, q[i].k);
	}

	int i;
	for (i = 0; i < m; i++)
		if (query(q[i].l, q[i].r) != q[i].k)
			break;

	if (i < m){
		printf("inconsistent\n");
	} else {
		printf("consistent\n");
		for (int i = 1; i <= n; i++)
			printf("%d%c", query(i,i), i < n ? ' ' : '\n');
	}
}

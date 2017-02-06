#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
	int plus, minus;
};

const int maxm = 100100;
int m, v[maxm];
node tree[4*maxm];

void update(int n, int l, int r, int i, int x){
	if (i < l || i > r) return;

	if (l == r){
		tree[n].plus = x > 0;
		tree[n].minus = x < 0;
		return;
	}

	update(2*n+1, l, (l+r)/2, i, x);
	update(2*n+2, (l+r)/2+1, r, i, x);

	int lr = min(tree[2*n+1].plus, tree[2*n+2].minus);
	tree[n].plus = tree[2*n+1].plus + tree[2*n+2].plus - lr;
	tree[n].minus = tree[2*n+1].minus + tree[2*n+2].minus - lr;
}

int top(int n = 0, int l = 1, int r = m, int k = 0){
	if (tree[n].plus - k <= 0)
		return -1;
	if (l == r)
		return v[l];

	if (tree[2*n+2].plus - k > 0)
		return top(2*n+2, (l+r)/2+1, r, k);
	else
		return top(2*n+1, l, (l+r)/2, k + tree[2*n+2].minus - tree[2*n+2].plus);
}

int main(){
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++){
		int p, t, x;

		scanf("%d %d", &p, &t);

		if (t == 1)
			scanf("%d", &x);
		else x = -1;

		v[p] = x;
		update(0, 1, m, p, x);

		printf("%d\n", top());
	}
}

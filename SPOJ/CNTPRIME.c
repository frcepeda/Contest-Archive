#include <stdio.h>
#include <stdbool.h>

#define MAXN 100010
#define MAXP 1000100

typedef struct {
	int count;
	bool notUpdated;
} node;

node tree[MAXN*3];
int T, N, Q;
int seq[MAXN];
bool notPrime[MAXP] = {true,true};

#define childA(a) ((a)*2+1)
#define childB(a) ((a)*2+2)

void init(int node, int start, int end){
	tree[node].notUpdated = false;

	if (start == end){
		tree[node].count = !notPrime[seq[start]];
		return;
	}

	init(childA(node), start, (start+end)/2);
	init(childB(node), (start+end)/2+1, end);

	tree[node].count = tree[childA(node)].count + tree[childB(node)].count;
}

void updateNode(int node, int start, int end){
	tree[node].notUpdated = false;

	tree[childA(node)].count = (!!tree[node].count) * ((start+end)/2 - start + 1);
	tree[childA(node)].notUpdated = true;

	tree[childB(node)].count = (!!tree[node].count) * (end - (start+end)/2);
	tree[childB(node)].notUpdated = true;
}

void update(int node, int start, int end, int a, int b, int v){
	if (a > end || b < start)
		return;

	if (a <= start && end <= b){
		tree[node].count = !notPrime[v] * (end - start + 1);
		tree[node].notUpdated = true;
		return;
	}

	if (tree[node].notUpdated)
		updateNode(node, start, end);

	update(childA(node), start, (start+end)/2, a, b, v);
	update(childB(node), (start+end)/2+1, end, a, b, v);

	tree[node].count = tree[childA(node)].count + tree[childB(node)].count;
}

int query(int node, int start, int end, int a, int b){
	if (a > end || b < start)
		return 0;
	
	if (a <= start && end <= b)
		return tree[node].count;
	
	if (tree[node].notUpdated)
		updateNode(node, start, end);

	return query(childA(node), start, (start+end)/2, a, b) + query(childB(node), (start+end)/2+1, end, a, b);
}

int main(void){
	int i, j, t;

	for (i = 4; i < MAXP; i += 2)
		notPrime[i] = true;

	for (i = 3; i < 1010; i += 2)
		if (!notPrime[i])
			for (j = i * i; j < MAXP; j += i)
				notPrime[j] = true;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		printf("Case %d:\n", t);

		scanf("%d %d", &N, &Q);
		for (i = 0; i < N; i++)
			scanf("%d", &seq[i]);

		init(0, 0, N-1);

		while (Q--){
			int a, x, y, v;
			scanf("%d", &a);
			if (a == 0){
				scanf("%d %d %d", &x, &y, &v);
				update(0, 0, N-1, x-1, y-1, v);
			} else {
				scanf("%d %d", &x, &y);
				printf("%d\n", query(0, 0, N-1, x-1, y-1));
			}
		}
	}

	return 0;
}

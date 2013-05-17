#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAXTREE (1<<18)

#define childA(a) ((a)*2+1)
#define childB(a) ((a)*2+2)

typedef struct {
	bool pendingChange;
	int count;
} node;

node tree[MAXTREE];
int N, M, A, B;

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

void update(int node, int nS, int nE, int start, int end){
	assert(tree[node].count >= 0);

	if (start > nE || end < nS) return;

	if (start <= nS && nE <= end){
		tree[node].pendingChange ^= true;
		tree[node].count = (nE - nS + 1) - tree[node].count;
		return;
	}

	if (tree[node].pendingChange){
		tree[node].pendingChange = false;

		tree[childA(node)].pendingChange ^= true;
		tree[childA(node)].count = ((nS+nE)/2 - nS + 1) - tree[childA(node)].count;

		tree[childB(node)].pendingChange ^= true;
		tree[childB(node)].count = (nE - (nS+nE)/2) - tree[childB(node)].count;
	}

	update(childA(node), nS, (nS+nE)/2, start, end);
	update(childB(node), (nS+nE)/2+1, nE, start, end);

	tree[node].count = tree[childA(node)].count + tree[childB(node)].count;
}

int query(int node, int nS, int nE, int start, int end){
	if (start > nE || end < nS)
		return 0;

	if (start <= nS && nE <= end)
		return tree[node].count;

	if (tree[node].pendingChange){
		tree[node].pendingChange = false;

		tree[childA(node)].pendingChange ^= true;
		tree[childA(node)].count = ((nS+nE)/2 - nS + 1) - tree[childA(node)].count;

		tree[childB(node)].pendingChange ^= true;
		tree[childB(node)].count = (nE - (nS+nE)/2) - tree[childB(node)].count;
	}

	return query(childA(node), nS, (nS+nE)/2, start, end) +
	       query(childB(node), (nS+nE)/2+1, nE, start, end);
}

int main(void){
	int k;

	scanf("%d %d", &N, &M);

	while (M--){
		scanf("%d %d %d", &k, &A, &B);

		if (k == 0){
			update(0,0,N-1,A-1,B-1);
		} else {
			printf("%d\n", query(0,0,N-1,A-1,B-1));
		}
	}

	return 0;
}
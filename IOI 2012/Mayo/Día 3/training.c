#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXNUM 2000
#define MAXDEGREE 10

int max(int a, int b){
	return a > b ? a : b;
}

typedef struct {
	int up, mask;
} parent;

parent makeParent(int up, int mask){
	parent p = {up, mask};
	return p;
}

typedef struct {
	int node, next;
} treeNode;

typedef struct {
	int a, b, cost, LCA;
} edge;

int preorder[MAXNUM];

int edgeCmp(const void *ap, const void *bp){
	edge *a = (edge *)ap;
	edge *b = (edge *)bp;

	if (preorder[a->LCA] > preorder[b->LCA])
		return 1;
	else if (preorder[a->LCA] < preorder[b->LCA])
		return -1;
	else
		return 0;
}

edge E[MAXNUM*MAXDEGREE/2];

int nodeNum, roadNum;

int totalCost;

int lastIndex;

int depth[MAXNUM];
int degree[MAXNUM];

bool isEven[MAXNUM];

parent parents[MAXNUM];

treeNode tree[MAXNUM];
int start[MAXNUM];
int nextTree = 1;

void addEdge(int from, int to){
	tree[nextTree].next = start[from];
	start[from] = nextTree;
	tree[nextTree++].node = to;
}

int DP[MAXNUM][1<<MAXDEGREE];

void dfs(int a){
	int curr;
	lastIndex++;
	for (curr = start[a]; curr != 0; curr = tree[curr].next){
		if (tree[curr].node == parents[a].up)
			continue;
		
		isEven[tree[curr].node] = isEven[a] ^ true;
		depth[tree[curr].node] = depth[a] + 1;
		parents[tree[curr].node] = makeParent(a, 1 << (degree[a]++));

		dfs(tree[curr].node);
	}
	preorder[a] = ++lastIndex;
}

void LCA(void){
	int i;
	for (i = 0; i < roadNum; i++){
		int a = E[i].a;
		int b = E[i].b;

		while (depth[a] > depth[b])
			a = parents[a].up;

		while (depth[b] > depth[a])
			b = parents[b].up;

		while (a != b) { 
			a = parents[a].up;
			b = parents[b].up;
		}

		E[i].LCA = a;
	}
}

void dp(void){
	parent A, B;
	int mask, i;

	for (i = 0; i < roadNum; i++) {
		if (E[i].cost && isEven[E[i].a] != isEven[E[i].b])
			continue;

		int LCA = E[i].LCA;
		int sum = E[i].cost;
		
		for (A = makeParent(E[i].a, 0); A.up != LCA; A = parents[A.up])
			sum += DP[A.up][A.mask];

		for (B = makeParent(E[i].b, 0); B.up != LCA; B = parents[B.up])
			sum += DP[B.up][B.mask];

		for (mask = (1 << degree[LCA]) - 1; mask >= 0; mask--) 
			if( !(mask & A.mask || mask & B.mask) ) 
				DP[LCA][mask] = max(DP[LCA][mask], sum + DP[LCA][mask | A.mask | B.mask]);
	}
}

int main(void){
	int i;

	scanf("%d %d", &nodeNum, &roadNum);

	for (i = 0; i < roadNum; i++) {
		scanf("%d %d %d", &E[i].a, &E[i].b, &E[i].cost );

		E[i].a--; E[i].b--;
		
		if(!E[i].cost) {
			addEdge(E[i].a, E[i].b);
			addEdge(E[i].b, E[i].a);
		} else {
			totalCost += E[i].cost;
		}
	}

	dfs(0);

	LCA();

	qsort(E, roadNum, sizeof(edge), edgeCmp);

	dp();

	printf("%d\n", totalCost - DP[0][0]);
	return 0;
}


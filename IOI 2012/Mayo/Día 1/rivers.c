#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int min (int a, int b) { return a < b ? a : b; }

#define INFINITY (1<<30)
#define MAXNODES 300
#define MAXSAWMILLS 60

typedef struct {
	int children[MAXNODES];
	int childNum;
	int trees, distance;
} node;

typedef struct {
	int node, sum;
} state;

node tree[MAXNODES];
node graph[MAXNODES];
int nextNode = 1;
int nextFakeNode;

int nodeNum, sawmills;

int cost[MAXNODES][MAXNODES];

void precomputeCosts(int node){
	state queue[MAXNODES];
	int qs = 0, qe = 1;

	queue[0].node = node;
	queue[0].sum = 0;

	while (qs < qe){
		state curr = queue[qs++];

		int i;
		for (i = 0; i < tree[curr.node].childNum; i++){
			state next = {tree[curr.node].children[i], curr.sum};
			next.sum += tree[next.node].distance;

			cost[node][next.node] = next.sum * tree[next.node].trees;

			queue[qe++] = next;
		}
	}

}

int dp[MAXNODES][MAXSAWMILLS][MAXNODES];
bool visited[MAXNODES][MAXSAWMILLS][MAXNODES];

int f(int curr, int remaining, int lastSawmill){
	if (visited[curr][remaining][lastSawmill])
		return dp[curr][remaining][lastSawmill];
	visited[curr][remaining][lastSawmill] = true;

	int answer = INFINITY;

	int i, use, left, right, extra = cost[lastSawmill][curr];

	for (use = 0; use <= !!remaining; use++){
		for (i = 0; i <= remaining - use; i++){
			if (tree[curr].children[0]){
				left = f(tree[curr].children[0], i, use ? curr : lastSawmill);
			} else {
				left = 0;
			}

			if (tree[curr].children[1]){
				right = f(tree[curr].children[1], remaining - use - i, use ? curr : lastSawmill);
			} else {
				right = 0;
			}
			
			answer = min(answer, left + right + (use ? 0 : extra));
		}
	}

	assert(answer < INFINITY);
	return dp[curr][remaining][lastSawmill] = answer;
}

int main(void){
	int i;

	scanf("%d %d", &nodeNum, &sawmills);
	nextFakeNode = nodeNum + 1;

	for (i = 1; i <= nodeNum; i++){
		int trees, distance, parent;
		scanf("%d %d %d", &trees, &parent, &distance);

		graph[parent].children[graph[parent].childNum++] = i;
		graph[i].trees = trees;
		graph[i].distance = distance;
	}

	for (i = 0; i <= nodeNum; i++){
		tree[i] = graph[i];
		if (graph[i].childNum <= 2){
			tree[i].children[0] = graph[i].children[0];
			tree[i].children[1] = graph[i].children[1];
		} else {
			int j;
			tree[i].childNum = 2;
			tree[i].children[0] = graph[i].children[0];
			tree[i].children[1] = nextFakeNode;
			for (j = 1; j < graph[i].childNum - 1; j++) {
				tree[nextFakeNode].childNum = 2;
				tree[nextFakeNode].children[0] = graph[i].children[j];
				tree[nextFakeNode].children[1] = nextFakeNode+1;
				nextFakeNode++;
			}
			tree[nextFakeNode-1].children[1] = graph[i].children[j];
		}
	}

	nodeNum = nextFakeNode;

	for (i = 0; i < nodeNum; i++){
		precomputeCosts(i);
	}

	printf("%d\n", f(0,sawmills,0));

	return 0;
}


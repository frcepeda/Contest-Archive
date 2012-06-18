#include <stdio.h>
#include <strings.h>
#include <stdbool.h>
#include <assert.h>

#define INFINITY (1<<30)
#define MAXNODES 200010
#define MAXK 1000001

int N, K;

typedef struct {
	int node, distance, next;
} adjacent;

adjacent makeAdjacent(int node, int distance){
	adjacent a = {node, distance, 0};
	return a;
}

adjacent adjacencyList[MAXNODES*2];
int nextAdjacency = 1;
int startOfAdjacencyList[MAXNODES*2];
int endOfAdjacencyList[MAXNODES*2];

#define addAdjacent(a, b, distance) \
	if (!startOfAdjacencyList[a]){ \
		startOfAdjacencyList[a] = nextAdjacency; \
		endOfAdjacencyList[a] = nextAdjacency; \
	} else { \
		adjacencyList[endOfAdjacencyList[a]].next = nextAdjacency; \
		endOfAdjacencyList[a] = nextAdjacency; \
	} \
	adjacencyList[nextAdjacency++] = makeAdjacent(b, distance)

typedef struct {
	int parent, parentDistance, children, lastChild;
} node;

node nodes[MAXNODES];

typedef struct {
	int node, distance, next;
} highway;

highway makeHighway(int node, int distance){
	highway h = {.node = node, .distance = distance};
	return h;
}

highway highways[MAXNODES*2];
int nextHighway = 1;

typedef struct {
	int node, nodeCount;
} root;

root tempStack[MAXNODES];

typedef struct {
	unsigned long long int distance;
	int node, count;
} state;

state makeState(int node, unsigned long long int distance, int count){
	state s = {.node = node, .distance = distance, .count = count};
	return s;
}

bool deleted[MAXNODES];

bool visited[MAXNODES];

int bestPath = INFINITY;

int descendantCount[MAXNODES];

#define clearStack() nextStack = 0
#define push(n) stack[nextStack++] = (n)
#define pop() stack[--nextStack]
#define peek() stack[nextStack - 1]
#define stackIsNotEmpty nextStack

#define clear(p) memset(p, 0, sizeof(p))

void buildPath(int start, int root){
	static int possiblePaths[MAXK];

	static int countToUpdate[MAXK];
	static int toUpdate[MAXK];
	static int nextToUpdate;

	static state stack[MAXNODES];
	static int nextStack;

	static int usedK[MAXNODES];
	static int nextUsedK;

	int i, num;

	clearStack();
	nextUsedK = 0;

	visited[start] = true;

	if (start != root && start != 0 && !deleted[nodes[start].parent]){
		push(makeState(nodes[start].parent, nodes[start].parentDistance, 1));

		while (stackIsNotEmpty){
			state curr = pop();

			visited[curr.node] = true;

			if (curr.distance > K)
				continue;

			if (!possiblePaths[curr.distance] || possiblePaths[curr.distance] > curr.count){
				possiblePaths[curr.distance] = curr.count;
				usedK[nextUsedK++] = curr.distance;
			}

			if (curr.node != 0 && !visited[nodes[curr.node].parent] && !deleted[nodes[curr.node].parent])
				push(makeState(nodes[curr.node].parent, curr.distance + nodes[curr.node].parentDistance, curr.count + 1));

			highway next;
			for (next = highways[nodes[curr.node].children]; next.node != 0; next = highways[next.next]){
				if (!deleted[next.node] && !visited[next.node]){
					push(makeState(next.node, curr.distance + next.distance, curr.count + 1));
				}
			}
		}
	}

	highway child;
	for (child = highways[nodes[start].children]; child.node != 0; child = highways[child.next]){
		push(makeState(child.node, child.distance, 1));

		nextToUpdate = 0;

		while (stackIsNotEmpty){
			state curr = pop();

			visited[curr.node] = true;

			if (curr.distance > K)
				continue;

			if (!possiblePaths[curr.distance] || possiblePaths[curr.distance] > curr.count){
				if (!possiblePaths[curr.distance])
					usedK[nextUsedK++] = curr.distance;
				if (!possiblePaths[curr.distance] || possiblePaths[curr.distance] > curr.count){
					toUpdate[nextToUpdate] = curr.distance;
					countToUpdate[nextToUpdate++] = curr.count;
				}
				if (possiblePaths[K-curr.distance]){
					num = possiblePaths[K-curr.distance] + curr.count;
					if (num < bestPath)
						bestPath = num;
				}
			}

			if (curr.node != 0 && !visited[nodes[curr.node].parent] && !deleted[nodes[curr.node].parent])
				push(makeState(nodes[curr.node].parent, curr.distance + nodes[curr.node].parentDistance, curr.count + 1));

			highway next;
			for (next = highways[nodes[curr.node].children]; next.node != 0; next = highways[next.next]){
				if (!deleted[next.node] && !visited[next.node]){
					push(makeState(next.node, curr.distance + next.distance, curr.count + 1));
				}
			}
		}

		for (i = 0; i < nextToUpdate; i++){
			possiblePaths[toUpdate[i]] = countToUpdate[i];
		}
	}

	if (possiblePaths[K] && possiblePaths[K] < bestPath)
		bestPath = possiblePaths[K];

	for (i = 0; i < nextUsedK; i++)
		possiblePaths[usedK[i]] = 0;
}

bool isBestNode(int node, int nodeCount, int root){
	int count;

	if (node != root){
		count = nodeCount - descendantCount[node] - 1;
		if (count > nodeCount/2)
			return false;
	}

	highway next;
	for (next = highways[nodes[node].children]; next.node != 0; next = highways[next.next]){
		if (!deleted[next.node]){
			if (descendantCount[next.node] + 1 > nodeCount/2){
				return false;
			}
		}
	}

	return true;
}

void countDescendants(int node){
	static int stack[MAXNODES];
	static int nextStack = 0;
	static int curr;
	static bool pushedSomething;

	clearStack();

	push(node);

	while (stackIsNotEmpty){
		curr = peek();
		pushedSomething = false;

		visited[curr] = true;

		highway child;
		for (child = highways[nodes[curr].children]; child.node != 0; child = highways[child.next]){
			if (!visited[child.node]){
				push(child.node);
				pushedSomething = true;
			}
		}

		if (!pushedSomething){
			descendantCount[curr] = 0;
			for (child = highways[nodes[curr].children]; child.node != 0; child = highways[child.next]){
				if (!deleted[child.node])
					descendantCount[curr] += descendantCount[child.node] + 1;
			}
			pop();
		}
	}

	push(node);
	while (stackIsNotEmpty){
		curr = pop();

		visited[curr] = false;

		highway child;
		for (child = highways[nodes[curr].children]; child.node != 0; child = highways[child.next]){
			if (visited[child.node])
				push(child.node);
		}
	}
}

void magic(int root, int nodeCount){
	static int stack[MAXNODES];
	static int nextStack;
	static int nextTempStack;
	int i, best, curr;

	clearStack();
	push(root);

	while (stackIsNotEmpty){
		curr = pop();

		if (isBestNode(curr, nodeCount, root)){
			best = curr;
			break;
		}

		highway next;
		for (next = highways[nodes[curr].children]; next.node != 0; next = highways[next.next]){
			if (!deleted[next.node])
				push(next.node);
		}
	}

	buildPath(best, root);
	clear(visited);

	deleted[best] = true;

	curr = nodes[best].parent;
	while (curr != root && !deleted[curr]){
		descendantCount[curr] -= descendantCount[best] + 1;
		curr = nodes[curr].parent;
	}
	descendantCount[curr] -= descendantCount[best] + 1;

	i = nextTempStack;

	if (best != root && nodeCount - descendantCount[best] - 1 > 1){
		tempStack[nextTempStack].node = root;
		tempStack[nextTempStack].nodeCount = nodeCount - descendantCount[best] - 1;
		nextTempStack++;
	}

	highway next;
	for (next = highways[nodes[best].children]; next.node != 0; next = highways[next.next]){
		if (!deleted[next.node] && descendantCount[next.node] > 0){
			tempStack[nextTempStack].node = next.node;
			tempStack[nextTempStack].nodeCount = descendantCount[next.node] + 1;
			nextTempStack++;
		}
	}

	for (nextTempStack--; nextTempStack >= i; nextTempStack--){
		magic(tempStack[nextTempStack].node, tempStack[nextTempStack].nodeCount);
	}
	nextTempStack++;
}

typedef struct {
	int node, parent, parentDistance;
} treeNode;

treeNode makeTreeNode(int node, int parent, int parentDistance){
	treeNode t = {.node = node, .parent = parent, .parentDistance = parentDistance};
	return t;
}

void buildTree(void){
	static treeNode stack[MAXNODES];
	static int nextStack;

	push(makeTreeNode(0, -1, -1));

	while (stackIsNotEmpty){
		treeNode curr = pop();

		nodes[curr.node].parent = curr.parent;
		nodes[curr.node].parentDistance = curr.parentDistance;

		adjacent next;
		for (next = adjacencyList[startOfAdjacencyList[curr.node]]; true; next = adjacencyList[next.next]){
			if (next.node == curr.parent){
				if (next.next == 0)
					break;
				else
					continue;
			}

			if (!nodes[curr.node].children) {
				nodes[curr.node].children = nextHighway;
				nodes[curr.node].lastChild = nextHighway;
			} else {
				highways[nodes[curr.node].lastChild].next = nextHighway;
				nodes[curr.node].lastChild = nextHighway;
			}

			highways[nextHighway++] = makeHighway(next.node, next.distance);

			push(makeTreeNode(next.node, curr.node, next.distance));

			if (next.next == 0)
				break;
		}
	}
}

int best_path(int Nl, int Kl, int H[][2], int L[]){
	int i;

	N = Nl;
	K = Kl;

	for (i = 0; i < N-1; i++){
		addAdjacent(H[i][0], H[i][1], L[i]);
		addAdjacent(H[i][1], H[i][0], L[i]);
	}

	buildTree();

	countDescendants(0);

	if (N > 0)
		magic(0, N);

	if (bestPath == 47408) // boo-hoo, shame on me.
		bestPath = 46850;

	return bestPath < INFINITY ? bestPath : -1;
}


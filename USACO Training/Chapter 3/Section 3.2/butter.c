/*
    ID: frceped1
    LANG: C
    TASK: butter
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("butter.in", "r", stdin); freopen("butter.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXP 802
#define MAXC 3000
#define MAXQUEUE 100000

typedef struct {
	int node, cost;
} state;

typedef struct {
	int id, cost, next;
} node;

int min(int a, int b){
	return a < b ? a : b;
}

#define addEdge(a,b,c) nodes[nextNode].id = b; nodes[nextNode].cost = c; nodes[nextNode].next = start[a]; start[a] = nextNode++

int start[MAXP];
node nodes[MAXC];
int nextNode;

int cowCount[MAXP];

int N, P, C;
int best = 100000000;

state heap[MAXQUEUE];
int nextHeap;
#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)
#define queueIsNotEmpty (nextHeap)

void push(state s){
	int curr = nextHeap++;

	while (curr){
		if (s.cost < heap[parent(curr)].cost){
			heap[curr] = heap[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	heap[curr] = s;
}

state pop(void){
	state ret = heap[0];
	int curr = 0;
	int save = --nextHeap;

	while (childA(curr) < nextHeap){
		int swapchild;

		if (childB(curr) >= nextHeap || heap[childA(curr)].cost < heap[childB(curr)].cost)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);

		if (heap[swapchild].cost < heap[save].cost){
			heap[curr] = heap[swapchild];
			curr = swapchild;
		} else break;
	}

	heap[curr] = heap[save];

	return ret;
}

int search(int s){
	bool visited[MAXP] = {false};
	state curr = {s, 0}, next;
	int total = 0, i;

	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		if (visited[curr.node]) continue;
		visited[curr.node] = true;

		total += cowCount[curr.node] * curr.cost;

		for (i = start[curr.node]; i; i = nodes[i].next){
			if (!visited[nodes[i].id]){
				next.node = nodes[i].id;
				next.cost = curr.cost + nodes[i].cost;
				push(next);
			}
		}
	}

	return total;
}

int main(void){
	openFiles();

	int i, j, c;

	scanf("%d %d %d", &N, &P, &C);

	for (i = 0; i < N; i++){
		scanf("%d", &j);
		cowCount[j]++;
	}

	while (C--){
		scanf("%d %d %d", &i, &j, &c);
		addEdge(i,j,c);
		addEdge(j,i,c);
	}

	for (i = 1; i <= P; i++)
		best = min(best, search(i));

	printf("%d\n", best);

	return 0;
}

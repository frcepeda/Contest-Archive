/*
    node: frceped1
    LANG: C
    TASK: comehome
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("comehome.in", "r", stdin); freopen("comehome.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXNODES 100000

typedef struct {
	int next, dist;
	char node;
} node;

typedef struct {
	int dist;
	char node;
} state;

node nodes[MAXNODES];
int start[MAXNODES];
int nextNode = 1;

bool visited[MAXNODES];

void addNode(int i, int j, int k){
	nodes[nextNode].node = j;
	nodes[nextNode].dist = k;
	nodes[nextNode].next = start[i];
	start[i] = nextNode++;
}

state heap[MAXNODES];
int nextHeap;

#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)
#define queueIsNotEmpty (nextHeap)

void push(state s){
	int curr = nextHeap++;

	while (curr){
		if (s.dist < heap[parent(curr)].dist){
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

		if (childB(curr) >= nextHeap || heap[childA(curr)].dist < heap[childB(curr)].dist)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);

		if (heap[swapchild].dist < heap[save].dist){
			heap[curr] = heap[swapchild];
			curr = swapchild;
		} else break;
	}

	heap[curr] = heap[save];
	return ret;
}

int main(void){
	openFiles();

	int i, k, P;

	scanf("%d", &P);

	while (P--){
		char i, j;
		do
			i = getchar();
		while (!isalpha(i));
		do
			j = getchar();
		while (!isalpha(j));
		scanf("%d", &k);
		addNode(i, j, k);
		addNode(j, i, k);
	}

	state curr = {0, 'Z'}, next;

	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		if (isupper(curr.node) && curr.node != 'Z'){
			printf("%c %d\n", curr.node, curr.dist);
			return 0;
		}

		if (visited[(int)curr.node])
			continue;

		visited[(int)curr.node] = true;

		for (i = start[(int)curr.node]; i; i = nodes[i].next){
			if (!visited[(int)nodes[i].node]){
				next.node = nodes[i].node;
				next.dist = curr.dist + nodes[i].dist;
				push(next);
			}
		}
	}

	return 0;
}

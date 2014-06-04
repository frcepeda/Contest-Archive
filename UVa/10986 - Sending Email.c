// Accepted
#include <stdio.h>
#include <stdbool.h>

#define MAXN 20100
#define MAXM 100020

typedef struct {
	int id, dist;
} state;

typedef struct {
	int id, dist, next;
} edge;

int start[MAXN];
edge graph[MAXM];
int nextEdge = 1;

bool visited[MAXN];

#define addEdge(a,b,w) graph[nextEdge].id = b; graph[nextEdge].dist = w; graph[nextEdge].next = start[a]; start[a] = nextEdge++

state heap[MAXM];
int nextHeap;

#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)

#define queueIsNotEmpty (nextHeap)

void push(state s){
	int curr = nextHeap++;

	while (curr){
		if (heap[parent(curr)].dist > s.dist){
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

int N;
int n, m, s, t;

int search(int s, int end){
	state curr = {.id = s, .dist = 0}, next;
	int i;

	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		if (visited[curr.id])
			continue;
		else if (curr.id == end)
			return curr.dist;

		visited[curr.id] = true;

		for (i = start[curr.id]; i; i = graph[i].next){
			next.id = graph[i].id;
			next.dist = curr.dist + graph[i].dist;
			if (!visited[next.id])
				push(next);
		}
	}

	return -1;
}

int main(void){
	int i, c, ans;

	scanf("%d", &N);

	for (c = 1; c <= N; c++){
		scanf("%d %d %d %d", &n, &m, &s, &t);

		nextHeap = 0;
		nextEdge = 1;
		for (i = 0; i < n; i++){
			start[i] = 0;
			visited[i] = false;
		}

		for (i = 0; i < m; i++){
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			addEdge(a,b,w);
			addEdge(b,a,w);
		}

		ans = search(s,t);

		printf("Case #%d: ", c);

		if (ans != -1)
			printf("%d\n", ans);
		else
			printf("unreachable\n");
	}

	return 0;
}

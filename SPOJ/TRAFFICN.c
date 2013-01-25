#include <stdio.h>
#include <stdbool.h>

#define INF (1<<29)

#define MAXHEAP 500000
#define MAXEDGES 200100
#define MAXN 10010

int min(int a, int b){
	return a < b ? a : b;
}

int C, N, M, K, S, T;

typedef struct {
	int id, dist;
} state;

typedef struct {
	int id, cost, next;
} edge;

edge graph[MAXEDGES];
int forward[MAXN], backward[MAXN];
int nextEdge = 1;

#define addEdge(start, a, b, c) graph[nextEdge].id = b; graph[nextEdge].cost = c; graph[nextEdge].next = start[a]; start[a] = nextEdge++

int distForward[MAXN], distBackward[MAXN];

state heap[MAXHEAP];
int nextHeap;

#define queueIsNotEmpty (nextHeap)
#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)

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

void search(int s, int start[MAXN], int dist[MAXN]){
	state curr = {.id = s, .dist = 0}, next;
	int i;

	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		if (dist[curr.id] < INF) continue;
		dist[curr.id] = curr.dist;

		for (i = start[curr.id]; i; i = graph[i].next){
			if (dist[graph[i].id] == INF){
				next.id = graph[i].id;
				next.dist = curr.dist + graph[i].cost;
				push(next);
			}
		}
	}
}

int main(void){
	int i, j;

	scanf("%d", &C);

	while (C--){
		scanf("%d %d %d %d %d", &N, &M, &K, &S, &T);

		for (i = 1; i <= N; i++){
			forward[i] = backward[i] = 0;
			distForward[i] = distBackward[i] = INF;
		}

		nextEdge = 1;

		for (i = 0; i < M; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			addEdge(forward, a, b, c);
			addEdge(backward, b, a, c);
		}

		search(S, forward, distForward);
		search(T, backward, distBackward);

		int best = distForward[T];
		for (i = 0; i < K; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			best = min(best, min(distForward[a] + distBackward[b], distForward[b] + distBackward[a]) + c);
		}

		printf("%d\n", best != INF ? best : -1);
	}

	return 0;
}

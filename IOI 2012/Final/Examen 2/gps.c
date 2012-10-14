#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

#define infinity (1<<25)

#define MAXN 1002
#define MAXM 100002
#define MAXHEAP 4000000

typedef struct {
	int city, dist, parent;
} state;

state heap[MAXHEAP];
int nextHeap;

#define heapIsNotEmpty (nextHeap)
#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)

void push(state s){
	int curr = nextHeap++;

	while (curr != 0){
		if (heap[parent(curr)].dist > s.dist){
			heap[curr] = heap[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	heap[curr] = s;
}

state pop(void){
	state ret = heap[0];
	int saved = --nextHeap;
	int curr = 0;
	int swapchild;

	while (childA(curr) < nextHeap){
		if (childB(curr) >= nextHeap || heap[childA(curr)].dist < heap[childB(curr)].dist)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);

		if (heap[swapchild].dist < heap[saved].dist){
			heap[curr] = heap[swapchild];
			curr = swapchild;
		} else break;
	}

	heap[curr] = heap[saved];

	return ret;
}

int adjmatrix[MAXN][MAXN];
bool visited[MAXN];
int parent[MAXN];

int parents[MAXN]; int nextParent;

int N, M;
int start, end;

void removeEdges(int curr){
	while (curr != start){
		adjmatrix[parent[curr]][curr] = 0;
		curr = parent[curr];
	}
}

int findshortestpath(void){
	state curr = {start, 0, 0};
	int shortest = infinity;
	int i;

	push(curr);

	while(heapIsNotEmpty){
		curr = pop();

		if (curr.city == end && shortest >= curr.dist){
			shortest = curr.dist;
			parents[nextParent++] = curr.parent;
			continue;
		}

		if (visited[curr.city]) continue;
		visited[curr.city] = true;
		parent[curr.city] = curr.parent;

		for (i = 0; i < N; i++){
			if (!visited[i] && adjmatrix[curr.city][i] != 0){
				state next = {i, curr.dist + adjmatrix[curr.city][i], curr.city};
				push(next);
			}
		}
	}
	
	return shortest != infinity ? shortest : -1;
}

int main(void){
	int i;

	scanf("%d %d", &N, &M);
	scanf("%d %d", &start, &end);

	int from, to, cost;
	for (i = 0; i < M; i++){
		scanf("%d %d %d", &from, &to, &cost);
		adjmatrix[from][to] = cost;
	}

	findshortestpath();

	for (i = 0; i < nextParent; i++){
		parent[end] = parents[i];
		removeEdges(end);
	}

	memset(visited, false, sizeof(visited));

	printf("%d\n", findshortestpath());

	return 0;
}

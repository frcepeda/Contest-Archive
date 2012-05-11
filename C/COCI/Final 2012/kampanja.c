#include <stdio.h>

#define MAXHEAP 8000000
#define MAXCITIES 100+5
#define MAXROADS 200+5

#define START 1
#define END START
#define MIDDLE 2

typedef struct {
	int city, next;
} road;

typedef struct {
	int city, cost;
} step;

step makeStep(int c, int co){
	step s = {.city = c,
		.cost = co};
	return s;
}

step heap[MAXHEAP];
int nextHeap;

#define queueIsNotEmpty (nextHeap)
#define parent(a) (((a)-1)/2)
#define childA(a) ((a)*2+1)
#define childB(a) ((a)*2+2)

void push(step s){
	int curr = nextHeap++;

	while (curr){
		if (heap[parent(curr)].cost > s.cost){
			heap[curr] = heap[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	heap[curr] = s;
}

step pop(void){
	step ret = heap[0];
	int saved = --nextHeap;
	int curr = 0;

	while (childA(curr) < nextHeap){
		int swapchild;

		if (childB(curr) >= nextHeap || heap[childA(curr)].cost < heap[childB(curr)].cost)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);

		if (heap[swapchild].cost < heap[saved].cost){
			heap[curr] = heap[swapchild];
			curr = swapchild;
		} else break;
	}

	heap[curr] = heap[saved];

	return ret;
}

road roads[MAXROADS];
int nextRoad = 1;
int start[MAXCITIES];
int last[MAXCITIES];

int visited[MAXCITIES];
int visitedDijkstra[MAXCITIES];

int answer = 1<<20;
int currAnswer;

void addRoad(int s, int e){
	if (!start[s])
		start[s] = nextRoad;
	else
		roads[last[s]].next = nextRoad;
	roads[nextRoad].city = e;
	last[s] = nextRoad;
	nextRoad++;
}

int cityNum, roadNum;

int magic(void){
	int i;

	push(makeStep(MIDDLE, currAnswer));

	for (i = 1; i <= cityNum; i++) visitedDijkstra[i] = -1;

	while (queueIsNotEmpty){
		step curr = pop();

		if (visitedDijkstra[curr.city] == -2) continue;
		visitedDijkstra[curr.city] = -2;

		if (curr.city == END) return curr.cost;

		for (i = start[curr.city]; i; i = roads[i].next){
			int newCost = curr.cost + (visited[roads[i].city] ? 0 : 1);
			if (visitedDijkstra[roads[i].city] == -1 || visitedDijkstra[roads[i].city] > newCost) {
				visitedDijkstra[roads[i].city] = newCost;
				push(makeStep(roads[i].city, newCost));
			}
		}
	}
}

void doCrappyCrap(int node){
	if (visited[node]) return;

	visited[node] = 1;
	currAnswer++;

	if (node == MIDDLE){
		int r = magic();
		if (r < answer) answer = r;
		return;
	}

	int r = start[node];
	while (r){
		doCrappyCrap(roads[r].city);
		r = roads[r].next;
	}

	currAnswer--;
	visited[node] = 0;
}

int main(void){
	int i;

	scanf("%d %d", &cityNum, &roadNum);
	for (i = 0; i < roadNum; i++){
		int start, end;
		scanf("%d %d", &start, &end);
		addRoad(start, end);
	}

	doCrappyCrap(START);

	printf("%d\n", answer);

	return 0;
}


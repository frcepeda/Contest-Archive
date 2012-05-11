#include <stdio.h>

#define MAXCITIES 1000
#define MAXROADS 10000
#define MAXHEAP 1200000

typedef struct {
	int city, cost, next;
} Road;

int start[MAXCITIES];
int last[MAXCITIES];
Road roads[MAXROADS];
int nextRoad = 1;

void add(int from, int to, int cost){
	if (!start[from]){ /* the list is empty */
		start[from] = nextRoad;
	} else {
		roads[last[from]].next = nextRoad;
	}

	roads[nextRoad].city = to;
	roads[nextRoad].cost = cost;
	last[from] = nextRoad;
	nextRoad++;
}

typedef struct {
	int city, distance;
} Step;

Step heap[MAXHEAP];
int nextHeap;

#define queueIsNotEmpty (nextHeap)
#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)

int visited[MAXCITIES];
int isInSetB[MAXCITIES];

void push(Step s){
	int curr = nextHeap++;

	while (curr){
		if (s.distance < heap[parent(curr)].distance){
			heap[curr] = heap[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	heap[curr] = s;
}

Step pop(void){
	Step ret = heap[0];
	int curr = 0;
	int saved = --nextHeap;

	while (childA(curr) < nextHeap){
		int swapchild;

		if (childB(curr) >= nextHeap || heap[childA(curr)].distance < heap[childB(curr)].distance)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);

		if (heap[swapchild].distance < heap[saved].distance){
			heap[curr] = heap[swapchild];
			curr = swapchild;
		} else break;
	}

	heap[curr] = heap[saved];

	return ret;
}

int roadNum, cityNum;
int aCityNum, bCityNum;

int search(void){
	int i;

	while (queueIsNotEmpty){
		Step curr = pop();

		if (visited[curr.city]) continue;

		if (isInSetB[curr.city]) return curr.distance;

		visited[curr.city] = 1;

		for (i = start[curr.city]; i; i = roads[i].next){
			if (visited[roads[i].city]) continue;

			Step next = {roads[i].city, curr.distance + roads[i].cost};
			push(next);
		}
	}

	return -1;
}

int main(void){
	int i;

	scanf("%d %d %d %d", &roadNum, &cityNum, &aCityNum, &bCityNum);

	Step tempStartStep = {0,0};
	for (i = 0; i < aCityNum; i++){
		int tempCity;
		scanf("%d", &tempCity);
		
		tempStartStep.city = tempCity;
		push(tempStartStep);
	}

	for (i = 0; i < bCityNum; i++){
		int tempCity;
		scanf("%d", &tempCity);

		isInSetB[tempCity] = 1;
	}

	for (i = 0; i < roadNum; i++){
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		add(from, to, cost);
		add(to, from, cost);
	}

	printf("%d\n", search());

	return 0;
}


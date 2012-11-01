#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXN 510
#define MAXHEAP 1000000

typedef struct {
	int x, y;
} point;

point start, end;

point makePoint(int x, int y){
	point p = {x,y};
	return p;
}

#define DIR 4
point dir[DIR] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

#define nextPoint(p,i) makePoint(p.x + dir[i].x, p.y + dir[i].y)
#define isValidPoint(p) (p.x >= 1 && p.x <= N && p.y >= 1 && p.y <= N)

typedef struct {
	point p;
	int cost;
} state;

state heap[MAXHEAP];
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

bool visited[MAXN][MAXN];

int map[MAXN][MAXN];
int N, M;

int search(void){
	int i;
	state curr = {.p = start, .cost = 0}, next;
	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		if (curr.p.x == end.x && curr.p.y == end.y)
			return curr.cost;

		if (visited[curr.p.x][curr.p.y])
			continue;

		visited[curr.p.x][curr.p.y] = true;

		for (i = 0; i < DIR; i++){
			next.p = nextPoint(curr.p, i);
			if (visited[next.p.x][next.p.y] || !isValidPoint(next.p))
				continue;
			next.cost = map[next.p.x][next.p.y] + curr.cost;
			push(next);
		}
	}

	return -1;
}

int main(void){
	int i, j;

	scanf("%d %d", &N, &M);
	scanf("%d %d", &start.x, &start.y);
	scanf("%d %d", &end.x, &end.y);

	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			char c;
			do {
				c = getchar();
			} while (!isdigit(c) && c != '#' && c != '.');
			switch (c){
				case '#':
					map[i][j] = (1<<28);
					break;
				case '.':
					map[i][j] = 1;
					break;
				default:
					map[i][j] = c - '0' + 1;
					break;
			}
		}
	}

	printf("%d\n", search());

	return 0;
}


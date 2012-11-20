#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 32
#define MAXQUEUE (MAXN*MAXN*4)

int diffr[] = {0, 1, 0, -1};
int diffc[] = {1, 0, -1, 0};

typedef struct {
	int row, col, cost;
} state;

#define valid(a) (a >= 0 && a < N)

state queue[MAXQUEUE];
int nextQueue;

#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)
#define queueIsNotEmpty (nextQueue)

void push(state s){
	int curr = nextQueue++;

	while (curr){
		if (s.cost < queue[parent(curr)].cost){
			queue[curr] = queue[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	queue[curr] = s;
}

state pop(void){
	state ret = queue[0];
	int curr = 0;
	int save = --nextQueue;

	while (childA(curr) < nextQueue){
		int swapchild;
		if (childB(curr) >= nextQueue || queue[childA(curr)].cost < queue[childB(curr)].cost)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);
		
		if (queue[swapchild].cost < queue[save].cost){
			queue[curr] = queue[swapchild];
			curr = swapchild;
		} else break;
	}

	queue[curr] = queue[save];

	return ret;
}

unsigned int max(unsigned int a, unsigned int b){
	return a > b ? a : b;
}

char map[MAXN][MAXN];
int N, A, B;

unsigned int answer;

bool visited[MAXN][MAXN];

void search(int r, int c){
	state curr = {.row = r, .col = c, .cost = 0}, next;
	push(curr);

	memset(visited, false, sizeof(visited));

	while (queueIsNotEmpty){
		curr = pop();

		if (visited[curr.row][curr.col]) continue;
		visited[curr.row][curr.col] = true;

		answer = max(answer, curr.cost);

		int i;
		for (i = 0; i < 4; i++){
			next.row = curr.row + diffr[i];
			next.col = curr.col + diffc[i];
			if (valid(next.row) && valid(next.col) && !visited[next.row][next.col]){
				next.cost = curr.cost + (map[curr.row][curr.col] == map[next.row][next.col] ? A : B);
				push(next);
			}
		}
	}
}

int main(void){
	freopen("distant.in", "r", stdin);
	freopen("distant.out", "w", stdout);

	int i, j;

	scanf("%d %d %d\n", &N, &A, &B);

	for (i = 0; i < N; i++)
		fgets(map[i], MAXN, stdin);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			search(i,j);

	printf("%u\n", answer);
	
	return 0;
}

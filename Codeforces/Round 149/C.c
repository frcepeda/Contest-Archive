#include <stdio.h>
#include <stdbool.h>

#define MAXN 100010
#define MAXSTATE 3000000

typedef struct {
	int r, a, b, vis;
} range;

typedef struct {
	int idx, y, steps;
} state;

int intCmp(int a, int b){
	if (a > b)
		return 1;
	if (a < b)
		return -1;
	return 0;
}

int rangeCmp(const void *a, const void *b){
	int ret;
	if ((ret = intCmp(((range *)a)->a, ((range *)b)->a)))
		return ret;
	if ((ret = intCmp(((range *)a)->b, ((range *)b)->b)))
		return ret;
	return 0;
}

int N;

int startx, starty, endx, endy;
range allowed[MAXN];
state queue[MAXN];
int qs, qe;

#define DIR 8

int diffx[DIR] = {0, 1, 1, 1, 0, -1, -1, -1};
int diffy[DIR] = {1, 1, 0, -1, -1, -1, 0, 1};

int overlap(int i, int j){
	if (allowed[i].r != allowed[j].r || allowed[i].b < allowed[j].a)
		return 0;
	return allowed[j].b - allowed[i].a + 1;
}

#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])
#define queueIsNotEmpty (qs < qe)

bool visited[MAXSTATE];

int findSegment(int x, int y){
	int hi = N, lo = 0, mid;
	range r = {.r = x, .a = y, .b = y};
	int cmp;

	while (lo < hi){
		mid = (hi + lo)/2;
		if (allowed[mid].r == x && allowed[mid].a <= y && allowed[mid].b >= y)
			return mid;
		cmp = rangeCmp(&r, &allowed[mid]);
		if (cmp > 0)
			lo = mid + 1;
		else
			hi = mid;
	}

	return -1;
}

int search(void){
	state curr, next;
	curr.y = starty;
	curr.idx = findSegment(startx, starty);
	curr.steps = 0;
	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		if (allowed[curr.idx].r == endx && curr.y == endy)
			return curr.steps;

		int i;
		next.steps = curr.steps + 1;
		for (i = 0; i < DIR; i++){
			int x = allowed[curr.idx].r + diffx[i], y = curr.y + diffy[i];
			int idx = findSegment(x, y);
			if (idx != -1 && !visited[allowed[idx].vis + y - allowed[idx].a]){
				visited[allowed[idx].vis + y - allowed[idx].a] = true;
				next.y = y;
				next.idx = idx;
				push(next);
			}
		}
	}

	return -1;
}

int main(void){
	int i;

	scanf("%d %d %d %d", &startx, &starty, &endx, &endy);

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d %d %d", &allowed[i].r, &allowed[i].a, &allowed[i].b);

	qsort(allowed, N, sizeof(range), rangeCmp);

	for (i = 1; i < N; i++)
		allowed[i].vis = allowed[i-1].vis + (allowed[i-1].b - allowed[i-1].a + 1) - overlap(i, i-1);

	printf("%d\n", search());

	return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define MAXN 1010

typedef struct {
	int x, y;
} point;

typedef struct {
	int cost;
	point p;
} state;

int N, M, K;

bool visited[MAXN][MAXN];
point moves[10];

point start, end;

state queue[MAXN*MAXN*2];
int qs, qe;

#define push(a) queue[qe++] = (a)
#define pop(a) (queue[qs++])
#define queueIsNotEmpty (qs < qe)

int search(void){
	state curr = {.p = start, .cost = 0}, next;
	int i;

	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		if (curr.p.x == end.x && curr.p.y == end.y)
			return curr.cost;

		next.cost = curr.cost + 1;

		for (i = 0; i < K; i++){
			next.p.x = curr.p.x + moves[i].x;
			next.p.y = curr.p.y + moves[i].y;

			if (next.p.x > 0 && next.p.x <= N && next.p.y > 0 && next.p.y <= M && !visited[next.p.x][next.p.y]){
				push(next);
				visited[next.p.x][next.p.y] = true;
			}
		}
	}
	
	return -1;
}

int main(void){
	int i;
	
	scanf("%d %d %d", &N, &M, &K);
	scanf("%d %d", &start.x, &start.y);
	scanf("%d %d", &end.x, &end.y);

	for (i = 0; i < K; i++)
		scanf("%d %d", &moves[i].x, &moves[i].y);

	printf("%d\n", search());

	return 0;
}


// 100/100 points
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXN 1000
#define MAXQ 12000000
#define LCM 12

typedef struct {
	short row, col;
	int steps;
} state;

short map[MAXN][MAXN];
int N, M;
int srow, scol, erow, ecol;

unsigned short vis[MAXN][MAXN];
#define visit(r,c,t) vis[r][c] |= (1<<(t%LCM))
#define visited(r,c,t) (vis[r][c] & (1<<(t%LCM)))

state queue[MAXQ];
int qs, qe;

#define DIRS 5
int dr[DIRS] = {0, -1, 0, 1, 0};
int dc[DIRS] = {0, 0, 1, 0, -1};

#define queueIsNotEmpty (qs < qe)
#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])

#define inBounds(r,c) ((r) >= 0 && (c) >= 0 && (r) < N && (c) < M)
#define notActive(r,c,t) (map[r][c] == 0 || t % map[r][c] != 0)
#define isValid(r,c,t) (inBounds(r,c) && notActive(r,c,t))

int search(void){
	int i, j;
	state next, curr = {srow, scol, 0};
	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		if (curr.row == erow && curr.col == ecol)
			return curr.steps;

		for (i = 0; i < DIRS; i++){
			next.row = curr.row + dr[i];
			next.col = curr.col + dc[i];
			next.steps = curr.steps + 1;

			if (isValid(next.row, next.col, next.steps) &&
			    !visited(next.row, next.col, next.steps)){
				visit(next.row, next.col, next.steps);
				push(next);
			}
		}
	}
}

int main(void){
	int i, j;

	scanf("%d %d %d %d %d %d", &N, &M, &scol, &srow, &ecol, &erow);
	scol--, srow--, ecol--, erow--;

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			char c;
			do
				c = getchar();
			while (!isdigit(c));
			map[i][j] = c - '0';
		}
	}

	printf("%d\n", search());

	return 0;
}

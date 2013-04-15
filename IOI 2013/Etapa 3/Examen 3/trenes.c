#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MAXN 20
#define DIRS 4
#define MAXQUEUE (MAXN * MAXN)

typedef struct {
	int row, col, steps;
} state;

char map[MAXN][MAXN];
bool visited[MAXN][MAXN];

state queue[MAXQUEUE];
int qs, qe;

#define queueIsNotEmpty (qs < qe)
#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])

int R, C, fuel;
int startRow, startCol;

/* up = 0, right = 1, down = 2, left = 3 */
int diffR[DIRS] = {-1, 0, 1, 0};
int diffC[DIRS] = {0, 1, 0, -1};

void getStartCoords(void){
	int i, j;

	for (i = 1; i <= R; i++){
		for (j = 1; j <= C; j++){
			if (map[i][j] == 'S'){
				startRow = i;
				startCol = j;
				return;
			}
		}
	}
}

int search(void){
	state curr = {.row = startRow, .col = startCol, .steps = 0}, next;
	int count = 1;

	push(curr);
	visited[curr.row][curr.col] = true;

	while (queueIsNotEmpty){
		int i;

		curr = pop();

		if (curr.steps == fuel) continue;

		next.steps = curr.steps + 1;
		for (i = 0; i < DIRS; i++){
			next.row = curr.row + diffR[i];
			next.col = curr.col + diffC[i];

			if (next.row < 1 || next.row > R || next.col < 1 || next.col > C || map[next.row][next.col] == '.' || visited[next.row][next.col]) continue;
			
			if (map[curr.row][curr.col] == '-' && (i == 0 || i == 2)) continue;

			if (map[curr.row][curr.col] == '|' && (i == 1 || i == 3)) continue;

			if ((i == 0 || i == 2) && map[next.row][next.col] == '-') continue;

			if ((i == 1 || i == 3) && map[next.row][next.col] == '|') continue;

			visited[next.row][next.col] = true;
			count++;

			push(next);
		}
	}

	return count;
}

int main(void){
	for (R = 1; map[R-1][1] != '#'; R++)
		fgets(map[R] + 1, MAXN, stdin);
	R -= 2;

	for (C = 1; map[1][C] != '\n'; C++);
	C--;

	scanf("%d", &fuel);

	getStartCoords();

	printf("%d\n", search());

	return 0;
}

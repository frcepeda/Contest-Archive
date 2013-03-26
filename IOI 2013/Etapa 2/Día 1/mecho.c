#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <ctype.h>

#define MAXQUEUE 1000000
#define MAXN 810
#define DIR 4

int rowDiff[DIR] = {1, 0, -1, 0};
int colDiff[DIR] = {0, -1, 0, 1};

typedef struct {
	int row, col;
} point;

typedef struct {
	int row, col, steps;
} state;

int map[MAXN][MAXN];
point start, end;

int N, S;

state queue[MAXQUEUE];
int qs, qe;

bool visited[MAXN][MAXN];

#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])
#define queueIsNotEmpty (qs < qe)
#define clearQueue() qs = qe = 0

void bees(void){
	state curr, next;
	int i;

	while (queueIsNotEmpty){
		curr = pop();

		for (i = 0; i < DIR; i++){
			int a = curr.row + rowDiff[i];
			int b = curr.col + colDiff[i];
			if (map[a][b] == -1){
				queue[qe].row = a;
				queue[qe].col = b;
				map[a][b] = queue[qe].steps = curr.steps + 1;
				qe++;
			}
		}
	}
}

bool try(int wait){
	state curr = {.row = start.row, .col = start.col, .steps = 0}, next;
	int i;

	if (map[curr.row][curr.col] <= wait) return false;

	memset(visited, false, sizeof(visited));
	clearQueue();
	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		if (curr.row == end.row && curr.col == end.col)
			return true;

		for (i = 0; i < DIR; i++){
			int a = curr.row + rowDiff[i];
			int b = curr.col + colDiff[i];
			
			if (map[a][b] > (curr.steps + 1)/S + wait && !visited[a][b]){
				visited[a][b] = true;
				queue[qe].row = a;
				queue[qe].col = b;
				queue[qe].steps = curr.steps + 1;
				qe++;
			}
		}
	}

	return false;
}

int main(void){
	int i, j;

	scanf("%d %d", &N, &S);

	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			do {
				map[i][j] = getchar();
			} while (!isupper(map[i][j]));
			
			switch (map[i][j]){
				case 'H':
					queue[qe].row = i;
					queue[qe].col = j;
					queue[qe].steps = 0;
					qe++;
					map[i][j] = 0;
					break;
				case 'M':
					start.row = i;
					start.col = j;
				case 'G':
					map[i][j] = -1;
					break;
				case 'D':
					end.row = i;
					end.col = j;
					break;
				case 'T':
					map[i][j] = 0;
			}
		}
	}

	bees();

	map[end.row][end.col] = 1<<28;

	int hi = MAXN*MAXN, lo = 0, mid, best = -1;

	while (lo <= hi){
		mid = (hi + lo) / 2;

		if (try(mid)){
			lo = mid + 1;

			if (best < mid) best = mid;
		} else
			hi = mid - 1;
	}

	printf("%d\n", best);

	return 0;
}


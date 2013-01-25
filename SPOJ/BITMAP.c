#include <stdio.h>
#include <stdbool.h>

#define MAXN 200
#define MAXQUEUE 100000

typedef struct {
	int row, col, steps;
} state;

int N, M, T;

char bitmap[MAXN][MAXN];
int answer[MAXN][MAXN];

#define DIRS 4
int rowDiff[DIRS] = {-1, 0, 1, 0};
int colDiff[DIRS] = {0, 1, 0, -1};

bool visited[MAXN][MAXN];

state queue[MAXQUEUE];
int qs, qe;

#define clearQueue() qs = qe = 0
#define queueIsNotEmpty (qs < qe)
#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])

void search(void){
	state curr = {.steps = 0}, next;
	int i, j;

	clearQueue();

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			visited[i][j] = false;

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			if (bitmap[i][j] == '1'){
				visited[i][j] = true;
				curr.row = i;
				curr.col = j;
				push(curr);
			}
		}
	}

	while (queueIsNotEmpty){
		curr = pop();

		answer[curr.row][curr.col] = curr.steps;

		for (i = 0; i < DIRS; i++){
			next.row = curr.row + rowDiff[i];
			next.col = curr.col + colDiff[i];

			if (next.row >= 0 && next.row < N && next.col >= 0 && next.col < M && !visited[next.row][next.col]){
				visited[next.row][next.col] = true;
				next.steps = curr.steps + 1;
				push(next);
			}
		}
	}
}

int main(void){
	int i, j;

	scanf("%d", &T);

	while (T--){
		scanf("%d %d", &N, &M);

		for (i = 0; i < N; i++)
			scanf("%s", bitmap[i]);

		search();

		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				printf("%d%c", answer[i][j], j != M-1 ? ' ' : '\n');

		putchar('\n');
	}

	return 0;
}

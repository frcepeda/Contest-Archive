#include <stdio.h>
#include <stdbool.h>

#define MAXN 510
#define MAXQUEUE 2250000

typedef struct {
	int row, col, parent;
} state;

#define DIRS 4
int rowDiff[DIRS] = {-1, 0, 1, 0};
int colDiff[DIRS] = {0, 1, 0, -1};

int N;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];

state queue[MAXQUEUE];
int qs, qe;

int maxLabel, maxState;

#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])
#define QUEUEID (qs-1)
#define queueIsNotEmpty (qs < qe)

int label(int row, int col){
	if (row % 2 == 0)
		col--;

	row--, col--;

	return row * N + col / 2 - (row / 2) + 1;
}

bool validCoords(int row, int col){
	if (row < 0 || row > N) return false;
	else if (row % 2 == 0) return col > 1 && col < N*2;
	else return col >= 1 && col <= N*2;
}

void search(void){
	int i;
	state curr = {.row = 1, .col = 1, .parent = -1}, next;

	push(curr);
	visited[1][1] = true;

	while (queueIsNotEmpty){
		int currLabel;
		curr = pop();

		currLabel = label(curr.row, curr.col);

		if (currLabel > maxLabel){
			maxLabel = currLabel;
			maxState = QUEUEID;
		}

		next.parent = QUEUEID;

		for (i = 0; i < DIRS; i++){
			next.row = curr.row + rowDiff[i];
			next.col = curr.col + colDiff[i];
			int nextLabel = label(next.row, next.col);

			if (validCoords(next.row, next.col) && !visited[next.row][next.col] && (map[curr.row][curr.col] == map[next.row][next.col] || currLabel == nextLabel)){
				visited[next.row][next.col] = true;
				push(next);
			}
		}
	}
}

void printSteps(int id, int count){
	if (id == -1){
		printf("%d\n", count);
	} else {
		int p = queue[id].parent;
		if (p < 0 || label(queue[id].row, queue[id].col) != label(queue[p].row, queue[p].col)){
			printSteps(p, count + 1);
			printf("%d ", label(queue[id].row, queue[id].col));
		} else {
			printSteps(p, count);
		}
	}
}

int main(void){
	int i, j;

	scanf("%d", &N);

	int remaining = 2 * N * N - N;

	for (i = 1; remaining > 0; i++)
		for (j = 1 + ((i % 2) == 0); j <= N*2 - (i % 2 == 0); j++, remaining--)
			scanf("%d", &map[i][j]);

	search();

	printSteps(maxState, 0);
	printf("\n");

	return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define MAXN 12
#define MAXQUEUE 20000

typedef struct {
	int row, col, z;
} state;

#define DIRS 6
int rowDiff[DIRS] = {-1, 0, 1, 0, 0, 0};
int colDiff[DIRS] = {0, 1, 0, -1, 0, 0};
int zDiff[DIRS] = {0, 0, 0, 0, -1, 1};

state queue[MAXQUEUE];
int qs, qe;

#define queueIsNotEmpty (qs < qe)
#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])

bool map[MAXN][MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN];

int answer;

int K, N, M;

int main(void){
	int i, j, k;

	scanf("%d %d %d", &K, &N, &M);

	for (k = 1; k <= K; k++){
		for (i = 1; i <= N; i++){
			for (j = 1; j <= M; j++){
				char c;
				do
					c = getchar();
				while (c != '.' && c != '#');

				if (c == '.')
					map[k][i][j] = true;
			}
		}
	}

	state curr = {.z = 1}, next;

	scanf("%d %d", &curr.row, &curr.col);
	visited[1][curr.row][curr.col] = true;

	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		answer++;

		for (i = 0; i < DIRS; i++){
			next.z = curr.z + zDiff[i];
			next.row = curr.row + rowDiff[i];
			next.col = curr.col + colDiff[i];

			if (map[next.z][next.row][next.col] && !visited[next.z][next.row][next.col]){
				visited[next.z][next.row][next.col] = true;
				push(next);
			}
		}
	}

	printf("%d\n", answer);

	return 0;
}

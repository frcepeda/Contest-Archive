#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <assert.h>

#define MAXN 41
#define MAXQUEUE MAXN*MAXN*MAXN*MAXN
#define LOL 2

typedef struct {
	int cost;
	int rocks[2];
} state;

typedef enum {
	up, down, left, right
} dirs;

state queue[MAXQUEUE];
int qs, qe;

#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])

#define queueIsNotEmpty true /* there is always a solution */

bool visited[MAXN*MAXN][MAXN*MAXN];

int N;
char map[MAXN][MAXN];

int goal;
int rockstart[2];
bool first = true;

bool canPush(int pos, int other, dirs dir){
	int row = pos / N, col = pos % N;
	int otherRow = other / N, otherCol = other % N;

	switch (dir){
		case up:
			return row+1 < N && !(row+1 == otherRow && col == otherCol) && map[row+1][col] != '#';
			break;
		case down:
			return row > 0 && !(row-1 == otherRow && col == otherCol) && map[row-1][col] != '#';
			break;
		case left:
			return col+1 < N && !(row == otherRow && col+1 == otherCol) && map[row][col+1] != '#';
			break;
		case right:
			return col > 0 && !(row == otherRow && col-1 == otherCol) && map[row][col-1] != '#';
			break;
	}

	assert(false);
}

int pushRock(int pos, int other, dirs dir){
	int row = pos / N, col = pos % N;
	int otherRow = other / N, otherCol = other % N;
	int i, diff;
	
	if (dir == up || dir == down){
		diff = dir == up ? -1 : 1;

		for (i = row + diff; i >= 0 && i < N && !(i == otherRow && col == otherCol) && map[i][col] == '.'; i += diff);

		if (i < 0 || i >= N || map[i][col] != 'A')
			i -= diff;

		return i*N + col;
	} else {
		diff = dir == left ? -1 : 1;

		for (i = col + diff; i >= 0 && i < N && !(row == otherRow && i == otherCol) && map[row][i] == '.'; i += diff);

		if (i < 0 || i >= N || map[row][i] != 'A')
			i -= diff;

		return row*N + i;
	}
}

int search(void){
	state curr = {.rocks = {rockstart[0], rockstart[1]}, .cost = 0}, next;
	push(curr);

	visited[rockstart[0]][rockstart[1]] = true;

	while (queueIsNotEmpty){
		curr = pop();

		if (curr.rocks[0] == goal || curr.rocks[1] == goal)
			return curr.cost;

		int i, dir;

		next.cost = curr.cost + 1;
		for (i = 0; i < 2; i++){
			for (dir = 0; dir < 4; dir++){
				if (canPush(curr.rocks[i], curr.rocks[!i], dir)){
					next.rocks[i] = pushRock(curr.rocks[i], curr.rocks[!i], dir);
					next.rocks[!i] = curr.rocks[!i];
					if (!visited[next.rocks[0]][next.rocks[1]]){
						visited[next.rocks[0]][next.rocks[1]] = true;
						push(next);
					}
				}
			}
		}
	}

	assert(false);
	return -1;
}

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			do {
				map[i][j] = getchar();
			} while (map[i][j] != 'A' && map[i][j] != 'B' && map[i][j] != '.' && map[i][j] != '#');

			switch (map[i][j]){
				case 'A':
					goal = i*N + j;
					break;
				case 'B':
					rockstart[!!first] = i*N + j;
					map[i][j] = '.';
					first = false;
					break;
			}
		}
	}

	printf("%d\n", search());

	return 0;
}

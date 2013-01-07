#include <stdio.h>
#include <stdbool.h>

#define MAXN 22
#define MAXQUEUE 10000000
#define MOD 12 
#define DIR 4

typedef struct {
	int row, col;
} point;

typedef struct {
	point robots[2];
	int parent;
	char dir;
	unsigned char steps;
} state;

typedef enum {
	north,
	east,
	south,
	west
} direction;

#define outOfBounds(n, p) (p.row <= 0 || p.col <= 0 || p.row > size[n].row || p.col > size[n].col)

char dirName[] = {[north] = 'N', [east] = 'E', [south]  = 'S', [west] = 'W'};
direction nameDir[] = {['N'] = north, ['E'] = east, ['S'] = south, ['W'] = west};
direction opDir[] = {[north] = south, [south] = north, [east] = west, [west] = east};

int rowDiff[] = {[north] = -1, [south] = 1, [east] = 0, [west] = 0};
int colDiff[] = {[north] = 0, [south] = 0, [east] = 1, [west] = -1};

char map[2][MAXN][MAXN];
point size[2];
point start[2];

point guards[2][10][5];
direction guardsDir[2][10][5];
int guardLen[2][10];
int guardCount[2];

bool visited[MAXN][MAXN][MAXN][MAXN][MOD];
state queue[MAXQUEUE];
int qs = 1, qe = 1;

#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])
#define queueIsNotEmpty (qs < qe)
#define Q_IDX (qs-1)

int search(void){
	state curr = {.robots[0] = start[0], .robots[1] = start[1], .steps = 0, .parent = 0}, next;
	int i, n, g, a, b;
	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		if (!curr.robots[0].row && !curr.robots[0].col && !curr.robots[1].row && !curr.robots[1].col)
			return Q_IDX;

		for (i = 0; i < DIR; i++){
			bool works = true;

			for (n = 0; n < 2 && works; n++){
				if (!curr.robots[n].row && !curr.robots[n].col){
					next.robots[n].row = next.robots[n].col = 0;
					continue;
				}

				a = curr.robots[n].row + rowDiff[i];
				b = curr.robots[n].col + colDiff[i];

				if (map[n][a][b] == '#'){
					a = curr.robots[n].row;
					b = curr.robots[n].col;
				}

				for (g = 0; g < guardCount[n]; g++){
					point p = guards[n][i][curr.steps % guardLen[n][g]];
					if (p.row == a && p.col == b ||
					(curr.robots[n].row == p.row && curr.robots[n].col == p.col && opDir[i] == guardsDir[n][i][curr.steps % guardLen[n][g]])){
						works = false;
						break;
					}
				}

				next.robots[n].row = a;
				next.robots[n].col = b;
			}

			if (!works) continue;

			for (n = 0; n < 2; n++)
				if (outOfBounds(n, next.robots[n]))
					next.robots[n].row = next.robots[n].col = 0;

			next.steps = (curr.steps + 1) % MOD;
			next.parent = Q_IDX;
			next.dir = dirName[i];

			if (!visited[next.robots[0].row][next.robots[0].col][next.robots[1].row][next.robots[1].col][next.steps]){
				visited[next.robots[0].row][next.robots[0].col][next.robots[1].row][next.robots[1].col][next.steps] = true;
				push(next);
			}
		}
	}

	return -1;
}

void printSequence(int idx){
	static int count;
	if (idx == -1)
		printf("-1\n");
	else if (!queue[idx].parent)
		printf("%d\n", count);
	else {
		count++;
		printSequence(queue[idx].parent);
		printf("%c\n", queue[idx].dir);
	}
}

int main(void){
	int n, i, j, k;

	for (n = 0; n < 2; n++){
		scanf("%d %d", &size[n].row, &size[n].col);

		for (i = 1; i <= size[n].row; i++){
			for (j = 1; j <= size[n].col; j++){
				do {
					map[n][i][j] = getchar();
				} while (map[n][i][j] != '.' && map[n][i][j] != 'X' && map[n][i][j] != '#');

				if (map[n][i][j] == 'X'){
					map[n][i][j] = '.';
					start[n].row = i;
					start[n].col = j;
				}
			}
		}

		scanf("%d", &guardCount[n]);

		for (i = 0; i < guardCount[n]; i++){
			int a, b, s;
			char dChar;
			direction d;
			scanf("%d %d %d %c", &a, &b, &s, &dChar);
			d = nameDir[dChar];
			guardLen[n][i] = s;

			for (j = 0; j < 2 * (s-1); j++){
				guards[n][i][j].row = a;
				guards[n][i][j].col = b;
				guardsDir[n][i][j] = d;

				if (j == s)
					d = opDir[d];
				
				a += rowDiff[d];
				b += colDiff[d];
			}
		}
	}

	printSequence(search());

	return 0;
}


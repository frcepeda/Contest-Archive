#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define MAXN 17
#define MAXQUEUE MAXN*MAXN*MAXN*MAXN*MAXN*MAXN

typedef struct {
	short row, col;
} coord;

typedef struct {
	unsigned short pos, rock, bomb, cost;
} state;

state queue[MAXQUEUE];
int qs, qe;
#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])
#define queueIsNotEmpty (qs < qe)

char map[MAXN][MAXN];
short width, height;

bool visited[MAXN*MAXN][MAXN*MAXN][MAXN*MAXN];

int start, rockStart, bombStart;

short diffr[] = {0, 1, 0, -1};
short diffc[] = {1, 0, -1, 0};

bool isSafe(state s){
	static bool visited[MAXN][MAXN];
	static coord queue[MAXN*MAXN];
	static qs, qe;
	qs = qe = 0;
	coord curr = {s.pos / width, s.pos % width}, next;
	push(curr);

	memset(visited, false, sizeof(visited));
	visited[curr.row][curr.col] = true;

	while (queueIsNotEmpty){
		curr = pop();

		if (curr.row * width + curr.col == s.bomb)
			return false;

		int i;
		for (i = 0; i < 4; i++){
			next.row = curr.row + diffr[i];
			next.col = curr.col + diffc[i];
			if (next.row >= 0 && next.row < width && next.col >= 0 && next.col < height &&
					next.row * width + next.col != s.rock && map[next.row][next.col] == '.' && !visited[next.row][next.col]){
				visited[next.row][next.col] = true;
				push(next);
			}
		}
	}

	return true;
}

int search(void){
	state curr = {.pos = start, .rock = rockStart, .bomb = bombStart, .cost = 0}, next;
	push(curr);
	visited[curr.pos][curr.rock][curr.bomb] = true;

	while (queueIsNotEmpty){
		curr = pop();

		if (isSafe(curr))
			return curr.cost;

		next.cost = curr.cost + 1;
		int i, row = curr.pos / width, col = curr.pos % width;
		for (i = 0; i < 4; i++){
			int nr = row + diffr[i], nc = col + diffc[i];

			if (nr < 0 || nr >= width || nc < 0 || nc >= height) continue;
			if (map[nr][nc] != '.') continue;

			if (nr*width + nc == curr.bomb){
				int br = curr.bomb / width + diffr[i], bc = curr.bomb % width + diffc[i];

				if (br < 0 || br >= width || bc < 0 || bc >= height) continue;
				if (map[br][bc] != '.') continue;
				if (br*width + bc == curr.rock) continue;

				if (visited[nr*width + nc][curr.rock][br*width + bc]) continue;
				visited[nr*width + nc][curr.rock][br*width + bc] = true;

				next.pos = nr*width + nc;
				next.rock = curr.rock;
				next.bomb = br*width + bc;

				push(next);
			} else if (nr*width + nc == curr.rock){
				int rr = curr.rock / width + diffr[i], rc = curr.rock % width + diffc[i];

				if (rr < 0 || rr >= width || rc < 0 || rc >= height) continue;
				if (map[rr][rc] != '.') continue;
				if (rr*width + rc == curr.bomb) continue;

				if (visited[nr*width + nc][rr*width + rc][curr.bomb]) continue;
				visited[nr*width + nc][rr*width + rc][curr.bomb] = true;

				next.pos = nr*width + nc;
				next.rock = rr*width + rc;
				next.bomb = curr.bomb;

				push(next);
			} else {
				if (visited[nr*width + nc][curr.rock][curr.bomb]) continue;
				visited[nr*width + nc][curr.rock][curr.bomb] = true;
				
				next.pos = nr*width + nc;
				next.rock = curr.rock;
				next.bomb = curr.bomb;

				push(next);
			}
		}
	}

	return -1;
}

int main(void){
	int i, j;

	scanf("%hd %hd", &height, &width);

	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			do {
				map[i][j] = getchar();
			} while (!isalpha(map[i][j]) && map[i][j] != '.' && map[i][j] != '#');

			switch(map[i][j]){
				case 'P':
					start = i*width + j;
					map[i][j] = '.';
					break;
				case 'R':
					rockStart = i*width + j;
					map[i][j] = '.';
					break;
				case 'B':
					bombStart = i*width + j;
					map[i][j] = '.';
					break;
			}
		}
	}

	printf("%d\n", search());

	return 0;
}

/*
    ID: frceped1
    LANG: C
    TASK: maze1
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 0

#if UPLOAD
	#define openFiles() freopen("maze1.in", "r", stdin); freopen("maze1.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXWIDTH 40
#define MAXHEIGHT 110
#define MAXQUEUE (MAXWIDTH*MAXHEIGHT*4)

int max(int a, int b){
	return a > b ? a : b;
}

typedef struct {
	int row, col, dist;
} state;

state makeState(int row, int col, int dist){
	state s = {.row = row, .col = col, .dist = dist};
	return s;
}

typedef enum {
	up = (1<<0),
	down = (1<<1),
	left = (1<<2),
	right = (1<<3),
} directions;

#define DIRS 4
state movs[DIRS] = {{-1,0,-1}, {1,0,-1}, {0,-1,-1}, {0,1,-1}};

#define dir(i) (1<<i)
#define nextState(s,i) (makeState(s.row + movs[i].row, s.col + movs[i].col, s.dist + 1))

int map[MAXHEIGHT][MAXWIDTH];
bool visited[MAXHEIGHT][MAXWIDTH];

bool wall[MAXWIDTH];
char tmp[MAXWIDTH*2];

int width, height;

void getWalls(bool vertical){
	int i = 0;
	fgets(tmp, MAXWIDTH, stdin);

	for (i = vertical; i <= width*2; i += 2)
		wall[i/2 + 1] = tmp[i] != ' ';
}

void horizontal(int row){
	int i;
	for (i = 1; i <= width+1; i++){
		map[row][i-1] |= wall[i] ? right : 0;
		map[row][i] |= wall[i] ? left : 0;
	}
}

void vertical(int row){
	int i;
	for (i = 1; i <= width; i++){
		map[row-1][i] |= wall[i] ? down : 0;
		map[row][i] |= wall[i] ? up : 0;
	}
}

state queue[MAXQUEUE];
int qs, qe;

#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])
#define queueIsNotEmpty (qs < qe)

int worst;

void search(void){
	state curr, next;
	int i;

	while (queueIsNotEmpty){
		curr = pop();

		if (visited[curr.row][curr.col]) continue;

		visited[curr.row][curr.col] = true;

		worst = max(worst, curr.dist);

		for (i = 0; i < DIRS; i++){
			if (!(map[curr.row][curr.col] & dir(i))){
				next = nextState(curr, i);
				if (!visited[next.row][next.col])
					push(next);
			}
		}
	}
}

int main(void){
	openFiles();

	int i, j;

	scanf("%d %d", &width, &height);
	fgets(tmp, MAXWIDTH, stdin);

	for (i = 1; i <= height; i++){
		getWalls(1);
		vertical(i);
		getWalls(0);
		horizontal(i);
	}
	getWalls(1);
	vertical(i);

	for (i = 1; i <= height; i++){
		if (!(map[i][1] & left))
			push(makeState(i, 1, 1));
		map[i][1] |= left;
		if (!(map[i][width] & right))
			push(makeState(i, width, 1));
		map[i][width] |= right;
	}

	for (i = 1; i <= width; i++){
		if (!(map[1][i] & up))
			push(makeState(1, i, 1));
		map[1][i] |= up;
		if (!(map[height][i] & down))
			push(makeState(height, i, 1));
		map[height][i] |= down;
	}

	search();

	printf("%d\n", worst);

	return 0;
}

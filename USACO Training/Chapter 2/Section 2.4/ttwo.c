/*
    ID: frceped1
    LANG: C
    TASK: ttwo
 */

#include <stdio.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("ttwo.in", "r", stdin); freopen("ttwo.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define DIRS 4
#define MAXMAP 15
#define INF 1e9

typedef enum {
	left = 1,
	down = 2,
	right = 4,
	up = 8
} directions;

typedef struct {
	int row, col;
} point;

point makePoint(int row, int col){
	point p = {row,col};
	return p;
}

point dirs[10] = {[down] = {1,0}, [left] = {0,-1}, [up] = {-1,0}, [right] = {0,1}};

#define nextPoint(p,i) makePoint(p.row + dirs[i].row, p.col + dirs[i].col)
point start[2];

bool map[MAXMAP][MAXMAP];

int min(int a, int b){
	return a < b ? a : b;
}

bool visited[MAXMAP][MAXMAP][MAXMAP][MAXMAP][10][10];

int try(void){
	point f = start[0], c = start[1];
	point nf, nc;
	int a = up, b = up;
	int count = 0;

	while (f.row != c.row || f.col != c.col){
		if (visited[f.row][f.col][c.row][c.col][a][b])
			return 0;
		visited[f.row][f.col][c.row][c.col][a][b] = true;

		nf = nextPoint(f,a);
		if (!map[nf.row][nf.col]){
			a /= 2;
			if (!a) a = 8;
		} else {
			f = nf;
		}

		nc = nextPoint(c,b);
		if (!map[nc.row][nc.col]){
			b /= 2;
			if (!b) b = 8;
		} else {
			c = nc;
		}

		count++;
	}

	return count;
}

int main(void){
	openFiles();

	int i, j, a, b, best;

	for (i = 1; i <= 10; i++){
		for (j = 1; j <= 10; j++){
			char c;
			do {
				c = getchar();
			} while (c != '.' && c != '*' && !isalpha(c));

			if (isalpha(c)){
				start[c == 'C'].row = i;
				start[c == 'C'].col = j;
			}

			map[i][j] = c != '*';
		}
	}

	printf("%d\n", try());

	return 0;
}

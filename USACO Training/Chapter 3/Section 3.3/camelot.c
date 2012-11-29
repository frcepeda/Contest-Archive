/*
    ID: frceped1
    LANG: C
    TASK: camelot
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("camelot.in", "r", stdin); freopen("camelot.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXROW 40
#define MAXCOL 40

int abs(int a){
	return a >= 0 ? a : -a;
}

int min(int a, int b){
	return a < b ? a : b;
}

#define MOVS 8
int diffR[MOVS] = {-2, -1, 1, 2, 2, 1, -1, -2};
int diffC[MOVS] = {1, 2, 2, 1, -1, -2, -2, -1};

typedef struct {
	int row, col;
} point;

#define isValid(r,c) ((r) >= 0 && (r) < height && (c) >= 0 && (c) < width)

point queue[MAXROW*MAXCOL + 100];
int qs, qe;

#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])
#define queueIsNotEmpty (qs < qe)
#define reset() qs = qe = 0

int dist[MAXROW][MAXCOL][MAXROW][MAXCOL];
int best = 1<<30;

point king;
point knights[MAXROW*MAXCOL];
int knightCount;

int width, height;

bool getCoords(point *p){
	char col;

	while ((col = getchar()) != EOF && !isalpha(col));
	
	if (col == EOF) return false;

	p->col = col - 'A';

	scanf("%d", &(p->row));
	p->row--;

	return true;
}

void bfs(int srow, int scol){
	point curr = {srow, scol}, next;
	int i, j;

	reset();
	push(curr);

	while (queueIsNotEmpty){
		curr = pop();

		for (i = 0; i < MOVS; i++){
			if (isValid(curr.row + diffR[i], curr.col + diffC[i]) && !dist[srow][scol][curr.row + diffR[i]][curr.col + diffC[i]]){
				next.row = curr.row + diffR[i];
				next.col = curr.col + diffC[i];
				dist[srow][scol][next.row][next.col] = dist[srow][scol][curr.row][curr.col] + 1;
				push(next);
			}
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			if (dist[srow][scol][i][j] == 0)
				dist[srow][scol][i][j] = -1;

	dist[srow][scol][srow][scol] = 0;
}

#define manhattanDist(a, b, c, d) (abs(a-c) + abs(b-d))
#define diagonalSteps(a, b, c, d) (min(abs(a-c), abs(b-d)))
#define kingDist(srow, scol, erow, ecol) (manhattanDist(srow, scol, erow, ecol) - diagonalSteps(srow, scol, erow, ecol))

int main(void){
	openFiles();

	int i, j, k;

	scanf("%d %d", &height, &width);

	getCoords(&king);

	while (getCoords(&knights[knightCount++]));
	knightCount--;

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			bfs(i,j);

	for (i = 0; i < height; i++){
		for (j = 0; j < width; j++){
			int here = kingDist(i, j, king.row, king.col);

			for (k = 0; k < knightCount; k++){
				if (dist[i][j][knights[k].row][knights[k].col] == -1)
					break;
				here += dist[i][j][knights[k].row][knights[k].col];
			}

			if (k != knightCount) // broke out
				continue;

			best = min(best, here);

			here -= kingDist(i, j, king.row, king.col);

			for (k = 0; k < knightCount; k++){
				here -= dist[i][j][knights[k].row][knights[k].col];

				// ----

				if (dist[i][j][knights[k].row][knights[k].col] != -1 && dist[i][j][king.row][king.col] != -1){
					here += dist[knights[k].row][knights[k].col][king.row][king.col];
					here += dist[i][j][king.row][king.col];

					best = min(best, here);

					here -= dist[knights[k].row][knights[k].col][king.row][king.col];
					here -= dist[i][j][king.row][king.col];
				}

				// ----

				here += dist[i][j][knights[k].row][knights[k].col];
				here += kingDist(king.row, king.col, knights[k].row, knights[k].col);

				best = min(best, here);

				here -= kingDist(king.row, king.col, knights[k].row, knights[k].col);
			}
		}
	}

	printf("%d\n", best);

	return 0;
}

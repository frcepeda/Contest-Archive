#include <stdio.h>

#define MAXROWS 30005
#define MAXCOLUMNS 32

#define EMPTY '.'
#define WALL 'X'
#define PEBBLE 'O'

// MAXROWS > MAXCOLUMNS                            ---v
#define getCoordFromColumnRow(column, row) (((row)*MAXROWS)+(column))
#define getColumnFromCoordNum(coord) ((coord)%MAXROWS)
#define getRowFromCoordNum(coord) ((coord)/MAXROWS)

enum {
	left,
	up,
	right
};

unsigned int path[MAXCOLUMNS][MAXROWS][3];

char grid[MAXCOLUMNS][MAXROWS];
int rowNum, columnNum;

int nextCoord[MAXCOLUMNS];

int addPebbleAtColumnRow(int column, int row){
	unsigned int allPaths = 0;
	int i;

	allPaths |= path[column][row][left];
	allPaths |= path[column][row][up];
	allPaths |= path[column][row][right];

	for (; row < rowNum-1; row++){
		if (grid[column][row+1] == WALL){
			break;
		} else if (grid[column][row+1] == EMPTY){
			path[column][row+1][up] |= allPaths;
		} else if (column > 0 && grid[column-1][row] == EMPTY && grid[column-1][row+1] == EMPTY){
			column--;
			path[column][row+1][right] |= allPaths;
		} else if (column < columnNum-1 && grid[column+1][row] == EMPTY && grid[column+1][row+1] == EMPTY){
			column++;
			path[column][row+1][left] |= allPaths;
		} else {
			break;
		}
	}

	grid[column][row] = PEBBLE;

	if (row > 0 && path[column][row][left]){
		for (i = 0; i < columnNum; i++){
			if (path[column][row][left] & (1<<i)){
				nextCoord[i] = getCoordFromColumnRow(column-1, row-1);
			}
		}
	}

	if (row > 0 && path[column][row][up]){
		for (i = 0; i < columnNum; i++){
			if (path[column][row][up] & (1<<i)){
				nextCoord[i] = getCoordFromColumnRow(column, row-1);
			}
		}
	}

	if (row > 0 && path[column][row][right]){
		for (i = 0; i < columnNum; i++){
			if (path[column][row][right] & (1<<i)){
				nextCoord[i] = getCoordFromColumnRow(column+1, row-1);
			}
		}
	}
}

int main(void){
	int i, j;

	scanf("%d %d", &rowNum, &columnNum);

	for (j = 0; j < rowNum; j++){
		for (i = 0; i < columnNum; i++){
			char c;
			do {
				scanf("%c", &c);
			} while (c != EMPTY && c != PEBBLE && c != WALL);
			grid[i][j] = c;
		}
	}

	for (i = 0; i < columnNum; i++){
		path[i][0][up] = (1<<i);
		nextCoord[i] = i;
	}

	int pebbles;

	scanf("%d", &pebbles);

	while (pebbles--) {
		scanf("%d", &i);
		i--;
		addPebbleAtColumnRow(getColumnFromCoordNum(nextCoord[i]), getRowFromCoordNum(nextCoord[i]));
	}

	for (j = 0; j < rowNum; j++){
		for (i = 0; i < columnNum; i++){
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}

	return 0;
}
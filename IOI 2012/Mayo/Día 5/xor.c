#include <stdio.h>
#include <stdbool.h>

#ifndef CASENUM
#define CASENUM -1
#endif

#define MAXNUM 2010
#define MAXMOVS 1000

bool find3Points(int, int);

bool grid[MAXNUM][MAXNUM]; 
int input[MAXNUM][MAXNUM];

int size;

typedef struct {
	int x1, y1, x2, y2;
} answer;

answer movs[MAXMOVS];
int movCount;

void addToList(int x1, int y1, int x2, int y2){
	movs[movCount].x1 = x1;
	movs[movCount].y1 = y1;
	movs[movCount].x2 = x2;
	movs[movCount].y2 = y2;
	movCount++;
}

bool up4(int x1, int y1, int x2, int y2){
	int i;
	for (i = y1-1; i > 0; i--){
		if (grid[x1][i] && grid[x2][i]){
			grid[x1][y1] = grid[x2][y2] = grid[x1][i] = grid[x2][i] = false;
			addToList(x1, i, x2-1, y1-1);
			return true;
		}
	}

	return false;
}

bool down4(int x1, int y1, int x2, int y2){
	int i;
	for (i = y1+1; i <= size+1; i++){
		if (grid[x1][i] && grid[x2][i]){
			grid[x1][y1] = grid[x2][y2] = grid[x1][i] = grid[x2][i] = false;
			addToList(x1, y1, x2-1, i-1);
			return true;
		}
	}

	return false;
}

bool find4Points(int x, int y){
	int i;

	for (i = x+1; i <= size+1; i++)
		if (grid[i][y])
			if (down4(x,y,i,y) || up4(x,y,i,y))
				return true;

	for (i = x-1; i > 0; i--)
		if (grid[i][y])
			if (down4(i,y,x,y) || up4(i,y,x,y))
				return true;

	return false;
}

bool up3(int x1, int y1, int x2, int y2){
	int i;

	for (i = y1-1; i > 0; i--){
		if (grid[x1][i]){
			grid[x1][y1] = grid[x2][y2] = grid[x1][i] = false;
			grid[x2][i] = true;
			addToList(x1, i, x2-1, y1-1);

			return find4Points(x2, i) || find3Points(x2, i) || true;
		} else if (grid[x2][i]){
			grid[x1][y1] = grid[x2][y2] = grid[x2][i] = false;
			grid[x1][i] = true;
			addToList(x1, i, x2-1, y1-1);

			return find4Points(x1, i) || find3Points(x1, i) || true;
		}
	}
	return false;
}

bool down3(int x1, int y1, int x2, int y2){
	int i;

	for (i = y1+1; i <= size+1; i++){
		if (grid[x1][i]){
			grid[x1][y1] = grid[x2][y2] = grid[x1][i] = false;
			grid[x2][i] = true;
			addToList(x1, y1, x2-1, i-1);

			return find4Points(x2,i) || find3Points(x2,i) || true;
		} else if (grid[x2][i]){
			grid[x1][y1] = grid[x2][y2] = grid[x2][i] = false;
			grid[x1][i] = true;
			addToList(x1, y1, x2-1, i-1);

			return find4Points(x1,i) || find3Points(x1,i) || true;
		}
	}
	return false;
}

bool right(int x1, int y1, int x2, int y2){
	int i;

	for (i = x1+1; i <= size+1; i++){
		if (grid[i][y1]){
			grid[x1][y1] = grid[x2][y2] = grid[i][y1] = false;
			grid[i][y2] = true;
			addToList(x1, y1, i-1, y2-1);

			return find4Points(i,y2) || find3Points(i,y2) || true;
		} else if (grid[i][y2]){
			grid[x1][y1] = grid[x2][y2] = grid[i][y2] = false;
			grid[i][y1] = true;
			addToList(x1, y1, i-1, y2-1);

			return find4Points(i,y1) || find3Points(i,y1) || true;
		}
	}
	return false;
}

bool left(int x1, int y1, int x2, int y2){
	int i;

	for (i = x1-1; i > 0; i--){
		if (grid[i][y1]){
			grid[x1][y1] = grid[x2][y2] = grid[i][y1] = false;
			grid[i][y2] = true;
			addToList(i, y1, x1-1, y2-1);

			return find4Points(i,y2) || find3Points(i,y2) || true;
		} else if (grid[i][y2]){
			grid[x1][y1] = grid[x2][y2] = grid[i][y2] = false;
			grid[i][y1] = true;
			addToList(i, y1, x1-1, y2-1);

			return find4Points(i,y1) || find3Points(i,y1) || true;
		}
	}
	return false;
}

bool find3Points(int x, int y){
	int i;

	for (i = x+1; i <= size+1; i++)
		if (grid[i][y])
			if (up3(x,y,i,y) || down3(x,y,i,y))
				return true;

	for (i = x-1; i > 0; i--)
		if (grid[i][y])
			if (up3(i,y,x,y) || down3(i,y,x,y))
				return true;

	for (i = y+1; i <= size+1; i++)
		if (grid[x][i])
			if (right(x,y,x,i) || left(x,y,x,i))
				return true;

	for (i = y-1; i > 0; i++)
		if (grid[x][i])
			if (right(x,i,x,y) || left(x,i,x,y))
				return true;

	return false;
}

int main(void){
	int i, j;

	scanf("%d", &size);

	for (j = 1; j <= size; j++)
		for (i = 1; i <= size; i++)
			scanf("%d", &input[i][j]);

	for (i = 1; i <= size+1; i++)
		for (j = 1; j <= size+1; j++)
			grid[i][j] = input[i][j] ^ input[i-1][j] ^ input[i][j-1] ^ input[i-1][j-1];

	for (i = 1; i <= size+1; i++)
		for (j = 1; j <= size+1; j++)
			if (grid[i][j])
				find4Points(i,j);

	for (i = size+1; i > 0; i--)
		for (j = size+1; j > 0; j--)
			if (grid[i][j])
				find3Points(i,j);

	//printf("#FILE xor %d\n", CASENUM);
	printf("%d\n", movCount);
	for (i = 0; i < movCount; i++)
		printf("%d %d %d %d\n", movs[i].x1, movs[i].x2, movs[i].y1, movs[i].y2);

	return 0;
}


#include <stdio.h>
#include <stdbool.h>

#define MAXN 13

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

int minc = 1<<30, maxc, minr = 1<<30, maxr;

bool map[MAXN][MAXN];
bool newMap[MAXN][MAXN];
int R, C;

int count(int i, int j){
	return (int)map[i+1][j] + map[i-1][j] + map[i][j+1] + map[i][j-1];
}

int main(void){
	int i, j;

	scanf("%d %d", &R, &C);

	for (i = 1; i <= R; i++){
		for (j = 1; j <= C; j++){
			char c;
			do
				c = getchar();
			while (c != '.' && c != 'X');

			map[i][j] = c == 'X';
		}
	}

	for (i = 1; i <= R; i++){
		for (j = 1 ; j <= C; j++){
			if (map[i][j] && count(i,j) > 1){
				newMap[i][j] = true;
				minc = min(minc, j);
				maxc = max(maxc, j);
				minr = min(minr, i);
				maxr = max(maxr, i);
			}
		}
	}

	for (i = minr; i <= maxr; i++){
		for (j = minc; j <= maxc; j++)
			putchar(newMap[i][j] ? 'X' : '.');
		printf("\n");
	}

	return 0;
}

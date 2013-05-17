#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXMAP 10
int N, M;
bool map[MAXMAP][MAXMAP];
int best;
int movs = 10000000;

void search(int count){
	int i, j, k, _i, _j;

if (!movs--){
printf("%d\n", best - 2);
exit(0);
}

	if (count >= best)
		return;

	bool found = false;

	for (i = 0; i < N && !found; i++)
		for (j = 0; j < M && !found; j++)
			if (!map[i][j])
				found = true;

	i--, j--;

	if (!found){
		if (count < best)
			best = count;
		return;
	}

	/*
	printf("%d %d\n", i, j);
	for (_i = 0; _i < N; _i++)
		for (_j = 0; _j < M; _j++)
			printf("%d%s", map[_i][_j], _j != M-1 ? "" : "\n");
	printf("\n");
	*/

	for (k = 0; i + k < N && !map[i+k][j]; k++){
		map[i+k][j] = true;
		search(count+1);
	}

	for (k-- ; k >= 0; k--)
		map[i+k][j] = false;

	for (k = 0; j + k < M && !map[i][j+k]; k++){
		map[i][j+k] = true;
		search(count+1);
	}

	for (k-- ; k >= 0; k--)
		map[i][j+k] = false;
}

int main(void){
	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			char c;
			do
				c = getchar();
			while (c != '.' && c != '#');
			map[i][j] = c == '#';
		}
	}

	int thingy = 0;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (j == 0 || (!map[i][j] && map[i][j-1]))
				thingy++;

	best = thingy;
	thingy = 0;

	for (j = 0; j < M; j++)
		for (i = 0; i < N; i++)
			if (i == 0 || (!map[i][j] && map[i-1][j]))
				thingy++;

	if (thingy < best)
		best = thingy;

	search(0);

	printf("%d\n", best);

	return 0;
}

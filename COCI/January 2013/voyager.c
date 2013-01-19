#include <stdio.h>

#define MAXN 510
#define INFINITY (1<<28)

typedef enum {
	up,
	right,
	down,
	left
} _dir;

char dirName[] = {[up] = 'U', [down] = 'D', [right] = 'R', [left] = 'L'};
int N, M;

int diffR[] = {-1, 0, 1, 0};
int diffC[] = {0, 1, 0, -1};

char map[MAXN][MAXN];
int memo[MAXN][MAXN][4];

int maxLength(int R, int C, _dir d){
	_dir new; 

	if (R < 0 || R >= N || C < 0 || C >= M || map[R][C] == 'C')
		return 0;

	if (memo[R][C][d] > 0)
		return memo[R][C][d];
	else if (memo[R][C][d] == -1)
		return INFINITY;

	memo[R][C][d] = -1;

	if (map[R][C] == '\\'){
		switch (d){
			case up:
				new = left;
				break;
			case right:
				new = down;
				break;
			case left:
				new = up;
				break;
			case down:
				new = right;
				break;
		}
	} else if (map[R][C] == '/'){
		switch (d){
			case up:
				new = right;
				break;
			case right:
				new = up;
				break;
			case left:
				new = down;
				break;
			case down:
				new = left;
				break;
		}
	} else
		new = d;

	return memo[R][C][d] = memo[R][C][new] = maxLength(R + diffR[new], C + diffC[new], new) + 1;
}

int main(void){
	int i, j, best = 0;
	int PR, PC;
	_dir bestdir;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			do {
				map[i][j] = getchar();
			} while (map[i][j] != '.' && map[i][j] != '\\' && map[i][j] != '/' && map[i][j] != 'C');
		}
	}

	scanf("%d %d", &PR, &PC);

	PR--; PC--;

	for (i = 0; i < 4; i++){
		int tmp = maxLength(PR, PC, i);
		if (tmp > best){
			best = tmp;
			bestdir = i;
		}
	}

	printf("%c\n", dirName[bestdir]);

	if (best < INFINITY)
		printf("%d\n", best);
	else
		printf("Voyager\n");

	return 0;
}

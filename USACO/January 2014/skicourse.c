// 100/100 points
#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("skicourse.in", "r", stdin); freopen("skicourse.out", "w", stdout)
#else
	#define openFiles()
#endif

#define MAXN 102

int N, M;
char grid[MAXN][MAXN];
bool used[MAXN][MAXN];

bool check(int i, int j, int x){
	int a, b, u, r;
	for (a = u = r = 0; a < x; a++){
		for (b = 0; b < x; b++){
			if (used[i+a][j+b])
				u++;
			else if (grid[i+a][j+b] == 'R')
				r++;
		}
	}
	return x*x != u && (!r || x*x - u == r);
}

bool try(int x){
	int i, j, rem = N*M;
	bool didSomething = true;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			used[i][j] = false;

	while (rem && didSomething){
		didSomething = false;

		for (i = 0; i+x <= N && rem; i++)
			for (j = 0; j+x <= M && rem; j++)
				if (check(i,j,x)){
					int a, b;
					for (a = 0; a < x; a++)
						for (b = 0; b < x; b++)
							if (!used[i+a][j+b]){
								used[i+a][j+b] = true;
								rem--;
							}
					didSomething = true;
				}
	}

	return !rem;
}

int main(void){
	int i, j;

	openFiles();

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		scanf("%s", grid[i]);

	int lo = 1, hi = (N < M ? N : M) + 1, mid;

	while (lo < hi){
		mid = (lo + hi)/2;
		if (try(mid))
			lo = mid + 1;
		else
			hi = mid;
	}

	printf("%d\n", lo-1);

	return 0;
}

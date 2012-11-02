/*
    ID: frceped1
    LANG: C
    TASK: stamps
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("stamps.in", "r", stdin); freopen("stamps.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 55
#define MAXPOSSIBLE 3000000

int stamps[MAXN];
int possible[MAXPOSSIBLE];

int N, K;

int min(int a, int b){
	return a < b ? a : b;
}

int main(void){
	openFiles();

	int i, j;

	scanf("%d %d", &K, &N);

	for (i = 0; i < N; i++)
		scanf("%d", &stamps[i]);

	for (i = 1; possible[i-1] <= K; i++){
		possible[i] = K+1;
		for (j = 0; j < N; j++)
			if (i-stamps[j] >= 0)
				possible[i] = min(possible[i], possible[i-stamps[j]] + 1);
	}
	
	printf("%d\n", i-2);

	return 0;
}

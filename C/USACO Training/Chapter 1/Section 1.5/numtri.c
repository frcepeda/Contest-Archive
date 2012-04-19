/*
    ID: frceped1
    LANG: C
    TASK: numtri
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("numtri.in", "r"); out = fopen("numtri.out", "w")
	#define getchar() fgetc(in)
	#define putchar(c) fputc(c, out)
#else
	#define read(...) scanf(__VA_ARGS__)
	#define print(...) printf(__VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), stdin);
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

#define MAXTREE 1000

int size;
int tree[MAXTREE][MAXTREE];
int dp[MAXTREE][MAXTREE];

int max(int a, int b){ return a>b?a:b; }

int main(void){
	openFiles();

	int i,j;
	read("%d", &size);

	for (j = size - 1; j >= 0; j--)
		for (i = 0; i < size - j; i++)
			read("%d", &tree[i][j]);

	for (i = 0; i < size; i++)
		dp[i][0] = tree[i][0];

	for (j = 1; j < size; j++)
		for (i = 0; i < size - j; i++)
			dp[i][j] = max(dp[i][j-1], dp[i+1][j-1]) + tree[i][j];

	print("%d\n", dp[0][size-1]);

	return 0;
}

/*
    ID: frceped1
    LANG: C
    TASK: runround
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("runround.in", "r", stdin); freopen("runround.out", "w", stdout)
#else
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

bool check(int N){
	static char num[20];
	static int len;
	int i = 0, visited, digits = 0;

	for (len = 0; N; len++){
		num[len] = N % 10;
		if (visited & (1<<num[len]))
			return false;
		visited ^= (1<<num[len]);
		N /= 10;
	}

	visited = (1<<len)-1;

	do {
		if ((visited & (1<<i)) == 0)
			break;
		visited ^= (1<<i);
		i -= num[i];
		while (i < 0)
			i += len;
		i %= len;
	} while (visited);

	return visited == 0 && i == 0;
}

int main(void){
	openFiles();

	int N;

	scanf("%d", &N);

	for (N++; ; N++){
		if (check(N)){
			printf("%d\n", N);
			break;
		}
	}

	return 0;
}

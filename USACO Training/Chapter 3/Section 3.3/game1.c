/*
    ID: frceped1
    LANG: C
    TASK: game1
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("game1.in", "r", stdin); freopen("game1.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXN 100

int max(int a, int b){
	return a > b ? a : b;
}

int values[MAXN];
int N, sum;

bool visited[MAXN][MAXN];
int mem[MAXN][MAXN];

int negamax(int s, int e){
	if (visited[s][e])
		return mem[s][e];
	visited[s][e] = true;

	if (s == e)
		return mem[s][e] = values[s];

	return mem[s][e] = max(values[s] - negamax(s+1, e), values[e] - negamax(s, e-1));
}

int main(void){
	openFiles();

	int i, A, B, diff;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d", &values[i]);
		sum += values[i];
	}

	diff = negamax(0, N-1);

/*
	A + B = sum
	A - B = diff
	2A = sum + diff
*/

	A = (sum + diff)/2;
	B = A - diff;

	printf("%d %d\n", A, B);

	return 0;
}

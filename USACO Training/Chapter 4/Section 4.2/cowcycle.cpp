/*
    ID: frceped1
    LANG: C++
    TASK: cowcycle
 */

#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("cowcycle.in", "r", stdin); freopen("cowcycle.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

double bestVariance = 1e50;
int best[2][10];

int chosen[2][10];

int F, R, F1, F2, R1, R2;

void check(void){
	int i, j, c = 0;
	double var = 0, mean = 0;
	double ratios[100];

	if (3*chosen[0][0]*chosen[1][0] > chosen[0][F-1]*chosen[1][R-1])
		return;

	for (i = 0; i < F; i++)
		for (j = 0; j < R; j++, c++)
			ratios[c] = ((double)chosen[0][i])/chosen[1][j];

	sort(ratios, ratios + c);

	for (i = 1; i < c; i++)
		mean += ratios[i] - ratios[i-1];
	mean /= c-1;

	for (i = 1; i < c; i++)
		var += ((ratios[i] - ratios[i-1]) - mean) * ((ratios[i] - ratios[i-1]) - mean);
	var /= c-1;

	if (var < bestVariance){
		bestVariance = var - 1e-10;

		for (i = 0; i < F; i++)
			best[0][i] = chosen[0][i];

		for (i = 0; i < R; i++)
			best[1][i] = chosen[1][i];
	}
}

void chooseRear(int n, int i){
	if (n == R){
		check();
		return;
	}

	for (; i <= R2; i++){
		chosen[1][n] = i;
		chooseRear(n + 1, i + 1);
	}
}

void chooseFront(int n, int i){
	if (n == F){
		chooseRear(0, R1);
		return;
	}

	for (; i <= F2; i++){
		chosen[0][n] = i;
		chooseFront(n + 1, i + 1);
	}
}

int main(void){
	int i;

	openFiles();

	scanf("%d %d %d %d %d %d", &F, &R, &F1, &F2, &R1, &R2);

	chooseFront(0, F1);

	for (i = 0; i < F; i++)
		printf("%d%c", best[0][i], i != F-1 ? ' ' : '\n');

	for (i = 0; i < R; i++)
		printf("%d%c", best[1][i], i != R-1 ? ' ' : '\n');

	return 0;
}

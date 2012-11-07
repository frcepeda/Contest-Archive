/*
    ID: frceped1
    LANG: C
    TASK: ratios
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("ratios.in", "r", stdin); freopen("ratios.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define INF 10000

int a, b, c, sum = INF, amount;
int mixtures[3][3];
int goal[3], gcdMultiple;

int gcd(int a, int b){
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

void try(int x, int y, int z){
	int tmp[3] = {0};
	int i, j;

	if (x+y+z > sum)
		return;

	for (i = 0; i < 3; i++)
		tmp[i] += x*mixtures[0][i];
	for (i = 0; i < 3; i++)
		tmp[i] += y*mixtures[1][i];
	for (i = 0; i < 3; i++)
		tmp[i] += z*mixtures[2][i];

	int g = gcd(gcd(tmp[0], tmp[1]), tmp[2]);

	if (g == 0)
		return;

	for (i = 0; i < 3; i++)
		if (tmp[i]/g*gcdMultiple != goal[i])
			return;

	if (g < gcdMultiple || (gcdMultiple != 1 && g != 1 && gcd(g, gcdMultiple) == 1))
		return;

	a = x, b = y, c = z;
	sum = x+y+z;
	amount = g / gcdMultiple;
}

int main(void){
	openFiles();

	int i, j, k;

	for (i = 0; i < 3; i++)
		scanf("%d", &goal[i]);
	gcdMultiple = gcd(gcd(goal[0], goal[1]), goal[2]);

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &mixtures[i][j]);

	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			for(k = 0; k < 100; k++)
				try(i,j,k);

	if (sum != INF)
		printf("%d %d %d %d\n", a, b, c, amount);
	else	
		printf("NONE\n");

	return 0;
}

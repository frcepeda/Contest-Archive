#include <stdio.h>

#define MAXPYRAMID 1000

int N, T, X, Y;

int sizes[MAXPYRAMID];
unsigned long long int choose[MAXPYRAMID][MAXPYRAMID];

int abs(int a){
	return a < 0 ? -a : a;
}

int min(int a, int b){
	return a < b ? a : b;
}

double answerThingy(int i, int n){
	unsigned long long int total = 0, mine = 0;
	int j, a = N - sizes[i-1], lim = i*2;

	if (a > 2*i){
		if (n <= (a - 2*i))
			return 1;
		lim = i*2 - (a - 2*i);
		n -= i;
		a -= (a - 2*i) * 2;
	}

	for (j = 0; j <= min(lim,a); j++){
		total += choose[a][j];
		if (j >= n)
			mine += choose[a][j];
	}

	/*
	if (n == i*2 + 1 && a != sizes[i] - sizes[i+1])
		return 0;
	*/

	return (double)mine/total;
}

int main(void){
	int t, i, j;

	sizes[0] = 1;
	for (i = 1; i < MAXPYRAMID; i++)
		sizes[i] = sizes[i-1] + 4*i + 1;

	for (i = 0; i < MAXPYRAMID; i++){
		choose[i][0] = 1;
		for (j = 1; j <= i; j++)
			choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
	}

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		double ans = 0;

		scanf("%d %d %d", &N, &X, &Y);

		for (i = 0; sizes[i] < N; i++);

		if (sizes[i] == N && X == 0 && Y == i*2)
			ans = 1;
		else if (abs(X) + abs(Y) <= 2 * (i - 1))
			ans = 1;
		else if (abs(X) + abs(Y) > 2 * i)
			ans = 0;
		else
			ans = answerThingy(i, abs(Y) + 1);

		printf("Case #%d: %lf\n", t, ans);
	}

	return 0;
}

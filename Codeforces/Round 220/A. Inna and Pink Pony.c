#include <stdio.h>

#define INF (1<<29)

int n, m, i, j, a, b;

int min(int a, int b) { return a < b ? a : b; }

int solve(int i, int j){
	int ret = 0;
	if (i % a || j % b) return INF;
	ret = min(i/a, j/b);
	i -= ret * a;
	j -= ret * b;
	if (i && j) return INF;
	if (j/b % 2 != 0 || i/a % 2 != 0) return INF;
	if (i == 0 && j != 0 && a >= n) return INF;
	if (j == 0 && i != 0 && b >= m) return INF;
	return ret + j/b + i/a;
}

int main(void){
	scanf("%d %d %d %d %d %d", &n, &m, &i, &j, &a, &b);
	int x = min(min(solve(i-1,j-1),solve(n-i,j-1)),min(solve(i-1,m-j),solve(n-i,m-j)));
	if (x < INF)
		printf("%d\n", x);
	else
		printf("Poor Inna and pony!\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1003

int max(int a, int b){ return a > b ? a : b; }

int n, m;
char v[MAXN][MAXN];
int a[MAXN][MAXN];
char table[MAXN][MAXN];

char next[256] = {['D'] = 'I', ['I'] = 'M', ['M'] = 'A', ['A'] = 'D'};

int search(int i, int j){
	if (v[i][j] == 2){
		printf("Poor Inna!\n");
		exit(0);
	} else if (v[i][j] == 1) return a[i][j];
	v[i][j] = 2;
	a[i][j] = 1;
	if (j+1 < m && table[i][j+1] == next[table[i][j]]) a[i][j] = max(a[i][j], search(i,j+1) + 1);
	if (i+1 < n && table[i+1][j] == next[table[i][j]]) a[i][j] = max(a[i][j], search(i+1,j) + 1);
	if (j       && table[i][j-1] == next[table[i][j]]) a[i][j] = max(a[i][j], search(i,j-1) + 1);
	if (i       && table[i-1][j] == next[table[i][j]]) a[i][j] = max(a[i][j], search(i-1,j) + 1);
	v[i][j] = 1;
	return a[i][j];
}

int main(void){
	int i, j, a = 0;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", table[i]);

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (table[i][j] == 'D' && !v[i][j])
				a = max(a, search(i,j));

	if (a < 4)
		printf("Poor Dima!\n");
	else
		printf("%d\n", a/4);
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAXN 520

int n, f;
char story[MAXN][32];
int path[MAXN][2];
int soFar[MAXN];

int dfs(int s, int d){
	if (s == 0) return;

	soFar[d] = s;

	if (s == f){
		printf("%d\n", d+1);
		for (s = 0; s <= d; s++)
			printf("%s\n", story[soFar[s]]);
		exit(0);
	}

	dfs(path[s][0], d+1);
	dfs(path[s][1], d+1);
}

int main(void){
	int i;

	scanf("%d %d\n", &n, &f);

	for (i = 1; i <= n; i++)
		scanf("\"%[^\"]\" %d %d\n", story[i], &path[i][0], &path[i][1]);

	dfs(1,0);

	return 0;
}

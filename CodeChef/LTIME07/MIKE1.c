#include <stdio.h>

#define MAXN 505

int N, M, L;
int map[MAXN][MAXN];
long long E1, E2;

#define valid(i,N) ((i) > 0 && (i) <= N)

int main(void){
	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			scanf("%d", &map[i][j]);

	scanf("%d", &L);

	while (L--){
		scanf("%d %d", &i, &j);
		if (E1 >= 0 && valid(i,N) && valid(j,M))
			E1 += map[i][j];
		else E1 = -1;
		if (E2 >= 0 && valid(j,N) && valid(i,M))
			E2 += map[j][i];
		else E2 = -1;
	}

	printf("%lld\n", E1 > E2 ? E1 : E2);

	return 0;
}

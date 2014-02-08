#include <stdio.h>
#include <string.h>

#define MAXN 10100

int N, M;
char a[MAXN], b[MAXN];
char p[256] = {['C'] = 1, ['G'] = 2, ['T'] = 3};
int cost[4];

int main(void){
	int i, j, k, best = 1<<30;

	scanf("%s", a);
	scanf("%s", b);
	N = strlen(a);
	M = strlen(b);

	for (i = 0; i < 4; i++)
		scanf("%d", &cost[i]);

	for (i = 0; i < N; i++)
		a[i] = p[a[i]];
	for (i = 0; i < M; i++)
		b[i] = p[b[i]];

	for (i = 0; i < N; i++){
		int t = 0;
		for (j = 0, k = i; j < M; j++){
			if (k < N && b[j] == a[k])
				k++;
			else
				t += cost[b[j]];
		}
		if (t < best)
			best = t;
	}

	printf("%d\n", best);

	return 0;
}

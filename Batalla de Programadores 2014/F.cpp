#include <cstdio>

using namespace std;

#define MAXN 110
#define MOD 10000

int N, L, S, T;

int adj[MAXN][MAXN];
int ans[MAXN][MAXN];
int tmp[MAXN][MAXN];

void matmult(int x[MAXN][MAXN], int y[MAXN][MAXN]){
	int i, j, k;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			tmp[i][j] = 0;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				tmp[i][j] = (tmp[i][j] + x[i][k] * y[k][j]) % MOD;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			x[i][j] = tmp[i][j];
}

void matexp(){
	for (int i = 0; i < N; i++)
		ans[i][i] = 1;
	for (; L; L /= 2){
		if (L & 1)
			matmult(ans, adj);
		matmult(adj, adj);
	}
}

int main(){
	int i, j, x;

	scanf("%d %d", &N, &L);
	scanf("%d %d", &S, &T);

	for (i = 0; i < N; i++){
		for (j = 0; j < 4; j++){
			scanf("%d", &x);
			adj[i][x-1]++;
		}
	}

	matexp();

	printf("%d\n", ans[S-1][T-1]);
}

#include <cstdio>
#include <algorithm>

using namespace std;

#define MOD 1000000007L
#define MAXN 70

int N, K;
int A[MAXN];
long long M[MAXN][MAXN], R[MAXN][MAXN], T[MAXN][MAXN];

void mm(long long a[MAXN][MAXN], long long b[MAXN][MAXN]){
	int i, j, k;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++){
			T[i][j] = 0;
			for (k = 0; k < N; k++)
				T[i][j] = (T[i][j] + a[i][k] * b[k][j]) % MOD;
		}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = T[i][j];
}

void matmult(){
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			R[i][j] = (i==j);

	for (; K; K /= 2){
		if (K % 2)
			mm(R, M);
		mm(M, M);
	}
}

int main(){
	int i, j;

	while (scanf("%d %d", &N, &K) != EOF){
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				M[i][j] = 0;

		for (i = 0; i < N; i++){
			int x, y;
			scanf("%d", &A[i]);
			scanf("%d", &x);
			for (j = 0; j < x; j++){
				scanf("%d", &y);
				M[i][y-1]++;
			}
		}

		matmult();

		for (i = 0; i < N; i++){
			long long ans = 0;
			for (j = 0; j < N; j++)
				ans = (ans + R[i][j] * A[j]) % MOD;
			printf("%lld\n", ans);
		}
	}
}

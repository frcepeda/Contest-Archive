// Accepted
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

#define MAXN 1001000
#define MAXLGN 21

int N, B;
int batIdx[MAXN], batLen[MAXN], frogs[MAXN], batTot[MAXN];
long long acc[MAXN];
int _maxfrog[MAXN][MAXLGN], _maxbat[MAXN][MAXLGN];

int lg2(int x){
	int r = -1;
	for (; x; x /= 2, r++);
	return r;
}

int getMax(int arr[MAXN][MAXLGN], int a, int b){
	int l = lg2(b - a + 1);
	return max(arr[a][l], arr[b - (1<<l) + 1][l]);
}

int main(){
	int i, j;

	for (; scanf("%d", &batLen[B]), batLen[B]; B++){
		batIdx[B+1] = batIdx[B] + batLen[B];
		for (i = 0; i < batLen[B]; i++, N++){
			scanf("%d", &frogs[N]);
			batTot[B] += frogs[N];
			acc[N] = (N ? acc[N-1] : 0) + frogs[N];
		}
	}

// Frogs
	for (i = 0; i < N; i++)
		_maxfrog[i][0] = frogs[i];

	for (j = 1; j < MAXLGN; j++)
		for (i = 0; i < N; i++)
			_maxfrog[i][j] = max(_maxfrog[i][j-1], _maxfrog[min(i+(1<<(j-1)),N-1)][j-1]);

// Batallions
	for (i = 0; i < B; i++)
		_maxbat[i][0] = batTot[i];

	for (j = 1; j < MAXLGN; j++)
		for (i = 0; i < B; i++)
			_maxbat[i][j] = max(_maxbat[i][j-1], _maxbat[min(i+(1<<(j-1)),B-1)][j-1]);

	int Q;
	scanf("%d", &Q);

	while (Q--){
		char type[10];
		int Bi, Bj, p, s;
		scanf("%s", type);

		if (strcmp(type, "BFG") == 0){
			scanf("%d %d %d", &Bi, &p, &s);
			printf("%d\n", getMax(_maxfrog, batIdx[Bi] + p, batIdx[Bi] + s));
		} else if (strcmp(type, "BFZ") == 0){
			scanf("%d %d %d %d", &Bi, &p, &Bj, &s);
			printf("%d\n", getMax(_maxfrog, batIdx[Bi] + p, batIdx[Bj] + s));
		} else if (strcmp(type, "BG") == 0){
			scanf("%d %d", &Bi, &Bj);
			printf("%d\n", getMax(_maxbat, Bi, Bj));
		} else if (strcmp(type, "CG") == 0){
			scanf("%d %d", &Bi, &Bj);
			printf("%lld\n", acc[batIdx[Bj] + batLen[Bj] - 1] - (Bi > 0 ? acc[batIdx[Bi] - 1] : 0));
		} else if (strcmp(type, "CFG") == 0){
			scanf("%d %d %d %d", &Bi, &p, &Bj, &s);
			printf("%lld\n", acc[batIdx[Bj] + s] - (Bi + p > 0 ? acc[batIdx[Bi] + p - 1] : 0));
		} else {
			assert(false);
		}
	}
}

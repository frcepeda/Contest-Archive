#include <stdio.h>
#include <stdbool.h>

#define MAXN 510

int map[MAXN][MAXN];
int N;

int parent[MAXN*MAXN];
int count[MAXN*MAXN];
int rank[MAXN*MAXN];

int abs(int a){
	return a >= 0 ? a : -a;
}

int set(int a){
	if (parent[a] == a)
		return a;
	return parent[a] = set(parent[a]);
}

void join(int a, int b){
	int A = set(a);
	int B = set(b);

	if (A == B) return;

	if (rank[A] < rank[B]){
		parent[A] = B;
		count[B] += count[A];
	} else if (rank[B] < rank[A]) {
		parent[B] = A;
		count[A] += count[B];
	} else {
		parent[A] = B;
		count[B] += count[A];
		rank[B]++;
	}
}

bool possible(int D){
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			parent[i*N + j] = i*N + j, rank[i*N + j] = count[i*N + j] = 1;

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			int coord = i*N + j;

			if (j > 0 && abs(map[i][j-1] - map[i][j]) <= D)
				join(coord, i*N + j-1);

			if (i > 0 && abs(map[i-1][j] - map[i][j]) <= D)
				join(coord, (i-1)*N + j);

			if (count[set(coord)] >= (N*N + 1)/2)
				return true;
		}
	}

	return false;
}

int main(void){
	freopen("tractor.in", "r", stdin);
	freopen("tractor.out", "w", stdout);

	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	int hi = 1000001, lo = 0, mid;

	while (lo < hi){
		mid = (hi + lo) / 2;

		if (possible(mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%d\n", hi);

	return 0;
}

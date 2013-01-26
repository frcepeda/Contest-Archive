#include <stdio.h>

#define MAXN 110

int points[MAXN][2];
int N;
int merged;

int parent[MAXN];
int rank[MAXN];

int set(int i){
	if (parent[i] == i)
		return i;
	else return parent[i] = set(parent[i]);
}

void merge(int i, int j){
	int pi = set(i);
	int pj = set(j);

	if (rank[pi] < rank[j]){
		parent[pi] = pj;
	} else if (rank[pi] > rank[j]){
		parent[pj] = pi;
	} else {
		parent[pi] = pj;
		rank[pj]++;
	}
}

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d %d", &points[i][0], &points[i][1]);

	for (i = 0; i < N; i++)
		parent[i] = i;

	for (i = 0; i < N; i++)
		for (j = i+1; j < N; j++)
			if ((points[i][0] == points[j][0] || points[i][1] == points[j][1]) && set(i) != set(j))
				merged++, merge(i,j);

	printf("%d\n", N - merged - 1);

	return 0;
}

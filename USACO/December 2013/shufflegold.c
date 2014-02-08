#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("shufflegold.in", "r", stdin); freopen("shufflegold.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXM 100010

int N, M, Q;
int P[MAXM], R[MAXM];

int query(int rem, int idx){
	for (; idx <= M && rem; rem--)
		idx = R[idx] + 1;
	return idx > M ? rem + M : idx - 1;
	/*
	if (idx > M) return rem + M;
	if (!rem) return idx - 1;
	return query(rem-1, R[idx] + 1);
	*/
}

int main(void){
	int i;
	openFiles();

	scanf("%d %d %d", &N, &M, &Q);

	for (i = 1; i <= M; i++){
		scanf("%d", &P[i]);
		R[P[i]] = i;
	}

	while (Q--){
		scanf("%d", &i);
		if (i >= M)
			printf("%d\n", query(N-i+1, 1));
		else
			printf("%d\n", query(N-M+1, M-i+1));
	}

	return 0;
}

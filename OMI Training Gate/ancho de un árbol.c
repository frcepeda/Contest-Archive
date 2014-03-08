#include <stdio.h>

#define MAXN 1010

int N;
int left[MAXN], right[MAXN];
int colLeft[MAXN], colRight[MAXN];

int search(int n, int level, int off){
	if (n == -1) return 0;

	int l = search(left[n], level+1, off);
	int r = search(right[n], level+1, off+l+1);

	if (off + l + 1 < colLeft[level])
		colLeft[level] = off + l + 1;

	if (off + l + 1 > colRight[level])
		colRight[level] = off + l + 1;

	return l + 1 + r;
}

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		colLeft[i] = MAXN;

	for (i = 0; i < N; i++){
		scanf("%d", &j);
		scanf("%d %d", &left[j], &right[j]);
	}

	search(1, 0, 0);

	int best = 0;
	for (i = 0; i < N; i++)
		if (colRight[i] - colLeft[i] > colRight[best] - colLeft[best])
			best = i;

	printf("%d %d\n", best + 1, colRight[best] - colLeft[best] + 1);

	return 0;
}

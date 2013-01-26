#include <stdio.h>
#include <assert.h>

#define MAXN 300

typedef struct {
	unsigned long long int x, y, z;
} block;

int max(int a, int b){
	return a > b ? a : b;
}

block blocks[MAXN];

unsigned long long int dp[MAXN][MAXN];
unsigned long long int sizes[MAXN];
int siz;
int n;

int lluintCmp(const void *ap, const void *bp){
	unsigned long long int a = *(unsigned long long int *)ap;
	unsigned long long int b = *(unsigned long long int *)bp;
	if (a > b) return 1;
	else if (a < b) return -1;
	else return 0;
}

int blockCmp(const void *ap, const void *bp){
	block *a = (block *)ap;
	block *b = (block *)bp;
	if (a->x != b->x)
		return a->x - b->x;
	if (a->y != b->y)
		return a->y - b->y;
	return a->z - b->z;
}

int relativeSize(int n){
	int lo = 0, hi = siz, mid;

	while (lo < hi){
		mid = (lo + hi);

		if (sizes[mid] >= n)
			hi = mid;
		else
			lo = mid + 1;
	}

	return hi + 1;
}

int main(void){
	int i, j, k;

	while (scanf("%d", &n), n){
		siz = 0;

		for (i = 0; i < n; i++){
			scanf("%llu %llu %llu", &blocks[i].x, &blocks[i].y, &blocks[i].z);
			sizes[siz++] = blocks[i].x;
			sizes[siz++] = blocks[i].y;
			sizes[siz++] = blocks[i].z;
		}

		qsort(sizes, siz, sizeof(sizes[0]), lluintCmp);

		for (i = 0; i < n; i++){
			blocks[n+i].x = blocks[2*n+i].y = blocks[3*n+i].y = blocks[4*n+i].z = blocks[5*n+i].z = blocks[i].x;
			blocks[n+i].z = blocks[2*n+i].x = blocks[3*n+i].z = blocks[4*n+i].x = blocks[5*n+i].y = blocks[i].y;
			blocks[n+i].y = blocks[2*n+i].z = blocks[3*n+i].x = blocks[4*n+i].y = blocks[5*n+i].x = blocks[i].z;
		}
		
		n *= 6;

		blocks[n++] = blocks[0];
		blocks[n].x = blocks[n].y = blocks[n].z = 1<<30;

		qsort(blocks+1, n, sizeof(block), blockCmp);

		for (i = 1; i < n; i++){
			for (j = i+1; j <= n; j++){
				if (blocks[i].x < blocks[j].x && blocks[i].y < blocks[j].y)
					dp[i][j] = max(dp[i-1][j], dp[i-1][i] + blocks[i].z);
				else
					dp[i][j] = dp[i-1][j];
			}
		}

		printf("%llu\n", dp[n-1][n]);
	}

	return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define MAXN 16
int N, K, rules[8];
int depth[1<<MAXN];

int min(int a, int b) { return a < b ? a : b; }

int next(int x){
	int r = 0, i;

	x = (x >> (N-1)) | (x << 1) | ((x&1) << (N+1));

	for (i = 0; i < N; i++)
		r |= rules[(x >> i) & 7] << i;

	return r;
}

int toNum(char *x, int n){
	int r = 0;
	while (n--)
		r = (r << 1) | (x[n] == 'O');
	return r;
}

int reverse(int x, int n){
	int r = 0, i;
	for (i = 0; i < n; i++)
		r |= (!!(x & (1<<i))) << (n-i-1);
	return r;
}

int rotate(int i, int n){
	return ((i << 1) & ((1<<n)-1)) | (i >> (n-1));
}

int minRotation(int x, int n){
	int m = 1<<30, i;
	x = reverse(x, n);
	for (i = 0; i < n; i++, x = rotate(x, n))
		m = min(m, x);
	return reverse(m, n);
}

void printAsString(int x, int n){
	for (x = minRotation(x,n); n; n--, x >>= 1)
		putchar((x&1) ? 'O' : 'I');
	putchar('\n');
}

int dfs(int x, int d){
	//printAsString(x, N);

	if (d == K){
		printAsString(x, N);
		exit(0);
	}

	if (depth[x]){
		K = (K - depth[x]) % (d - depth[x]);
		while (K--) x = next(x);
		printAsString(x, N);
		exit(0);
	}

	depth[x] = d;

	dfs(next(x), d+1);
}

int main(void){
	int i, j, start;
	char tmp[MAXN+10];

	scanf("%d", &N);

	scanf("%s", tmp);

	start = toNum(tmp, N);

	for (i = 0; i < 8; i++){
		scanf("%s", tmp);
		j = toNum(tmp, 4);
		rules[((j & 2) >> 1) | ((j & 1) << 1) | (j & 4)] = !!(j & 8);
	}

	scanf("%d", &K);

	dfs(start, 0);

	return 0;
}

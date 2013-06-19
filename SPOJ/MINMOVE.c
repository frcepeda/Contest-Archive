#include <stdio.h>
#include <assert.h>
#include <strings.h>

#define MAXN 200100
#define BASE 29

int min(int a, int b){
	return a < b ? a : b;
}

char str[MAXN];
unsigned long long int hash[MAXN];
unsigned long long int bpow[MAXN];

int N;

#define getHash(h,a,b) (a ? (h[(b)] - h[(a)-1] * bpow[(b)-(a)+1]) : h[(b)])

int firstDiffChar(char *a, int aoff, char *b, int boff, unsigned long long int *h1, unsigned long long int *h2, int n){
	int lo = 0, hi = n, mid;

	while (lo < hi){
		mid = (lo + hi) / 2;
		if (getHash(h1, aoff, mid + aoff) != getHash(h2, boff, mid + boff))
			hi = mid;
		else
			lo = mid + 1;
	}

	return hi;
}

int hstrncmp(char *a, int aoff, char *b, int boff, unsigned long long int *h1, unsigned long long int *h2, int n){
	int d = firstDiffChar(a, aoff, b, boff, h1, h2, n);
	return d < n ? a[aoff + d] - b[boff + d] : 0;
}

int getLeastLex(void){
	int i, best = 0;

	for (i = 1; i < N; i++)
		if (hstrncmp(str, best, str, i, hash, hash, N) > 0)
			best = i;

	return best;
}

int main(void){
	int i;

	scanf("%s", str);
	N = strlen(str);

	bpow[0] = 1;
	for (i = 1; i <= N*2; i++)
		bpow[i] = bpow[i-1] * BASE;

	strncpy(str + N, str, N);

	for (i = 0; i < N; i++)
		hash[i] = (i > 0 ? hash[i-1] : 0) * BASE + str[i] - 'A';

	printf("%d\n", getLeastLex());

	return 0;
}

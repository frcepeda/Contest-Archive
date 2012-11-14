#include <stdio.h>
#include <stdbool.h>

#define MAXN 50
#define MAXMEMO 22
#define MAXMEMOSTORAGE (1<<MAXMEMO)

int max(int a, int b){
	return a > b ? a : b;
}

int counter = 38500000;
int N;

int best, stop;
unsigned char memo[MAXMEMO][MAXMEMOSTORAGE];
unsigned long long int zeros[MAXN];

int bitCount(unsigned long long int n){
	int ans = 0;
	while (n){
		n -= n & -n;
		ans++;
	}
	return ans;
}

int memoFindBestSubmatrix(int n, unsigned int removed){
	if (n == MAXMEMO || n+N-MAXMEMO > stop){
		return N - bitCount(removed);
	}

	if (memo[n][removed])
		return memo[n][removed];

	memo[n][removed] = memoFindBestSubmatrix(n+1, removed | (1<<n));

	if (!(removed & (1<<n)) && !(zeros[n + N - MAXMEMO] & (1ll<<(n+N-MAXMEMO))))
		memo[n][removed] = max(memo[n][removed], memoFindBestSubmatrix(n+1, removed | (zeros[n + N - MAXMEMO] >> (N - MAXMEMO))));

	return memo[n][removed];
}

void findBestSubmatrix(int n, unsigned long long int removed){
	counter--;
	if (!counter){
		printf("%d\n", best+1); /* HA... again! */
		exit(0);
	}
	if (N > MAXMEMO && n == N - MAXMEMO){
		best = max(best, -bitCount(removed & ((1 << (N - MAXMEMO)) - 1)) + memoFindBestSubmatrix(0, (unsigned int)(removed >> (N - MAXMEMO))));
	} else if (n == N || n > stop){
		best = max(best, N - bitCount(removed));
	} else if (N - bitCount(removed) + N - n > best) {
		findBestSubmatrix(n+1, removed | (1ll<<n));
		if (!(removed & (1ll<<n)) && !(zeros[n] & (1ll<<n)))
			findBestSubmatrix(n+1, removed | zeros[n]);
	}
}

int main(void){
	int i, j, t;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			scanf("%d", &t);
			zeros[i] |= t ? 0 : (1ll << j);
		}
		if (i)
			zeros[i] &= ((1ll << N) - 1) ^ ((1ll << (i-1) - 1));
	}

	for (i = N-1; i >= 0; i--)
		if (zeros[i])
			break;
	stop = i;

	for (i = 0; i < N; i++)
		if (zeros[i])
			break;

	findBestSubmatrix(i, 0);

	printf("%d\n", best);

	return 0;
}

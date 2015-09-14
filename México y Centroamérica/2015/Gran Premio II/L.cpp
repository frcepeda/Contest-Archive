#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 30010

int N, K;
long long x[MAXN];

int main(){
	while (scanf("%d %d", &N, &K) == 2){
		int i, j, k;

		for (i = 0; i < N; i++){
			x[i] = 0;

			for (j = 0; j < K; j++){
				scanf("%d", &k);
				x[i] |= (1LL<<j) * (k % 2);
			}
		}

		for (i = 0; i < K; i++){
			for (j = i; j < N; j++)
				if (x[j] & (1LL<<i))
					break;

			if (j == N) break;

			swap(x[i], x[j]);

			for (j = i+1; j < N; j++)
				if (x[j] & (1LL<<i))
					x[j] ^= x[i];
		}

		printf("%c\n", i < K || (i == K && N == K)? 'S' : 'N');
	}
}

#include <stdio.h>

#define MAXN 1000010
#define MOD 1000000003

int T, C;
long long int sum[MAXN];

int main(void){
	long long int i, acc = 0;

	for (i = 1; i < MAXN; i++){
		acc = (acc + i*i*i) % MOD;
		sum[i] = (sum[i-1] + acc) % MOD;
	}

	scanf("%d", &T);

	while (T--){
		scanf("%d", &C);
		printf("%lld\n", sum[C]);
	}

	return 0;
}


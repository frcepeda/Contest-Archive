#include <cstdio>

using namespace std;

#define MAXN 2000100
#define MOD 1000000007L

long long F[MAXN];
int N, K;

long long modinv(long long x){
	long long e = MOD-2, r = 1;

	x %= MOD;

	for (; e; e /= 2){
		if (e % 2 == 1)
			r = (r * x) % MOD;
		x = (x * x) % MOD;
	}

	return r;
}

int main(){
	F[0] = 1;
	for (long long i = 1; i < MAXN; i++)
		F[i] = (F[i-1] * i) % MOD;

	while (scanf("%d %d", &N, &K) != EOF)
		printf("%lld\n", (F[N+K] * modinv(F[N] * F[K])) % MOD);
}

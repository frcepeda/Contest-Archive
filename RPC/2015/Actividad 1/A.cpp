#include <cstdio>

#define MAXN 100100
#define mod 1000000007LL

int T, N;
long long f[MAXN] = {1};

int main(){
	scanf("%d", &T);

	for (int i = 1; i < MAXN; i++)
		f[i] = (f[i-1] * i) % mod;

	while (T--){
		scanf("%d", &N);
		printf("%lld\n", (f[N] - 1 + mod) % mod);
	}
}

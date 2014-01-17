#include <cstdio>
#include <algorithm>

using namespace std;

int N, K, M;
long long ans;

long long _pow(int x, int k){
	long long i = 1;
	while (k--) i = (i*x) % M;
	return i;
}

int main(void){
	int i, j, k;

	scanf("%d %d %d", &N, &K, &M);

	for (i = 1; i < N; i++)
		if (__gcd(i,N) == 1)
			ans = (ans + _pow(i,K)) % M;

	printf("%lld\n", ans);

	return 0;
}

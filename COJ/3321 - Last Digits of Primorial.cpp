#include <cstdio>
#include <algorithm>

#define LIM 1000100

using namespace std;

#ifndef LOL
typedef __int128 ll;
#else
typedef long long ll;
#endif

bool notPrime[LIM];
bool w[LIM];
ll f[LIM];

int main(){
	f[0] = f[1] = 1;
	notPrime[0] = notPrime[1] = true;

	for (int i = 2; i*i < LIM; i++)
		if (!notPrime[i])
			for (int j = i*i; j < LIM; j += i)
				notPrime[j] = true;

	const long long MOD = 10000000000LL;
	for (int i = 2; i < LIM; i++){
		f[i] = f[i-1] * (!notPrime[i] ? i : 1);
		w[i] = w[i-1] || (f[i] >= MOD);
		f[i] %= MOD;
	}

	int T, N;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		if (w[N])
			printf("%010lld\n", f[N]);
		else
			printf("%lld\n", f[N]);
	}
}

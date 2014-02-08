#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100010
#define LIM 320
#define pb push_back

typedef long long ll;

int N;
int a[MAXN];
bool notPrime[MAXN];
int primes[10000], P;
vector<int> factors[MAXN];

ll solve(int a, int b, int d){
	int i;

	if (a >= b) return 0;

	for (i = a; i < b; i++)
		if (factors[i].size() <= d || factors[i][d] != factors[a][d])
			break;

	return factors[a][d] * solve(a, i, d+1) + solve(i, b, d+1) + 1;
}

int main(){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);

	notPrime[0] = notPrime[1] = true;
	for (i = 4; i < MAXN; i += 2)
		notPrime[i] = true;

	for (i = 3; i < LIM; i += 2)
		if (!notPrime[i])
			for (j = i*i; j < MAXN; j += i)
				notPrime[j] = true;

	primes[P++] = 2;
	for (i = 3; i < MAXN; i += 2)
		if (!notPrime[i])
			primes[P++] = i;

	for (i = 0; i < N; i++)
		for (j = 0; a[i] != 1 && j < P; j++)
			for (; a[i] % primes[j] == 0; a[i] /= primes[j])
				factors[i].pb(primes[j]);

	sort(factors, factors + N);

	printf("%lld\n", solve(0, N, 0));
}
